long long div_ceil(long long a, long long b) {
  if ((a >= 0 and b >= 0) or (a < 0 and b < 0)) {
    return a / b + (a % b != 0);
  } else {
    return a / b;
  }
}

long long div_floor(long long a, long long b) {
  if ((a >= 0 and b >= 0) or (a < 0 and b < 0)) {
    return a / b;
  } else {
    return a / b - (a % b != 0);
  }
}
