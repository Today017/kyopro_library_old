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
  bundledCode: "#line 1 \"graph/dijkstra2.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n// Dijkstra\u6CD5 \n// O(Mlog(N)) (M:\u8FBA\u306E\u672C\u6570, N:\u9802\
    \u70B9\u6570)\n// INF min\u306E\u5358\u4F4D\u5143\ntemplate<typename T>\nstruct\
    \ dijkstra_graph {\n\tT INF;\n\tint n;\n\tvector<vector<pair<int, T>>> G;\n\t\
    dijkstra_graph(int n) {\n\t\tthis->n = n;\n\t\tG.resize(n);\n\t};\n\tvoid add_edge(int\
    \ from, int to, T cost) {\n\t\tG[from].push_back(make_pair(to, cost));\n\t}\n\t\
    dijkstra_graph(const vector<vector<pair<int, T>>> &G, T INF = LLONG_MAX) {\n\t\
    \tn = G.size();\n\t\tthis->G = G;\n\t\tthis->INF = INF;\n\t}\n\tvector<T> dijkstra(int\
    \ start) {\n\t\tvector<T> dst(n, this->INF);\n\t\tpriority_queue<pair<T, int>>\
    \ pq;\n\t\tdst[start] = 0;\n\t\tpq.push(make_pair(0, start));\n\t\twhile (!pq.empty())\
    \ {\n\t\t\tT dst_sum = -pq.top().first;\n\t\t\tint now = pq.top().second;\n\t\t\
    \tpq.pop();\n\t\t\tif (dst[now] < dst_sum) {\n\t\t\t\tcontinue;\n\t\t\t}\n\t\t\
    \tfor (pair<int, T> P : G[now]) {\n\t\t\t\tint nxt = P.first;\n\t\t\t\tint cost\
    \ = P.second;\n\t\t\t\tif (dst[nxt] > dst[now] + cost) {\n\t\t\t\t\tdst[nxt] =\
    \ dst[now] + cost;\n\t\t\t\t\tpq.push(make_pair(-dst[nxt], nxt));\n\t\t\t\t}\n\
    \t\t\t}\n\t\t}\n\t\treturn dst;\n\t}\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n// Dijkstra\u6CD5 \n//\
    \ O(Mlog(N)) (M:\u8FBA\u306E\u672C\u6570, N:\u9802\u70B9\u6570)\n// INF min\u306E\
    \u5358\u4F4D\u5143\ntemplate<typename T>\nstruct dijkstra_graph {\n\tT INF;\n\t\
    int n;\n\tvector<vector<pair<int, T>>> G;\n\tdijkstra_graph(int n) {\n\t\tthis->n\
    \ = n;\n\t\tG.resize(n);\n\t};\n\tvoid add_edge(int from, int to, T cost) {\n\t\
    \tG[from].push_back(make_pair(to, cost));\n\t}\n\tdijkstra_graph(const vector<vector<pair<int,\
    \ T>>> &G, T INF = LLONG_MAX) {\n\t\tn = G.size();\n\t\tthis->G = G;\n\t\tthis->INF\
    \ = INF;\n\t}\n\tvector<T> dijkstra(int start) {\n\t\tvector<T> dst(n, this->INF);\n\
    \t\tpriority_queue<pair<T, int>> pq;\n\t\tdst[start] = 0;\n\t\tpq.push(make_pair(0,\
    \ start));\n\t\twhile (!pq.empty()) {\n\t\t\tT dst_sum = -pq.top().first;\n\t\t\
    \tint now = pq.top().second;\n\t\t\tpq.pop();\n\t\t\tif (dst[now] < dst_sum) {\n\
    \t\t\t\tcontinue;\n\t\t\t}\n\t\t\tfor (pair<int, T> P : G[now]) {\n\t\t\t\tint\
    \ nxt = P.first;\n\t\t\t\tint cost = P.second;\n\t\t\t\tif (dst[nxt] > dst[now]\
    \ + cost) {\n\t\t\t\t\tdst[nxt] = dst[now] + cost;\n\t\t\t\t\tpq.push(make_pair(-dst[nxt],\
    \ nxt));\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn dst;\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/dijkstra2.cpp
  requiredBy: []
  timestamp: '2023-11-30 18:16:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/dijkstra2.cpp
layout: document
redirect_from:
- /library/graph/dijkstra2.cpp
- /library/graph/dijkstra2.cpp.html
title: graph/dijkstra2.cpp
---
