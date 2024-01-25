---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Dynamic Modint
    links: []
  bundledCode: "#line 1 \"mod/dynamic_modint.cpp\"\n#include <iostream>\r\n\r\n/**\r\
    \n * @brief Dynamic Modint\r\n */\r\n\r\nstruct dynamic_modint {\r\n    long long\
    \ value;\r\n    static long long mod;\r\n    static void set_mod(long long x)\
    \ {\r\n        mod = x;\r\n    }\r\n    static long long get_mod() {\r\n     \
    \   return mod;\r\n    }\r\n    dynamic_modint(long long x = 0) {\r\n        if\
    \ (x >= 0) {\r\n            value = x % mod;\r\n        } else {\r\n         \
    \   value = mod - (-x) % mod;\r\n        }\r\n    }\r\n    dynamic_modint operator-()\
    \ const {\r\n        return dynamic_modint(-value);\r\n    }\r\n    dynamic_modint\
    \ operator+() const {\r\n        return dynamic_modint(*this);\r\n    }\r\n  \
    \  dynamic_modint &operator+=(const dynamic_modint &other) {\r\n        value\
    \ += other.value;\r\n        if (value >= mod) {\r\n            value -= mod;\r\
    \n        }\r\n        return *this;\r\n    }\r\n    dynamic_modint &operator-=(const\
    \ dynamic_modint &other) {\r\n        value += mod - other.value;\r\n        if\
    \ (value >= mod) {\r\n            value -= mod;\r\n        }\r\n        return\
    \ *this;\r\n    }\r\n    dynamic_modint &operator*=(const dynamic_modint other)\
    \ {\r\n        value = value * other.value % mod;\r\n        return *this;\r\n\
    \    }\r\n    dynamic_modint &operator/=(dynamic_modint other) {\r\n        (*this)\
    \ *= other.inv();\r\n        return *this;\r\n    }\r\n    dynamic_modint operator+(const\
    \ dynamic_modint &other) const {\r\n        return dynamic_modint(*this) += other;\r\
    \n    }\r\n    dynamic_modint operator-(const dynamic_modint &other) const {\r\
    \n        return dynamic_modint(*this) -= other;\r\n    }\r\n    dynamic_modint\
    \ operator*(const dynamic_modint &other) const {\r\n        return dynamic_modint(*this)\
    \ *= other;\r\n    }\r\n    dynamic_modint operator/(const dynamic_modint &other)\
    \ const {\r\n        return dynamic_modint(*this) /= other;\r\n    }\r\n    dynamic_modint\
    \ pow(long long x) const {\r\n        dynamic_modint ret(1), mul(value);\r\n \
    \       while (x > 0) {\r\n            if (x % 2 == 1) {\r\n                ret\
    \ *= mul;\r\n            }\r\n            mul *= mul;\r\n            x /= 2;\r\
    \n        }\r\n        return ret;\r\n    }\r\n    dynamic_modint inv() const\
    \ {\r\n        return pow(mod - 2);\r\n    }\r\n    bool operator==(const dynamic_modint\
    \ &other) const {\r\n        return value == other.value;\r\n    }\r\n    bool\
    \ operator!=(const dynamic_modint &other) const {\r\n        return value != other.value;\r\
    \n    }\r\n    friend std::ostream &operator<<(std::ostream &os, const dynamic_modint\
    \ &x) {\r\n        return os << x.value;\r\n    }\r\n    friend std::istream &operator>>(std::istream\
    \ &is, dynamic_modint &x) {\r\n        long long v;\r\n        is >> v;\r\n  \
    \      x = dynamic_modint(v);\r\n        return is;\r\n    }\r\n};\r\nlong long\
    \ dynamic_modint::mod = 998244353;\r\n"
  code: "#include <iostream>\r\n\r\n/**\r\n * @brief Dynamic Modint\r\n */\r\n\r\n\
    struct dynamic_modint {\r\n    long long value;\r\n    static long long mod;\r\
    \n    static void set_mod(long long x) {\r\n        mod = x;\r\n    }\r\n    static\
    \ long long get_mod() {\r\n        return mod;\r\n    }\r\n    dynamic_modint(long\
    \ long x = 0) {\r\n        if (x >= 0) {\r\n            value = x % mod;\r\n \
    \       } else {\r\n            value = mod - (-x) % mod;\r\n        }\r\n   \
    \ }\r\n    dynamic_modint operator-() const {\r\n        return dynamic_modint(-value);\r\
    \n    }\r\n    dynamic_modint operator+() const {\r\n        return dynamic_modint(*this);\r\
    \n    }\r\n    dynamic_modint &operator+=(const dynamic_modint &other) {\r\n \
    \       value += other.value;\r\n        if (value >= mod) {\r\n            value\
    \ -= mod;\r\n        }\r\n        return *this;\r\n    }\r\n    dynamic_modint\
    \ &operator-=(const dynamic_modint &other) {\r\n        value += mod - other.value;\r\
    \n        if (value >= mod) {\r\n            value -= mod;\r\n        }\r\n  \
    \      return *this;\r\n    }\r\n    dynamic_modint &operator*=(const dynamic_modint\
    \ other) {\r\n        value = value * other.value % mod;\r\n        return *this;\r\
    \n    }\r\n    dynamic_modint &operator/=(dynamic_modint other) {\r\n        (*this)\
    \ *= other.inv();\r\n        return *this;\r\n    }\r\n    dynamic_modint operator+(const\
    \ dynamic_modint &other) const {\r\n        return dynamic_modint(*this) += other;\r\
    \n    }\r\n    dynamic_modint operator-(const dynamic_modint &other) const {\r\
    \n        return dynamic_modint(*this) -= other;\r\n    }\r\n    dynamic_modint\
    \ operator*(const dynamic_modint &other) const {\r\n        return dynamic_modint(*this)\
    \ *= other;\r\n    }\r\n    dynamic_modint operator/(const dynamic_modint &other)\
    \ const {\r\n        return dynamic_modint(*this) /= other;\r\n    }\r\n    dynamic_modint\
    \ pow(long long x) const {\r\n        dynamic_modint ret(1), mul(value);\r\n \
    \       while (x > 0) {\r\n            if (x % 2 == 1) {\r\n                ret\
    \ *= mul;\r\n            }\r\n            mul *= mul;\r\n            x /= 2;\r\
    \n        }\r\n        return ret;\r\n    }\r\n    dynamic_modint inv() const\
    \ {\r\n        return pow(mod - 2);\r\n    }\r\n    bool operator==(const dynamic_modint\
    \ &other) const {\r\n        return value == other.value;\r\n    }\r\n    bool\
    \ operator!=(const dynamic_modint &other) const {\r\n        return value != other.value;\r\
    \n    }\r\n    friend std::ostream &operator<<(std::ostream &os, const dynamic_modint\
    \ &x) {\r\n        return os << x.value;\r\n    }\r\n    friend std::istream &operator>>(std::istream\
    \ &is, dynamic_modint &x) {\r\n        long long v;\r\n        is >> v;\r\n  \
    \      x = dynamic_modint(v);\r\n        return is;\r\n    }\r\n};\r\nlong long\
    \ dynamic_modint::mod = 998244353;\r\n"
  dependsOn: []
  isVerificationFile: false
  path: mod/dynamic_modint.cpp
  requiredBy: []
  timestamp: '2024-01-25 11:55:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: mod/dynamic_modint.cpp
layout: document
redirect_from:
- /library/mod/dynamic_modint.cpp
- /library/mod/dynamic_modint.cpp.html
title: Dynamic Modint
---
