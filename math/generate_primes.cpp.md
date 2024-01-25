---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Generate primes
    links: []
  bundledCode: "#line 1 \"math/generate_primes.cpp\"\n#include <vector>\n\n/**\n *\
    \ @brief Generate primes\n * @attention O(nlog(log(n)))\n*/\n\nstd::vector<int>\
    \ generate_primes(int n) {\n    std::vector<int> ret;\n    std::vector<bool> vst(n\
    \ + 1, false);\n    vst[0] = vst[1] = true;\n    for (int i = 2; i <= n; i++)\
    \ {\n        if (vst[i]) {\n            continue;\n        }\n        ret.push_back(i);\n\
    \        for (int j = 2 * i; j <= n; j += i) {\n            vst[j] = true;\n \
    \       }\n    }\n    return ret;\n}\n"
  code: "#include <vector>\n\n/**\n * @brief Generate primes\n * @attention O(nlog(log(n)))\n\
    */\n\nstd::vector<int> generate_primes(int n) {\n    std::vector<int> ret;\n \
    \   std::vector<bool> vst(n + 1, false);\n    vst[0] = vst[1] = true;\n    for\
    \ (int i = 2; i <= n; i++) {\n        if (vst[i]) {\n            continue;\n \
    \       }\n        ret.push_back(i);\n        for (int j = 2 * i; j <= n; j +=\
    \ i) {\n            vst[j] = true;\n        }\n    }\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/generate_primes.cpp
  requiredBy: []
  timestamp: '2024-01-25 11:55:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/generate_primes.cpp
layout: document
redirect_from:
- /library/math/generate_primes.cpp
- /library/math/generate_primes.cpp.html
title: Generate primes
---
