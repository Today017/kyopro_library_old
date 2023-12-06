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
    \ &G, int root = 0) {\n\tint n = G.size();\n\tstd::vector<int> depth(n);\n\tauto\
    \ dfs = [&](auto &&dfs, int now, int pre) -> void {\n\t\tfor (int nxt : G[now])\
    \ {\n\t\t\tif (nxt != pre) {\n\t\t\t\tdepth[nxt] = depth[now] + 1;\n\t\t\t\tdfs(dfs,\
    \ nxt, now);\n\t\t\t}\n\t\t}\n\t};\n\tdfs(dfs, root, -1);\n\treturn depth;\n}\n"
  code: "#include <vector>\n\n/**\n * @brief \u6728\u306E\u6DF1\u3055\n */\n\nstd::vector<int>\
    \ tree_depth(std::vector<std::vector<int>> &G, int root = 0) {\n\tint n = G.size();\n\
    \tstd::vector<int> depth(n);\n\tauto dfs = [&](auto &&dfs, int now, int pre) ->\
    \ void {\n\t\tfor (int nxt : G[now]) {\n\t\t\tif (nxt != pre) {\n\t\t\t\tdepth[nxt]\
    \ = depth[now] + 1;\n\t\t\t\tdfs(dfs, nxt, now);\n\t\t\t}\n\t\t}\n\t};\n\tdfs(dfs,\
    \ root, -1);\n\treturn depth;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/tree_depth.cpp
  requiredBy: []
  timestamp: '2023-12-06 10:41:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/tree_depth.cpp
layout: document
redirect_from:
- /library/graph/tree_depth.cpp
- /library/graph/tree_depth.cpp.html
title: "\u6728\u306E\u6DF1\u3055"
---
