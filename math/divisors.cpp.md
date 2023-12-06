---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u7D04\u6570\u5217\u6319"
    links: []
  bundledCode: "#line 1 \"math/divisors.cpp\"\n#include <vector>\n#include <algorithm>\n\
    \n/**\n * @brief \u7D04\u6570\u5217\u6319\n * @attention O(sqrt(n))\n */\n\nstd::vector<long\
    \ long> divisors(long long n) {\n\tstd::vector<long long> ret;\n\tfor (long long\
    \ i = 1; i * i <= n; i++) {\n\t\tif (n % i) {\n\t\t\tcontinue;\n\t\t}\n\t\tret.push_back(i);\n\
    \t\tif (n / i != i) {\n\t\t\tret.push_back(n / i);\n\t\t}\n\t}\n\tstd::sort(ret.begin(),\
    \ ret.end());\n\treturn ret;\n}\n"
  code: "#include <vector>\n#include <algorithm>\n\n/**\n * @brief \u7D04\u6570\u5217\
    \u6319\n * @attention O(sqrt(n))\n */\n\nstd::vector<long long> divisors(long\
    \ long n) {\n\tstd::vector<long long> ret;\n\tfor (long long i = 1; i * i <= n;\
    \ i++) {\n\t\tif (n % i) {\n\t\t\tcontinue;\n\t\t}\n\t\tret.push_back(i);\n\t\t\
    if (n / i != i) {\n\t\t\tret.push_back(n / i);\n\t\t}\n\t}\n\tstd::sort(ret.begin(),\
    \ ret.end());\n\treturn ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/divisors.cpp
  requiredBy: []
  timestamp: '2023-12-06 10:41:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/divisors.cpp
layout: document
redirect_from:
- /library/math/divisors.cpp
- /library/math/divisors.cpp.html
title: "\u7D04\u6570\u5217\u6319"
---
