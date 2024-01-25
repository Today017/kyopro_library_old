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
    \    lowest_common_ancestor(std::vector<std::vector<int>> &G, int root = 0) {\n\
    \        int n = G.size();\n        int k = 1;\n        while ((1 << k) < n) {\n\
    \            k++;\n        }\n        parent = std::vector<std::vector<int>>(k,\
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
    \ now, tmp + 1);\n            }\n        }\n    }\n};\n#line 6 \"test/graph/lowest_common_ancestor/lca.test.cpp\"\
    \n\nint main() {\n\tint N, Q;\n\tcin >> N >> Q;\n\n\tvector<vector<int>> G(N);\n\
    \tfor (int i = 1; i < N; i++) {\n\t\tint p;\n\t\tcin >> p;\n\t\tG[p].push_back(i);\n\
    \t\tG[i].push_back(p);\n\t}\n\n\tlowest_common_ancestor lca(G);\n\n\twhile (Q--)\
    \ {\n\t\tint u, v;\n\t\tcin >> u >> v;\n\n\t\tcout << lca.lca(u, v) << '\\n';\n\
    \t}\n}\n"
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
  timestamp: '2024-01-25 11:55:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/lowest_common_ancestor/lca.test.cpp
layout: document
redirect_from:
- /verify/test/graph/lowest_common_ancestor/lca.test.cpp
- /verify/test/graph/lowest_common_ancestor/lca.test.cpp.html
title: test/graph/lowest_common_ancestor/lca.test.cpp
---
