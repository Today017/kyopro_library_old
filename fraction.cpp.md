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
  bundledCode: "#line 1 \"fraction.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nstruct fraction {\n\t__int128_t p, q;\n\t// p/q\n\tfraction(__int128_t\
    \ p = 0, __int128_t q = 1) {\n\t\tthis->p = p;\n\t\tthis->q = q;\n\t}\n\tvoid\
    \ norm() {\n\t\t__int128_t g = gcd(p, q);\n\t\tp /= g;\n\t\tq /= g;\n\t\tif (q\
    \ < 0) {\n\t\t\tp = -p;\n\t\t\tq = -q;\n\t\t}\n\t}\n\tbool operator<(const fraction\
    \ &other) const {\n\t\treturn p * other.q < other.p * q;\n\t}\n\tbool operator<=(const\
    \ fraction &other) const {\n\t\treturn p * other.q <= other.p * q;\n\t}\n\tbool\
    \ operator>(const fraction &other) const {\n\t\treturn p * other.q > other.p *\
    \ q;\n\t}\n\tbool operator>=(const fraction &other) const {\n\t\treturn p * other.q\
    \ >= other.p * q;\n\t}\n\tbool operator==(const fraction &other) const {\n\t\t\
    return p * other.q == other.p * q;\n\t}\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\nstruct fraction {\n\t__int128_t\
    \ p, q;\n\t// p/q\n\tfraction(__int128_t p = 0, __int128_t q = 1) {\n\t\tthis->p\
    \ = p;\n\t\tthis->q = q;\n\t}\n\tvoid norm() {\n\t\t__int128_t g = gcd(p, q);\n\
    \t\tp /= g;\n\t\tq /= g;\n\t\tif (q < 0) {\n\t\t\tp = -p;\n\t\t\tq = -q;\n\t\t\
    }\n\t}\n\tbool operator<(const fraction &other) const {\n\t\treturn p * other.q\
    \ < other.p * q;\n\t}\n\tbool operator<=(const fraction &other) const {\n\t\t\
    return p * other.q <= other.p * q;\n\t}\n\tbool operator>(const fraction &other)\
    \ const {\n\t\treturn p * other.q > other.p * q;\n\t}\n\tbool operator>=(const\
    \ fraction &other) const {\n\t\treturn p * other.q >= other.p * q;\n\t}\n\tbool\
    \ operator==(const fraction &other) const {\n\t\treturn p * other.q == other.p\
    \ * q;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: fraction.cpp
  requiredBy: []
  timestamp: '2023-11-30 13:56:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: fraction.cpp
layout: document
redirect_from:
- /library/fraction.cpp
- /library/fraction.cpp.html
title: fraction.cpp
---
