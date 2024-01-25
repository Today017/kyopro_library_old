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
  bundledCode: "#line 1 \"algorithm/compress_vector.cpp\"\n#include <vector>\r\n#include\
    \ <algorithm>\r\n\r\ntemplate <typename T>\r\nstd::vector<T> compress(std::vector<T>\
    \ &A) {\r\n    int n = A.size();\r\n    std::vector<T> ret(n);\r\n    for (int\
    \ i = 0; i < n; i++) {\r\n        ret[i] = A[i];\r\n    }\r\n    std::sort(ret.begin(),\
    \ ret.end());\r\n    ret.erase(std::unique(ret.begin(), ret.end()), ret.end());\r\
    \n    for (int i = 0; i < n; i++) {\r\n        A[i] = std::lower_bound(ret.begin(),\
    \ ret.end(), A[i]) - ret.begin();\r\n    }\r\n    return ret;\r\n}\n"
  code: "#include <vector>\r\n#include <algorithm>\r\n\r\ntemplate <typename T>\r\n\
    std::vector<T> compress(std::vector<T> &A) {\r\n    int n = A.size();\r\n    std::vector<T>\
    \ ret(n);\r\n    for (int i = 0; i < n; i++) {\r\n        ret[i] = A[i];\r\n \
    \   }\r\n    std::sort(ret.begin(), ret.end());\r\n    ret.erase(std::unique(ret.begin(),\
    \ ret.end()), ret.end());\r\n    for (int i = 0; i < n; i++) {\r\n        A[i]\
    \ = std::lower_bound(ret.begin(), ret.end(), A[i]) - ret.begin();\r\n    }\r\n\
    \    return ret;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/compress_vector.cpp
  requiredBy: []
  timestamp: '2024-01-25 11:55:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/compress_vector.cpp
layout: document
redirect_from:
- /library/algorithm/compress_vector.cpp
- /library/algorithm/compress_vector.cpp.html
title: algorithm/compress_vector.cpp
---
