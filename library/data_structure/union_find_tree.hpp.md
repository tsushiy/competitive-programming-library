---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :heavy_check_mark: UnionFind Tree <small>(data_structure/union_find_tree.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c8f6850ec2ec3fb32f203c1f4e3c2fd2">data_structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data_structure/union_find_tree.hpp">View this file on GitHub</a>
    - Last commit date: 2019-09-23 14:42:48+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/data_structure/union_find_tree.test.cpp.html">data_structure/union_find_tree.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief UnionFind Tree
 * @note O(α(N))
 */
struct UnionFind{
private:
  vector<int> par, rank, sizes;
public:
  UnionFind(int n) : par(n, -1), rank(n, 0), sizes(n, 1){}
  int find(int x) { return (par[x] < 0) ? x : (par[x] = find(par[x])); }
  bool unite(int x, int y){
    x = find(x), y = find(y);
    if(x==y) return false;
    else if(rank[x]<rank[y]){
      par[x] = y;
      sizes[y] += sizes[x];
    } else if(rank[x]>rank[y]){
      par[y] = x;
      sizes[x] += sizes[y];
    } else{
      par[y] = x;
      rank[x] += 1;
      sizes[x] += sizes[y];
    }
    return true;
  }
  bool same(int x, int y) { return find(x) == find(y); }
  int size(int x) { return sizes[find(x)]; }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data_structure/union_find_tree.hpp"
/**
 * @brief UnionFind Tree
 * @note O(α(N))
 */
struct UnionFind{
private:
  vector<int> par, rank, sizes;
public:
  UnionFind(int n) : par(n, -1), rank(n, 0), sizes(n, 1){}
  int find(int x) { return (par[x] < 0) ? x : (par[x] = find(par[x])); }
  bool unite(int x, int y){
    x = find(x), y = find(y);
    if(x==y) return false;
    else if(rank[x]<rank[y]){
      par[x] = y;
      sizes[y] += sizes[x];
    } else if(rank[x]>rank[y]){
      par[y] = x;
      sizes[x] += sizes[y];
    } else{
      par[y] = x;
      rank[x] += 1;
      sizes[x] += sizes[y];
    }
    return true;
  }
  bool same(int x, int y) { return find(x) == find(y); }
  int size(int x) { return sizes[find(x)]; }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

