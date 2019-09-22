/**
 * @brief Matrix data structure
 */
template<typename T>
struct Matrix {
private:
  vector<vector<T>> mat;

public:
  Matrix() {}
  Matrix(int n, int m) : mat(n, vector<T>(m, 0)) {}
  Matrix(int n) : mat(n, vector<T>(n, 0)) {}
  Matrix(vector<vector<T>> mat) : mat(mat) {};

  int height() const { return mat.size(); }
  int width() const { return mat[0].size(); }
  vector<T> &operator[](size_t k) { return mat.at(k); }
  const vector<T> &operator[](size_t k) const { return mat.at(k); }
  static Matrix unit(size_t n) {
    Matrix I(n);
    for (int i = 0; i < (int)n; ++i) I[i][i] = 1;
    return I;
  }
  Matrix &operator+=(const Matrix &B) {
    int h = this->height(), w = this->width();
    assert(h == B.height() and w == B.width());
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        (*this)[i][j] += B[i][j];
      }
    }
    return *this;
  }
  Matrix &operator-=(const Matrix &B) {
    int h = this->height(), w = this->width();
    assert(h == B.height() and w == B.width());
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        (*this)[i][j] -= B[i][j];
      }
    }
    return *this;
  }
  Matrix &operator*=(const Matrix &B) {
    int h = this->height(), z = this->width(), w = B.width();
    assert(z == B.height());
    vector<vector<T>> ret(h, vector<T>(w, 0));
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        for (int k = 0; k < z; ++k) {
          ret[i][j] += (*this)[i][k] * B[k][j];
        }
      }
    }
    (this->mat).swap(ret);
    return *this;
  }
  Matrix operator+(const Matrix &B) const { return Matrix(*this) += B; }
  Matrix operator-(const Matrix &B) const { return Matrix(*this) -= B; }
  Matrix operator*(const Matrix &B) const { return Matrix(*this) *= B; }
  Matrix pow(long long k) {
    Matrix B(this->mat), ret = unit(this->height());
    while (k) {
      if (k & 1) ret *= B;
      B *= B;
      k >>= 1;
    }
    return ret;
  }
  static int gause_jordan(Matrix &A) {
    constexpr double EPS = 1e-9;
    int m = A.height(), n = A.width();
    int rank = 0;
    for (int col = 0; col < n-1; ++col) {
      int pivot = -1;
      T ma = EPS;
      for (int row = rank; row < m; ++row) {
        if (abs(A[row][col]) > ma) {
          ma = abs(A[row][col]);
          pivot = row;
        }
      }
      if (pivot == -1) continue;
      swap(A[pivot], A[rank]);
      T fac = A[rank][col];
      for (int col2 = 0; col2 < n; ++col2) A[rank][col2] /= fac;
      for (int row = 0; row < m; ++row) {
        if (row != rank and abs(A[row][col]) > EPS) {
          T fac = A[row][col];
          for (int col2 = 0; col2 < n; ++col2) A[row][col2] -= A[rank][col2] * fac;
        }
      }
      ++rank;
    }
    return rank;
  }
  static vector<T> linear_equation(Matrix A, vector<T> b) {
    constexpr double EPS = 1e-9;
    int m = A.height(), n = A.width();
    Matrix M(m, n+1);
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) M[i][j] = A[i][j];
      M[i][n] = b[i];
    }
    int rank = gause_jordan(M);
    vector<T> res;
    for (int row = rank; row < m; ++row) {
      if (abs(M[row][n]) < EPS) return res;
    }
    res.assign(n, 0);
    for (int i = 0; i < rank; ++i) res[i] = M[i][n];
    return res;
  }
  friend ostream &operator<<(ostream &os, const Matrix<T> &x) {
    int h = x.height(), w = x.width();
    for (int i = 0; i < h; ++i) {
      os << "[";
      for (int j = 0; j < w; ++j) {
        os << x[i][j];
        if (j != w-1) os <<", ";
      }
      os << (i != h-1 ? "]\n" : "]");
    }
    return os;
  }
};