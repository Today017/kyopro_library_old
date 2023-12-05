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
    document_title: Rolling Hash
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
    \ mod107 = modint<1000000007>;\n#line 2 \"string/rolling_hash.cpp\"\n\n/**\n *\
    \ @brief Rolling Hash\n */\n\nstruct rolling_hash {\n\tusing mint1 = modint<998244353>;\n\
    \tusing mint2 = modint<1000000007>;\n\tusing mint3 = modint<1000000009>;\n\tusing\
    \ mint4 = modint<1000000021>;\n\tusing mint5 = modint<1000000033>;\n\tvector<long\
    \ long> BASE;\n\tvector<mint1> power1, hash1, inv1;\n\tvector<mint2> power2, hash2,\
    \ inv2;\n\tvector<mint3> power3, hash3, inv3;\n\tvector<mint4> power4, hash4,\
    \ inv4;\n\tvector<mint5> power5, hash5, inv5;\n\trolling_hash(string s, vector<long\
    \ long> base = {}) {\n\t\tint n = s.size();\n\t\tmt19937 rng(time(0));\n\t\tBASE.resize(5);\n\
    \t\tif (base.size() != 5) {\n\t\t\tBASE[0] = mint1(rng()).value + 30000;\n\t\t\
    \tBASE[1] = mint2(rng()).value + 30000;\n\t\t\tBASE[2] = mint3(rng()).value +\
    \ 30000;\n\t\t\tBASE[3] = mint4(rng()).value + 30000;\n\t\t\tBASE[4] = mint5(rng()).value\
    \ + 30000;\n\t\t} else {\n\t\t\tBASE = base;\n\t\t}\n\t\tpower1.resize(n + 1);\n\
    \t\thash1.resize(n + 1);\n\t\tinv1.resize(n + 1);\n\t\tpower2.resize(n + 1);\n\
    \t\thash2.resize(n + 1);\n\t\tinv2.resize(n + 1);\n\t\tpower3.resize(n + 1);\n\
    \t\thash3.resize(n + 1);\n\t\tinv3.resize(n + 1);\n\t\tpower4.resize(n + 1);\n\
    \t\thash4.resize(n + 1);\n\t\tinv4.resize(n + 1);\n\t\tpower5.resize(n + 1);\n\
    \t\thash5.resize(n + 1);\n\t\tinv5.resize(n + 1);\n\t\tpower1[0] = 1;\n\t\tinv1[n]\
    \ = mint1(BASE[0]).pow(n).inv();\n\t\tpower2[0] = 1;\n\t\tinv2[n] = mint2(BASE[1]).pow(n).inv();\n\
    \t\tpower3[0] = 1;\n\t\tinv3[n] = mint3(BASE[2]).pow(n).inv();\n\t\tpower4[0]\
    \ = 1;\n\t\tinv4[n] = mint4(BASE[3]).pow(n).inv();\n\t\tpower5[0] = 1;\n\t\tinv5[n]\
    \ = mint5(BASE[4]).pow(n).inv();\n\t\tfor (int i = 0; i < n; i++) {\n\t\t\tint\
    \ num = s[i] - 'A';\n\t\t\tpower1[i + 1] = power1[i] * BASE[0];\n\t\t\tinv1[n\
    \ - i - 1] = inv1[n - i] * BASE[0];\n\t\t\thash1[i + 1] = hash1[i] + power1[i]\
    \ * num;\n\t\t\tpower2[i + 1] = power2[i] * BASE[1];\n\t\t\tinv2[n - i - 1] =\
    \ inv2[n - i] * BASE[1];\n\t\t\thash2[i + 1] = hash2[i] + power2[i] * num;\n\t\
    \t\tpower3[i + 1] = power3[i] * BASE[2];\n\t\t\tinv3[n - i - 1] = inv3[n - i]\
    \ * BASE[2];\n\t\t\thash3[i + 1] = hash3[i] + power3[i] * num;\n\t\t\tpower4[i\
    \ + 1] = power4[i] * BASE[3];\n\t\t\tinv4[n - i - 1] = inv4[n - i] * BASE[3];\n\
    \t\t\thash4[i + 1] = hash4[i] + power4[i] * num;\n\t\t\tpower5[i + 1] = power5[i]\
    \ * BASE[4];\n\t\t\tinv5[n - i - 1] = inv5[n - i] * BASE[4];\n\t\t\thash5[i +\
    \ 1] = hash5[i] + power5[i] * num;\n\t\t}\n\t}\n\ttuple<unsigned long long, unsigned\
    \ long long, unsigned long long, unsigned long long, unsigned long long> hash(int\
    \ l, int r) {\n\t\tmint1 val1 = (hash1[r] - hash1[l]) * inv1[l];\n\t\tmint2 val2\
    \ = (hash2[r] - hash2[l]) * inv2[l];\n\t\tmint3 val3 = (hash3[r] - hash3[l]) *\
    \ inv3[l];\n\t\tmint4 val4 = (hash4[r] - hash4[l]) * inv4[l];\n\t\tmint5 val5\
    \ = (hash5[r] - hash5[l]) * inv5[l];\n\t\treturn make_tuple(val1.value, val2.value,\
    \ val3.value, val4.value, val5.value);\n\t}\n};\n"
  code: "#include \"mod/modint.cpp\"\n\n/**\n * @brief Rolling Hash\n */\n\nstruct\
    \ rolling_hash {\n\tusing mint1 = modint<998244353>;\n\tusing mint2 = modint<1000000007>;\n\
    \tusing mint3 = modint<1000000009>;\n\tusing mint4 = modint<1000000021>;\n\tusing\
    \ mint5 = modint<1000000033>;\n\tvector<long long> BASE;\n\tvector<mint1> power1,\
    \ hash1, inv1;\n\tvector<mint2> power2, hash2, inv2;\n\tvector<mint3> power3,\
    \ hash3, inv3;\n\tvector<mint4> power4, hash4, inv4;\n\tvector<mint5> power5,\
    \ hash5, inv5;\n\trolling_hash(string s, vector<long long> base = {}) {\n\t\t\
    int n = s.size();\n\t\tmt19937 rng(time(0));\n\t\tBASE.resize(5);\n\t\tif (base.size()\
    \ != 5) {\n\t\t\tBASE[0] = mint1(rng()).value + 30000;\n\t\t\tBASE[1] = mint2(rng()).value\
    \ + 30000;\n\t\t\tBASE[2] = mint3(rng()).value + 30000;\n\t\t\tBASE[3] = mint4(rng()).value\
    \ + 30000;\n\t\t\tBASE[4] = mint5(rng()).value + 30000;\n\t\t} else {\n\t\t\t\
    BASE = base;\n\t\t}\n\t\tpower1.resize(n + 1);\n\t\thash1.resize(n + 1);\n\t\t\
    inv1.resize(n + 1);\n\t\tpower2.resize(n + 1);\n\t\thash2.resize(n + 1);\n\t\t\
    inv2.resize(n + 1);\n\t\tpower3.resize(n + 1);\n\t\thash3.resize(n + 1);\n\t\t\
    inv3.resize(n + 1);\n\t\tpower4.resize(n + 1);\n\t\thash4.resize(n + 1);\n\t\t\
    inv4.resize(n + 1);\n\t\tpower5.resize(n + 1);\n\t\thash5.resize(n + 1);\n\t\t\
    inv5.resize(n + 1);\n\t\tpower1[0] = 1;\n\t\tinv1[n] = mint1(BASE[0]).pow(n).inv();\n\
    \t\tpower2[0] = 1;\n\t\tinv2[n] = mint2(BASE[1]).pow(n).inv();\n\t\tpower3[0]\
    \ = 1;\n\t\tinv3[n] = mint3(BASE[2]).pow(n).inv();\n\t\tpower4[0] = 1;\n\t\tinv4[n]\
    \ = mint4(BASE[3]).pow(n).inv();\n\t\tpower5[0] = 1;\n\t\tinv5[n] = mint5(BASE[4]).pow(n).inv();\n\
    \t\tfor (int i = 0; i < n; i++) {\n\t\t\tint num = s[i] - 'A';\n\t\t\tpower1[i\
    \ + 1] = power1[i] * BASE[0];\n\t\t\tinv1[n - i - 1] = inv1[n - i] * BASE[0];\n\
    \t\t\thash1[i + 1] = hash1[i] + power1[i] * num;\n\t\t\tpower2[i + 1] = power2[i]\
    \ * BASE[1];\n\t\t\tinv2[n - i - 1] = inv2[n - i] * BASE[1];\n\t\t\thash2[i +\
    \ 1] = hash2[i] + power2[i] * num;\n\t\t\tpower3[i + 1] = power3[i] * BASE[2];\n\
    \t\t\tinv3[n - i - 1] = inv3[n - i] * BASE[2];\n\t\t\thash3[i + 1] = hash3[i]\
    \ + power3[i] * num;\n\t\t\tpower4[i + 1] = power4[i] * BASE[3];\n\t\t\tinv4[n\
    \ - i - 1] = inv4[n - i] * BASE[3];\n\t\t\thash4[i + 1] = hash4[i] + power4[i]\
    \ * num;\n\t\t\tpower5[i + 1] = power5[i] * BASE[4];\n\t\t\tinv5[n - i - 1] =\
    \ inv5[n - i] * BASE[4];\n\t\t\thash5[i + 1] = hash5[i] + power5[i] * num;\n\t\
    \t}\n\t}\n\ttuple<unsigned long long, unsigned long long, unsigned long long,\
    \ unsigned long long, unsigned long long> hash(int l, int r) {\n\t\tmint1 val1\
    \ = (hash1[r] - hash1[l]) * inv1[l];\n\t\tmint2 val2 = (hash2[r] - hash2[l]) *\
    \ inv2[l];\n\t\tmint3 val3 = (hash3[r] - hash3[l]) * inv3[l];\n\t\tmint4 val4\
    \ = (hash4[r] - hash4[l]) * inv4[l];\n\t\tmint5 val5 = (hash5[r] - hash5[l]) *\
    \ inv5[l];\n\t\treturn make_tuple(val1.value, val2.value, val3.value, val4.value,\
    \ val5.value);\n\t}\n};"
  dependsOn:
  - mod/modint.cpp
  isVerificationFile: false
  path: string/rolling_hash.cpp
  requiredBy: []
  timestamp: '2023-12-06 08:26:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/rolling_hash.cpp
layout: document
redirect_from:
- /library/string/rolling_hash.cpp
- /library/string/rolling_hash.cpp.html
title: Rolling Hash
---
