---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u6728\u306E\u6DF1\u3055"
    links: []
  bundledCode: "#line 1 \"graph/tree_depth.cpp\"\n#include <vector>\n\n/**\n * @brief\
    \ \u6728\u306E\u6DF1\u3055\n */\n\nstd::vector<int> tree_depth(std::vector<std::vector<int>>\
    \ &G, int root = 0) {\n    int n = G.size();\n    std::vector<int> depth(n);\n\
    \    auto dfs = [&](auto &&dfs, int now, int pre) -> void {\n        for (int\
    \ nxt : G[now]) {\n            if (nxt != pre) {\n                depth[nxt] =\
    \ depth[now] + 1;\n                dfs(dfs, nxt, now);\n            }\n      \
    \  }\n    };\n    dfs(dfs, root, -1);\n    return depth;\n}\n"
  code: "#include <vector>\n\n/**\n * @brief \u6728\u306E\u6DF1\u3055\n */\n\nstd::vector<int>\
    \ tree_depth(std::vector<std::vector<int>> &G, int root = 0) {\n    int n = G.size();\n\
    \    std::vector<int> depth(n);\n    auto dfs = [&](auto &&dfs, int now, int pre)\
    \ -> void {\n        for (int nxt : G[now]) {\n            if (nxt != pre) {\n\
    \                depth[nxt] = depth[now] + 1;\n                dfs(dfs, nxt, now);\n\
    \            }\n        }\n    };\n    dfs(dfs, root, -1);\n    return depth;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: graph/tree_depth.cpp
  requiredBy: []
  timestamp: '2024-01-25 11:55:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/tree_depth.cpp
layout: document
redirect_from:
- /library/graph/tree_depth.cpp
- /library/graph/tree_depth.cpp.html
title: "\u6728\u306E\u6DF1\u3055"
---
