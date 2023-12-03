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
  bundledCode: "#line 1 \"math/prime_factorize.cpp\"\nvector<pair<long long, int>>\
    \ prime_factorize(long long n) {\n\tvector<pair<long long, int>> ret;\n\tfor (long\
    \ long i = 2; i * i <= n; i++) {\n\t\tif (n % i != 0) {\n\t\t\tcontinue;\n\t\t\
    }\n\t\tint ex = 0;\n\t\twhile (n % i == 0) {\n\t\t\tex++;\n\t\t\tn /= i;\n\t\t\
    }\n\t\tret.push_back({i, ex});\n\t}\n\tif (n != 1) {\n\t\tret.push_back({n, 1});\n\
    \t}\n\treturn ret;\n}\n"
  code: "vector<pair<long long, int>> prime_factorize(long long n) {\n\tvector<pair<long\
    \ long, int>> ret;\n\tfor (long long i = 2; i * i <= n; i++) {\n\t\tif (n % i\
    \ != 0) {\n\t\t\tcontinue;\n\t\t}\n\t\tint ex = 0;\n\t\twhile (n % i == 0) {\n\
    \t\t\tex++;\n\t\t\tn /= i;\n\t\t}\n\t\tret.push_back({i, ex});\n\t}\n\tif (n !=\
    \ 1) {\n\t\tret.push_back({n, 1});\n\t}\n\treturn ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/prime_factorize.cpp
  requiredBy: []
  timestamp: '2023-12-04 01:54:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/prime_factorize.cpp
layout: document
redirect_from:
- /library/math/prime_factorize.cpp
- /library/math/prime_factorize.cpp.html
title: math/prime_factorize.cpp
---
