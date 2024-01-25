---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Modint
    links: []
  bundledCode: "#line 1 \"mod/mod_combination.cpp\"\n#include <iostream>\n\n/**\n\
    \ * @brief Modint\n */\n\ntemplate <long long MOD>\nstruct modint {\n    long\
    \ long value;\n    modint(long long x = 0) {\n        if (x >= 0) {\n        \
    \    value = x % MOD;\n        } else {\n            value = MOD - (-x) % MOD;\n\
    \        }\n    }\n    modint operator-() const {\n        return modint(-value);\n\
    \    }\n    modint operator+() const {\n        return modint(*this);\n    }\n\
    \    modint &operator+=(const modint &other) {\n        value += other.value;\n\
    \        if (value >= MOD) {\n            value -= MOD;\n        }\n        return\
    \ *this;\n    }\n    modint &operator-=(const modint &other) {\n        value\
    \ += MOD - other.value;\n        if (value >= MOD) {\n            value -= MOD;\n\
    \        }\n        return *this;\n    }\n    modint &operator*=(const modint\
    \ other) {\n        value = value * other.value % MOD;\n        return *this;\n\
    \    }\n    modint &operator/=(modint other) {\n        (*this) *= other.inv();\n\
    \        return *this;\n    }\n    modint operator+(const modint &other) const\
    \ {\n        return modint(*this) += other;\n    }\n    modint operator-(const\
    \ modint &other) const {\n        return modint(*this) -= other;\n    }\n    modint\
    \ operator*(const modint &other) const {\n        return modint(*this) *= other;\n\
    \    }\n    modint operator/(const modint &other) const {\n        return modint(*this)\
    \ /= other;\n    }\n    modint pow(long long x) const {\n        modint ret(1),\
    \ mul(value);\n        while (x > 0) {\n            if (x % 2 == 1) {\n      \
    \          ret *= mul;\n            }\n            mul *= mul;\n            x\
    \ /= 2;\n        }\n        return ret;\n    }\n    modint inv() const {\n   \
    \     return pow(MOD - 2);\n    }\n    bool operator==(const modint &other) const\
    \ {\n        return value == other.value;\n    }\n    bool operator!=(const modint\
    \ &other) const {\n        return value != other.value;\n    }\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const modint &x) {\n        return os << x.value;\n\
    \    }\n    friend std::istream &operator>>(std::istream &is, modint &x) {\n \
    \       long long v;\n        is >> v;\n        x = modint<MOD>(v);\n        return\
    \ is;\n    }\n};\nusing mod998 = modint<998244353>;\nusing mod107 = modint<1000000007>;\n\
    \n#include <vector>\n\n/**\n * @brief Combination\n */\n\ntemplate <typename T>\n\
    struct combination {\n    std::vector<T> fact, factinv;\n    combination(int n)\
    \ {\n        fact.resize(n + 1);\n        factinv.resize(n + 1);\n        fact[0]\
    \ = 1;\n        for (int i = 1; i <= n; i++) {\n            fact[i] = fact[i -\
    \ 1] * i;\n        }\n        for (int i = 0; i <= n; i++) {\n            factinv[i]\
    \ = fact[i].inv();\n        }\n    }\n    T nCr(long long n, long long r) {\n\
    \        if (n < 0 || r < 0 || n - r < 0) {\n            return 0;\n        }\n\
    \        return fact[n] * factinv[r] * factinv[n - r];\n    }\n    T nPr(long\
    \ long n, long long r) {\n        if (n < 0 || r < 0 || n - r < 0) {\n       \
    \     return 0;\n        }\n        return fact[n] * factinv[n - r];\n    }\n\
    };\n"
  code: "#include <iostream>\n\n/**\n * @brief Modint\n */\n\ntemplate <long long\
    \ MOD>\nstruct modint {\n    long long value;\n    modint(long long x = 0) {\n\
    \        if (x >= 0) {\n            value = x % MOD;\n        } else {\n     \
    \       value = MOD - (-x) % MOD;\n        }\n    }\n    modint operator-() const\
    \ {\n        return modint(-value);\n    }\n    modint operator+() const {\n \
    \       return modint(*this);\n    }\n    modint &operator+=(const modint &other)\
    \ {\n        value += other.value;\n        if (value >= MOD) {\n            value\
    \ -= MOD;\n        }\n        return *this;\n    }\n    modint &operator-=(const\
    \ modint &other) {\n        value += MOD - other.value;\n        if (value >=\
    \ MOD) {\n            value -= MOD;\n        }\n        return *this;\n    }\n\
    \    modint &operator*=(const modint other) {\n        value = value * other.value\
    \ % MOD;\n        return *this;\n    }\n    modint &operator/=(modint other) {\n\
    \        (*this) *= other.inv();\n        return *this;\n    }\n    modint operator+(const\
    \ modint &other) const {\n        return modint(*this) += other;\n    }\n    modint\
    \ operator-(const modint &other) const {\n        return modint(*this) -= other;\n\
    \    }\n    modint operator*(const modint &other) const {\n        return modint(*this)\
    \ *= other;\n    }\n    modint operator/(const modint &other) const {\n      \
    \  return modint(*this) /= other;\n    }\n    modint pow(long long x) const {\n\
    \        modint ret(1), mul(value);\n        while (x > 0) {\n            if (x\
    \ % 2 == 1) {\n                ret *= mul;\n            }\n            mul *=\
    \ mul;\n            x /= 2;\n        }\n        return ret;\n    }\n    modint\
    \ inv() const {\n        return pow(MOD - 2);\n    }\n    bool operator==(const\
    \ modint &other) const {\n        return value == other.value;\n    }\n    bool\
    \ operator!=(const modint &other) const {\n        return value != other.value;\n\
    \    }\n    friend std::ostream &operator<<(std::ostream &os, const modint &x)\
    \ {\n        return os << x.value;\n    }\n    friend std::istream &operator>>(std::istream\
    \ &is, modint &x) {\n        long long v;\n        is >> v;\n        x = modint<MOD>(v);\n\
    \        return is;\n    }\n};\nusing mod998 = modint<998244353>;\nusing mod107\
    \ = modint<1000000007>;\n\n#include <vector>\n\n/**\n * @brief Combination\n */\n\
    \ntemplate <typename T>\nstruct combination {\n    std::vector<T> fact, factinv;\n\
    \    combination(int n) {\n        fact.resize(n + 1);\n        factinv.resize(n\
    \ + 1);\n        fact[0] = 1;\n        for (int i = 1; i <= n; i++) {\n      \
    \      fact[i] = fact[i - 1] * i;\n        }\n        for (int i = 0; i <= n;\
    \ i++) {\n            factinv[i] = fact[i].inv();\n        }\n    }\n    T nCr(long\
    \ long n, long long r) {\n        if (n < 0 || r < 0 || n - r < 0) {\n       \
    \     return 0;\n        }\n        return fact[n] * factinv[r] * factinv[n -\
    \ r];\n    }\n    T nPr(long long n, long long r) {\n        if (n < 0 || r <\
    \ 0 || n - r < 0) {\n            return 0;\n        }\n        return fact[n]\
    \ * factinv[n - r];\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: mod/mod_combination.cpp
  requiredBy: []
  timestamp: '2024-01-25 11:55:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: mod/mod_combination.cpp
layout: document
redirect_from:
- /library/mod/mod_combination.cpp
- /library/mod/mod_combination.cpp.html
title: Modint
---
