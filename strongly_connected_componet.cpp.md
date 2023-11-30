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
  bundledCode: "#line 1 \"strongly_connected_componet.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nvector<vector<int>> strongly_connected_components_decomposition(const\
    \ vector<vector<int>> &G) {\n\tint n = G.size();\n\tvector<vector<int>> G2(n);\n\
    \tfor (int i = 0; i < n; i++) {\n\t\tfor (int nxt : G[i]) {\n\t\t\tG2[nxt].push_back(i);\n\
    \t\t}\n\t}\n\tvector<int> order(n), component(n, -1);\n\tvector<bool> vst(n);\n\
    \tauto F = [&](auto F, int now) -> void {\n\t\tvst[now] = true;\n\t\tfor (int\
    \ nxt : G[now]) {\n\t\t\tif (!vst[nxt]) {\n\t\t\t\tF(F, nxt);\n\t\t\t}\n\t\t}\n\
    \t\torder.push_back(now);\n\t};\n\tauto F2 = [&](auto F2, int now, int idx) ->\
    \ void {\n\t\tcomponent[now] = idx;\n\t\tfor (int nxt : G2[now]) {\n\t\t\tif (component[nxt]\
    \ == -1) {\n\t\t\t\tF2(F2, nxt, idx);\n\t\t\t}\n\t\t}\n\t};\n\tfor (int i = 0;\
    \ i < n; i++) {\n\t\tif (!vst[i]) {\n\t\t\tF(F, i);\n\t\t}\n\t}\n\tint idx = 0;\n\
    \treverse(order.begin(), order.end());\n\tfor (int now : order) {\n\t\tif (component[now]\
    \ == -1) {\n\t\t\tF2(F2, now, idx);\n\t\t\tidx++;\n\t\t}\n\t}\n\tint n_n = *max_element(component.begin(),\
    \ component.end()) + 1;\n\tvector<vector<int>> ret(n_n);\n\tfor (int i = 0; i\
    \ < n; i++) {\n\t\tret[component[i]].push_back(i);\n\t}\n\treturn ret;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\nvector<vector<int>> strongly_connected_components_decomposition(const\
    \ vector<vector<int>> &G) {\n\tint n = G.size();\n\tvector<vector<int>> G2(n);\n\
    \tfor (int i = 0; i < n; i++) {\n\t\tfor (int nxt : G[i]) {\n\t\t\tG2[nxt].push_back(i);\n\
    \t\t}\n\t}\n\tvector<int> order(n), component(n, -1);\n\tvector<bool> vst(n);\n\
    \tauto F = [&](auto F, int now) -> void {\n\t\tvst[now] = true;\n\t\tfor (int\
    \ nxt : G[now]) {\n\t\t\tif (!vst[nxt]) {\n\t\t\t\tF(F, nxt);\n\t\t\t}\n\t\t}\n\
    \t\torder.push_back(now);\n\t};\n\tauto F2 = [&](auto F2, int now, int idx) ->\
    \ void {\n\t\tcomponent[now] = idx;\n\t\tfor (int nxt : G2[now]) {\n\t\t\tif (component[nxt]\
    \ == -1) {\n\t\t\t\tF2(F2, nxt, idx);\n\t\t\t}\n\t\t}\n\t};\n\tfor (int i = 0;\
    \ i < n; i++) {\n\t\tif (!vst[i]) {\n\t\t\tF(F, i);\n\t\t}\n\t}\n\tint idx = 0;\n\
    \treverse(order.begin(), order.end());\n\tfor (int now : order) {\n\t\tif (component[now]\
    \ == -1) {\n\t\t\tF2(F2, now, idx);\n\t\t\tidx++;\n\t\t}\n\t}\n\tint n_n = *max_element(component.begin(),\
    \ component.end()) + 1;\n\tvector<vector<int>> ret(n_n);\n\tfor (int i = 0; i\
    \ < n; i++) {\n\t\tret[component[i]].push_back(i);\n\t}\n\treturn ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: strongly_connected_componet.cpp
  requiredBy: []
  timestamp: '2023-11-30 13:56:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: strongly_connected_componet.cpp
layout: document
redirect_from:
- /library/strongly_connected_componet.cpp
- /library/strongly_connected_componet.cpp.html
title: strongly_connected_componet.cpp
---
