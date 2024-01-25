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
    \ <typename Cap>\nstruct max_flow {\n    max_flow(int n) {\n        this->n =\
    \ n;\n        G.resize(n);\n    }\n    void add_edge(int u, int v, Cap c) {\n\
    \        G[u].push_back(std::make_tuple(v, G[v].size(), c));\n        G[v].push_back(std::make_tuple(u,\
    \ (int)G[u].size() - 1, 0));\n    }\n    Cap get_max_flow(int start, int goal)\
    \ {\n        Cap ret = 0;\n        while (true) {\n            vector<int> dst\
    \ = calculate_distance(start);\n            if (dst[goal] < 0) {\n           \
    \     return ret;\n            }\n            vector<int> removed(n, 0);\n   \
    \         while (true) {\n                Cap add = flowing(start, goal, std::numeric_limits<Cap>::max(),\
    \ removed, dst);\n                if (add == 0) {\n                    break;\n\
    \                }\n                ret += add;\n            }\n        }\n  \
    \      return ret;\n    }\n\nprivate:\n    int n;\n    std::vector<std::vector<std::tuple<int,\
    \ int, Cap>>> G;\n    vector<int> calculate_distance(int start) {\n        std::vector<int>\
    \ dst(n, -1);\n        dst[start] = 0;\n        std::queue<int> que;\n       \
    \ que.push(start);\n        while (!que.empty()) {\n            int now = que.front();\n\
    \            que.pop();\n            for (std::tuple<int, int, Cap> tup : G[now])\
    \ {\n                int nxt;\n                Cap cap;\n                std::tie(nxt,\
    \ ignore, cap) = tup;\n                if (cap > 0 && dst[nxt] == -1) {\n    \
    \                dst[nxt] = dst[now] + 1;\n                    que.push(nxt);\n\
    \                }\n            }\n        }\n        return dst;\n    }\n   \
    \ Cap flowing(int now, int goal, Cap limit, std::vector<int> &removed, std::vector<int>\
    \ &dst) {\n        if (now == goal) {\n            return limit;\n        }\n\
    \        while (removed[now] < (int)G[now].size()) {\n            int nxt, rev;\n\
    \            Cap cap;\n            std::tie(nxt, rev, cap) = G[now][removed[now]];\n\
    \            if (cap > 0 && dst[now] < dst[nxt]) {\n                Cap flow =\
    \ flowing(nxt, goal, std::min(limit, cap), removed, dst);\n                if\
    \ (flow > 0) {\n                    std::get<2>(G[now][removed[now]]) -= flow;\n\
    \                    std::get<2>(G[nxt][rev]) += flow;\n                    return\
    \ flow;\n                }\n            }\n            removed[now]++;\n     \
    \   }\n        return 0;\n    }\n};\n"
  code: "#include <vector>\n#include <queue>\n#include <tuple>\n#include <limits>\n\
    \n/**\n * @brief Max Flow\n */\n\ntemplate <typename Cap>\nstruct max_flow {\n\
    \    max_flow(int n) {\n        this->n = n;\n        G.resize(n);\n    }\n  \
    \  void add_edge(int u, int v, Cap c) {\n        G[u].push_back(std::make_tuple(v,\
    \ G[v].size(), c));\n        G[v].push_back(std::make_tuple(u, (int)G[u].size()\
    \ - 1, 0));\n    }\n    Cap get_max_flow(int start, int goal) {\n        Cap ret\
    \ = 0;\n        while (true) {\n            vector<int> dst = calculate_distance(start);\n\
    \            if (dst[goal] < 0) {\n                return ret;\n            }\n\
    \            vector<int> removed(n, 0);\n            while (true) {\n        \
    \        Cap add = flowing(start, goal, std::numeric_limits<Cap>::max(), removed,\
    \ dst);\n                if (add == 0) {\n                    break;\n       \
    \         }\n                ret += add;\n            }\n        }\n        return\
    \ ret;\n    }\n\nprivate:\n    int n;\n    std::vector<std::vector<std::tuple<int,\
    \ int, Cap>>> G;\n    vector<int> calculate_distance(int start) {\n        std::vector<int>\
    \ dst(n, -1);\n        dst[start] = 0;\n        std::queue<int> que;\n       \
    \ que.push(start);\n        while (!que.empty()) {\n            int now = que.front();\n\
    \            que.pop();\n            for (std::tuple<int, int, Cap> tup : G[now])\
    \ {\n                int nxt;\n                Cap cap;\n                std::tie(nxt,\
    \ ignore, cap) = tup;\n                if (cap > 0 && dst[nxt] == -1) {\n    \
    \                dst[nxt] = dst[now] + 1;\n                    que.push(nxt);\n\
    \                }\n            }\n        }\n        return dst;\n    }\n   \
    \ Cap flowing(int now, int goal, Cap limit, std::vector<int> &removed, std::vector<int>\
    \ &dst) {\n        if (now == goal) {\n            return limit;\n        }\n\
    \        while (removed[now] < (int)G[now].size()) {\n            int nxt, rev;\n\
    \            Cap cap;\n            std::tie(nxt, rev, cap) = G[now][removed[now]];\n\
    \            if (cap > 0 && dst[now] < dst[nxt]) {\n                Cap flow =\
    \ flowing(nxt, goal, std::min(limit, cap), removed, dst);\n                if\
    \ (flow > 0) {\n                    std::get<2>(G[now][removed[now]]) -= flow;\n\
    \                    std::get<2>(G[nxt][rev]) += flow;\n                    return\
    \ flow;\n                }\n            }\n            removed[now]++;\n     \
    \   }\n        return 0;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/max_flow.cpp
  requiredBy: []
  timestamp: '2024-01-25 11:55:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/max_flow.cpp
layout: document
redirect_from:
- /library/graph/max_flow.cpp
- /library/graph/max_flow.cpp.html
title: Max Flow
---
