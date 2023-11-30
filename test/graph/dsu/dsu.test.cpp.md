---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/dsu.cpp
    title: Disjoint Set Union
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"test/graph/dsu/dsu.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"graph/dsu.cpp\"\n\
    /**\r\n * @brief Disjoint Set Union\r\n * @docs docs/graph/dsu.md\r\n*/\r\n\r\n\
    struct dsu {\r\n\tvector<int> par, sz;\r\n\tdsu(int n) {\r\n\t\tpar.resize(n);\r\
    \n\t\tsz.resize(n);\r\n\t\tfor (int i = 0; i < n; i++) {\r\n\t\t\tpar[i] = i;\r\
    \n\t\t\tsz[i] = 1;\r\n\t\t}\r\n\t}\r\n\tint find(int x) {\r\n\t\tif (par[x] ==\
    \ x) {\r\n\t\t\treturn x;\r\n\t\t}\r\n\t\tpar[x] = find(par[x]);\r\n\t\treturn\
    \ par[x];\r\n\t}\r\n\tvoid unite(int x, int y) {\r\n\t\tx = find(x);\r\n\t\ty\
    \ = find(y);\r\n\t\tif (x == y) {\r\n\t\t\treturn;\r\n\t\t}\r\n\t\tif (sz[x] <\
    \ sz[y]) {\r\n\t\t\tswap(x, y);\r\n\t\t}\r\n\t\tpar[y] = x;\r\n\t\tsz[x] += sz[y];\r\
    \n\t}\r\n\tint size(int x) {\r\n\t\treturn sz[find(x)];\r\n\t}\r\n\tbool is_united(int\
    \ x, int y) {\r\n\t\treturn find(x) == find(y);\r\n\t}\r\n};\r\n#line 6 \"test/graph/dsu/dsu.test.cpp\"\
    \n\nint main() {\n\tint N, Q;\n\tcin >> N >> Q;\n\n\tdsu ds(N);\n\n\twhile (Q--)\
    \ {\n\t\tint t, u, v;\n\t\tcin >> t >> u >> v;\n\n\t\tif (t == 0) {\n\t\t\tds.unite(u,\
    \ v);\n\t\t} else {\n\t\t\tcout << ds.is_united(u, v) << '\\n';\n\t\t}\n\t}\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#include \"../../../graph/dsu.cpp\"\n\nint main() {\n\t\
    int N, Q;\n\tcin >> N >> Q;\n\n\tdsu ds(N);\n\n\twhile (Q--) {\n\t\tint t, u,\
    \ v;\n\t\tcin >> t >> u >> v;\n\n\t\tif (t == 0) {\n\t\t\tds.unite(u, v);\n\t\t\
    } else {\n\t\t\tcout << ds.is_united(u, v) << '\\n';\n\t\t}\n\t}\n}\n"
  dependsOn:
  - graph/dsu.cpp
  isVerificationFile: true
  path: test/graph/dsu/dsu.test.cpp
  requiredBy: []
  timestamp: '2023-11-30 22:56:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/dsu/dsu.test.cpp
layout: document
redirect_from:
- /verify/test/graph/dsu/dsu.test.cpp
- /verify/test/graph/dsu/dsu.test.cpp.html
title: test/graph/dsu/dsu.test.cpp
---
