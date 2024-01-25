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
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 3 \"graph/dsu.cpp\"\n\
    \r\n/**\r\n * @brief Disjoint Set Union\r\n * @docs docs/graph/dsu.md\r\n */\r\
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
    \n    std::vector<int> par, sz;\r\n};\r\n#line 6 \"test/graph/dsu/dsu.test.cpp\"\
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
  timestamp: '2024-01-25 11:55:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/dsu/dsu.test.cpp
layout: document
redirect_from:
- /verify/test/graph/dsu/dsu.test.cpp
- /verify/test/graph/dsu/dsu.test.cpp.html
title: test/graph/dsu/dsu.test.cpp
---
