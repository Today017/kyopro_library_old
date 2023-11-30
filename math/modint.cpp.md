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
  bundledCode: "#line 1 \"math/modint.cpp\"\ntemplate <unsigned long long MOD>\r\n\
    struct modint {\r\n\tunsigned long long value;\r\n\tconstexpr modint(const unsigned\
    \ long long x = 0) {\r\n\t\tvalue = x % MOD;\r\n\t}\r\n\tconstexpr modint raw(const\
    \ unsigned long long x = 0) {\r\n\t\treturn modint(x);\r\n\t}\r\n\tconstexpr modint\
    \ operator+(const modint other) {\r\n\t\treturn modint(*this) += other;\r\n\t\
    }\r\n\tconstexpr modint operator-(const modint other) {\r\n\t\treturn modint(*this)\
    \ -= other;\r\n\t}\r\n\tconstexpr modint operator*(const modint other) {\r\n\t\
    \treturn modint(*this) *= other;\r\n\t}\r\n\tconstexpr modint operator/(const\
    \ modint other) {\r\n\t\treturn modint(*this) /= other;\r\n\t}\r\n\tconstexpr\
    \ modint &operator+=(const modint other) {\r\n\t\tvalue += other.value;\r\n\t\t\
    if (value >= MOD) {\r\n\t\t\tvalue -= MOD;\r\n\t\t}\r\n\t\treturn *this;\r\n\t\
    }\r\n\tconstexpr modint &operator-=(const modint other) {\r\n\t\tif (value < other.value)\
    \ {\r\n\t\t\tvalue += MOD;\r\n\t\t}\r\n\t\tvalue -= other.value;\r\n\t\treturn\
    \ *this;\r\n\t}\r\n\tconstexpr modint &operator*=(const modint other) {\r\n\t\t\
    value = value * other.value % MOD;\r\n\t\treturn *this;\r\n\t}\r\n\tconstexpr\
    \ modint &operator/=(modint other) {\r\n\t\t(*this) *= other.inv();\r\n\t\treturn\
    \ *this;\r\n\t}\r\n\tconstexpr modint pow(long long x) {\r\n\t\tmodint ret(1),\
    \ _this(*this);\r\n\t\tfor (; x; x >>= 1, _this *= _this) {\r\n\t\t\tif (x & 1)\
    \ {\r\n\t\t\t\tret *= _this;\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn ret;\r\n\t}\r\n\
    \tconstexpr modint inv() {\r\n\t\treturn pow(MOD - 2);\r\n\t}\r\n\tfriend ostream\
    \ &operator<<(ostream &os, const modint &x) {\r\n\t\treturn os << x.value;\r\n\
    \t}\r\n\tfriend istream &operator>>(istream &is, modint &x) {\r\n\t\tis >> x.value;\r\
    \n\t\tx.value %= MOD;\r\n\t\tif (x.value < 0) {\r\n\t\t\tx.value += MOD;\r\n\t\
    \t}\r\n\t\treturn is;\r\n\t}\r\n};\r\nusing mod998 = modint<998244353>;\r\nusing\
    \ mod107 = modint<1000000007>;\n"
  code: "template <unsigned long long MOD>\r\nstruct modint {\r\n\tunsigned long long\
    \ value;\r\n\tconstexpr modint(const unsigned long long x = 0) {\r\n\t\tvalue\
    \ = x % MOD;\r\n\t}\r\n\tconstexpr modint raw(const unsigned long long x = 0)\
    \ {\r\n\t\treturn modint(x);\r\n\t}\r\n\tconstexpr modint operator+(const modint\
    \ other) {\r\n\t\treturn modint(*this) += other;\r\n\t}\r\n\tconstexpr modint\
    \ operator-(const modint other) {\r\n\t\treturn modint(*this) -= other;\r\n\t\
    }\r\n\tconstexpr modint operator*(const modint other) {\r\n\t\treturn modint(*this)\
    \ *= other;\r\n\t}\r\n\tconstexpr modint operator/(const modint other) {\r\n\t\
    \treturn modint(*this) /= other;\r\n\t}\r\n\tconstexpr modint &operator+=(const\
    \ modint other) {\r\n\t\tvalue += other.value;\r\n\t\tif (value >= MOD) {\r\n\t\
    \t\tvalue -= MOD;\r\n\t\t}\r\n\t\treturn *this;\r\n\t}\r\n\tconstexpr modint &operator-=(const\
    \ modint other) {\r\n\t\tif (value < other.value) {\r\n\t\t\tvalue += MOD;\r\n\
    \t\t}\r\n\t\tvalue -= other.value;\r\n\t\treturn *this;\r\n\t}\r\n\tconstexpr\
    \ modint &operator*=(const modint other) {\r\n\t\tvalue = value * other.value\
    \ % MOD;\r\n\t\treturn *this;\r\n\t}\r\n\tconstexpr modint &operator/=(modint\
    \ other) {\r\n\t\t(*this) *= other.inv();\r\n\t\treturn *this;\r\n\t}\r\n\tconstexpr\
    \ modint pow(long long x) {\r\n\t\tmodint ret(1), _this(*this);\r\n\t\tfor (;\
    \ x; x >>= 1, _this *= _this) {\r\n\t\t\tif (x & 1) {\r\n\t\t\t\tret *= _this;\r\
    \n\t\t\t}\r\n\t\t}\r\n\t\treturn ret;\r\n\t}\r\n\tconstexpr modint inv() {\r\n\
    \t\treturn pow(MOD - 2);\r\n\t}\r\n\tfriend ostream &operator<<(ostream &os, const\
    \ modint &x) {\r\n\t\treturn os << x.value;\r\n\t}\r\n\tfriend istream &operator>>(istream\
    \ &is, modint &x) {\r\n\t\tis >> x.value;\r\n\t\tx.value %= MOD;\r\n\t\tif (x.value\
    \ < 0) {\r\n\t\t\tx.value += MOD;\r\n\t\t}\r\n\t\treturn is;\r\n\t}\r\n};\r\n\
    using mod998 = modint<998244353>;\r\nusing mod107 = modint<1000000007>;"
  dependsOn: []
  isVerificationFile: false
  path: math/modint.cpp
  requiredBy: []
  timestamp: '2023-12-01 06:34:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/modint.cpp
layout: document
redirect_from:
- /library/math/modint.cpp
- /library/math/modint.cpp.html
title: math/modint.cpp
---
