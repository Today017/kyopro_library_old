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
    template <typename Cap, typename Cost>\nstruct min_cost_flow {\n    min_cost_flow(int\
    \ n) {\n        this->n = n;\n        this->G.resize(n);\n    }\n    void add_edge(int\
    \ u, int v, Cap cap, Cost cost) {\n        G[u].push_back(std::make_tuple(v, cap,\
    \ cost, (int)G[v].size()));\n        G[v].push_back(std::make_tuple(u, 0, -cost,\
    \ (int)G[u].size() - 1));\n    }\n    Cost get_min_cost_flow(int start, int goal,\
    \ Cap flow) {\n        Cost ret = 0;\n        while (flow > 0) {\n           \
    \ std::vector<Cost> dst;\n            std::vector<int> pre_vertex, pre_edge;\n\
    \            std::tie(dst, pre_vertex, pre_edge) = calculate_cost(start);\n  \
    \          if (dst[goal] == std::numeric_limits<Cost>::max()) {\n            \
    \    return std::numeric_limits<Cost>::max();\n            }\n            Cap\
    \ now_flow = flow;\n            int now_vertex = goal;\n            while (now_vertex\
    \ != start) {\n                now_flow = min(now_flow, std::get<1>(G[pre_vertex[now_vertex]][pre_edge[now_vertex]]));\n\
    \                now_vertex = pre_vertex[now_vertex];\n            }\n       \
    \     ret += now_flow * dst[goal];\n            flow -= now_flow;\n          \
    \  now_vertex = goal;\n            while (now_vertex != start) {\n           \
    \     std::get<1>(G[pre_vertex[now_vertex]][pre_edge[now_vertex]]) -= now_flow;\n\
    \                int rev = std::get<3>(G[pre_vertex[now_vertex]][pre_edge[now_vertex]]);\n\
    \                std::get<1>(G[now_vertex][rev]) += now_flow;\n              \
    \  now_vertex = pre_vertex[now_vertex];\n            }\n        }\n        return\
    \ ret;\n    }\n\nprivate:\n    int n;\n    std::vector<std::vector<std::tuple<int,\
    \ Cap, Cost, int>>> G;\n    std::tuple<std::vector<Cost>, std::vector<int>, std::vector<int>>\
    \ calculate_cost(int start) {\n        std::vector<Cost> dst(n, std::numeric_limits<Cost>::max());\n\
    \        std::vector<int> pre_vertex(n, 0), pre_edge(n, 0);\n        dst[start]\
    \ = 0;\n        while (true) {\n            bool update = false;\n           \
    \ for (int i = 0; i < n; i++) {\n                if (dst[i] == std::numeric_limits<Cost>::max())\
    \ {\n                    continue;\n                }\n                for (int\
    \ j = 0; j < (int)G[i].size(); j++) {\n                    int nxt;\n        \
    \            Cap cap;\n                    Cost cost;\n                    std::tie(nxt,\
    \ cap, cost, std::ignore) = G[i][j];\n                    if (cap > 0 && dst[nxt]\
    \ > dst[i] + cost) {\n                        dst[nxt] = dst[i] + cost;\n    \
    \                    update = true;\n                        pre_vertex[nxt] =\
    \ i;\n                        pre_edge[nxt] = j;\n                    }\n    \
    \            }\n            }\n            if (!update) {\n                break;\n\
    \            }\n        }\n        return std::make_tuple(dst, pre_vertex, pre_edge);\n\
    \    }\n};\n"
  code: "#include <limits>\n#include <tuple>\n#include <utility>\n#include <vector>\n\
    \n/**\n * @brief Min Cost Flow\n */\n\ntemplate <typename Cap, typename Cost>\n\
    struct min_cost_flow {\n    min_cost_flow(int n) {\n        this->n = n;\n   \
    \     this->G.resize(n);\n    }\n    void add_edge(int u, int v, Cap cap, Cost\
    \ cost) {\n        G[u].push_back(std::make_tuple(v, cap, cost, (int)G[v].size()));\n\
    \        G[v].push_back(std::make_tuple(u, 0, -cost, (int)G[u].size() - 1));\n\
    \    }\n    Cost get_min_cost_flow(int start, int goal, Cap flow) {\n        Cost\
    \ ret = 0;\n        while (flow > 0) {\n            std::vector<Cost> dst;\n \
    \           std::vector<int> pre_vertex, pre_edge;\n            std::tie(dst,\
    \ pre_vertex, pre_edge) = calculate_cost(start);\n            if (dst[goal] ==\
    \ std::numeric_limits<Cost>::max()) {\n                return std::numeric_limits<Cost>::max();\n\
    \            }\n            Cap now_flow = flow;\n            int now_vertex =\
    \ goal;\n            while (now_vertex != start) {\n                now_flow =\
    \ min(now_flow, std::get<1>(G[pre_vertex[now_vertex]][pre_edge[now_vertex]]));\n\
    \                now_vertex = pre_vertex[now_vertex];\n            }\n       \
    \     ret += now_flow * dst[goal];\n            flow -= now_flow;\n          \
    \  now_vertex = goal;\n            while (now_vertex != start) {\n           \
    \     std::get<1>(G[pre_vertex[now_vertex]][pre_edge[now_vertex]]) -= now_flow;\n\
    \                int rev = std::get<3>(G[pre_vertex[now_vertex]][pre_edge[now_vertex]]);\n\
    \                std::get<1>(G[now_vertex][rev]) += now_flow;\n              \
    \  now_vertex = pre_vertex[now_vertex];\n            }\n        }\n        return\
    \ ret;\n    }\n\nprivate:\n    int n;\n    std::vector<std::vector<std::tuple<int,\
    \ Cap, Cost, int>>> G;\n    std::tuple<std::vector<Cost>, std::vector<int>, std::vector<int>>\
    \ calculate_cost(int start) {\n        std::vector<Cost> dst(n, std::numeric_limits<Cost>::max());\n\
    \        std::vector<int> pre_vertex(n, 0), pre_edge(n, 0);\n        dst[start]\
    \ = 0;\n        while (true) {\n            bool update = false;\n           \
    \ for (int i = 0; i < n; i++) {\n                if (dst[i] == std::numeric_limits<Cost>::max())\
    \ {\n                    continue;\n                }\n                for (int\
    \ j = 0; j < (int)G[i].size(); j++) {\n                    int nxt;\n        \
    \            Cap cap;\n                    Cost cost;\n                    std::tie(nxt,\
    \ cap, cost, std::ignore) = G[i][j];\n                    if (cap > 0 && dst[nxt]\
    \ > dst[i] + cost) {\n                        dst[nxt] = dst[i] + cost;\n    \
    \                    update = true;\n                        pre_vertex[nxt] =\
    \ i;\n                        pre_edge[nxt] = j;\n                    }\n    \
    \            }\n            }\n            if (!update) {\n                break;\n\
    \            }\n        }\n        return std::make_tuple(dst, pre_vertex, pre_edge);\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/min_cost_flow.cpp
  requiredBy: []
  timestamp: '2024-01-25 11:55:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/min_cost_flow.cpp
layout: document
redirect_from:
- /library/graph/min_cost_flow.cpp
- /library/graph/min_cost_flow.cpp.html
title: Min Cost Flow
---
