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
    \ <tuple>\r\n#include <limits>\r\n\r\n/**\r\n * @brief Bellman Ford\r\n * @attention\
    \ O(VE)\r\n * @return \u8CA0\u306E\u30B5\u30A4\u30AF\u30EB\u3092\u542B\u3080\u304B\
    \u5426\u304B\r\n */\r\n\r\ntemplate <typename T>\r\nbool bellman_ford(const std::vector<std::tuple<int,\
    \ int, T>> &E, int n, int start, std::vector<T> &dst, T INF = std::numeric_limits<T>::max())\
    \ {\r\n    dst = std::vector<T>(n, INF);\r\n    dst[start] = 0;\r\n    int cnt\
    \ = 0;\r\n    while (cnt < n) {\r\n        bool fin = true;\r\n        for (std::tuple<int,\
    \ int, T> t : E) {\r\n            int a, b;\r\n            T c;\r\n          \
    \  std::tie(a, b, c) = t;\r\n            if (dst[a] != INF && dst[a] + c < dst[b])\
    \ {\r\n                dst[b] = dst[a] + c;\r\n                fin = false;\r\n\
    \            }\r\n        }\r\n        if (fin) {\r\n            break;\r\n  \
    \      }\r\n        cnt++;\r\n    }\r\n    return cnt == n;\r\n}\r\n"
  code: "#include <vector>\r\n#include <tuple>\r\n#include <limits>\r\n\r\n/**\r\n\
    \ * @brief Bellman Ford\r\n * @attention O(VE)\r\n * @return \u8CA0\u306E\u30B5\
    \u30A4\u30AF\u30EB\u3092\u542B\u3080\u304B\u5426\u304B\r\n */\r\n\r\ntemplate\
    \ <typename T>\r\nbool bellman_ford(const std::vector<std::tuple<int, int, T>>\
    \ &E, int n, int start, std::vector<T> &dst, T INF = std::numeric_limits<T>::max())\
    \ {\r\n    dst = std::vector<T>(n, INF);\r\n    dst[start] = 0;\r\n    int cnt\
    \ = 0;\r\n    while (cnt < n) {\r\n        bool fin = true;\r\n        for (std::tuple<int,\
    \ int, T> t : E) {\r\n            int a, b;\r\n            T c;\r\n          \
    \  std::tie(a, b, c) = t;\r\n            if (dst[a] != INF && dst[a] + c < dst[b])\
    \ {\r\n                dst[b] = dst[a] + c;\r\n                fin = false;\r\n\
    \            }\r\n        }\r\n        if (fin) {\r\n            break;\r\n  \
    \      }\r\n        cnt++;\r\n    }\r\n    return cnt == n;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/bellman_ford.cpp
  requiredBy: []
  timestamp: '2024-01-25 11:55:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/bellman_ford.cpp
layout: document
redirect_from:
- /library/graph/bellman_ford.cpp
- /library/graph/bellman_ford.cpp.html
title: Bellman Ford
---
