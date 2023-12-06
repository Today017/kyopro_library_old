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
    \ &A) {\r\n\tint n = A.size();\r\n\tstd::vector<T> ret(n);\r\n\tfor (int i = 0;\
    \ i < n; i++) {\r\n\t\tret[i] = A[i];\r\n\t}\r\n\tstd::sort(ret.begin(), ret.end());\r\
    \n\tret.erase(std::unique(ret.begin(), ret.end()), ret.end());\r\n\tfor (int i\
    \ = 0; i < n; i++) {\r\n\t\tA[i] = std::lower_bound(ret.begin(), ret.end(), A[i])\
    \ - ret.begin();\r\n\t}\r\n\treturn ret;\r\n}\n"
  code: "#include <vector>\r\n#include <algorithm>\r\n\r\ntemplate <typename T>\r\n\
    std::vector<T> compress(std::vector<T> &A) {\r\n\tint n = A.size();\r\n\tstd::vector<T>\
    \ ret(n);\r\n\tfor (int i = 0; i < n; i++) {\r\n\t\tret[i] = A[i];\r\n\t}\r\n\t\
    std::sort(ret.begin(), ret.end());\r\n\tret.erase(std::unique(ret.begin(), ret.end()),\
    \ ret.end());\r\n\tfor (int i = 0; i < n; i++) {\r\n\t\tA[i] = std::lower_bound(ret.begin(),\
    \ ret.end(), A[i]) - ret.begin();\r\n\t}\r\n\treturn ret;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/compress_vector.cpp
  requiredBy: []
  timestamp: '2023-12-06 10:41:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/compress_vector.cpp
layout: document
redirect_from:
- /library/algorithm/compress_vector.cpp
- /library/algorithm/compress_vector.cpp.html
title: algorithm/compress_vector.cpp
---
