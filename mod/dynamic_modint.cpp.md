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
    \n * @brief Dynamic Modint\r\n */\r\n\r\nstruct dynamic_modint {\r\n\tlong long\
    \ value;\r\n\tstatic long long mod;\r\n\tstatic void set_mod(long long x) {\r\n\
    \t\tmod = x;\r\n\t}\r\n\tstatic long long get_mod() {\r\n\t\treturn mod;\r\n\t\
    }\r\n\tdynamic_modint(long long x = 0) {\r\n\t\tif (x >= 0) {\r\n\t\t\tvalue =\
    \ x % mod;\r\n\t\t} else {\r\n\t\t\tvalue = mod - (-x) % mod;\r\n\t\t}\r\n\t}\r\
    \n\tdynamic_modint operator-() const {\r\n\t\treturn dynamic_modint(-value);\r\
    \n\t}\r\n\tdynamic_modint operator+() const {\r\n\t\treturn dynamic_modint(*this);\r\
    \n\t}\r\n\tdynamic_modint &operator+=(const dynamic_modint &other) {\r\n\t\tvalue\
    \ += other.value;\r\n\t\tif (value >= mod) {\r\n\t\t\tvalue -= mod;\r\n\t\t}\r\
    \n\t\treturn *this;\r\n\t}\r\n\tdynamic_modint &operator-=(const dynamic_modint\
    \ &other) {\r\n\t\tvalue += mod - other.value;\r\n\t\tif (value >= mod) {\r\n\t\
    \t\tvalue -= mod;\r\n\t\t}\r\n\t\treturn *this;\r\n\t}\r\n\tdynamic_modint &operator*=(const\
    \ dynamic_modint other) {\r\n\t\tvalue = value * other.value % mod;\r\n\t\treturn\
    \ *this;\r\n\t}\r\n\tdynamic_modint &operator/=(dynamic_modint other) {\r\n\t\t\
    (*this) *= other.inv();\r\n\t\treturn *this;\r\n\t}\r\n\tdynamic_modint operator+(const\
    \ dynamic_modint &other) const {\r\n\t\treturn dynamic_modint(*this) += other;\r\
    \n\t}\r\n\tdynamic_modint operator-(const dynamic_modint &other) const {\r\n\t\
    \treturn dynamic_modint(*this) -= other;\r\n\t}\r\n\tdynamic_modint operator*(const\
    \ dynamic_modint &other) const {\r\n\t\treturn dynamic_modint(*this) *= other;\r\
    \n\t}\r\n\tdynamic_modint operator/(const dynamic_modint &other) const {\r\n\t\
    \treturn dynamic_modint(*this) /= other;\r\n\t}\r\n\tdynamic_modint pow(long long\
    \ x) const {\r\n\t\tdynamic_modint ret(1), mul(value);\r\n\t\twhile (x > 0) {\r\
    \n\t\t\tif (x % 2 == 1) {\r\n\t\t\t\tret *= mul;\r\n\t\t\t}\r\n\t\t\tmul *= mul;\r\
    \n\t\t\tx /= 2;\r\n\t\t}\r\n\t\treturn ret;\r\n\t}\r\n\tdynamic_modint inv() const\
    \ {\r\n\t\treturn pow(mod - 2);\r\n\t}\r\n\tbool operator==(const dynamic_modint\
    \ &other) const {\r\n\t\treturn value == other.value;\r\n\t}\r\n\tbool operator!=(const\
    \ dynamic_modint &other) const {\r\n\t\treturn value != other.value;\r\n\t}\r\n\
    \tfriend std::ostream &operator<<(std::ostream &os, const dynamic_modint &x) {\r\
    \n\t\treturn os << x.value;\r\n\t}\r\n\tfriend std::istream &operator>>(std::istream\
    \ &is, dynamic_modint &x) {\r\n\t\tlong long v;\r\n\t\tis >> v;\r\n\t\tx = dynamic_modint(v);\r\
    \n\t\treturn is;\r\n\t}\r\n};\r\nlong long dynamic_modint::mod = 998244353;\r\n"
  code: "#include <iostream>\r\n\r\n/**\r\n * @brief Dynamic Modint\r\n */\r\n\r\n\
    struct dynamic_modint {\r\n\tlong long value;\r\n\tstatic long long mod;\r\n\t\
    static void set_mod(long long x) {\r\n\t\tmod = x;\r\n\t}\r\n\tstatic long long\
    \ get_mod() {\r\n\t\treturn mod;\r\n\t}\r\n\tdynamic_modint(long long x = 0) {\r\
    \n\t\tif (x >= 0) {\r\n\t\t\tvalue = x % mod;\r\n\t\t} else {\r\n\t\t\tvalue =\
    \ mod - (-x) % mod;\r\n\t\t}\r\n\t}\r\n\tdynamic_modint operator-() const {\r\n\
    \t\treturn dynamic_modint(-value);\r\n\t}\r\n\tdynamic_modint operator+() const\
    \ {\r\n\t\treturn dynamic_modint(*this);\r\n\t}\r\n\tdynamic_modint &operator+=(const\
    \ dynamic_modint &other) {\r\n\t\tvalue += other.value;\r\n\t\tif (value >= mod)\
    \ {\r\n\t\t\tvalue -= mod;\r\n\t\t}\r\n\t\treturn *this;\r\n\t}\r\n\tdynamic_modint\
    \ &operator-=(const dynamic_modint &other) {\r\n\t\tvalue += mod - other.value;\r\
    \n\t\tif (value >= mod) {\r\n\t\t\tvalue -= mod;\r\n\t\t}\r\n\t\treturn *this;\r\
    \n\t}\r\n\tdynamic_modint &operator*=(const dynamic_modint other) {\r\n\t\tvalue\
    \ = value * other.value % mod;\r\n\t\treturn *this;\r\n\t}\r\n\tdynamic_modint\
    \ &operator/=(dynamic_modint other) {\r\n\t\t(*this) *= other.inv();\r\n\t\treturn\
    \ *this;\r\n\t}\r\n\tdynamic_modint operator+(const dynamic_modint &other) const\
    \ {\r\n\t\treturn dynamic_modint(*this) += other;\r\n\t}\r\n\tdynamic_modint operator-(const\
    \ dynamic_modint &other) const {\r\n\t\treturn dynamic_modint(*this) -= other;\r\
    \n\t}\r\n\tdynamic_modint operator*(const dynamic_modint &other) const {\r\n\t\
    \treturn dynamic_modint(*this) *= other;\r\n\t}\r\n\tdynamic_modint operator/(const\
    \ dynamic_modint &other) const {\r\n\t\treturn dynamic_modint(*this) /= other;\r\
    \n\t}\r\n\tdynamic_modint pow(long long x) const {\r\n\t\tdynamic_modint ret(1),\
    \ mul(value);\r\n\t\twhile (x > 0) {\r\n\t\t\tif (x % 2 == 1) {\r\n\t\t\t\tret\
    \ *= mul;\r\n\t\t\t}\r\n\t\t\tmul *= mul;\r\n\t\t\tx /= 2;\r\n\t\t}\r\n\t\treturn\
    \ ret;\r\n\t}\r\n\tdynamic_modint inv() const {\r\n\t\treturn pow(mod - 2);\r\n\
    \t}\r\n\tbool operator==(const dynamic_modint &other) const {\r\n\t\treturn value\
    \ == other.value;\r\n\t}\r\n\tbool operator!=(const dynamic_modint &other) const\
    \ {\r\n\t\treturn value != other.value;\r\n\t}\r\n\tfriend std::ostream &operator<<(std::ostream\
    \ &os, const dynamic_modint &x) {\r\n\t\treturn os << x.value;\r\n\t}\r\n\tfriend\
    \ std::istream &operator>>(std::istream &is, dynamic_modint &x) {\r\n\t\tlong\
    \ long v;\r\n\t\tis >> v;\r\n\t\tx = dynamic_modint(v);\r\n\t\treturn is;\r\n\t\
    }\r\n};\r\nlong long dynamic_modint::mod = 998244353;\r\n"
  dependsOn: []
  isVerificationFile: false
  path: mod/dynamic_modint.cpp
  requiredBy: []
  timestamp: '2023-12-27 22:35:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: mod/dynamic_modint.cpp
layout: document
redirect_from:
- /library/mod/dynamic_modint.cpp
- /library/mod/dynamic_modint.cpp.html
title: Dynamic Modint
---
