---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Max Flow
    links: []
  bundledCode: "#line 1 \"graph/max_flow.cpp\"\n#include <vector>\n#include <queue>\n\
    #include <tuple>\n#include <limits>\n\n/**\n * @brief Max Flow\n */\n\ntemplate\
    \ <typename Cap>\nstruct max_flow {\n\tmax_flow(int n) {\n\t\tthis->n = n;\n\t\
    \tG.resize(n);\n\t}\n\tvoid add_edge(int u, int v, Cap c) {\n\t\tG[u].push_back(std::make_tuple(v,\
    \ G[v].size(), c));\n\t\tG[v].push_back(std::make_tuple(u, (int)G[u].size() -\
    \ 1, 0));\n\t}\n\tCap get_max_flow(int start, int goal) {\n\t\tCap ret = 0;\n\t\
    \twhile (true) {\n\t\t\tvector<int> dst = calculate_distance(start);\n\t\t\tif\
    \ (dst[goal] < 0) {\n\t\t\t\treturn ret;\n\t\t\t}\n\t\t\tvector<int> removed(n,\
    \ 0);\n\t\t\twhile (true) {\n\t\t\t\tCap add = flowing(start, goal, std::numeric_limits<Cap>::max(),\
    \ removed, dst);\n\t\t\t\tif (add == 0) {\n\t\t\t\t\tbreak;\n\t\t\t\t}\n\t\t\t\
    \tret += add;\n\t\t\t}\n\t\t}\n\t\treturn ret;\n\t}\n\n\tprivate:\n\tint n;\n\t\
    std::vector<std::vector<std::tuple<int, int, Cap>>> G;\n\tvector<int> calculate_distance(int\
    \ start) {\n\t\tstd::vector<int> dst(n, -1);\n\t\tdst[start] = 0;\n\t\tstd::queue<int>\
    \ que;\n\t\tque.push(start);\n\t\twhile (!que.empty()) {\n\t\t\tint now = que.front();\n\
    \t\t\tque.pop();\n\t\t\tfor (std::tuple<int, int, Cap> tup : G[now]) {\n\t\t\t\
    \tint nxt;\n\t\t\t\tCap cap;\n\t\t\t\tstd::tie(nxt, ignore, cap) = tup;\n\t\t\t\
    \tif (cap > 0 && dst[nxt] == -1) {\n\t\t\t\t\tdst[nxt] = dst[now] + 1;\n\t\t\t\
    \t\tque.push(nxt);\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn dst;\n\t}\n\tCap flowing(int\
    \ now, int goal, Cap limit, std::vector<int> &removed, std::vector<int> &dst)\
    \ {\n\t\tif (now == goal) {\n\t\t\treturn limit;\n\t\t}\n\t\twhile (removed[now]\
    \ < (int)G[now].size()) {\n\t\t\tint nxt, rev;\n\t\t\tCap cap;\n\t\t\tstd::tie(nxt,\
    \ rev, cap) = G[now][removed[now]];\n\t\t\tif (cap > 0 && dst[now] < dst[nxt])\
    \ {\n\t\t\t\tCap flow = flowing(nxt, goal, std::min(limit, cap), removed, dst);\n\
    \t\t\t\tif (flow > 0) {\n\t\t\t\t\tstd::get<2>(G[now][removed[now]]) -= flow;\n\
    \t\t\t\t\tstd::get<2>(G[nxt][rev]) += flow;\n\t\t\t\t\treturn flow;\n\t\t\t\t\
    }\n\t\t\t}\n\t\t\tremoved[now]++;\n\t\t}\n\t\treturn 0;\n\t}\n};\n"
  code: "#include <vector>\n#include <queue>\n#include <tuple>\n#include <limits>\n\
    \n/**\n * @brief Max Flow\n */\n\ntemplate <typename Cap>\nstruct max_flow {\n\
    \tmax_flow(int n) {\n\t\tthis->n = n;\n\t\tG.resize(n);\n\t}\n\tvoid add_edge(int\
    \ u, int v, Cap c) {\n\t\tG[u].push_back(std::make_tuple(v, G[v].size(), c));\n\
    \t\tG[v].push_back(std::make_tuple(u, (int)G[u].size() - 1, 0));\n\t}\n\tCap get_max_flow(int\
    \ start, int goal) {\n\t\tCap ret = 0;\n\t\twhile (true) {\n\t\t\tvector<int>\
    \ dst = calculate_distance(start);\n\t\t\tif (dst[goal] < 0) {\n\t\t\t\treturn\
    \ ret;\n\t\t\t}\n\t\t\tvector<int> removed(n, 0);\n\t\t\twhile (true) {\n\t\t\t\
    \tCap add = flowing(start, goal, std::numeric_limits<Cap>::max(), removed, dst);\n\
    \t\t\t\tif (add == 0) {\n\t\t\t\t\tbreak;\n\t\t\t\t}\n\t\t\t\tret += add;\n\t\t\
    \t}\n\t\t}\n\t\treturn ret;\n\t}\n\n\tprivate:\n\tint n;\n\tstd::vector<std::vector<std::tuple<int,\
    \ int, Cap>>> G;\n\tvector<int> calculate_distance(int start) {\n\t\tstd::vector<int>\
    \ dst(n, -1);\n\t\tdst[start] = 0;\n\t\tstd::queue<int> que;\n\t\tque.push(start);\n\
    \t\twhile (!que.empty()) {\n\t\t\tint now = que.front();\n\t\t\tque.pop();\n\t\
    \t\tfor (std::tuple<int, int, Cap> tup : G[now]) {\n\t\t\t\tint nxt;\n\t\t\t\t\
    Cap cap;\n\t\t\t\tstd::tie(nxt, ignore, cap) = tup;\n\t\t\t\tif (cap > 0 && dst[nxt]\
    \ == -1) {\n\t\t\t\t\tdst[nxt] = dst[now] + 1;\n\t\t\t\t\tque.push(nxt);\n\t\t\
    \t\t}\n\t\t\t}\n\t\t}\n\t\treturn dst;\n\t}\n\tCap flowing(int now, int goal,\
    \ Cap limit, std::vector<int> &removed, std::vector<int> &dst) {\n\t\tif (now\
    \ == goal) {\n\t\t\treturn limit;\n\t\t}\n\t\twhile (removed[now] < (int)G[now].size())\
    \ {\n\t\t\tint nxt, rev;\n\t\t\tCap cap;\n\t\t\tstd::tie(nxt, rev, cap) = G[now][removed[now]];\n\
    \t\t\tif (cap > 0 && dst[now] < dst[nxt]) {\n\t\t\t\tCap flow = flowing(nxt, goal,\
    \ std::min(limit, cap), removed, dst);\n\t\t\t\tif (flow > 0) {\n\t\t\t\t\tstd::get<2>(G[now][removed[now]])\
    \ -= flow;\n\t\t\t\t\tstd::get<2>(G[nxt][rev]) += flow;\n\t\t\t\t\treturn flow;\n\
    \t\t\t\t}\n\t\t\t}\n\t\t\tremoved[now]++;\n\t\t}\n\t\treturn 0;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/max_flow.cpp
  requiredBy: []
  timestamp: '2023-12-24 07:38:04+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/max_flow.cpp
layout: document
redirect_from:
- /library/graph/max_flow.cpp
- /library/graph/max_flow.cpp.html
title: Max Flow
---
