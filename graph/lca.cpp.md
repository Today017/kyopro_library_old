---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/lowest_common_ancestor/lca.test.cpp
    title: test/graph/lowest_common_ancestor/lca.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/lca.md
    document_title: Lowest Common Ancestor
    links: []
  bundledCode: "#line 1 \"graph/lca.cpp\"\n#include <vector>\n#include <utility>\n\
    \n/**\n * @brief Lowest Common Ancestor\n * @docs docs/graph/lca.md\n */\n\nstruct\
    \ lowest_common_ancestor {\n    lowest_common_ancestor(std::vector<std::vector<int>>\
    \ &G, int root = 0) {\n        int n = G.size();\n        int k = 1;\n       \
    \ while ((1 << k) < n) {\n            k++;\n        }\n        parent = std::vector<std::vector<int>>(k,\
    \ std::vector<int>(n, -1));\n        dst = std::vector<int>(n, -1);\n        dfs(G,\
    \ root, -1, 0);\n        for (int i = 0; i + 1 < k; i++) {\n            for (int\
    \ j = 0; j < n; j++) {\n                if (parent[i][j] < 0) {\n            \
    \        parent[i + 1][j] = -1;\n                } else {\n                  \
    \  parent[i + 1][j] = parent[i][parent[i][j]];\n                }\n          \
    \  }\n        }\n    }\n    int lca(int u, int v) {\n        if (dst[u] < dst[v])\
    \ {\n            std::swap(u, v);\n        }\n        int k = parent.size();\n\
    \        for (int i = 0; i < k; i++) {\n            if ((dst[u] - dst[v]) >> i\
    \ & 1) {\n                u = parent[i][u];\n            }\n        }\n      \
    \  if (u == v) {\n            return u;\n        }\n        for (int i = k - 1;\
    \ i >= 0; i--) {\n            if (parent[i][u] != parent[i][v]) {\n          \
    \      u = parent[i][u];\n                v = parent[i][v];\n            }\n \
    \       }\n        return parent[0][u];\n    }\n    int distance(int u, int v)\
    \ {\n        return dst[u] + dst[v] - 2 * dst[lca(u, v)];\n    }\n    bool is_on_path(int\
    \ u, int v, int x) {\n        return distance(u, x) + distance(x, v) == distance(u,\
    \ v);\n    }\n    int climb(int u, int d) {\n        int k = parent.size();\n\
    \        for (int i = k - 1; i >= 0; i--) {\n            if (d >> i & 1) {\n \
    \               u = parent[i][u];\n            }\n        }\n        return u;\n\
    \    }\n\nprivate:\n    std::vector<std::vector<int>> parent;\n    std::vector<int>\
    \ dst;\n    void dfs(std::vector<std::vector<int>> &G, int now, int pre, int tmp)\
    \ {\n        parent[0][now] = pre;\n        dst[now] = tmp;\n        for (int\
    \ nxt : G[now]) {\n            if (nxt != pre) {\n                dfs(G, nxt,\
    \ now, tmp + 1);\n            }\n        }\n    }\n};\n"
  code: "#include <vector>\n#include <utility>\n\n/**\n * @brief Lowest Common Ancestor\n\
    \ * @docs docs/graph/lca.md\n */\n\nstruct lowest_common_ancestor {\n    lowest_common_ancestor(std::vector<std::vector<int>>\
    \ &G, int root = 0) {\n        int n = G.size();\n        int k = 1;\n       \
    \ while ((1 << k) < n) {\n            k++;\n        }\n        parent = std::vector<std::vector<int>>(k,\
    \ std::vector<int>(n, -1));\n        dst = std::vector<int>(n, -1);\n        dfs(G,\
    \ root, -1, 0);\n        for (int i = 0; i + 1 < k; i++) {\n            for (int\
    \ j = 0; j < n; j++) {\n                if (parent[i][j] < 0) {\n            \
    \        parent[i + 1][j] = -1;\n                } else {\n                  \
    \  parent[i + 1][j] = parent[i][parent[i][j]];\n                }\n          \
    \  }\n        }\n    }\n    int lca(int u, int v) {\n        if (dst[u] < dst[v])\
    \ {\n            std::swap(u, v);\n        }\n        int k = parent.size();\n\
    \        for (int i = 0; i < k; i++) {\n            if ((dst[u] - dst[v]) >> i\
    \ & 1) {\n                u = parent[i][u];\n            }\n        }\n      \
    \  if (u == v) {\n            return u;\n        }\n        for (int i = k - 1;\
    \ i >= 0; i--) {\n            if (parent[i][u] != parent[i][v]) {\n          \
    \      u = parent[i][u];\n                v = parent[i][v];\n            }\n \
    \       }\n        return parent[0][u];\n    }\n    int distance(int u, int v)\
    \ {\n        return dst[u] + dst[v] - 2 * dst[lca(u, v)];\n    }\n    bool is_on_path(int\
    \ u, int v, int x) {\n        return distance(u, x) + distance(x, v) == distance(u,\
    \ v);\n    }\n    int climb(int u, int d) {\n        int k = parent.size();\n\
    \        for (int i = k - 1; i >= 0; i--) {\n            if (d >> i & 1) {\n \
    \               u = parent[i][u];\n            }\n        }\n        return u;\n\
    \    }\n\nprivate:\n    std::vector<std::vector<int>> parent;\n    std::vector<int>\
    \ dst;\n    void dfs(std::vector<std::vector<int>> &G, int now, int pre, int tmp)\
    \ {\n        parent[0][now] = pre;\n        dst[now] = tmp;\n        for (int\
    \ nxt : G[now]) {\n            if (nxt != pre) {\n                dfs(G, nxt,\
    \ now, tmp + 1);\n            }\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/lca.cpp
  requiredBy: []
  timestamp: '2024-01-25 11:55:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/lowest_common_ancestor/lca.test.cpp
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