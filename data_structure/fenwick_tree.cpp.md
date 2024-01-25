---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/fenwick_tree/fenwick_tree.test.cpp
    title: test/data_structure/fenwick_tree/fenwick_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/hl_decomposition/hld.test.cpp
    title: test/graph/hl_decomposition/hld.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data_structure/fenwick_tree.md
    document_title: Fenwick Tree
    links: []
  bundledCode: "#line 1 \"data_structure/fenwick_tree.cpp\"\n#include <vector>\r\n\
    \r\n/**\r\n * @brief Fenwick Tree\r\n * @docs docs/data_structure/fenwick_tree.md\r\
    \n */\r\n\r\ntemplate <typename T>\r\nstruct fenwick_tree {\r\n    fenwick_tree(int\
    \ n) {\r\n        this->n = n;\r\n        dat.resize(n);\r\n    }\r\n    void\
    \ add(int i, T x) {\r\n        i++;\r\n        while (i <= n) {\r\n          \
    \  dat[i - 1] += x;\r\n            i += i & -i;\r\n        }\r\n    }\r\n    T\
    \ operator[](int i) {\r\n        return sum(i, i + 1);\r\n    }\r\n    T sum(int\
    \ l, int r) {\r\n        return sum(r) - sum(l);\r\n    }\r\n\r\nprivate:\r\n\
    \    int n;\r\n    std::vector<T> dat;\r\n    T sum(int r) {\r\n        T ret\
    \ = 0;\r\n        while (r > 0) {\r\n            ret += dat[r - 1];\r\n      \
    \      r -= r & -r;\r\n        }\r\n        return ret;\r\n    }\r\n};\n"
  code: "#include <vector>\r\n\r\n/**\r\n * @brief Fenwick Tree\r\n * @docs docs/data_structure/fenwick_tree.md\r\
    \n */\r\n\r\ntemplate <typename T>\r\nstruct fenwick_tree {\r\n    fenwick_tree(int\
    \ n) {\r\n        this->n = n;\r\n        dat.resize(n);\r\n    }\r\n    void\
    \ add(int i, T x) {\r\n        i++;\r\n        while (i <= n) {\r\n          \
    \  dat[i - 1] += x;\r\n            i += i & -i;\r\n        }\r\n    }\r\n    T\
    \ operator[](int i) {\r\n        return sum(i, i + 1);\r\n    }\r\n    T sum(int\
    \ l, int r) {\r\n        return sum(r) - sum(l);\r\n    }\r\n\r\nprivate:\r\n\
    \    int n;\r\n    std::vector<T> dat;\r\n    T sum(int r) {\r\n        T ret\
    \ = 0;\r\n        while (r > 0) {\r\n            ret += dat[r - 1];\r\n      \
    \      r -= r & -r;\r\n        }\r\n        return ret;\r\n    }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/fenwick_tree.cpp
  requiredBy: []
  timestamp: '2024-01-25 11:55:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/fenwick_tree/fenwick_tree.test.cpp
  - test/graph/hl_decomposition/hld.test.cpp
documentation_of: data_structure/fenwick_tree.cpp
layout: document
redirect_from:
- /library/data_structure/fenwick_tree.cpp
- /library/data_structure/fenwick_tree.cpp.html
title: Fenwick Tree
---

ac-library/fenwicktreeと仕様はほぼ同じです。

```fenwick_tree<T> ft(int n)```
- $O(n)$


```ft.add(int i, T x)```
- 位置`i`に`x`を加算する。
- $0\le p<n$
- $O(\log{n})$


```ft.sum(int l, int r)```
- 区間`[l,r)`の総和を返す。
- $0\le l \le r\le n$
- $O(\log{n})$

#### 区間加算1点取得をしたい場合
```cpp
fenwick_tree<int> ft(N + 1);

// 区間加算
ft.add(l, x);
ft.add(r + 1, x);

// 取得
ft.sum(i + 1);
```