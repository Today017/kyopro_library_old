---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/lca.cpp
    title: Lowest Common Ancestor
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"test/graph/lowest_common_ancestor/lca.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 3 \"graph/lca.cpp\"\n\n/**\n * @brief Lowest Common\
    \ Ancestor\n * @docs docs/graph/lca.md\n */\n\nstruct lowest_common_ancestor {\n\
    \tstd::vector<std::vector<int>> parent;\n\tstd::vector<int> dst;\n\tlowest_common_ancestor(std::vector<std::vector<int>>\
    \ &G, int root = 0) {\n\t\tint n = G.size();\n\t\tint k = 1;\n\t\twhile ((1 <<\
    \ k) < n) {\n\t\t\tk++;\n\t\t}\n\t\tparent = std::vector<std::vector<int>>(k,\
    \ std::vector<int>(n, -1));\n\t\tdst = std::vector<int>(n, -1);\n\t\tdfs(G, root,\
    \ -1, 0);\n\t\tfor (int i = 0; i + 1 < k; i++) {\n\t\t\tfor (int j = 0; j < n;\
    \ j++) {\n\t\t\t\tif (parent[i][j] < 0) {\n\t\t\t\t\tparent[i + 1][j] = -1;\n\t\
    \t\t\t} else {\n\t\t\t\t\tparent[i + 1][j] = parent[i][parent[i][j]];\n\t\t\t\t\
    }\n\t\t\t}\n\t\t}\n\t}\n\tvoid dfs(std::vector<std::vector<int>> &G, int now,\
    \ int pre, int tmp) {\n\t\tparent[0][now] = pre;\n\t\tdst[now] = tmp;\n\t\tfor\
    \ (int nxt : G[now]) {\n\t\t\tif (nxt != pre) {\n\t\t\t\tdfs(G, nxt, now, tmp\
    \ + 1);\n\t\t\t}\n\t\t}\n\t}\n\tint lca(int u, int v) {\n\t\tif (dst[u] < dst[v])\
    \ {\n\t\t\tstd::swap(u, v);\n\t\t}\n\t\tint k = parent.size();\n\t\tfor (int i\
    \ = 0; i < k; i++) {\n\t\t\tif ((dst[u] - dst[v]) >> i & 1) {\n\t\t\t\tu = parent[i][u];\n\
    \t\t\t}\n\t\t}\n\t\tif (u == v) {\n\t\t\treturn u;\n\t\t}\n\t\tfor (int i = k\
    \ - 1; i >= 0; i--) {\n\t\t\tif (parent[i][u] != parent[i][v]) {\n\t\t\t\tu =\
    \ parent[i][u];\n\t\t\t\tv = parent[i][v];\n\t\t\t}\n\t\t}\n\t\treturn parent[0][u];\n\
    \t}\n\tint distance(int u, int v) {\n\t\treturn dst[u] + dst[v] - 2 * dst[lca(u,\
    \ v)];\n\t}\n\tbool is_on_path(int u, int v, int x) {\n\t\treturn distance(u,\
    \ x) + distance(x, v) == distance(u, v);\n\t}\n\tint climb(int u, int d) {\n\t\
    \tint k = parent.size();\n\t\tfor (int i = k - 1; i >= 0; i--) {\n\t\t\tif (d\
    \ >> i & 1) {\n\t\t\t\tu = parent[i][u];\n\t\t\t}\n\t\t}\n\t\treturn u;\n\t}\n\
    };\n#line 6 \"test/graph/lowest_common_ancestor/lca.test.cpp\"\n\nint main() {\n\
    \tint N, Q;\n\tcin >> N >> Q;\n\n\tvector<vector<int>> G(N);\n\tfor (int i = 1;\
    \ i < N; i++) {\n\t\tint p;\n\t\tcin >> p;\n\t\tG[p].push_back(i);\n\t\tG[i].push_back(p);\n\
    \t}\n\n\tlowest_common_ancestor lca(G);\n\n\twhile (Q--) {\n\t\tint u, v;\n\t\t\
    cin >> u >> v;\n\n\t\tcout << lca.lca(u, v) << '\\n';\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#include \"../../../graph/lca.cpp\"\n\nint main() {\n\t\
    int N, Q;\n\tcin >> N >> Q;\n\n\tvector<vector<int>> G(N);\n\tfor (int i = 1;\
    \ i < N; i++) {\n\t\tint p;\n\t\tcin >> p;\n\t\tG[p].push_back(i);\n\t\tG[i].push_back(p);\n\
    \t}\n\n\tlowest_common_ancestor lca(G);\n\n\twhile (Q--) {\n\t\tint u, v;\n\t\t\
    cin >> u >> v;\n\n\t\tcout << lca.lca(u, v) << '\\n';\n\t}\n}"
  dependsOn:
  - graph/lca.cpp
  isVerificationFile: true
  path: test/graph/lowest_common_ancestor/lca.test.cpp
  requiredBy: []
  timestamp: '2023-12-06 10:41:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/lowest_common_ancestor/lca.test.cpp
layout: document
redirect_from:
- /verify/test/graph/lowest_common_ancestor/lca.test.cpp
- /verify/test/graph/lowest_common_ancestor/lca.test.cpp.html
title: test/graph/lowest_common_ancestor/lca.test.cpp
---
