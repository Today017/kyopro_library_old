---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Dijkstra
    links: []
  bundledCode: "#line 1 \"graph/dijkstra.cpp\"\n#include <vector>\n#include <queue>\n\
    #include <utility>\n#include <limits>\n\n/**\n * @brief Dijkstra\n * @attention\
    \ O(Elog(E))\n */\n\ntemplate <typename T>\nstd::vector<T> dijkstra(const std::vector<std::vector<std::pair<int,\
    \ T>>> &G, int start = 0, T INF = std::numeric_limits<T>::max()) {\n    int n\
    \ = G.size();\n    std::vector<T> dst(n, INF);\n    std::priority_queue<std::pair<T,\
    \ int>> pq;\n    dst[start] = 0;\n    pq.push(std::make_pair(0, start));\n   \
    \ while (!pq.empty()) {\n        T dst_sum = pq.top().first;\n        int now\
    \ = pq.top().second;\n        pq.pop();\n        dst_sum = -dst_sum;\n       \
    \ if (dst[now] < dst_sum) {\n            continue;\n        }\n        for (std::pair<int,\
    \ T> P : G[now]) {\n            int nxt = P.first;\n            T cost = P.second;\n\
    \            if (dst[nxt] > dst[now] + cost) {\n                dst[nxt] = dst[now]\
    \ + cost;\n                pq.push(make_pair(-dst[nxt], nxt));\n            }\n\
    \        }\n    }\n    return dst;\n}\n"
  code: "#include <vector>\n#include <queue>\n#include <utility>\n#include <limits>\n\
    \n/**\n * @brief Dijkstra\n * @attention O(Elog(E))\n */\n\ntemplate <typename\
    \ T>\nstd::vector<T> dijkstra(const std::vector<std::vector<std::pair<int, T>>>\
    \ &G, int start = 0, T INF = std::numeric_limits<T>::max()) {\n    int n = G.size();\n\
    \    std::vector<T> dst(n, INF);\n    std::priority_queue<std::pair<T, int>> pq;\n\
    \    dst[start] = 0;\n    pq.push(std::make_pair(0, start));\n    while (!pq.empty())\
    \ {\n        T dst_sum = pq.top().first;\n        int now = pq.top().second;\n\
    \        pq.pop();\n        dst_sum = -dst_sum;\n        if (dst[now] < dst_sum)\
    \ {\n            continue;\n        }\n        for (std::pair<int, T> P : G[now])\
    \ {\n            int nxt = P.first;\n            T cost = P.second;\n        \
    \    if (dst[nxt] > dst[now] + cost) {\n                dst[nxt] = dst[now] +\
    \ cost;\n                pq.push(make_pair(-dst[nxt], nxt));\n            }\n\
    \        }\n    }\n    return dst;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/dijkstra.cpp
  requiredBy: []
  timestamp: '2024-01-25 11:55:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/dijkstra.cpp
layout: document
redirect_from:
- /library/graph/dijkstra.cpp
- /library/graph/dijkstra.cpp.html
title: Dijkstra
---
