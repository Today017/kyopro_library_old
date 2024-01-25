---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/dsu/dsu.test.cpp
    title: test/graph/dsu/dsu.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/dsu.md
    document_title: Disjoint Set Union
    links: []
  bundledCode: "#line 1 \"graph/dsu.cpp\"\n#include <vector>\r\n#include <utility>\r\
    \n\r\n/**\r\n * @brief Disjoint Set Union\r\n * @docs docs/graph/dsu.md\r\n */\r\
    \n\r\nstruct dsu {\r\n    dsu(int n) {\r\n        par.resize(n);\r\n        sz.resize(n);\r\
    \n        for (int i = 0; i < n; i++) {\r\n            par[i] = i;\r\n       \
    \     sz[i] = 1;\r\n        }\r\n    }\r\n    int find(int x) {\r\n        if\
    \ (par[x] == x) {\r\n            return x;\r\n        }\r\n        par[x] = find(par[x]);\r\
    \n        return par[x];\r\n    }\r\n    void unite(int x, int y) {\r\n      \
    \  x = find(x);\r\n        y = find(y);\r\n        if (x == y) {\r\n         \
    \   return;\r\n        }\r\n        if (sz[x] < sz[y]) {\r\n            std::swap(x,\
    \ y);\r\n        }\r\n        par[y] = x;\r\n        sz[x] += sz[y];\r\n    }\r\
    \n    int size(int x) {\r\n        return sz[find(x)];\r\n    }\r\n    bool is_united(int\
    \ x, int y) {\r\n        return find(x) == find(y);\r\n    }\r\n\r\nprivate:\r\
    \n    std::vector<int> par, sz;\r\n};\r\n"
  code: "#include <vector>\r\n#include <utility>\r\n\r\n/**\r\n * @brief Disjoint\
    \ Set Union\r\n * @docs docs/graph/dsu.md\r\n */\r\n\r\nstruct dsu {\r\n    dsu(int\
    \ n) {\r\n        par.resize(n);\r\n        sz.resize(n);\r\n        for (int\
    \ i = 0; i < n; i++) {\r\n            par[i] = i;\r\n            sz[i] = 1;\r\n\
    \        }\r\n    }\r\n    int find(int x) {\r\n        if (par[x] == x) {\r\n\
    \            return x;\r\n        }\r\n        par[x] = find(par[x]);\r\n    \
    \    return par[x];\r\n    }\r\n    void unite(int x, int y) {\r\n        x =\
    \ find(x);\r\n        y = find(y);\r\n        if (x == y) {\r\n            return;\r\
    \n        }\r\n        if (sz[x] < sz[y]) {\r\n            std::swap(x, y);\r\n\
    \        }\r\n        par[y] = x;\r\n        sz[x] += sz[y];\r\n    }\r\n    int\
    \ size(int x) {\r\n        return sz[find(x)];\r\n    }\r\n    bool is_united(int\
    \ x, int y) {\r\n        return find(x) == find(y);\r\n    }\r\n\r\nprivate:\r\
    \n    std::vector<int> par, sz;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/dsu.cpp
  requiredBy: []
  timestamp: '2024-01-25 11:55:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/dsu/dsu.test.cpp
documentation_of: graph/dsu.cpp
layout: document
redirect_from:
- /library/graph/dsu.cpp
- /library/graph/dsu.cpp.html
title: Disjoint Set Union
---

union by sizeにより実装しています。
以下アッカーマン関数の逆関数を$\alpha$とします。

```dsu ds(int n)```
- $O(n)$


```ds.find(int x)```
- 頂点`x`を含む連結成分の代表元を返す。
- $O(\alpha(n))$


```ds.unite(int x, int y)```
- 頂点`x`,`y`を連結する。
- $O(\alpha(n))$

```ds.size(int x)```
- 頂点`x`を含む連結成分のサイズを返す。
- $O(1)$

```ds.is_united(int x, int y)```
- 頂点のペア`(x, y)`が連結であるかを返す。
- $O(\alpha(n))$