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
  bundledCode: "#line 1 \"algorithm/compress_vector.cpp\"\ntemplate <typename T>\r\
    \nvector<T> compress(vector<T> &A) {\r\n\tint n = A.size();\r\n\tvector<T> ret(n);\r\
    \n\tfor (int i = 0; i < n; i++) {\r\n\t\tret[i] = A[i];\r\n\t}\r\n\tsort(ret.begin(),\
    \ ret.end());\r\n\tret.erase(unique(ret.begin(), ret.end()), ret.end());\r\n\t\
    for (int i = 0; i < n; i++) {\r\n\t\tA[i] = lower_bound(ret.begin(), ret.end(),\
    \ A[i]) - ret.begin();\r\n\t}\r\n\treturn ret;\r\n}\n"
  code: "template <typename T>\r\nvector<T> compress(vector<T> &A) {\r\n\tint n =\
    \ A.size();\r\n\tvector<T> ret(n);\r\n\tfor (int i = 0; i < n; i++) {\r\n\t\t\
    ret[i] = A[i];\r\n\t}\r\n\tsort(ret.begin(), ret.end());\r\n\tret.erase(unique(ret.begin(),\
    \ ret.end()), ret.end());\r\n\tfor (int i = 0; i < n; i++) {\r\n\t\tA[i] = lower_bound(ret.begin(),\
    \ ret.end(), A[i]) - ret.begin();\r\n\t}\r\n\treturn ret;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/compress_vector.cpp
  requiredBy: []
  timestamp: '2023-12-04 01:54:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/compress_vector.cpp
layout: document
redirect_from:
- /library/algorithm/compress_vector.cpp
- /library/algorithm/compress_vector.cpp.html
title: algorithm/compress_vector.cpp
---
