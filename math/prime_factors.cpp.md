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
  bundledCode: "#line 1 \"math/prime_factors.cpp\"\n#include <bits/stdc++.h>\r\nusing\
    \ namespace std;\r\n\r\nvector<long long> prime_factors(long long n) {\r\n\tvector<long\
    \ long> ret;\r\n\tfor (long long i = 2; i * i <= n; i++) {\r\n\t\tif (n % i !=\
    \ 0) {\r\n\t\t\tcontinue;\r\n\t\t}\r\n\t\twhile (n % i == 0) {\r\n\t\t\tn /= i;\r\
    \n\t\t}\r\n\t\tret.push_back(i);\r\n\t}\r\n\tif (n != 1) {\r\n\t\tret.push_back(n);\r\
    \n\t}\r\n\treturn ret;\r\n}\n"
  code: "#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\nvector<long long>\
    \ prime_factors(long long n) {\r\n\tvector<long long> ret;\r\n\tfor (long long\
    \ i = 2; i * i <= n; i++) {\r\n\t\tif (n % i != 0) {\r\n\t\t\tcontinue;\r\n\t\t\
    }\r\n\t\twhile (n % i == 0) {\r\n\t\t\tn /= i;\r\n\t\t}\r\n\t\tret.push_back(i);\r\
    \n\t}\r\n\tif (n != 1) {\r\n\t\tret.push_back(n);\r\n\t}\r\n\treturn ret;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/prime_factors.cpp
  requiredBy: []
  timestamp: '2023-11-30 18:16:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/prime_factors.cpp
layout: document
redirect_from:
- /library/math/prime_factors.cpp
- /library/math/prime_factors.cpp.html
title: math/prime_factors.cpp
---
