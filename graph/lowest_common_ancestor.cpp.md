---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/lowest_common_ancestor.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nstruct lowest_common_ancestor {\n\tvector<vector<int>>\
    \ parent;\n\tvector<int> dst;\n\tlowest_common_ancestor(vector<vector<int>> &G,\
    \ int root = 0) {\n\t\tint n = G.size();\n\t\tint k = 1;\n\t\twhile ((1 << k)\
    \ < n) {\n\t\t\tk++;\n\t\t}\n\t\tparent = vector<vector<int>>(k, vector<int>(n,\
    \ -1));\n\t\tdst = vector<int>(n, -1);\n\t\tdfs(G, root, -1, 0);\n\t\tfor (int\
    \ i = 0; i + 1 < k; i++) {\n\t\t\tfor (int j = 0; j < n; j++) {\n\t\t\t\tif (parent[i][j]\
    \ < 0) {\n\t\t\t\t\tparent[i + 1][j] = -1;\n\t\t\t\t} else {\n\t\t\t\t\tparent[i\
    \ + 1][j] = parent[i][parent[i][j]];\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\tvoid dfs(vector<vector<int>>\
    \ &G, int now, int pre, int tmp) {\n\t\tparent[0][now] = pre;\n\t\tdst[now] =\
    \ tmp;\n\t\tfor (int nxt : G[now]) {\n\t\t\tif (nxt != pre) {\n\t\t\t\tdfs(G,\
    \ nxt, now, tmp + 1);\n\t\t\t}\n\t\t}\n\t}\n\tint lca(int u, int v) {\n\t\tif\
    \ (dst[u] < dst[v]) {\n\t\t\tswap(u, v);\n\t\t}\n\t\tint k = parent.size();\n\t\
    \tfor (int i = 0; i < k; i++) {\n\t\t\tif ((dst[u] - dst[v]) >> i & 1) {\n\t\t\
    \t\tu = parent[i][u];\n\t\t\t}\n\t\t}\n\t\tif (u == v) {\n\t\t\treturn u;\n\t\t\
    }\n\t\tfor (int i = k - 1; i >= 0; i--) {\n\t\t\tif (parent[i][u] != parent[i][v])\
    \ {\n\t\t\t\tu = parent[i][u];\n\t\t\t\tv = parent[i][v];\n\t\t\t}\n\t\t}\n\t\t\
    return parent[0][u];\n\t}\n\tint distance(int u, int v) {\n\t\treturn dst[u] +\
    \ dst[v] - 2 * dst[lca(u, v)];\n\t}\n\tbool is_on_path(int u, int v, int x) {\n\
    \t\treturn distance(u, x) + distance(x, v) == distance(u, v);\n\t}\n\tint climb(int\
    \ u, int d) {\n\t\tint k = parent.size();\n\t\tfor (int i = k - 1; i >= 0; i--)\
    \ {\n\t\t\tif (d >> i & 1) {\n\t\t\t\tu = parent[i][u];\n\t\t\t}\n\t\t}\n\t\t\
    return u;\n\t}\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\nstruct lowest_common_ancestor\
    \ {\n\tvector<vector<int>> parent;\n\tvector<int> dst;\n\tlowest_common_ancestor(vector<vector<int>>\
    \ &G, int root = 0) {\n\t\tint n = G.size();\n\t\tint k = 1;\n\t\twhile ((1 <<\
    \ k) < n) {\n\t\t\tk++;\n\t\t}\n\t\tparent = vector<vector<int>>(k, vector<int>(n,\
    \ -1));\n\t\tdst = vector<int>(n, -1);\n\t\tdfs(G, root, -1, 0);\n\t\tfor (int\
    \ i = 0; i + 1 < k; i++) {\n\t\t\tfor (int j = 0; j < n; j++) {\n\t\t\t\tif (parent[i][j]\
    \ < 0) {\n\t\t\t\t\tparent[i + 1][j] = -1;\n\t\t\t\t} else {\n\t\t\t\t\tparent[i\
    \ + 1][j] = parent[i][parent[i][j]];\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\tvoid dfs(vector<vector<int>>\
    \ &G, int now, int pre, int tmp) {\n\t\tparent[0][now] = pre;\n\t\tdst[now] =\
    \ tmp;\n\t\tfor (int nxt : G[now]) {\n\t\t\tif (nxt != pre) {\n\t\t\t\tdfs(G,\
    \ nxt, now, tmp + 1);\n\t\t\t}\n\t\t}\n\t}\n\tint lca(int u, int v) {\n\t\tif\
    \ (dst[u] < dst[v]) {\n\t\t\tswap(u, v);\n\t\t}\n\t\tint k = parent.size();\n\t\
    \tfor (int i = 0; i < k; i++) {\n\t\t\tif ((dst[u] - dst[v]) >> i & 1) {\n\t\t\
    \t\tu = parent[i][u];\n\t\t\t}\n\t\t}\n\t\tif (u == v) {\n\t\t\treturn u;\n\t\t\
    }\n\t\tfor (int i = k - 1; i >= 0; i--) {\n\t\t\tif (parent[i][u] != parent[i][v])\
    \ {\n\t\t\t\tu = parent[i][u];\n\t\t\t\tv = parent[i][v];\n\t\t\t}\n\t\t}\n\t\t\
    return parent[0][u];\n\t}\n\tint distance(int u, int v) {\n\t\treturn dst[u] +\
    \ dst[v] - 2 * dst[lca(u, v)];\n\t}\n\tbool is_on_path(int u, int v, int x) {\n\
    \t\treturn distance(u, x) + distance(x, v) == distance(u, v);\n\t}\n\tint climb(int\
    \ u, int d) {\n\t\tint k = parent.size();\n\t\tfor (int i = k - 1; i >= 0; i--)\
    \ {\n\t\t\tif (d >> i & 1) {\n\t\t\t\tu = parent[i][u];\n\t\t\t}\n\t\t}\n\t\t\
    return u;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/lowest_common_ancestor.cpp
  requiredBy: []
  timestamp: '2023-11-30 18:16:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/lowest_common_ancestor.cpp
layout: document
redirect_from:
- /library/graph/lowest_common_ancestor.cpp
- /library/graph/lowest_common_ancestor.cpp.html
title: graph/lowest_common_ancestor.cpp
---
