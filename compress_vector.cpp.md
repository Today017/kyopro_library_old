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
  bundledCode: "#line 1 \"compress_vector.cpp\"\n#include <bits/stdc++.h>\r\nusing\
    \ namespace std;\r\n\r\ntemplate <typename T>\r\nvector<T> compress(vector<T>\
    \ &A) {\r\n\tint n = A.size();\r\n\tvector<T> ret(n);\r\n\tfor (int i = 0; i <\
    \ n; i++) {\r\n\t\tret[i] = A[i];\r\n\t}\r\n\tsort(ret.begin(), ret.end());\r\n\
    \tret.erase(unique(ret.begin(), ret.end()), ret.end());\r\n\tfor (int i = 0; i\
    \ < n; i++) {\r\n\t\tA[i] = lower_bound(ret.begin(), ret.end(), A[i]) - ret.begin();\r\
    \n\t}\r\n\treturn ret;\r\n}\n"
  code: "#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\ntemplate <typename\
    \ T>\r\nvector<T> compress(vector<T> &A) {\r\n\tint n = A.size();\r\n\tvector<T>\
    \ ret(n);\r\n\tfor (int i = 0; i < n; i++) {\r\n\t\tret[i] = A[i];\r\n\t}\r\n\t\
    sort(ret.begin(), ret.end());\r\n\tret.erase(unique(ret.begin(), ret.end()), ret.end());\r\
    \n\tfor (int i = 0; i < n; i++) {\r\n\t\tA[i] = lower_bound(ret.begin(), ret.end(),\
    \ A[i]) - ret.begin();\r\n\t}\r\n\treturn ret;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: compress_vector.cpp
  requiredBy: []
  timestamp: '2023-11-30 13:56:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: compress_vector.cpp
layout: document
redirect_from:
- /library/compress_vector.cpp
- /library/compress_vector.cpp.html
title: compress_vector.cpp
---
