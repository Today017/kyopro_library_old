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
  bundledCode: "#line 1 \"graph/topological_sort.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nvector<int> topological_sort(const vector<vector<int>>\
    \ &G) {\n\tint n = G.size();\n\tvector<int> indeg(n);\n\tfor (int i = 0; i < n;\
    \ i++) {\n\t\tfor (int nxt : G[i]) {\n\t\t\tindeg[nxt]++;\n\t\t}\n\t}\n\tqueue<int>\
    \ Q;\n\tfor (int i = 0; i < n; i++) {\n\t\tif (indeg[i] == 0) {\n\t\t\tQ.push(i);\n\
    \t\t}\n\t}\n\tvector<int> ret;\n\twhile (!Q.empty()) {\n\t\tint now = Q.front();\n\
    \t\tQ.pop();\n\t\tfor (int nxt : G[now]) {\n\t\t\tindeg[nxt]--;\n\t\t\tif (indeg[nxt]\
    \ == 0) {\n\t\t\t\tQ.push(nxt);\n\t\t\t}\n\t\t}\n\t\tret.push_back(now);\n\t}\n\
    \treturn ret;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\nvector<int> topological_sort(const\
    \ vector<vector<int>> &G) {\n\tint n = G.size();\n\tvector<int> indeg(n);\n\t\
    for (int i = 0; i < n; i++) {\n\t\tfor (int nxt : G[i]) {\n\t\t\tindeg[nxt]++;\n\
    \t\t}\n\t}\n\tqueue<int> Q;\n\tfor (int i = 0; i < n; i++) {\n\t\tif (indeg[i]\
    \ == 0) {\n\t\t\tQ.push(i);\n\t\t}\n\t}\n\tvector<int> ret;\n\twhile (!Q.empty())\
    \ {\n\t\tint now = Q.front();\n\t\tQ.pop();\n\t\tfor (int nxt : G[now]) {\n\t\t\
    \tindeg[nxt]--;\n\t\t\tif (indeg[nxt] == 0) {\n\t\t\t\tQ.push(nxt);\n\t\t\t}\n\
    \t\t}\n\t\tret.push_back(now);\n\t}\n\treturn ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/topological_sort.cpp
  requiredBy: []
  timestamp: '2023-11-30 18:16:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/topological_sort.cpp
layout: document
redirect_from:
- /library/graph/topological_sort.cpp
- /library/graph/topological_sort.cpp.html
title: graph/topological_sort.cpp
---
