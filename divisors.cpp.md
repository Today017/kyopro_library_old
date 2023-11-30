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
  bundledCode: "#line 1 \"divisors.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nvector<long long> divisors(long long n) {\n\tvector<long long> ret;\n\
    \tfor (long long i = 1; i * i <= n; i++) {\n\t\tif (n % i) {\n\t\t\tcontinue;\n\
    \t\t}\n\t\tret.push_back(i);\n\t\tif (n / i != i) {\n\t\t\tret.push_back(n / i);\n\
    \t\t}\n\t}\n\tsort(ret.begin(), ret.end());\n\treturn ret;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\nvector<long long> divisors(long\
    \ long n) {\n\tvector<long long> ret;\n\tfor (long long i = 1; i * i <= n; i++)\
    \ {\n\t\tif (n % i) {\n\t\t\tcontinue;\n\t\t}\n\t\tret.push_back(i);\n\t\tif (n\
    \ / i != i) {\n\t\t\tret.push_back(n / i);\n\t\t}\n\t}\n\tsort(ret.begin(), ret.end());\n\
    \treturn ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: divisors.cpp
  requiredBy: []
  timestamp: '2023-11-30 13:56:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: divisors.cpp
layout: document
redirect_from:
- /library/divisors.cpp
- /library/divisors.cpp.html
title: divisors.cpp
---
