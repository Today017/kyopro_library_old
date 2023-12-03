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
  bundledCode: "#line 1 \"math/extgcd.cpp\"\ntuple<long long, long long, long long>\
    \ extgcd(long long a, long long b) {\n\tif (b == 0) {\n\t\treturn {a, 1, 0};\n\
    \t}\n\tlong long q = a / b, r = a % b;\n\tlong long g, s, t;\n\ttie(g, s, t) =\
    \ extgcd(b, r);\n\tlong long x = t;\n\tlong long y = s - q * t;\n\treturn make_tuple(g,\
    \ x, y);\n}\n\nlong long modinv(long long a, long long mod) {\n\tlong long g,\
    \ x, y;\n\ttie(g, x, y) = extgcd(a, mod);\n\tif (g != 1) {\n\t\treturn -1;\n\t\
    }\n\treturn x % mod;\n}\n\nstruct bezout_equation {\n\tlong long a, b, c, g;\n\
    \tlong long X, Y;\n\tbezout_equation(long long a, long long b, long long c) {\n\
    \t\tif (a < b) {\n\t\t\tswap(a, b);\n\t\t}\n\t\tthis->a = a;\n\t\tthis->b = b;\n\
    \t\tthis->c = c;\n\t}\n\ttuple<long long, long long, long long> extgcd(long long\
    \ a, long long b) {\n\t\tif (b == 0) {\n\t\t\treturn {a, 1, 0};\n\t\t}\n\t\tlong\
    \ long q = a / b, r = a % b;\n\t\tlong long g, s, t;\n\t\ttie(g, s, t) = extgcd(b,\
    \ r);\n\t\tlong long x = t;\n\t\tlong long y = s - q * t;\n\t\treturn make_tuple(g,\
    \ x, y);\n\t}\n\tbool build() {\n\t\tlong long g, X, Y;\n\t\ttie(g, X, Y) = extgcd(a,\
    \ b);\n\t\tif (c % g != 0) {\n\t\t\treturn false;\n\t\t}\n\t\tthis->g = g;\n\t\
    \tthis->X = X;\n\t\tthis->Y = Y;\n\t\treturn true;\n\t}\n\tpair<long long, long\
    \ long> general_solution(long long t) {\n\t\tlong long x = b / g * t + X;\n\t\t\
    long long y = -a / g * t + Y;\n\t\treturn make_pair(x, y);\n\t}\n};\n"
  code: "tuple<long long, long long, long long> extgcd(long long a, long long b) {\n\
    \tif (b == 0) {\n\t\treturn {a, 1, 0};\n\t}\n\tlong long q = a / b, r = a % b;\n\
    \tlong long g, s, t;\n\ttie(g, s, t) = extgcd(b, r);\n\tlong long x = t;\n\tlong\
    \ long y = s - q * t;\n\treturn make_tuple(g, x, y);\n}\n\nlong long modinv(long\
    \ long a, long long mod) {\n\tlong long g, x, y;\n\ttie(g, x, y) = extgcd(a, mod);\n\
    \tif (g != 1) {\n\t\treturn -1;\n\t}\n\treturn x % mod;\n}\n\nstruct bezout_equation\
    \ {\n\tlong long a, b, c, g;\n\tlong long X, Y;\n\tbezout_equation(long long a,\
    \ long long b, long long c) {\n\t\tif (a < b) {\n\t\t\tswap(a, b);\n\t\t}\n\t\t\
    this->a = a;\n\t\tthis->b = b;\n\t\tthis->c = c;\n\t}\n\ttuple<long long, long\
    \ long, long long> extgcd(long long a, long long b) {\n\t\tif (b == 0) {\n\t\t\
    \treturn {a, 1, 0};\n\t\t}\n\t\tlong long q = a / b, r = a % b;\n\t\tlong long\
    \ g, s, t;\n\t\ttie(g, s, t) = extgcd(b, r);\n\t\tlong long x = t;\n\t\tlong long\
    \ y = s - q * t;\n\t\treturn make_tuple(g, x, y);\n\t}\n\tbool build() {\n\t\t\
    long long g, X, Y;\n\t\ttie(g, X, Y) = extgcd(a, b);\n\t\tif (c % g != 0) {\n\t\
    \t\treturn false;\n\t\t}\n\t\tthis->g = g;\n\t\tthis->X = X;\n\t\tthis->Y = Y;\n\
    \t\treturn true;\n\t}\n\tpair<long long, long long> general_solution(long long\
    \ t) {\n\t\tlong long x = b / g * t + X;\n\t\tlong long y = -a / g * t + Y;\n\t\
    \treturn make_pair(x, y);\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/extgcd.cpp
  requiredBy: []
  timestamp: '2023-12-04 01:54:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/extgcd.cpp
layout: document
redirect_from:
- /library/math/extgcd.cpp
- /library/math/extgcd.cpp.html
title: math/extgcd.cpp
---
