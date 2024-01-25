---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: string/rolling_hash.cpp
    title: Rolling Hash
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Modint
    links: []
  bundledCode: "#line 1 \"mod/modint.cpp\"\n#include <iostream>\r\n\r\n/**\r\n * @brief\
    \ Modint\r\n */\r\n\r\ntemplate <long long MOD>\r\nstruct modint {\r\n    long\
    \ long value;\r\n    modint(long long x = 0) {\r\n        if (x >= 0) {\r\n  \
    \          value = x % MOD;\r\n        } else {\r\n            value = MOD - (-x)\
    \ % MOD;\r\n        }\r\n    }\r\n    modint operator-() const {\r\n        return\
    \ modint(-value);\r\n    }\r\n    modint operator+() const {\r\n        return\
    \ modint(*this);\r\n    }\r\n    modint &operator+=(const modint &other) {\r\n\
    \        value += other.value;\r\n        if (value >= MOD) {\r\n            value\
    \ -= MOD;\r\n        }\r\n        return *this;\r\n    }\r\n    modint &operator-=(const\
    \ modint &other) {\r\n        value += MOD - other.value;\r\n        if (value\
    \ >= MOD) {\r\n            value -= MOD;\r\n        }\r\n        return *this;\r\
    \n    }\r\n    modint &operator*=(const modint other) {\r\n        value = value\
    \ * other.value % MOD;\r\n        return *this;\r\n    }\r\n    modint &operator/=(modint\
    \ other) {\r\n        (*this) *= other.inv();\r\n        return *this;\r\n   \
    \ }\r\n    modint operator+(const modint &other) const {\r\n        return modint(*this)\
    \ += other;\r\n    }\r\n    modint operator-(const modint &other) const {\r\n\
    \        return modint(*this) -= other;\r\n    }\r\n    modint operator*(const\
    \ modint &other) const {\r\n        return modint(*this) *= other;\r\n    }\r\n\
    \    modint operator/(const modint &other) const {\r\n        return modint(*this)\
    \ /= other;\r\n    }\r\n    modint pow(long long x) const {\r\n        modint\
    \ ret(1), mul(value);\r\n        while (x > 0) {\r\n            if (x % 2 == 1)\
    \ {\r\n                ret *= mul;\r\n            }\r\n            mul *= mul;\r\
    \n            x /= 2;\r\n        }\r\n        return ret;\r\n    }\r\n    modint\
    \ inv() const {\r\n        return pow(MOD - 2);\r\n    }\r\n    bool operator==(const\
    \ modint &other) const {\r\n        return value == other.value;\r\n    }\r\n\
    \    bool operator!=(const modint &other) const {\r\n        return value != other.value;\r\
    \n    }\r\n    friend std::ostream &operator<<(std::ostream &os, const modint\
    \ &x) {\r\n        return os << x.value;\r\n    }\r\n    friend std::istream &operator>>(std::istream\
    \ &is, modint &x) {\r\n        long long v;\r\n        is >> v;\r\n        x =\
    \ modint<MOD>(v);\r\n        return is;\r\n    }\r\n};\r\nusing mod998 = modint<998244353>;\r\
    \nusing mod107 = modint<1000000007>;\r\n"
  code: "#include <iostream>\r\n\r\n/**\r\n * @brief Modint\r\n */\r\n\r\ntemplate\
    \ <long long MOD>\r\nstruct modint {\r\n    long long value;\r\n    modint(long\
    \ long x = 0) {\r\n        if (x >= 0) {\r\n            value = x % MOD;\r\n \
    \       } else {\r\n            value = MOD - (-x) % MOD;\r\n        }\r\n   \
    \ }\r\n    modint operator-() const {\r\n        return modint(-value);\r\n  \
    \  }\r\n    modint operator+() const {\r\n        return modint(*this);\r\n  \
    \  }\r\n    modint &operator+=(const modint &other) {\r\n        value += other.value;\r\
    \n        if (value >= MOD) {\r\n            value -= MOD;\r\n        }\r\n  \
    \      return *this;\r\n    }\r\n    modint &operator-=(const modint &other) {\r\
    \n        value += MOD - other.value;\r\n        if (value >= MOD) {\r\n     \
    \       value -= MOD;\r\n        }\r\n        return *this;\r\n    }\r\n    modint\
    \ &operator*=(const modint other) {\r\n        value = value * other.value % MOD;\r\
    \n        return *this;\r\n    }\r\n    modint &operator/=(modint other) {\r\n\
    \        (*this) *= other.inv();\r\n        return *this;\r\n    }\r\n    modint\
    \ operator+(const modint &other) const {\r\n        return modint(*this) += other;\r\
    \n    }\r\n    modint operator-(const modint &other) const {\r\n        return\
    \ modint(*this) -= other;\r\n    }\r\n    modint operator*(const modint &other)\
    \ const {\r\n        return modint(*this) *= other;\r\n    }\r\n    modint operator/(const\
    \ modint &other) const {\r\n        return modint(*this) /= other;\r\n    }\r\n\
    \    modint pow(long long x) const {\r\n        modint ret(1), mul(value);\r\n\
    \        while (x > 0) {\r\n            if (x % 2 == 1) {\r\n                ret\
    \ *= mul;\r\n            }\r\n            mul *= mul;\r\n            x /= 2;\r\
    \n        }\r\n        return ret;\r\n    }\r\n    modint inv() const {\r\n  \
    \      return pow(MOD - 2);\r\n    }\r\n    bool operator==(const modint &other)\
    \ const {\r\n        return value == other.value;\r\n    }\r\n    bool operator!=(const\
    \ modint &other) const {\r\n        return value != other.value;\r\n    }\r\n\
    \    friend std::ostream &operator<<(std::ostream &os, const modint &x) {\r\n\
    \        return os << x.value;\r\n    }\r\n    friend std::istream &operator>>(std::istream\
    \ &is, modint &x) {\r\n        long long v;\r\n        is >> v;\r\n        x =\
    \ modint<MOD>(v);\r\n        return is;\r\n    }\r\n};\r\nusing mod998 = modint<998244353>;\r\
    \nusing mod107 = modint<1000000007>;\r\n"
  dependsOn: []
  isVerificationFile: false
  path: mod/modint.cpp
  requiredBy:
  - string/rolling_hash.cpp
  timestamp: '2024-01-25 11:55:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: mod/modint.cpp
layout: document
redirect_from:
- /library/mod/modint.cpp
- /library/mod/modint.cpp.html
title: Modint
---
