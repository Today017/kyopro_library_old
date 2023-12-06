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
    \n\r\nstruct dsu {\r\n\tstd::vector<int> par, sz;\r\n\tdsu(int n) {\r\n\t\tpar.resize(n);\r\
    \n\t\tsz.resize(n);\r\n\t\tfor (int i = 0; i < n; i++) {\r\n\t\t\tpar[i] = i;\r\
    \n\t\t\tsz[i] = 1;\r\n\t\t}\r\n\t}\r\n\tint find(int x) {\r\n\t\tif (par[x] ==\
    \ x) {\r\n\t\t\treturn x;\r\n\t\t}\r\n\t\tpar[x] = find(par[x]);\r\n\t\treturn\
    \ par[x];\r\n\t}\r\n\tvoid unite(int x, int y) {\r\n\t\tx = find(x);\r\n\t\ty\
    \ = find(y);\r\n\t\tif (x == y) {\r\n\t\t\treturn;\r\n\t\t}\r\n\t\tif (sz[x] <\
    \ sz[y]) {\r\n\t\t\tstd::swap(x, y);\r\n\t\t}\r\n\t\tpar[y] = x;\r\n\t\tsz[x]\
    \ += sz[y];\r\n\t}\r\n\tint size(int x) {\r\n\t\treturn sz[find(x)];\r\n\t}\r\n\
    \tbool is_united(int x, int y) {\r\n\t\treturn find(x) == find(y);\r\n\t}\r\n\
    };\r\n"
  code: "#include <vector>\r\n#include <utility>\r\n\r\n/**\r\n * @brief Disjoint\
    \ Set Union\r\n * @docs docs/graph/dsu.md\r\n */\r\n\r\nstruct dsu {\r\n\tstd::vector<int>\
    \ par, sz;\r\n\tdsu(int n) {\r\n\t\tpar.resize(n);\r\n\t\tsz.resize(n);\r\n\t\t\
    for (int i = 0; i < n; i++) {\r\n\t\t\tpar[i] = i;\r\n\t\t\tsz[i] = 1;\r\n\t\t\
    }\r\n\t}\r\n\tint find(int x) {\r\n\t\tif (par[x] == x) {\r\n\t\t\treturn x;\r\
    \n\t\t}\r\n\t\tpar[x] = find(par[x]);\r\n\t\treturn par[x];\r\n\t}\r\n\tvoid unite(int\
    \ x, int y) {\r\n\t\tx = find(x);\r\n\t\ty = find(y);\r\n\t\tif (x == y) {\r\n\
    \t\t\treturn;\r\n\t\t}\r\n\t\tif (sz[x] < sz[y]) {\r\n\t\t\tstd::swap(x, y);\r\
    \n\t\t}\r\n\t\tpar[y] = x;\r\n\t\tsz[x] += sz[y];\r\n\t}\r\n\tint size(int x)\
    \ {\r\n\t\treturn sz[find(x)];\r\n\t}\r\n\tbool is_united(int x, int y) {\r\n\t\
    \treturn find(x) == find(y);\r\n\t}\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/dsu.cpp
  requiredBy: []
  timestamp: '2023-12-06 10:41:43+09:00'
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