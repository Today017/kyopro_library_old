---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "ExtGCD, mod\u4E0A\u306E\u9006\u5143, \u4E0D\u5B9A\u4E00\u6B21\
      \u65B9\u7A0B\u5F0F"
    links: []
  bundledCode: "#line 1 \"math/extgcd.cpp\"\n#include <tuple>\n#include <utility>\n\
    \n/**\n * @brief ExtGCD, mod\u4E0A\u306E\u9006\u5143, \u4E0D\u5B9A\u4E00\u6B21\
    \u65B9\u7A0B\u5F0F\n*/\n\nstd::tuple<long long, long long, long long> extgcd(long\
    \ long a, long long b) {\n    if (b == 0) {\n        return {a, 1, 0};\n    }\n\
    \    long long q = a / b, r = a % b;\n    long long g, s, t;\n    std::tie(g,\
    \ s, t) = extgcd(b, r);\n    long long x = t;\n    long long y = s - q * t;\n\
    \    return std::make_tuple(g, x, y);\n}\n\nlong long modinv(long long a, long\
    \ long mod) {\n    long long g, x, y;\n    std::tie(g, x, y) = extgcd(a, mod);\n\
    \    if (g != 1) {\n        return -1;\n    }\n    return x % mod;\n}\n\nstruct\
    \ bezout_equation {\n    long long a, b, c, g;\n    long long X, Y;\n    bezout_equation(long\
    \ long a, long long b, long long c) {\n        if (a < b) {\n            std::swap(a,\
    \ b);\n        }\n        this->a = a;\n        this->b = b;\n        this->c\
    \ = c;\n    }\n    std::tuple<long long, long long, long long> extgcd(long long\
    \ a, long long b) {\n        if (b == 0) {\n            return {a, 1, 0};\n  \
    \      }\n        long long q = a / b, r = a % b;\n        long long g, s, t;\n\
    \        std::tie(g, s, t) = extgcd(b, r);\n        long long x = t;\n       \
    \ long long y = s - q * t;\n        return std::make_tuple(g, x, y);\n    }\n\
    \    bool build() {\n        long long g, X, Y;\n        std::tie(g, X, Y) = extgcd(a,\
    \ b);\n        if (c % g != 0) {\n            return false;\n        }\n     \
    \   this->g = g;\n        this->X = X;\n        this->Y = Y;\n        return true;\n\
    \    }\n    std::pair<long long, long long> general_solution(long long t) {\n\
    \        long long x = b / g * t + X;\n        long long y = -a / g * t + Y;\n\
    \        return std::make_pair(x, y);\n    }\n};\n"
  code: "#include <tuple>\n#include <utility>\n\n/**\n * @brief ExtGCD, mod\u4E0A\u306E\
    \u9006\u5143, \u4E0D\u5B9A\u4E00\u6B21\u65B9\u7A0B\u5F0F\n*/\n\nstd::tuple<long\
    \ long, long long, long long> extgcd(long long a, long long b) {\n    if (b ==\
    \ 0) {\n        return {a, 1, 0};\n    }\n    long long q = a / b, r = a % b;\n\
    \    long long g, s, t;\n    std::tie(g, s, t) = extgcd(b, r);\n    long long\
    \ x = t;\n    long long y = s - q * t;\n    return std::make_tuple(g, x, y);\n\
    }\n\nlong long modinv(long long a, long long mod) {\n    long long g, x, y;\n\
    \    std::tie(g, x, y) = extgcd(a, mod);\n    if (g != 1) {\n        return -1;\n\
    \    }\n    return x % mod;\n}\n\nstruct bezout_equation {\n    long long a, b,\
    \ c, g;\n    long long X, Y;\n    bezout_equation(long long a, long long b, long\
    \ long c) {\n        if (a < b) {\n            std::swap(a, b);\n        }\n \
    \       this->a = a;\n        this->b = b;\n        this->c = c;\n    }\n    std::tuple<long\
    \ long, long long, long long> extgcd(long long a, long long b) {\n        if (b\
    \ == 0) {\n            return {a, 1, 0};\n        }\n        long long q = a /\
    \ b, r = a % b;\n        long long g, s, t;\n        std::tie(g, s, t) = extgcd(b,\
    \ r);\n        long long x = t;\n        long long y = s - q * t;\n        return\
    \ std::make_tuple(g, x, y);\n    }\n    bool build() {\n        long long g, X,\
    \ Y;\n        std::tie(g, X, Y) = extgcd(a, b);\n        if (c % g != 0) {\n \
    \           return false;\n        }\n        this->g = g;\n        this->X =\
    \ X;\n        this->Y = Y;\n        return true;\n    }\n    std::pair<long long,\
    \ long long> general_solution(long long t) {\n        long long x = b / g * t\
    \ + X;\n        long long y = -a / g * t + Y;\n        return std::make_pair(x,\
    \ y);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/extgcd.cpp
  requiredBy: []
  timestamp: '2024-01-25 11:55:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/extgcd.cpp
layout: document
redirect_from:
- /library/math/extgcd.cpp
- /library/math/extgcd.cpp.html
title: "ExtGCD, mod\u4E0A\u306E\u9006\u5143, \u4E0D\u5B9A\u4E00\u6B21\u65B9\u7A0B\u5F0F"
---
