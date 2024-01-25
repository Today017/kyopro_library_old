---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Fraction
    links: []
  bundledCode: "#line 1 \"math/fraction.cpp\"\n#include <numeric>\n\n/**\n * @brief\
    \ Fraction\n */\n\nstruct fraction {\n    __int128_t p, q;\n    fraction(__int128_t\
    \ p = 0, __int128_t q = 1) {\n        this->p = p;\n        this->q = q;\n   \
    \ }\n    void norm() {\n        __int128_t g = std::gcd(p, q);\n        p /= g;\n\
    \        q /= g;\n        if (q < 0) {\n            p = -p;\n            q = -q;\n\
    \        }\n    }\n    bool operator<(const fraction &other) const {\n       \
    \ return p * other.q < other.p * q;\n    }\n    bool operator<=(const fraction\
    \ &other) const {\n        return p * other.q <= other.p * q;\n    }\n    bool\
    \ operator>(const fraction &other) const {\n        return p * other.q > other.p\
    \ * q;\n    }\n    bool operator>=(const fraction &other) const {\n        return\
    \ p * other.q >= other.p * q;\n    }\n    bool operator==(const fraction &other)\
    \ const {\n        return p * other.q == other.p * q;\n    }\n};\n"
  code: "#include <numeric>\n\n/**\n * @brief Fraction\n */\n\nstruct fraction {\n\
    \    __int128_t p, q;\n    fraction(__int128_t p = 0, __int128_t q = 1) {\n  \
    \      this->p = p;\n        this->q = q;\n    }\n    void norm() {\n        __int128_t\
    \ g = std::gcd(p, q);\n        p /= g;\n        q /= g;\n        if (q < 0) {\n\
    \            p = -p;\n            q = -q;\n        }\n    }\n    bool operator<(const\
    \ fraction &other) const {\n        return p * other.q < other.p * q;\n    }\n\
    \    bool operator<=(const fraction &other) const {\n        return p * other.q\
    \ <= other.p * q;\n    }\n    bool operator>(const fraction &other) const {\n\
    \        return p * other.q > other.p * q;\n    }\n    bool operator>=(const fraction\
    \ &other) const {\n        return p * other.q >= other.p * q;\n    }\n    bool\
    \ operator==(const fraction &other) const {\n        return p * other.q == other.p\
    \ * q;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: math/fraction.cpp
  requiredBy: []
  timestamp: '2024-01-25 11:55:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/fraction.cpp
layout: document
redirect_from:
- /library/math/fraction.cpp
- /library/math/fraction.cpp.html
title: Fraction
---
