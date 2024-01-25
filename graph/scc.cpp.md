---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Strongly Connected Components Decomposition
    links: []
  bundledCode: "#line 1 \"graph/scc.cpp\"\n#include <tuple>\n#include <vector>\n#include\
    \ <algorithm>\n\n/**\n * @brief Strongly Connected Components Decomposition\n\
    \ */\n\nstd::tuple<std::vector<std::vector<int>>, std::vector<std::vector<int>>,\
    \ std::vector<int>> strongly_connected_components_decomposition(const std::vector<std::vector<int>>\
    \ &G) {\n    int n = G.size();\n    std::vector<std::vector<int>> G2(n);\n   \
    \ for (int i = 0; i < n; i++) {\n        for (int nxt : G[i]) {\n            G2[nxt].push_back(i);\n\
    \        }\n    }\n    std::vector<int> order(n), component(n, -1);\n    std::vector<bool>\
    \ vst(n);\n    auto F = [&](auto F, int now) -> void {\n        vst[now] = true;\n\
    \        for (int nxt : G[now]) {\n            if (!vst[nxt]) {\n            \
    \    F(F, nxt);\n            }\n        }\n        order.push_back(now);\n   \
    \ };\n    auto F2 = [&](auto F2, int now, int idx) -> void {\n        component[now]\
    \ = idx;\n        for (int nxt : G2[now]) {\n            if (component[nxt] ==\
    \ -1) {\n                F2(F2, nxt, idx);\n            }\n        }\n    };\n\
    \    for (int i = 0; i < n; i++) {\n        if (!vst[i]) {\n            F(F, i);\n\
    \        }\n    }\n    int idx = 0;\n    std::reverse(order.begin(), order.end());\n\
    \    for (int now : order) {\n        if (component[now] == -1) {\n          \
    \  F2(F2, now, idx);\n            idx++;\n        }\n    }\n    int n_n = *std::max_element(component.begin(),\
    \ component.end()) + 1;\n    std::vector<std::vector<int>> ret(n_n);\n    for\
    \ (int i = 0; i < n; i++) {\n        ret[component[i]].push_back(i);\n    }\n\
    \    std::vector<std::vector<int>> ret2(n_n);\n    for (int i = 0; i < n; i++)\
    \ {\n        for (int j : G[i]) {\n            if (component[i] != component[j])\
    \ {\n                ret2[component[i]].push_back(component[j]);\n           \
    \ }\n        }\n    }\n    for (int i = 0; i < n_n; i++) {\n        sort(ret2[i].begin(),\
    \ ret2[i].end());\n        ret2[i].erase(std::unique(ret2[i].begin(), ret2[i].end()),\
    \ ret2[i].end());\n    }\n    return std::make_tuple(ret, ret2, component);\n\
    }\n"
  code: "#include <tuple>\n#include <vector>\n#include <algorithm>\n\n/**\n * @brief\
    \ Strongly Connected Components Decomposition\n */\n\nstd::tuple<std::vector<std::vector<int>>,\
    \ std::vector<std::vector<int>>, std::vector<int>> strongly_connected_components_decomposition(const\
    \ std::vector<std::vector<int>> &G) {\n    int n = G.size();\n    std::vector<std::vector<int>>\
    \ G2(n);\n    for (int i = 0; i < n; i++) {\n        for (int nxt : G[i]) {\n\
    \            G2[nxt].push_back(i);\n        }\n    }\n    std::vector<int> order(n),\
    \ component(n, -1);\n    std::vector<bool> vst(n);\n    auto F = [&](auto F, int\
    \ now) -> void {\n        vst[now] = true;\n        for (int nxt : G[now]) {\n\
    \            if (!vst[nxt]) {\n                F(F, nxt);\n            }\n   \
    \     }\n        order.push_back(now);\n    };\n    auto F2 = [&](auto F2, int\
    \ now, int idx) -> void {\n        component[now] = idx;\n        for (int nxt\
    \ : G2[now]) {\n            if (component[nxt] == -1) {\n                F2(F2,\
    \ nxt, idx);\n            }\n        }\n    };\n    for (int i = 0; i < n; i++)\
    \ {\n        if (!vst[i]) {\n            F(F, i);\n        }\n    }\n    int idx\
    \ = 0;\n    std::reverse(order.begin(), order.end());\n    for (int now : order)\
    \ {\n        if (component[now] == -1) {\n            F2(F2, now, idx);\n    \
    \        idx++;\n        }\n    }\n    int n_n = *std::max_element(component.begin(),\
    \ component.end()) + 1;\n    std::vector<std::vector<int>> ret(n_n);\n    for\
    \ (int i = 0; i < n; i++) {\n        ret[component[i]].push_back(i);\n    }\n\
    \    std::vector<std::vector<int>> ret2(n_n);\n    for (int i = 0; i < n; i++)\
    \ {\n        for (int j : G[i]) {\n            if (component[i] != component[j])\
    \ {\n                ret2[component[i]].push_back(component[j]);\n           \
    \ }\n        }\n    }\n    for (int i = 0; i < n_n; i++) {\n        sort(ret2[i].begin(),\
    \ ret2[i].end());\n        ret2[i].erase(std::unique(ret2[i].begin(), ret2[i].end()),\
    \ ret2[i].end());\n    }\n    return std::make_tuple(ret, ret2, component);\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/scc.cpp
  requiredBy: []
  timestamp: '2024-01-25 11:55:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/scc.cpp
layout: document
redirect_from:
- /library/graph/scc.cpp
- /library/graph/scc.cpp.html
title: Strongly Connected Components Decomposition
---
