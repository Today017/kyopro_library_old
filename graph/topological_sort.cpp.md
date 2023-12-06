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
    \ std::vector<std::vector<int>> &G) {\n\tint n = G.size();\n\tstd::vector<int>\
    \ indeg(n);\n\tfor (int i = 0; i < n; i++) {\n\t\tfor (int nxt : G[i]) {\n\t\t\
    \tindeg[nxt]++;\n\t\t}\n\t}\n\tstd::queue<int> Q;\n\tfor (int i = 0; i < n; i++)\
    \ {\n\t\tif (indeg[i] == 0) {\n\t\t\tQ.push(i);\n\t\t}\n\t}\n\tstd::vector<int>\
    \ ret;\n\twhile (!Q.empty()) {\n\t\tint now = Q.front();\n\t\tQ.pop();\n\t\tfor\
    \ (int nxt : G[now]) {\n\t\t\tindeg[nxt]--;\n\t\t\tif (indeg[nxt] == 0) {\n\t\t\
    \t\tQ.push(nxt);\n\t\t\t}\n\t\t}\n\t\tret.push_back(now);\n\t}\n\treturn ret;\n\
    }\n"
  code: "#include <vector>\n#include <queue>\n\n/**\n * @brief Topological Sort\n\
    \ */\n\nstd::vector<int> topological_sort(const std::vector<std::vector<int>>\
    \ &G) {\n\tint n = G.size();\n\tstd::vector<int> indeg(n);\n\tfor (int i = 0;\
    \ i < n; i++) {\n\t\tfor (int nxt : G[i]) {\n\t\t\tindeg[nxt]++;\n\t\t}\n\t}\n\
    \tstd::queue<int> Q;\n\tfor (int i = 0; i < n; i++) {\n\t\tif (indeg[i] == 0)\
    \ {\n\t\t\tQ.push(i);\n\t\t}\n\t}\n\tstd::vector<int> ret;\n\twhile (!Q.empty())\
    \ {\n\t\tint now = Q.front();\n\t\tQ.pop();\n\t\tfor (int nxt : G[now]) {\n\t\t\
    \tindeg[nxt]--;\n\t\t\tif (indeg[nxt] == 0) {\n\t\t\t\tQ.push(nxt);\n\t\t\t}\n\
    \t\t}\n\t\tret.push_back(now);\n\t}\n\treturn ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/topological_sort.cpp
  requiredBy: []
  timestamp: '2023-12-06 10:41:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/topological_sort.cpp
layout: document
redirect_from:
- /library/graph/topological_sort.cpp
- /library/graph/topological_sort.cpp.html
title: Topological Sort
---
