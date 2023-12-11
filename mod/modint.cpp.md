---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: mod/mod_combination.cpp
    title: Combination
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
    \ Modint\r\n */\r\n\r\ntemplate <unsigned long long MOD>\r\nstruct modint {\r\n\
    \tunsigned long long value;\r\n\tconstexpr modint(const long long x = 0) {\r\n\
    \t\tvalue = x % MOD;\r\n\t}\r\n\tconstexpr modint<MOD> operator+(const modint<MOD>\
    \ other) {\r\n\t\treturn modint<MOD>(*this) += other;\r\n\t}\r\n\tconstexpr modint<MOD>\
    \ operator-(const modint<MOD> other) {\r\n\t\treturn modint<MOD>(*this) -= other;\r\
    \n\t}\r\n\tconstexpr modint<MOD> operator*(const modint<MOD> other) {\r\n\t\t\
    return modint<MOD>(*this) *= other;\r\n\t}\r\n\tconstexpr modint<MOD> operator/(const\
    \ modint<MOD> other) {\r\n\t\treturn modint<MOD>(*this) /= other;\r\n\t}\r\n\t\
    constexpr modint<MOD> &operator+=(const modint<MOD> other) {\r\n\t\tvalue += other.value;\r\
    \n\t\tif (value >= MOD) {\r\n\t\t\tvalue -= MOD;\r\n\t\t}\r\n\t\treturn *this;\r\
    \n\t}\r\n\tconstexpr modint<MOD> &operator-=(const modint<MOD> other) {\r\n\t\t\
    if (value < other.value) {\r\n\t\t\tvalue += MOD;\r\n\t\t}\r\n\t\tvalue -= other.value;\r\
    \n\t\treturn *this;\r\n\t}\r\n\tconstexpr modint<MOD> &operator*=(const modint<MOD>\
    \ other) {\r\n\t\tvalue = value * other.value % MOD;\r\n\t\treturn *this;\r\n\t\
    }\r\n\tconstexpr modint<MOD> &operator/=(modint<MOD> other) {\r\n\t\t(*this) *=\
    \ other.inv();\r\n\t\treturn *this;\r\n\t}\r\n\tconstexpr modint<MOD> pow(long\
    \ long x) {\r\n\t\tmodint<MOD> ret(1), _this(*this);\r\n\t\tfor (; x > 0; x >>=\
    \ 1, _this *= _this) {\r\n\t\t\tif (x & 1) {\r\n\t\t\t\tret *= _this;\r\n\t\t\t\
    }\r\n\t\t}\r\n\t\treturn ret;\r\n\t}\r\n\tconstexpr modint<MOD> inv() {\r\n\t\t\
    return pow(MOD - 2);\r\n\t}\r\n\tconstexpr friend std::ostream &operator<<(ostream\
    \ &os, const modint<MOD> &x) {\r\n\t\treturn os << x.value;\r\n\t}\r\n\tconstexpr\
    \ friend std::istream &operator>>(istream &is, modint<MOD> &x) {\r\n\t\tis >>\
    \ x.value;\r\n\t\tx.value %= MOD;\r\n\t\tif (x.value < 0) {\r\n\t\t\tx.value +=\
    \ MOD;\r\n\t\t}\r\n\t\treturn is;\r\n\t}\r\n};\r\nusing mod998 = modint<998244353>;\r\
    \nusing mod107 = modint<1000000007>;\n"
  code: "#include <iostream>\r\n\r\n/**\r\n * @brief Modint\r\n */\r\n\r\ntemplate\
    \ <unsigned long long MOD>\r\nstruct modint {\r\n\tunsigned long long value;\r\
    \n\tconstexpr modint(const long long x = 0) {\r\n\t\tvalue = x % MOD;\r\n\t}\r\
    \n\tconstexpr modint<MOD> operator+(const modint<MOD> other) {\r\n\t\treturn modint<MOD>(*this)\
    \ += other;\r\n\t}\r\n\tconstexpr modint<MOD> operator-(const modint<MOD> other)\
    \ {\r\n\t\treturn modint<MOD>(*this) -= other;\r\n\t}\r\n\tconstexpr modint<MOD>\
    \ operator*(const modint<MOD> other) {\r\n\t\treturn modint<MOD>(*this) *= other;\r\
    \n\t}\r\n\tconstexpr modint<MOD> operator/(const modint<MOD> other) {\r\n\t\t\
    return modint<MOD>(*this) /= other;\r\n\t}\r\n\tconstexpr modint<MOD> &operator+=(const\
    \ modint<MOD> other) {\r\n\t\tvalue += other.value;\r\n\t\tif (value >= MOD) {\r\
    \n\t\t\tvalue -= MOD;\r\n\t\t}\r\n\t\treturn *this;\r\n\t}\r\n\tconstexpr modint<MOD>\
    \ &operator-=(const modint<MOD> other) {\r\n\t\tif (value < other.value) {\r\n\
    \t\t\tvalue += MOD;\r\n\t\t}\r\n\t\tvalue -= other.value;\r\n\t\treturn *this;\r\
    \n\t}\r\n\tconstexpr modint<MOD> &operator*=(const modint<MOD> other) {\r\n\t\t\
    value = value * other.value % MOD;\r\n\t\treturn *this;\r\n\t}\r\n\tconstexpr\
    \ modint<MOD> &operator/=(modint<MOD> other) {\r\n\t\t(*this) *= other.inv();\r\
    \n\t\treturn *this;\r\n\t}\r\n\tconstexpr modint<MOD> pow(long long x) {\r\n\t\
    \tmodint<MOD> ret(1), _this(*this);\r\n\t\tfor (; x > 0; x >>= 1, _this *= _this)\
    \ {\r\n\t\t\tif (x & 1) {\r\n\t\t\t\tret *= _this;\r\n\t\t\t}\r\n\t\t}\r\n\t\t\
    return ret;\r\n\t}\r\n\tconstexpr modint<MOD> inv() {\r\n\t\treturn pow(MOD -\
    \ 2);\r\n\t}\r\n\tconstexpr friend std::ostream &operator<<(ostream &os, const\
    \ modint<MOD> &x) {\r\n\t\treturn os << x.value;\r\n\t}\r\n\tconstexpr friend\
    \ std::istream &operator>>(istream &is, modint<MOD> &x) {\r\n\t\tis >> x.value;\r\
    \n\t\tx.value %= MOD;\r\n\t\tif (x.value < 0) {\r\n\t\t\tx.value += MOD;\r\n\t\
    \t}\r\n\t\treturn is;\r\n\t}\r\n};\r\nusing mod998 = modint<998244353>;\r\nusing\
    \ mod107 = modint<1000000007>;"
  dependsOn: []
  isVerificationFile: false
  path: mod/modint.cpp
  requiredBy:
  - string/rolling_hash.cpp
  - mod/mod_combination.cpp
  timestamp: '2023-12-11 19:09:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: mod/modint.cpp
layout: document
redirect_from:
- /library/mod/modint.cpp
- /library/mod/modint.cpp.html
title: Modint
---
