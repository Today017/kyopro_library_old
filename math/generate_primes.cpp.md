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
  bundledCode: "#line 1 \"math/generate_primes.cpp\"\n// \u30A8\u30E9\u30C8\u30B9\u30C6\
    \u30CD\u30B9\u306E\u7BE9\u306B\u3088\u308B\u7D20\u6570\u5217\u6319\n// O(Nlog(log(N)))\n\
    vector<int> generate_primes(int n) {\n\tvector<int> ret;\n\tvector<bool> vst(n\
    \ + 1, false);\n\tvst[0] = vst[1] = true;\n\tfor (int i = 2; i <= n; i++) {\n\t\
    \tif (vst[i]) {\n\t\t\tcontinue;\n\t\t}\n\t\tret.push_back(i);\n\t\tfor (int j\
    \ = 2 * i; j <= n; j += i) {\n\t\t\tvst[j] = true;\n\t\t}\n\t}\n\treturn ret;\n\
    }\n"
  code: "// \u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9\u306B\u3088\u308B\
    \u7D20\u6570\u5217\u6319\n// O(Nlog(log(N)))\nvector<int> generate_primes(int\
    \ n) {\n\tvector<int> ret;\n\tvector<bool> vst(n + 1, false);\n\tvst[0] = vst[1]\
    \ = true;\n\tfor (int i = 2; i <= n; i++) {\n\t\tif (vst[i]) {\n\t\t\tcontinue;\n\
    \t\t}\n\t\tret.push_back(i);\n\t\tfor (int j = 2 * i; j <= n; j += i) {\n\t\t\t\
    vst[j] = true;\n\t\t}\n\t}\n\treturn ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/generate_primes.cpp
  requiredBy: []
  timestamp: '2023-12-04 01:54:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/generate_primes.cpp
layout: document
redirect_from:
- /library/math/generate_primes.cpp
- /library/math/generate_primes.cpp.html
title: math/generate_primes.cpp
---
