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
    links: []
  bundledCode: "#line 1 \"graph/dsu.cpp\"\n#include <bits/stdc++.h>\r\nusing namespace\
    \ std;\r\n\r\nstruct dsu {\r\n\tvector<int> par, sz;\r\n\tdsu(int n) {\r\n\t\t\
    par.resize(n);\r\n\t\tsz.resize(n);\r\n\t\tfor (int i = 0; i < n; i++) {\r\n\t\
    \t\tpar[i] = i;\r\n\t\t\tsz[i] = 1;\r\n\t\t}\r\n\t}\r\n\tint find(int x) {\r\n\
    \t\tif (par[x] == x) {\r\n\t\t\treturn x;\r\n\t\t}\r\n\t\tpar[x] = find(par[x]);\r\
    \n\t\treturn par[x];\r\n\t}\r\n\tvoid unite(int x, int y) {\r\n\t\tx = find(x);\r\
    \n\t\ty = find(y);\r\n\t\tif (x == y) {\r\n\t\t\treturn;\r\n\t\t}\r\n\t\tif (sz[x]\
    \ < sz[y]) {\r\n\t\t\tswap(x, y);\r\n\t\t}\r\n\t\tpar[y] = x;\r\n\t\tsz[x] +=\
    \ sz[y];\r\n\t}\r\n\tint size(int x) {\r\n\t\treturn sz[find(x)];\r\n\t}\r\n\t\
    bool is_united(int x, int y) {\r\n\t\treturn find(x) == find(y);\r\n\t}\r\n};\r\
    \n"
  code: "#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\nstruct dsu {\r\n\t\
    vector<int> par, sz;\r\n\tdsu(int n) {\r\n\t\tpar.resize(n);\r\n\t\tsz.resize(n);\r\
    \n\t\tfor (int i = 0; i < n; i++) {\r\n\t\t\tpar[i] = i;\r\n\t\t\tsz[i] = 1;\r\
    \n\t\t}\r\n\t}\r\n\tint find(int x) {\r\n\t\tif (par[x] == x) {\r\n\t\t\treturn\
    \ x;\r\n\t\t}\r\n\t\tpar[x] = find(par[x]);\r\n\t\treturn par[x];\r\n\t}\r\n\t\
    void unite(int x, int y) {\r\n\t\tx = find(x);\r\n\t\ty = find(y);\r\n\t\tif (x\
    \ == y) {\r\n\t\t\treturn;\r\n\t\t}\r\n\t\tif (sz[x] < sz[y]) {\r\n\t\t\tswap(x,\
    \ y);\r\n\t\t}\r\n\t\tpar[y] = x;\r\n\t\tsz[x] += sz[y];\r\n\t}\r\n\tint size(int\
    \ x) {\r\n\t\treturn sz[find(x)];\r\n\t}\r\n\tbool is_united(int x, int y) {\r\
    \n\t\treturn find(x) == find(y);\r\n\t}\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/dsu.cpp
  requiredBy: []
  timestamp: '2023-11-30 18:16:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/dsu/dsu.test.cpp
documentation_of: graph/dsu.cpp
layout: document
redirect_from:
- /library/graph/dsu.cpp
- /library/graph/dsu.cpp.html
title: graph/dsu.cpp
---
