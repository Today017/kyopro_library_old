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
  bundledCode: "#line 1 \"graph/dijkstra.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n// Dijkstra\u6CD5 \n// O(Elog(E))\n// INF min\u306E\u5358\u4F4D\u5143\
    \ntemplate<typename T>\nvector<T> dijkstra(const vector<vector<pair<int, T>>>\
    \ &G, int start = 0, T INF = LLONG_MAX) {\n\tint n = G.size();\n\tvector<T> dst(n,\
    \ INF);\n\tpriority_queue<pair<T, int>> pq;\n\tdst[start] = 0;\n\tpq.push(make_pair(0,\
    \ start));\n\twhile (!pq.empty()) {\n\t\tT dst_sum = pq.top().first;\n\t\tint\
    \ now = pq.top().second;\n\t\tpq.pop();\n\t\tdst_sum = -dst_sum;\n\t\tif (dst[now]\
    \ < dst_sum) {\n\t\t\tcontinue;\n\t\t}\n\t\tfor (pair<int, T> P : G[now]) {\n\t\
    \t\tint nxt = P.first;\n\t\t\tT cost = P.second;\n\t\t\tif (dst[nxt] > dst[now]\
    \ + cost) {\n\t\t\t\tdst[nxt] = dst[now] + cost;\n\t\t\t\tpq.push(make_pair(-dst[nxt],\
    \ nxt));\n\t\t\t}\n\t\t}\n\t}\n\treturn dst;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n// Dijkstra\u6CD5 \n//\
    \ O(Elog(E))\n// INF min\u306E\u5358\u4F4D\u5143\ntemplate<typename T>\nvector<T>\
    \ dijkstra(const vector<vector<pair<int, T>>> &G, int start = 0, T INF = LLONG_MAX)\
    \ {\n\tint n = G.size();\n\tvector<T> dst(n, INF);\n\tpriority_queue<pair<T, int>>\
    \ pq;\n\tdst[start] = 0;\n\tpq.push(make_pair(0, start));\n\twhile (!pq.empty())\
    \ {\n\t\tT dst_sum = pq.top().first;\n\t\tint now = pq.top().second;\n\t\tpq.pop();\n\
    \t\tdst_sum = -dst_sum;\n\t\tif (dst[now] < dst_sum) {\n\t\t\tcontinue;\n\t\t\
    }\n\t\tfor (pair<int, T> P : G[now]) {\n\t\t\tint nxt = P.first;\n\t\t\tT cost\
    \ = P.second;\n\t\t\tif (dst[nxt] > dst[now] + cost) {\n\t\t\t\tdst[nxt] = dst[now]\
    \ + cost;\n\t\t\t\tpq.push(make_pair(-dst[nxt], nxt));\n\t\t\t}\n\t\t}\n\t}\n\t\
    return dst;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/dijkstra.cpp
  requiredBy: []
  timestamp: '2023-11-30 18:16:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/dijkstra.cpp
layout: document
redirect_from:
- /library/graph/dijkstra.cpp
- /library/graph/dijkstra.cpp.html
title: graph/dijkstra.cpp
---
