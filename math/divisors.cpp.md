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
    \ long> divisors(long long n) {\n    std::vector<long long> ret;\n    for (long\
    \ long i = 1; i * i <= n; i++) {\n        if (n % i != 0) {\n            continue;\n\
    \        }\n        ret.push_back(i);\n        if (n / i != i) {\n           \
    \ ret.push_back(n / i);\n        }\n    }\n    std::sort(ret.begin(), ret.end());\n\
    \    return ret;\n}\n"
  code: "#include <vector>\n#include <algorithm>\n\n/**\n * @brief \u7D04\u6570\u5217\
    \u6319\n * @attention O(sqrt(n))\n */\n\nstd::vector<long long> divisors(long\
    \ long n) {\n    std::vector<long long> ret;\n    for (long long i = 1; i * i\
    \ <= n; i++) {\n        if (n % i != 0) {\n            continue;\n        }\n\
    \        ret.push_back(i);\n        if (n / i != i) {\n            ret.push_back(n\
    \ / i);\n        }\n    }\n    std::sort(ret.begin(), ret.end());\n    return\
    \ ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/divisors.cpp
  requiredBy: []
  timestamp: '2024-01-25 11:55:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/divisors.cpp
layout: document
redirect_from:
- /library/math/divisors.cpp
- /library/math/divisors.cpp.html
title: "\u7D04\u6570\u5217\u6319"
---
