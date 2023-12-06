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
    \ generate_primes(int n) {\n\tstd::vector<int> ret;\n\tstd::vector<bool> vst(n\
    \ + 1, false);\n\tvst[0] = vst[1] = true;\n\tfor (int i = 2; i <= n; i++) {\n\t\
    \tif (vst[i]) {\n\t\t\tcontinue;\n\t\t}\n\t\tret.push_back(i);\n\t\tfor (int j\
    \ = 2 * i; j <= n; j += i) {\n\t\t\tvst[j] = true;\n\t\t}\n\t}\n\treturn ret;\n\
    }\n"
  code: "#include <vector>\n\n/**\n * @brief Generate primes\n * @attention O(nlog(log(n)))\n\
    */\n\nstd::vector<int> generate_primes(int n) {\n\tstd::vector<int> ret;\n\tstd::vector<bool>\
    \ vst(n + 1, false);\n\tvst[0] = vst[1] = true;\n\tfor (int i = 2; i <= n; i++)\
    \ {\n\t\tif (vst[i]) {\n\t\t\tcontinue;\n\t\t}\n\t\tret.push_back(i);\n\t\tfor\
    \ (int j = 2 * i; j <= n; j += i) {\n\t\t\tvst[j] = true;\n\t\t}\n\t}\n\treturn\
    \ ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/generate_primes.cpp
  requiredBy: []
  timestamp: '2023-12-06 10:41:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/generate_primes.cpp
layout: document
redirect_from:
- /library/math/generate_primes.cpp
- /library/math/generate_primes.cpp.html
title: Generate primes
---
