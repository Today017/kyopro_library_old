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
    \ &G) {\n\tint n = G.size();\n\tstd::vector<std::vector<int>> G2(n);\n\tfor (int\
    \ i = 0; i < n; i++) {\n\t\tfor (int nxt : G[i]) {\n\t\t\tG2[nxt].push_back(i);\n\
    \t\t}\n\t}\n\tstd::vector<int> order(n), component(n, -1);\n\tstd::vector<bool>\
    \ vst(n);\n\tauto F = [&](auto F, int now) -> void {\n\t\tvst[now] = true;\n\t\
    \tfor (int nxt : G[now]) {\n\t\t\tif (!vst[nxt]) {\n\t\t\t\tF(F, nxt);\n\t\t\t\
    }\n\t\t}\n\t\torder.push_back(now);\n\t};\n\tauto F2 = [&](auto F2, int now, int\
    \ idx) -> void {\n\t\tcomponent[now] = idx;\n\t\tfor (int nxt : G2[now]) {\n\t\
    \t\tif (component[nxt] == -1) {\n\t\t\t\tF2(F2, nxt, idx);\n\t\t\t}\n\t\t}\n\t\
    };\n\tfor (int i = 0; i < n; i++) {\n\t\tif (!vst[i]) {\n\t\t\tF(F, i);\n\t\t\
    }\n\t}\n\tint idx = 0;\n\tstd::reverse(order.begin(), order.end());\n\tfor (int\
    \ now : order) {\n\t\tif (component[now] == -1) {\n\t\t\tF2(F2, now, idx);\n\t\
    \t\tidx++;\n\t\t}\n\t}\n\tint n_n = *std::max_element(component.begin(), component.end())\
    \ + 1;\n\tstd::vector<std::vector<int>> ret(n_n);\n\tfor (int i = 0; i < n; i++)\
    \ {\n\t\tret[component[i]].push_back(i);\n\t}\n\tstd::vector<std::vector<int>>\
    \ ret2(n_n);\n\tfor (int i = 0; i < n; i++) {\n\t\tfor (int j : G[i]) {\n\t\t\t\
    if (component[i] != component[j]) {\n\t\t\t\tret2[component[i]].push_back(component[j]);\n\
    \t\t\t}\n\t\t}\n\t}\n\tfor (int i = 0; i < n_n; i++) {\n\t\tsort(ret2[i].begin(),\
    \ ret2[i].end());\n\t\tret2[i].erase(std::unique(ret2[i].begin(), ret2[i].end()),\
    \ ret2[i].end());\n\t}\n\treturn std::make_tuple(ret, ret2, component);\n}\n"
  code: "#include <tuple>\n#include <vector>\n#include <algorithm>\n\n/**\n * @brief\
    \ Strongly Connected Components Decomposition\n */\n\nstd::tuple<std::vector<std::vector<int>>,\
    \ std::vector<std::vector<int>>, std::vector<int>> strongly_connected_components_decomposition(const\
    \ std::vector<std::vector<int>> &G) {\n\tint n = G.size();\n\tstd::vector<std::vector<int>>\
    \ G2(n);\n\tfor (int i = 0; i < n; i++) {\n\t\tfor (int nxt : G[i]) {\n\t\t\t\
    G2[nxt].push_back(i);\n\t\t}\n\t}\n\tstd::vector<int> order(n), component(n, -1);\n\
    \tstd::vector<bool> vst(n);\n\tauto F = [&](auto F, int now) -> void {\n\t\tvst[now]\
    \ = true;\n\t\tfor (int nxt : G[now]) {\n\t\t\tif (!vst[nxt]) {\n\t\t\t\tF(F,\
    \ nxt);\n\t\t\t}\n\t\t}\n\t\torder.push_back(now);\n\t};\n\tauto F2 = [&](auto\
    \ F2, int now, int idx) -> void {\n\t\tcomponent[now] = idx;\n\t\tfor (int nxt\
    \ : G2[now]) {\n\t\t\tif (component[nxt] == -1) {\n\t\t\t\tF2(F2, nxt, idx);\n\
    \t\t\t}\n\t\t}\n\t};\n\tfor (int i = 0; i < n; i++) {\n\t\tif (!vst[i]) {\n\t\t\
    \tF(F, i);\n\t\t}\n\t}\n\tint idx = 0;\n\tstd::reverse(order.begin(), order.end());\n\
    \tfor (int now : order) {\n\t\tif (component[now] == -1) {\n\t\t\tF2(F2, now,\
    \ idx);\n\t\t\tidx++;\n\t\t}\n\t}\n\tint n_n = *std::max_element(component.begin(),\
    \ component.end()) + 1;\n\tstd::vector<std::vector<int>> ret(n_n);\n\tfor (int\
    \ i = 0; i < n; i++) {\n\t\tret[component[i]].push_back(i);\n\t}\n\tstd::vector<std::vector<int>>\
    \ ret2(n_n);\n\tfor (int i = 0; i < n; i++) {\n\t\tfor (int j : G[i]) {\n\t\t\t\
    if (component[i] != component[j]) {\n\t\t\t\tret2[component[i]].push_back(component[j]);\n\
    \t\t\t}\n\t\t}\n\t}\n\tfor (int i = 0; i < n_n; i++) {\n\t\tsort(ret2[i].begin(),\
    \ ret2[i].end());\n\t\tret2[i].erase(std::unique(ret2[i].begin(), ret2[i].end()),\
    \ ret2[i].end());\n\t}\n\treturn std::make_tuple(ret, ret2, component);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/scc.cpp
  requiredBy: []
  timestamp: '2024-01-09 15:41:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/scc.cpp
layout: document
redirect_from:
- /library/graph/scc.cpp
- /library/graph/scc.cpp.html
title: Strongly Connected Components Decomposition
---
