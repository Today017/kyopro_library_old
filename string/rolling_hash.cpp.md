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
  bundledCode: "#line 1 \"string/rolling_hash.cpp\"\nstruct rolling_hash {\n\tconst\
    \ long long base = 1000000007;\n\tconst long long mod = 998244353;\n\tvector<long\
    \ long> hashed, power;\n\trolling_hash(string s) {\n\t\tint n = s.size();\n\t\t\
    hashed.resize(n + 1);\n\t\tpower.resize(n + 1);\n\t\tpower[0] = 1;\n\t\tfor (int\
    \ i = 0; i < n; i++) {\n\t\t\tpower[i + 1] = power[i] * base % mod;\n\t\t\thashed[i\
    \ + 1] = ((hashed[i] * base) + (s[i] - 'a')) % mod;\n\t\t}\n\t}\n\tlong long hash(int\
    \ l, int r) {\n\t\tlong long ret = mod + hashed[r] - (hashed[l] * power[r - l])\
    \ % mod;\n\t\tret %= mod;\n\t\treturn ret;\n\t}\n};\n"
  code: "struct rolling_hash {\n\tconst long long base = 1000000007;\n\tconst long\
    \ long mod = 998244353;\n\tvector<long long> hashed, power;\n\trolling_hash(string\
    \ s) {\n\t\tint n = s.size();\n\t\thashed.resize(n + 1);\n\t\tpower.resize(n +\
    \ 1);\n\t\tpower[0] = 1;\n\t\tfor (int i = 0; i < n; i++) {\n\t\t\tpower[i + 1]\
    \ = power[i] * base % mod;\n\t\t\thashed[i + 1] = ((hashed[i] * base) + (s[i]\
    \ - 'a')) % mod;\n\t\t}\n\t}\n\tlong long hash(int l, int r) {\n\t\tlong long\
    \ ret = mod + hashed[r] - (hashed[l] * power[r - l]) % mod;\n\t\tret %= mod;\n\
    \t\treturn ret;\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: string/rolling_hash.cpp
  requiredBy: []
  timestamp: '2023-11-30 18:16:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/rolling_hash.cpp
layout: document
redirect_from:
- /library/string/rolling_hash.cpp
- /library/string/rolling_hash.cpp.html
title: string/rolling_hash.cpp
---
