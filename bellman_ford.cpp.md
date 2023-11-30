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
  bundledCode: "#line 1 \"bellman_ford.cpp\"\n#include <bits/stdc++.h>\r\nusing namespace\
    \ std;\r\n\r\n// \u30D9\u30EB\u30DE\u30F3\u30D5\u30A9\u30FC\u30C9\u6CD5 (\u8CA0\
    \u306E\u30B3\u30B9\u30C8\u306E\u8FBA\u3092\u542B\u3080\u91CD\u307F\u4ED8\u304D\
    \u6709\u5411\u30B0\u30E9\u30D5\u306B\u5BFE\u3057\u3066\u3001\u5358\u4E00\u59CB\
    \u70B9\u6700\u77ED\u7D4C\u8DEF\u554F\u984C\u3092\u89E3\u304F)\r\n// O(NM)\r\n\
    // return \u8CA0\u306E\u30B5\u30A4\u30AF\u30EB\u304C\u5B58\u5728\u3057\u306A\u3044\
    \u304B\u5426\u304B\r\nbool bellman_ford(const vector<tuple<int, int, long long>>\
    \ &E, int n, int start, vector<long long> &dst, long long INF = LLONG_MAX) {\r\
    \n\tdst = vector<long long>(n, INF);\r\n\tdst[start] = 0;\r\n\tint cnt = 0;\r\n\
    \twhile (cnt < n) {\r\n\t\tbool fin = true;\r\n\t\tfor (tuple<int, int, long long>\
    \ T : E) {\r\n\t\t\tint a, b;\r\n\t\t\tlong long c;\r\n\t\t\ttie(a, b, c) = T;\r\
    \n\t\t\tif (dst[a] != INF && dst[a] + c < dst[b]) {\r\n\t\t\t\tdst[b] = dst[a]\
    \ + c;\r\n\t\t\t\tfin = false;\r\n\t\t\t}\r\n\t\t}\r\n\t\tif (fin) {\r\n\t\t\t\
    break;\r\n\t\t}\r\n\t\tcnt++;\r\n\t}\r\n\treturn cnt == n;\r\n}\n"
  code: "#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\n// \u30D9\u30EB\u30DE\
    \u30F3\u30D5\u30A9\u30FC\u30C9\u6CD5 (\u8CA0\u306E\u30B3\u30B9\u30C8\u306E\u8FBA\
    \u3092\u542B\u3080\u91CD\u307F\u4ED8\u304D\u6709\u5411\u30B0\u30E9\u30D5\u306B\
    \u5BFE\u3057\u3066\u3001\u5358\u4E00\u59CB\u70B9\u6700\u77ED\u7D4C\u8DEF\u554F\
    \u984C\u3092\u89E3\u304F)\r\n// O(NM)\r\n// return \u8CA0\u306E\u30B5\u30A4\u30AF\
    \u30EB\u304C\u5B58\u5728\u3057\u306A\u3044\u304B\u5426\u304B\r\nbool bellman_ford(const\
    \ vector<tuple<int, int, long long>> &E, int n, int start, vector<long long> &dst,\
    \ long long INF = LLONG_MAX) {\r\n\tdst = vector<long long>(n, INF);\r\n\tdst[start]\
    \ = 0;\r\n\tint cnt = 0;\r\n\twhile (cnt < n) {\r\n\t\tbool fin = true;\r\n\t\t\
    for (tuple<int, int, long long> T : E) {\r\n\t\t\tint a, b;\r\n\t\t\tlong long\
    \ c;\r\n\t\t\ttie(a, b, c) = T;\r\n\t\t\tif (dst[a] != INF && dst[a] + c < dst[b])\
    \ {\r\n\t\t\t\tdst[b] = dst[a] + c;\r\n\t\t\t\tfin = false;\r\n\t\t\t}\r\n\t\t\
    }\r\n\t\tif (fin) {\r\n\t\t\tbreak;\r\n\t\t}\r\n\t\tcnt++;\r\n\t}\r\n\treturn\
    \ cnt == n;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: bellman_ford.cpp
  requiredBy: []
  timestamp: '2023-11-30 13:56:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: bellman_ford.cpp
layout: document
redirect_from:
- /library/bellman_ford.cpp
- /library/bellman_ford.cpp.html
title: bellman_ford.cpp
---
