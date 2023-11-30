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
  bundledCode: "#line 1 \"mod_combination.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#include <atcoder/all>\nusing namespace atcoder;\n\ntemplate <typename\
    \ T>\nstruct combination {\n\tvector<T> fact, factinv;\n\tcombination(int n) {\n\
    \t\tfact.resize(n + 1);\n\t\tfactinv.resize(n + 1);\n\t\tfact[0] = 1;\n\t\tfor\
    \ (int i = 1; i <= n; i++) {\n\t\t\tfact[i] = fact[i - 1] * i;\n\t\t}\n\t\tfor\
    \ (int i = 0; i <= n; i++) {\n\t\t\tfactinv[i] = fact[i].inv();\n\t\t}\n\t}\n\t\
    T nCr(long long n, long long r) {\n\t\tif (n < 0 || r < 0 || n - r < 0) {\n\t\t\
    \treturn 0;\n\t\t}\n\t\treturn fact[n] * factinv[r] * factinv[n - r];\n\t}\n\t\
    T nPr(long long n, long long r) {\n\t\tif (n < 0 || r < 0 || n - r < 0) {\n\t\t\
    \treturn 0;\n\t\t}\n\t\treturn fact[n] * factinv[n - r];\n\t}\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n#include <atcoder/all>\n\
    using namespace atcoder;\n\ntemplate <typename T>\nstruct combination {\n\tvector<T>\
    \ fact, factinv;\n\tcombination(int n) {\n\t\tfact.resize(n + 1);\n\t\tfactinv.resize(n\
    \ + 1);\n\t\tfact[0] = 1;\n\t\tfor (int i = 1; i <= n; i++) {\n\t\t\tfact[i] =\
    \ fact[i - 1] * i;\n\t\t}\n\t\tfor (int i = 0; i <= n; i++) {\n\t\t\tfactinv[i]\
    \ = fact[i].inv();\n\t\t}\n\t}\n\tT nCr(long long n, long long r) {\n\t\tif (n\
    \ < 0 || r < 0 || n - r < 0) {\n\t\t\treturn 0;\n\t\t}\n\t\treturn fact[n] * factinv[r]\
    \ * factinv[n - r];\n\t}\n\tT nPr(long long n, long long r) {\n\t\tif (n < 0 ||\
    \ r < 0 || n - r < 0) {\n\t\t\treturn 0;\n\t\t}\n\t\treturn fact[n] * factinv[n\
    \ - r];\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: mod_combination.cpp
  requiredBy: []
  timestamp: '2023-11-30 13:56:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: mod_combination.cpp
layout: document
redirect_from:
- /library/mod_combination.cpp
- /library/mod_combination.cpp.html
title: mod_combination.cpp
---
