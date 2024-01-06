---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Min Cost Flow
    links: []
  bundledCode: "#line 1 \"graph/min_cost_flow.cpp\"\n#include <limits>\n#include <tuple>\n\
    #include <utility>\n#include <vector>\n\n/**\n * @brief Min Cost Flow\n */\n\n\
    template <typename Cap, typename Cost>\nstruct min_cost_flow {\n\tmin_cost_flow(int\
    \ n) {\n\t\tthis->n = n;\n\t\tthis->G.resize(n);\n\t}\n\tvoid add_edge(int u,\
    \ int v, Cap cap, Cost cost) {\n\t\tG[u].push_back(std::make_tuple(v, cap, cost,\
    \ (int)G[v].size()));\n\t\tG[v].push_back(std::make_tuple(u, 0, -cost, (int)G[u].size()\
    \ - 1));\n\t}\n\tCost get_min_cost_flow(int start, int goal, Cap flow) {\n\t\t\
    Cost ret = 0;\n\t\twhile (flow > 0) {\n\t\t\tstd::vector<Cost> dst;\n\t\t\tstd::vector<int>\
    \ pre_vertex, pre_edge;\n\t\t\tstd::tie(dst, pre_vertex, pre_edge) = calculate_cost(start);\n\
    \t\t\tif (dst[goal] == std::numeric_limits<Cost>::max()) {\n\t\t\t\treturn std::numeric_limits<Cost>::max();\n\
    \t\t\t}\n\t\t\tCap now_flow = flow;\n\t\t\tint now_vertex = goal;\n\t\t\twhile\
    \ (now_vertex != start) {\n\t\t\t\tnow_flow = min(now_flow, std::get<1>(G[pre_vertex[now_vertex]][pre_edge[now_vertex]]));\n\
    \t\t\t\tnow_vertex = pre_vertex[now_vertex];\n\t\t\t}\n\t\t\tret += now_flow *\
    \ dst[goal];\n\t\t\tflow -= now_flow;\n\t\t\tnow_vertex = goal;\n\t\t\twhile (now_vertex\
    \ != start) {\n\t\t\t\tstd::get<1>(G[pre_vertex[now_vertex]][pre_edge[now_vertex]])\
    \ -= now_flow;\n\t\t\t\tint rev = std::get<3>(G[pre_vertex[now_vertex]][pre_edge[now_vertex]]);\n\
    \t\t\t\tstd::get<1>(G[now_vertex][rev]) += now_flow;\n\t\t\t\tnow_vertex = pre_vertex[now_vertex];\n\
    \t\t\t}\n\t\t}\n\t\treturn ret;\n\t}\n\n\tprivate:\n\tint n;\n\tstd::vector<std::vector<std::tuple<int,\
    \ Cap, Cost, int>>> G;\n\tstd::tuple<std::vector<Cost>, std::vector<int>, std::vector<int>>\
    \ calculate_cost(int start) {\n\t\tstd::vector<Cost> dst(n, std::numeric_limits<Cost>::max());\n\
    \t\tstd::vector<int> pre_vertex(n, 0), pre_edge(n, 0);\n\t\tdst[start] = 0;\n\t\
    \twhile (true) {\n\t\t\tbool update = false;\n\t\t\tfor (int i = 0; i < n; i++)\
    \ {\n\t\t\t\tif (dst[i] == std::numeric_limits<Cost>::max()) {\n\t\t\t\t\tcontinue;\n\
    \t\t\t\t}\n\t\t\t\tfor (int j = 0; j < (int)G[i].size(); j++) {\n\t\t\t\t\tint\
    \ nxt;\n\t\t\t\t\tCap cap;\n\t\t\t\t\tCost cost;\n\t\t\t\t\tstd::tie(nxt, cap,\
    \ cost, std::ignore) = G[i][j];\n\t\t\t\t\tif (cap > 0 && dst[nxt] > dst[i] +\
    \ cost) {\n\t\t\t\t\t\tdst[nxt] = dst[i] + cost;\n\t\t\t\t\t\tupdate = true;\n\
    \t\t\t\t\t\tpre_vertex[nxt] = i;\n\t\t\t\t\t\tpre_edge[nxt] = j;\n\t\t\t\t\t}\n\
    \t\t\t\t}\n\t\t\t}\n\t\t\tif (!update) {\n\t\t\t\tbreak;\n\t\t\t}\n\t\t}\n\t\t\
    return std::make_tuple(dst, pre_vertex, pre_edge);\n\t}\n};\n"
  code: "#include <limits>\n#include <tuple>\n#include <utility>\n#include <vector>\n\
    \n/**\n * @brief Min Cost Flow\n */\n\ntemplate <typename Cap, typename Cost>\n\
    struct min_cost_flow {\n\tmin_cost_flow(int n) {\n\t\tthis->n = n;\n\t\tthis->G.resize(n);\n\
    \t}\n\tvoid add_edge(int u, int v, Cap cap, Cost cost) {\n\t\tG[u].push_back(std::make_tuple(v,\
    \ cap, cost, (int)G[v].size()));\n\t\tG[v].push_back(std::make_tuple(u, 0, -cost,\
    \ (int)G[u].size() - 1));\n\t}\n\tCost get_min_cost_flow(int start, int goal,\
    \ Cap flow) {\n\t\tCost ret = 0;\n\t\twhile (flow > 0) {\n\t\t\tstd::vector<Cost>\
    \ dst;\n\t\t\tstd::vector<int> pre_vertex, pre_edge;\n\t\t\tstd::tie(dst, pre_vertex,\
    \ pre_edge) = calculate_cost(start);\n\t\t\tif (dst[goal] == std::numeric_limits<Cost>::max())\
    \ {\n\t\t\t\treturn std::numeric_limits<Cost>::max();\n\t\t\t}\n\t\t\tCap now_flow\
    \ = flow;\n\t\t\tint now_vertex = goal;\n\t\t\twhile (now_vertex != start) {\n\
    \t\t\t\tnow_flow = min(now_flow, std::get<1>(G[pre_vertex[now_vertex]][pre_edge[now_vertex]]));\n\
    \t\t\t\tnow_vertex = pre_vertex[now_vertex];\n\t\t\t}\n\t\t\tret += now_flow *\
    \ dst[goal];\n\t\t\tflow -= now_flow;\n\t\t\tnow_vertex = goal;\n\t\t\twhile (now_vertex\
    \ != start) {\n\t\t\t\tstd::get<1>(G[pre_vertex[now_vertex]][pre_edge[now_vertex]])\
    \ -= now_flow;\n\t\t\t\tint rev = std::get<3>(G[pre_vertex[now_vertex]][pre_edge[now_vertex]]);\n\
    \t\t\t\tstd::get<1>(G[now_vertex][rev]) += now_flow;\n\t\t\t\tnow_vertex = pre_vertex[now_vertex];\n\
    \t\t\t}\n\t\t}\n\t\treturn ret;\n\t}\n\n\tprivate:\n\tint n;\n\tstd::vector<std::vector<std::tuple<int,\
    \ Cap, Cost, int>>> G;\n\tstd::tuple<std::vector<Cost>, std::vector<int>, std::vector<int>>\
    \ calculate_cost(int start) {\n\t\tstd::vector<Cost> dst(n, std::numeric_limits<Cost>::max());\n\
    \t\tstd::vector<int> pre_vertex(n, 0), pre_edge(n, 0);\n\t\tdst[start] = 0;\n\t\
    \twhile (true) {\n\t\t\tbool update = false;\n\t\t\tfor (int i = 0; i < n; i++)\
    \ {\n\t\t\t\tif (dst[i] == std::numeric_limits<Cost>::max()) {\n\t\t\t\t\tcontinue;\n\
    \t\t\t\t}\n\t\t\t\tfor (int j = 0; j < (int)G[i].size(); j++) {\n\t\t\t\t\tint\
    \ nxt;\n\t\t\t\t\tCap cap;\n\t\t\t\t\tCost cost;\n\t\t\t\t\tstd::tie(nxt, cap,\
    \ cost, std::ignore) = G[i][j];\n\t\t\t\t\tif (cap > 0 && dst[nxt] > dst[i] +\
    \ cost) {\n\t\t\t\t\t\tdst[nxt] = dst[i] + cost;\n\t\t\t\t\t\tupdate = true;\n\
    \t\t\t\t\t\tpre_vertex[nxt] = i;\n\t\t\t\t\t\tpre_edge[nxt] = j;\n\t\t\t\t\t}\n\
    \t\t\t\t}\n\t\t\t}\n\t\t\tif (!update) {\n\t\t\t\tbreak;\n\t\t\t}\n\t\t}\n\t\t\
    return std::make_tuple(dst, pre_vertex, pre_edge);\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/min_cost_flow.cpp
  requiredBy: []
  timestamp: '2024-01-07 08:32:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/min_cost_flow.cpp
layout: document
redirect_from:
- /library/graph/min_cost_flow.cpp
- /library/graph/min_cost_flow.cpp.html
title: Min Cost Flow
---
