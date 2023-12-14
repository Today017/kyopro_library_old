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
    \ Modint\r\n */\r\n\r\ntemplate <long long MOD>\r\nstruct modint {\r\n\tlong long\
    \ value;\r\n\tmodint(long long x = 0) {\r\n\t\tif (x >= 0) {\r\n\t\t\tvalue =\
    \ x % MOD;\r\n\t\t} else {\r\n\t\t\tvalue = MOD - (-x) % MOD;\r\n\t\t}\r\n\t}\r\
    \n\tmodint operator-() const {\r\n\t\treturn modint(-value);\r\n\t}\r\n\tmodint\
    \ operator+() const {\r\n\t\treturn modint(*this);\r\n\t}\r\n\tmodint &operator+=(const\
    \ modint &other) {\r\n\t\tvalue += other.value;\r\n\t\tif (value >= MOD) {\r\n\
    \t\t\tvalue -= MOD;\r\n\t\t}\r\n\t\treturn *this;\r\n\t}\r\n\tmodint &operator-=(const\
    \ modint &other) {\r\n\t\tvalue += MOD - other.value;\r\n\t\tif (value >= MOD)\
    \ {\r\n\t\t\tvalue -= MOD;\r\n\t\t}\r\n\t\treturn *this;\r\n\t}\r\n\tmodint &operator*=(const\
    \ modint other) {\r\n\t\tvalue = value * other.value % MOD;\r\n\t\treturn *this;\r\
    \n\t}\r\n\tmodint &operator/=(modint other) {\r\n\t\t(*this) *= other.inv();\r\
    \n\t\treturn *this;\r\n\t}\r\n\tmodint operator+(const modint &other) const {\r\
    \n\t\treturn modint(*this) += other;\r\n\t}\r\n\tmodint operator-(const modint\
    \ &other) const {\r\n\t\treturn modint(*this) -= other;\r\n\t}\r\n\tmodint operator*(const\
    \ modint &other) const {\r\n\t\treturn modint(*this) *= other;\r\n\t}\r\n\tmodint\
    \ operator/(const modint &other) const {\r\n\t\treturn modint(*this) /= other;\r\
    \n\t}\r\n\tmodint pow(long long x) const {\r\n\t\tmodint ret(1), mul(value);\r\
    \n\t\twhile (x > 0) {\r\n\t\t\tif (x % 2 == 1) {\r\n\t\t\t\tret *= mul;\r\n\t\t\
    \t}\r\n\t\t\tmul *= mul;\r\n\t\t\tx /= 2;\r\n\t\t}\r\n\t\treturn ret;\r\n\t}\r\
    \n\tmodint inv() const {\r\n\t\treturn pow(MOD - 2);\r\n\t}\r\n\tbool operator==(const\
    \ modint &other) const {\r\n\t\treturn value == other.value;\r\n\t}\r\n\tbool\
    \ operator!=(const modint &other) const {\r\n\t\treturn value != other.value;\r\
    \n\t}\r\n\tfriend std::ostream &operator<<(std::ostream &os, const modint &x)\
    \ {\r\n\t\treturn os << x.value;\r\n\t}\r\n\tfriend std::istream &operator>>(std::istream\
    \ &is, modint &x) {\r\n\t\tlong long v;\r\n\t\tis >> v;\r\n\t\tx = modint<MOD>(v);\r\
    \n\t\treturn is;\r\n\t}\r\n};\r\nusing mod998 = modint<998244353>;\r\nusing mod107\
    \ = modint<1000000007>;\r\n#line 2 \"mod/mod_combination.cpp\"\n#include <vector>\n\
    \n/**\n * @brief Combination\n */\n\ntemplate <typename T>\nstruct combination\
    \ {\n\tstd::vector<T> fact, factinv;\n\tcombination(int n) {\n\t\tfact.resize(n\
    \ + 1);\n\t\tfactinv.resize(n + 1);\n\t\tfact[0] = 1;\n\t\tfor (int i = 1; i <=\
    \ n; i++) {\n\t\t\tfact[i] = fact[i - 1] * i;\n\t\t}\n\t\tfor (int i = 0; i <=\
    \ n; i++) {\n\t\t\tfactinv[i] = fact[i].inv();\n\t\t}\n\t}\n\tT nCr(long long\
    \ n, long long r) {\n\t\tif (n < 0 || r < 0 || n - r < 0) {\n\t\t\treturn 0;\n\
    \t\t}\n\t\treturn fact[n] * factinv[r] * factinv[n - r];\n\t}\n\tT nPr(long long\
    \ n, long long r) {\n\t\tif (n < 0 || r < 0 || n - r < 0) {\n\t\t\treturn 0;\n\
    \t\t}\n\t\treturn fact[n] * factinv[n - r];\n\t}\n};\n"
  code: "#include \"mod/modint.cpp\"\n#include <vector>\n\n/**\n * @brief Combination\n\
    \ */\n\ntemplate <typename T>\nstruct combination {\n\tstd::vector<T> fact, factinv;\n\
    \tcombination(int n) {\n\t\tfact.resize(n + 1);\n\t\tfactinv.resize(n + 1);\n\t\
    \tfact[0] = 1;\n\t\tfor (int i = 1; i <= n; i++) {\n\t\t\tfact[i] = fact[i - 1]\
    \ * i;\n\t\t}\n\t\tfor (int i = 0; i <= n; i++) {\n\t\t\tfactinv[i] = fact[i].inv();\n\
    \t\t}\n\t}\n\tT nCr(long long n, long long r) {\n\t\tif (n < 0 || r < 0 || n -\
    \ r < 0) {\n\t\t\treturn 0;\n\t\t}\n\t\treturn fact[n] * factinv[r] * factinv[n\
    \ - r];\n\t}\n\tT nPr(long long n, long long r) {\n\t\tif (n < 0 || r < 0 || n\
    \ - r < 0) {\n\t\t\treturn 0;\n\t\t}\n\t\treturn fact[n] * factinv[n - r];\n\t\
    }\n};"
  dependsOn:
  - mod/modint.cpp
  isVerificationFile: false
  path: mod/mod_combination.cpp
  requiredBy: []
  timestamp: '2023-12-15 01:46:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: mod/mod_combination.cpp
layout: document
redirect_from:
- /library/mod/mod_combination.cpp
- /library/mod/mod_combination.cpp.html
title: Combination
---
