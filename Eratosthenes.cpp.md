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
  bundledCode: "#line 1 \"Eratosthenes.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n// \u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9\u306B\u3088\
    \u308B\u7D20\u6570\u5217\u6319\n// O(Nlog(log(N)))\nvector<int> generate_primes(int\
    \ n) {\n\tvector<int> ret;\n\tvector<bool> vst(n + 1, false);\n\tvst[0] = vst[1]\
    \ = true;\n\tfor (int i = 2; i <= n; i++) {\n\t\tif (vst[i]) {\n\t\t\tcontinue;\n\
    \t\t}\n\t\tret.push_back(i);\n\t\tfor (int j = 2 * i; j <= n; j += i) {\n\t\t\t\
    vst[j] = true;\n\t\t}\n\t}\n\treturn ret;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n// \u30A8\u30E9\u30C8\u30B9\
    \u30C6\u30CD\u30B9\u306E\u7BE9\u306B\u3088\u308B\u7D20\u6570\u5217\u6319\n// O(Nlog(log(N)))\n\
    vector<int> generate_primes(int n) {\n\tvector<int> ret;\n\tvector<bool> vst(n\
    \ + 1, false);\n\tvst[0] = vst[1] = true;\n\tfor (int i = 2; i <= n; i++) {\n\t\
    \tif (vst[i]) {\n\t\t\tcontinue;\n\t\t}\n\t\tret.push_back(i);\n\t\tfor (int j\
    \ = 2 * i; j <= n; j += i) {\n\t\t\tvst[j] = true;\n\t\t}\n\t}\n\treturn ret;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: Eratosthenes.cpp
  requiredBy: []
  timestamp: '2023-11-30 13:56:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Eratosthenes.cpp
layout: document
redirect_from:
- /library/Eratosthenes.cpp
- /library/Eratosthenes.cpp.html
title: Eratosthenes.cpp
---
