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
  bundledCode: "#line 1 \"math/divisors.cpp\"\nvector<long long> divisors(long long\
    \ n) {\n\tvector<long long> ret;\n\tfor (long long i = 1; i * i <= n; i++) {\n\
    \t\tif (n % i) {\n\t\t\tcontinue;\n\t\t}\n\t\tret.push_back(i);\n\t\tif (n / i\
    \ != i) {\n\t\t\tret.push_back(n / i);\n\t\t}\n\t}\n\tsort(ret.begin(), ret.end());\n\
    \treturn ret;\n}\n"
  code: "vector<long long> divisors(long long n) {\n\tvector<long long> ret;\n\tfor\
    \ (long long i = 1; i * i <= n; i++) {\n\t\tif (n % i) {\n\t\t\tcontinue;\n\t\t\
    }\n\t\tret.push_back(i);\n\t\tif (n / i != i) {\n\t\t\tret.push_back(n / i);\n\
    \t\t}\n\t}\n\tsort(ret.begin(), ret.end());\n\treturn ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/divisors.cpp
  requiredBy: []
  timestamp: '2023-12-04 01:54:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/divisors.cpp
layout: document
redirect_from:
- /library/math/divisors.cpp
- /library/math/divisors.cpp.html
title: math/divisors.cpp
---
