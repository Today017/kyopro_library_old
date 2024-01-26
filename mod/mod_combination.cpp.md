---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: mod/modint.cpp
    title: Modint
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Combination
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
    \nusing mod107 = modint<1000000007>;\r\n#line 2 \"mod/mod_combination.cpp\"\n\
    #include <vector>\n\n/**\n * @brief Combination\n */\n\ntemplate <typename T>\n\
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
  code: "#include \"mod/modint.cpp\"\n#include <vector>\n\n/**\n * @brief Combination\n\
    \ */\n\ntemplate <typename T>\nstruct combination {\n    std::vector<T> fact,\
    \ factinv;\n    combination(int n) {\n        fact.resize(n + 1);\n        factinv.resize(n\
    \ + 1);\n        fact[0] = 1;\n        for (int i = 1; i <= n; i++) {\n      \
    \      fact[i] = fact[i - 1] * i;\n        }\n        for (int i = 0; i <= n;\
    \ i++) {\n            factinv[i] = fact[i].inv();\n        }\n    }\n    T nCr(long\
    \ long n, long long r) {\n        if (n < 0 || r < 0 || n - r < 0) {\n       \
    \     return 0;\n        }\n        return fact[n] * factinv[r] * factinv[n -\
    \ r];\n    }\n    T nPr(long long n, long long r) {\n        if (n < 0 || r <\
    \ 0 || n - r < 0) {\n            return 0;\n        }\n        return fact[n]\
    \ * factinv[n - r];\n    }\n};\n"
  dependsOn:
  - mod/modint.cpp
  isVerificationFile: false
  path: mod/mod_combination.cpp
  requiredBy: []
  timestamp: '2024-01-26 15:21:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: mod/mod_combination.cpp
layout: document
redirect_from:
- /library/mod/mod_combination.cpp
- /library/mod/mod_combination.cpp.html
title: Combination
---
