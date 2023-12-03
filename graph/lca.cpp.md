---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/graph/lca.md
    document_title: Lowest Common Ancestor
    links: []
  bundledCode: "#line 1 \"graph/lca.cpp\"\n/**\n * @brief Lowest Common Ancestor\n\
    \ * @docs docs/graph/lca.md\n*/\n\nstruct lowest_common_ancestor {\n\tvector<vector<int>>\
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
  code: "/**\n * @brief Lowest Common Ancestor\n * @docs docs/graph/lca.md\n*/\n\n\
    struct lowest_common_ancestor {\n\tvector<vector<int>> parent;\n\tvector<int>\
    \ dst;\n\tlowest_common_ancestor(vector<vector<int>> &G, int root = 0) {\n\t\t\
    int n = G.size();\n\t\tint k = 1;\n\t\twhile ((1 << k) < n) {\n\t\t\tk++;\n\t\t\
    }\n\t\tparent = vector<vector<int>>(k, vector<int>(n, -1));\n\t\tdst = vector<int>(n,\
    \ -1);\n\t\tdfs(G, root, -1, 0);\n\t\tfor (int i = 0; i + 1 < k; i++) {\n\t\t\t\
    for (int j = 0; j < n; j++) {\n\t\t\t\tif (parent[i][j] < 0) {\n\t\t\t\t\tparent[i\
    \ + 1][j] = -1;\n\t\t\t\t} else {\n\t\t\t\t\tparent[i + 1][j] = parent[i][parent[i][j]];\n\
    \t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\tvoid dfs(vector<vector<int>> &G, int now, int\
    \ pre, int tmp) {\n\t\tparent[0][now] = pre;\n\t\tdst[now] = tmp;\n\t\tfor (int\
    \ nxt : G[now]) {\n\t\t\tif (nxt != pre) {\n\t\t\t\tdfs(G, nxt, now, tmp + 1);\n\
    \t\t\t}\n\t\t}\n\t}\n\tint lca(int u, int v) {\n\t\tif (dst[u] < dst[v]) {\n\t\
    \t\tswap(u, v);\n\t\t}\n\t\tint k = parent.size();\n\t\tfor (int i = 0; i < k;\
    \ i++) {\n\t\t\tif ((dst[u] - dst[v]) >> i & 1) {\n\t\t\t\tu = parent[i][u];\n\
    \t\t\t}\n\t\t}\n\t\tif (u == v) {\n\t\t\treturn u;\n\t\t}\n\t\tfor (int i = k\
    \ - 1; i >= 0; i--) {\n\t\t\tif (parent[i][u] != parent[i][v]) {\n\t\t\t\tu =\
    \ parent[i][u];\n\t\t\t\tv = parent[i][v];\n\t\t\t}\n\t\t}\n\t\treturn parent[0][u];\n\
    \t}\n\tint distance(int u, int v) {\n\t\treturn dst[u] + dst[v] - 2 * dst[lca(u,\
    \ v)];\n\t}\n\tbool is_on_path(int u, int v, int x) {\n\t\treturn distance(u,\
    \ x) + distance(x, v) == distance(u, v);\n\t}\n\tint climb(int u, int d) {\n\t\
    \tint k = parent.size();\n\t\tfor (int i = k - 1; i >= 0; i--) {\n\t\t\tif (d\
    \ >> i & 1) {\n\t\t\t\tu = parent[i][u];\n\t\t\t}\n\t\t}\n\t\treturn u;\n\t}\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/lca.cpp
  requiredBy: []
  timestamp: '2023-12-04 01:54:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/lca.cpp
layout: document
redirect_from:
- /library/graph/lca.cpp
- /library/graph/lca.cpp.html
title: Lowest Common Ancestor
---
```lowest_common_ancestor　lca(vector<vector<int>> G, int root)```
- `root`を根として、lcaのための前計算を行う。
- $O(n\log{n})$

```lca.lca(int u, int v)```
- 頂点`u`,`v`のLCAを返す。
- $0\le u, v < n$
- $O(\log{n})$

```lca.distance(int u, int v)```
- パス`u`,`v`の長さを返す。
- $0\le u, v < n$
- $O(\log{n})$

```lca.is_on_path(int u, int v, int x)```
- 頂点`x`がパス`u`,`v`上にあるかを返す。
- $0\le u, v, x < n$
- $O(\log{n})$

```lca.climb(int u, int d)```
- 頂点`u`から`d`回遡った祖先を返す。
- $0\le u < n$
- $O(\log{n})$