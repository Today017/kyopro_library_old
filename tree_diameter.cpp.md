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
  bundledCode: "#line 1 \"tree_diameter.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nvector<int> tree_diameter(vector<vector<int>>& G) {\n\tint n = G.size();\n\
    \tconst int INF = 1001001001;\n\tvector<int> dst(n, INF);\n\tdst[0] = 0;\n\tauto\
    \ F1 = [&](auto&& F1, int now, int pre) -> void {\n\t\tfor (int nxt : G[now])\
    \ {\n\t\t\tif (nxt != pre) {\n\t\t\t\tdst[nxt] = dst[now] + 1;\n\t\t\t\tF1(F1,\
    \ nxt, now);\n\t\t\t}\n\t\t}\n\t};\n\tF1(F1, 0, -1);\n\tint l = max_element(dst.begin(),\
    \ dst.end()) - dst.begin();\n\tdst = vector<int>(n, INF);\n\tdst[l] = 0;\n\tF1(F1,\
    \ l, -1);\n\tint r = max_element(dst.begin(), dst.end()) - dst.begin();\n\tvector<int>\
    \ path;\n\tauto F2 = [&](auto&& F2, int now, int pre) -> bool {\n\t\tif (now ==\
    \ l) {\n\t\t\tpath.push_back(now);\n\t\t\treturn true;\n\t\t}\n\t\tbool ret =\
    \ false;\n\t\tfor (int nxt : G[now]) {\n\t\t\tif (nxt != pre) {\n\t\t\t\tif (F2(F2,\
    \ nxt, now)) {\n\t\t\t\t\tret = true;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\tif (ret)\
    \ {\n\t\t\tpath.push_back(now);\n\t\t}\n\t\treturn ret;\n\t};\n\tF2(F2, r, -1);\n\
    \treturn path;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\nvector<int> tree_diameter(vector<vector<int>>&\
    \ G) {\n\tint n = G.size();\n\tconst int INF = 1001001001;\n\tvector<int> dst(n,\
    \ INF);\n\tdst[0] = 0;\n\tauto F1 = [&](auto&& F1, int now, int pre) -> void {\n\
    \t\tfor (int nxt : G[now]) {\n\t\t\tif (nxt != pre) {\n\t\t\t\tdst[nxt] = dst[now]\
    \ + 1;\n\t\t\t\tF1(F1, nxt, now);\n\t\t\t}\n\t\t}\n\t};\n\tF1(F1, 0, -1);\n\t\
    int l = max_element(dst.begin(), dst.end()) - dst.begin();\n\tdst = vector<int>(n,\
    \ INF);\n\tdst[l] = 0;\n\tF1(F1, l, -1);\n\tint r = max_element(dst.begin(), dst.end())\
    \ - dst.begin();\n\tvector<int> path;\n\tauto F2 = [&](auto&& F2, int now, int\
    \ pre) -> bool {\n\t\tif (now == l) {\n\t\t\tpath.push_back(now);\n\t\t\treturn\
    \ true;\n\t\t}\n\t\tbool ret = false;\n\t\tfor (int nxt : G[now]) {\n\t\t\tif\
    \ (nxt != pre) {\n\t\t\t\tif (F2(F2, nxt, now)) {\n\t\t\t\t\tret = true;\n\t\t\
    \t\t}\n\t\t\t}\n\t\t}\n\t\tif (ret) {\n\t\t\tpath.push_back(now);\n\t\t}\n\t\t\
    return ret;\n\t};\n\tF2(F2, r, -1);\n\treturn path;\n}"
  dependsOn: []
  isVerificationFile: false
  path: tree_diameter.cpp
  requiredBy: []
  timestamp: '2023-11-30 13:56:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tree_diameter.cpp
layout: document
redirect_from:
- /library/tree_diameter.cpp
- /library/tree_diameter.cpp.html
title: tree_diameter.cpp
---
