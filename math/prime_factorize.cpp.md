---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Prime Factorize
    links: []
  bundledCode: "#line 1 \"math/prime_factorize.cpp\"\n#include <vector>\n#include\
    \ <utility>\n\n/**\n * @brief Prime Factorize\n * @attention O(n sqrt(n))\n */\n\
    \nstd::vector<std::pair<long long, int>> prime_factorize(long long n) {\n\tstd::vector<std::pair<long\
    \ long, int>> ret;\n\tfor (long long i = 2; i * i <= n; i++) {\n\t\tif (n % i\
    \ != 0) {\n\t\t\tcontinue;\n\t\t}\n\t\tint ex = 0;\n\t\twhile (n % i == 0) {\n\
    \t\t\tex++;\n\t\t\tn /= i;\n\t\t}\n\t\tret.push_back({i, ex});\n\t}\n\tif (n !=\
    \ 1) {\n\t\tret.push_back({n, 1});\n\t}\n\treturn ret;\n}\n"
  code: "#include <vector>\n#include <utility>\n\n/**\n * @brief Prime Factorize\n\
    \ * @attention O(n sqrt(n))\n */\n\nstd::vector<std::pair<long long, int>> prime_factorize(long\
    \ long n) {\n\tstd::vector<std::pair<long long, int>> ret;\n\tfor (long long i\
    \ = 2; i * i <= n; i++) {\n\t\tif (n % i != 0) {\n\t\t\tcontinue;\n\t\t}\n\t\t\
    int ex = 0;\n\t\twhile (n % i == 0) {\n\t\t\tex++;\n\t\t\tn /= i;\n\t\t}\n\t\t\
    ret.push_back({i, ex});\n\t}\n\tif (n != 1) {\n\t\tret.push_back({n, 1});\n\t\
    }\n\treturn ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/prime_factorize.cpp
  requiredBy: []
  timestamp: '2023-12-06 10:41:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/prime_factorize.cpp
layout: document
redirect_from:
- /library/math/prime_factorize.cpp
- /library/math/prime_factorize.cpp.html
title: Prime Factorize
---
