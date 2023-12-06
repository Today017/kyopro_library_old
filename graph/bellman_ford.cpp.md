---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Bellman Ford
    links: []
  bundledCode: "#line 1 \"graph/bellman_ford.cpp\"\n#include <vector>\r\n#include\
    \ <tuple>\r\n#include <climits>\r\n\r\n/**\r\n * @brief Bellman Ford\r\n * @attention\
    \ O(VE)\r\n * @return \u8CA0\u306E\u30B5\u30A4\u30AF\u30EB\u3092\u542B\u3080\u304B\
    \u5426\u304B\r\n */\r\n\r\ntemplate <typename T>\r\nbool bellman_ford(const std::vector<std::tuple<int,\
    \ int, T>> &E, int n, int start, std::vector<T> &dst, T INF = LLONG_MAX) {\r\n\
    \tdst = std::vector<T>(n, INF);\r\n\tdst[start] = 0;\r\n\tint cnt = 0;\r\n\twhile\
    \ (cnt < n) {\r\n\t\tbool fin = true;\r\n\t\tfor (std::tuple<int, int, T> T :\
    \ E) {\r\n\t\t\tint a, b;\r\n\t\t\tT c;\r\n\t\t\tstd::tie(a, b, c) = T;\r\n\t\t\
    \tif (dst[a] != INF && dst[a] + c < dst[b]) {\r\n\t\t\t\tdst[b] = dst[a] + c;\r\
    \n\t\t\t\tfin = false;\r\n\t\t\t}\r\n\t\t}\r\n\t\tif (fin) {\r\n\t\t\tbreak;\r\
    \n\t\t}\r\n\t\tcnt++;\r\n\t}\r\n\treturn cnt == n;\r\n}\n"
  code: "#include <vector>\r\n#include <tuple>\r\n#include <climits>\r\n\r\n/**\r\n\
    \ * @brief Bellman Ford\r\n * @attention O(VE)\r\n * @return \u8CA0\u306E\u30B5\
    \u30A4\u30AF\u30EB\u3092\u542B\u3080\u304B\u5426\u304B\r\n */\r\n\r\ntemplate\
    \ <typename T>\r\nbool bellman_ford(const std::vector<std::tuple<int, int, T>>\
    \ &E, int n, int start, std::vector<T> &dst, T INF = LLONG_MAX) {\r\n\tdst = std::vector<T>(n,\
    \ INF);\r\n\tdst[start] = 0;\r\n\tint cnt = 0;\r\n\twhile (cnt < n) {\r\n\t\t\
    bool fin = true;\r\n\t\tfor (std::tuple<int, int, T> T : E) {\r\n\t\t\tint a,\
    \ b;\r\n\t\t\tT c;\r\n\t\t\tstd::tie(a, b, c) = T;\r\n\t\t\tif (dst[a] != INF\
    \ && dst[a] + c < dst[b]) {\r\n\t\t\t\tdst[b] = dst[a] + c;\r\n\t\t\t\tfin = false;\r\
    \n\t\t\t}\r\n\t\t}\r\n\t\tif (fin) {\r\n\t\t\tbreak;\r\n\t\t}\r\n\t\tcnt++;\r\n\
    \t}\r\n\treturn cnt == n;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/bellman_ford.cpp
  requiredBy: []
  timestamp: '2023-12-06 10:41:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/bellman_ford.cpp
layout: document
redirect_from:
- /library/graph/bellman_ford.cpp
- /library/graph/bellman_ford.cpp.html
title: Bellman Ford
---
