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
    \nstd::vector<std::pair<long long, int>> prime_factorize(long long n) {\n    std::vector<std::pair<long\
    \ long, int>> ret;\n    for (long long i = 2; i * i <= n; i++) {\n        if (n\
    \ % i != 0) {\n            continue;\n        }\n        int ex = 0;\n       \
    \ while (n % i == 0) {\n            ex++;\n            n /= i;\n        }\n  \
    \      ret.push_back({i, ex});\n    }\n    if (n != 1) {\n        ret.push_back({n,\
    \ 1});\n    }\n    return ret;\n}\n"
  code: "#include <vector>\n#include <utility>\n\n/**\n * @brief Prime Factorize\n\
    \ * @attention O(n sqrt(n))\n */\n\nstd::vector<std::pair<long long, int>> prime_factorize(long\
    \ long n) {\n    std::vector<std::pair<long long, int>> ret;\n    for (long long\
    \ i = 2; i * i <= n; i++) {\n        if (n % i != 0) {\n            continue;\n\
    \        }\n        int ex = 0;\n        while (n % i == 0) {\n            ex++;\n\
    \            n /= i;\n        }\n        ret.push_back({i, ex});\n    }\n    if\
    \ (n != 1) {\n        ret.push_back({n, 1});\n    }\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/prime_factorize.cpp
  requiredBy: []
  timestamp: '2024-01-25 11:55:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/prime_factorize.cpp
layout: document
redirect_from:
- /library/math/prime_factorize.cpp
- /library/math/prime_factorize.cpp.html
title: Prime Factorize
---
