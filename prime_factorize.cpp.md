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
  bundledCode: "#line 1 \"prime_factorize.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nvector<pair<long long, int>> prime_factorize(long long n) {\n\tvector<pair<long\
    \ long, int>> ret;\n\tfor (long long i = 2; i * i <= n; i++) {\n\t\tif (n % i\
    \ != 0) {\n\t\t\tcontinue;\n\t\t}\n\t\tint ex = 0;\n\t\twhile (n % i == 0) {\n\
    \t\t\tex++;\n\t\t\tn /= i;\n\t\t}\n\t\tret.push_back({i, ex});\n\t}\n\tif (n !=\
    \ 1) {\n\t\tret.push_back({n, 1});\n\t}\n\treturn ret;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\nvector<pair<long long,\
    \ int>> prime_factorize(long long n) {\n\tvector<pair<long long, int>> ret;\n\t\
    for (long long i = 2; i * i <= n; i++) {\n\t\tif (n % i != 0) {\n\t\t\tcontinue;\n\
    \t\t}\n\t\tint ex = 0;\n\t\twhile (n % i == 0) {\n\t\t\tex++;\n\t\t\tn /= i;\n\
    \t\t}\n\t\tret.push_back({i, ex});\n\t}\n\tif (n != 1) {\n\t\tret.push_back({n,\
    \ 1});\n\t}\n\treturn ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: prime_factorize.cpp
  requiredBy: []
  timestamp: '2023-11-30 13:56:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: prime_factorize.cpp
layout: document
redirect_from:
- /library/prime_factorize.cpp
- /library/prime_factorize.cpp.html
title: prime_factorize.cpp
---
