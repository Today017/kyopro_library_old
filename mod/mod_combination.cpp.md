---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: mod/modint.cpp
    title: mod/modint.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Combination
    links: []
  bundledCode: "#line 1 \"mod/modint.cpp\"\ntemplate <unsigned long long MOD>\r\n\
    struct modint {\r\n\tunsigned long long value;\r\n\tconstexpr modint(const long\
    \ long x = 0) {\r\n\t\tvalue = x % MOD;\r\n\t}\r\n\tconstexpr modint<MOD> operator+(const\
    \ modint<MOD> other) {\r\n\t\treturn modint<MOD>(*this) += other;\r\n\t}\r\n\t\
    constexpr modint<MOD> operator-(const modint<MOD> other) {\r\n\t\treturn modint<MOD>(*this)\
    \ -= other;\r\n\t}\r\n\tconstexpr modint<MOD> operator*(const modint<MOD> other)\
    \ {\r\n\t\treturn modint<MOD>(*this) *= other;\r\n\t}\r\n\tconstexpr modint<MOD>\
    \ operator/(const modint<MOD> other) {\r\n\t\treturn modint<MOD>(*this) /= other;\r\
    \n\t}\r\n\tconstexpr modint<MOD> &operator+=(const modint<MOD> other) {\r\n\t\t\
    value += other.value;\r\n\t\tif (value >= MOD) {\r\n\t\t\tvalue -= MOD;\r\n\t\t\
    }\r\n\t\treturn *this;\r\n\t}\r\n\tconstexpr modint<MOD> &operator-=(const modint<MOD>\
    \ other) {\r\n\t\tif (value < other.value) {\r\n\t\t\tvalue += MOD;\r\n\t\t}\r\
    \n\t\tvalue -= other.value;\r\n\t\treturn *this;\r\n\t}\r\n\tconstexpr modint<MOD>\
    \ &operator*=(const modint<MOD> other) {\r\n\t\tvalue = value * other.value %\
    \ MOD;\r\n\t\treturn *this;\r\n\t}\r\n\tconstexpr modint<MOD> &operator/=(modint<MOD>\
    \ other) {\r\n\t\t(*this) *= other.inv();\r\n\t\treturn *this;\r\n\t}\r\n\tconstexpr\
    \ modint<MOD> pow(long long x) {\r\n\t\tmodint<MOD> ret(1), _this(*this);\r\n\t\
    \tfor (; x; x >>= 1, _this *= _this) {\r\n\t\t\tif (x & 1) {\r\n\t\t\t\tret *=\
    \ _this;\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn ret;\r\n\t}\r\n\tconstexpr modint<MOD>\
    \ inv() {\r\n\t\treturn pow(MOD - 2);\r\n\t}\r\n\tconstexpr friend ostream &operator<<(ostream\
    \ &os, const modint<MOD> &x) {\r\n\t\treturn os << x.value;\r\n\t}\r\n\tconstexpr\
    \ friend istream &operator>>(istream &is, modint<MOD> &x) {\r\n\t\tis >> x.value;\r\
    \n\t\tx.value %= MOD;\r\n\t\tif (x.value < 0) {\r\n\t\t\tx.value += MOD;\r\n\t\
    \t}\r\n\t\treturn is;\r\n\t}\r\n};\r\nusing mod998 = modint<998244353>;\r\nusing\
    \ mod107 = modint<1000000007>;\n#line 2 \"mod/mod_combination.cpp\"\n\n/**\n *\
    \ @brief Combination\n */\n\ntemplate <typename T>\nstruct combination {\n\tvector<T>\
    \ fact, factinv;\n\tcombination(int n) {\n\t\tfact.resize(n + 1);\n\t\tfactinv.resize(n\
    \ + 1);\n\t\tfact[0] = 1;\n\t\tfor (int i = 1; i <= n; i++) {\n\t\t\tfact[i] =\
    \ fact[i - 1] * i;\n\t\t}\n\t\tfor (int i = 0; i <= n; i++) {\n\t\t\tfactinv[i]\
    \ = fact[i].inv();\n\t\t}\n\t}\n\tT nCr(long long n, long long r) {\n\t\tif (n\
    \ < 0 || r < 0 || n - r < 0) {\n\t\t\treturn 0;\n\t\t}\n\t\treturn fact[n] * factinv[r]\
    \ * factinv[n - r];\n\t}\n\tT nPr(long long n, long long r) {\n\t\tif (n < 0 ||\
    \ r < 0 || n - r < 0) {\n\t\t\treturn 0;\n\t\t}\n\t\treturn fact[n] * factinv[n\
    \ - r];\n\t}\n};\n"
  code: "#include \"mod/modint.cpp\"\n\n/**\n * @brief Combination\n */\n\ntemplate\
    \ <typename T>\nstruct combination {\n\tvector<T> fact, factinv;\n\tcombination(int\
    \ n) {\n\t\tfact.resize(n + 1);\n\t\tfactinv.resize(n + 1);\n\t\tfact[0] = 1;\n\
    \t\tfor (int i = 1; i <= n; i++) {\n\t\t\tfact[i] = fact[i - 1] * i;\n\t\t}\n\t\
    \tfor (int i = 0; i <= n; i++) {\n\t\t\tfactinv[i] = fact[i].inv();\n\t\t}\n\t\
    }\n\tT nCr(long long n, long long r) {\n\t\tif (n < 0 || r < 0 || n - r < 0) {\n\
    \t\t\treturn 0;\n\t\t}\n\t\treturn fact[n] * factinv[r] * factinv[n - r];\n\t\
    }\n\tT nPr(long long n, long long r) {\n\t\tif (n < 0 || r < 0 || n - r < 0) {\n\
    \t\t\treturn 0;\n\t\t}\n\t\treturn fact[n] * factinv[n - r];\n\t}\n};"
  dependsOn:
  - mod/modint.cpp
  isVerificationFile: false
  path: mod/mod_combination.cpp
  requiredBy: []
  timestamp: '2023-12-06 08:26:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: mod/mod_combination.cpp
layout: document
redirect_from:
- /library/mod/mod_combination.cpp
- /library/mod/mod_combination.cpp.html
title: Combination
---
