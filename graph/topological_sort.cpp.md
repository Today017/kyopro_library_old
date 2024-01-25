---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Topological Sort
    links: []
  bundledCode: "#line 1 \"graph/topological_sort.cpp\"\n#include <vector>\n#include\
    \ <queue>\n\n/**\n * @brief Topological Sort\n */\n\nstd::vector<int> topological_sort(const\
    \ std::vector<std::vector<int>> &G) {\n    int n = G.size();\n    std::vector<int>\
    \ indeg(n);\n    for (int i = 0; i < n; i++) {\n        for (int nxt : G[i]) {\n\
    \            indeg[nxt]++;\n        }\n    }\n    std::queue<int> Q;\n    for\
    \ (int i = 0; i < n; i++) {\n        if (indeg[i] == 0) {\n            Q.push(i);\n\
    \        }\n    }\n    std::vector<int> ret;\n    while (!Q.empty()) {\n     \
    \   int now = Q.front();\n        Q.pop();\n        for (int nxt : G[now]) {\n\
    \            indeg[nxt]--;\n            if (indeg[nxt] == 0) {\n             \
    \   Q.push(nxt);\n            }\n        }\n        ret.push_back(now);\n    }\n\
    \    return ret;\n}\n"
  code: "#include <vector>\n#include <queue>\n\n/**\n * @brief Topological Sort\n\
    \ */\n\nstd::vector<int> topological_sort(const std::vector<std::vector<int>>\
    \ &G) {\n    int n = G.size();\n    std::vector<int> indeg(n);\n    for (int i\
    \ = 0; i < n; i++) {\n        for (int nxt : G[i]) {\n            indeg[nxt]++;\n\
    \        }\n    }\n    std::queue<int> Q;\n    for (int i = 0; i < n; i++) {\n\
    \        if (indeg[i] == 0) {\n            Q.push(i);\n        }\n    }\n    std::vector<int>\
    \ ret;\n    while (!Q.empty()) {\n        int now = Q.front();\n        Q.pop();\n\
    \        for (int nxt : G[now]) {\n            indeg[nxt]--;\n            if (indeg[nxt]\
    \ == 0) {\n                Q.push(nxt);\n            }\n        }\n        ret.push_back(now);\n\
    \    }\n    return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/topological_sort.cpp
  requiredBy: []
  timestamp: '2024-01-25 11:55:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/topological_sort.cpp
layout: document
redirect_from:
- /library/graph/topological_sort.cpp
- /library/graph/topological_sort.cpp.html
title: Topological Sort
---
