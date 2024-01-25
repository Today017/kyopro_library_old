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
    document_title: Rolling Hash
    links: []
  bundledCode: "#line 1 \"string/rolling_hash.cpp\"\n#include <vector>\n#include <string>\n\
    #include <random>\n#include <tuple>\n#line 1 \"mod/modint.cpp\"\n#include <iostream>\r\
    \n\r\n/**\r\n * @brief Modint\r\n */\r\n\r\ntemplate <long long MOD>\r\nstruct\
    \ modint {\r\n    long long value;\r\n    modint(long long x = 0) {\r\n      \
    \  if (x >= 0) {\r\n            value = x % MOD;\r\n        } else {\r\n     \
    \       value = MOD - (-x) % MOD;\r\n        }\r\n    }\r\n    modint operator-()\
    \ const {\r\n        return modint(-value);\r\n    }\r\n    modint operator+()\
    \ const {\r\n        return modint(*this);\r\n    }\r\n    modint &operator+=(const\
    \ modint &other) {\r\n        value += other.value;\r\n        if (value >= MOD)\
    \ {\r\n            value -= MOD;\r\n        }\r\n        return *this;\r\n   \
    \ }\r\n    modint &operator-=(const modint &other) {\r\n        value += MOD -\
    \ other.value;\r\n        if (value >= MOD) {\r\n            value -= MOD;\r\n\
    \        }\r\n        return *this;\r\n    }\r\n    modint &operator*=(const modint\
    \ other) {\r\n        value = value * other.value % MOD;\r\n        return *this;\r\
    \n    }\r\n    modint &operator/=(modint other) {\r\n        (*this) *= other.inv();\r\
    \n        return *this;\r\n    }\r\n    modint operator+(const modint &other)\
    \ const {\r\n        return modint(*this) += other;\r\n    }\r\n    modint operator-(const\
    \ modint &other) const {\r\n        return modint(*this) -= other;\r\n    }\r\n\
    \    modint operator*(const modint &other) const {\r\n        return modint(*this)\
    \ *= other;\r\n    }\r\n    modint operator/(const modint &other) const {\r\n\
    \        return modint(*this) /= other;\r\n    }\r\n    modint pow(long long x)\
    \ const {\r\n        modint ret(1), mul(value);\r\n        while (x > 0) {\r\n\
    \            if (x % 2 == 1) {\r\n                ret *= mul;\r\n            }\r\
    \n            mul *= mul;\r\n            x /= 2;\r\n        }\r\n        return\
    \ ret;\r\n    }\r\n    modint inv() const {\r\n        return pow(MOD - 2);\r\n\
    \    }\r\n    bool operator==(const modint &other) const {\r\n        return value\
    \ == other.value;\r\n    }\r\n    bool operator!=(const modint &other) const {\r\
    \n        return value != other.value;\r\n    }\r\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const modint &x) {\r\n        return os << x.value;\r\n    }\r\n    friend\
    \ std::istream &operator>>(std::istream &is, modint &x) {\r\n        long long\
    \ v;\r\n        is >> v;\r\n        x = modint<MOD>(v);\r\n        return is;\r\
    \n    }\r\n};\r\nusing mod998 = modint<998244353>;\r\nusing mod107 = modint<1000000007>;\r\
    \n#line 6 \"string/rolling_hash.cpp\"\n\n/**\n * @brief Rolling Hash\n */\n\n\
    struct rolling_hash {\n\tusing mint1 = modint<998244353>;\n\tusing mint2 = modint<1000000007>;\n\
    \tusing mint3 = modint<1000000009>;\n\tusing mint4 = modint<1000000021>;\n\tusing\
    \ mint5 = modint<1000000033>;\n\tstd::vector<long long> BASE;\n\tstd::vector<mint1>\
    \ power1, hash1, inv1;\n\tstd::vector<mint2> power2, hash2, inv2;\n\tstd::vector<mint3>\
    \ power3, hash3, inv3;\n\tstd::vector<mint4> power4, hash4, inv4;\n\tstd::vector<mint5>\
    \ power5, hash5, inv5;\n\trolling_hash(std::string s, std::vector<long long> base\
    \ = {}) {\n\t\tint n = s.size();\n\t\tstd::mt19937 rng(time(0));\n\t\tBASE.resize(5);\n\
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
    \ 1] = hash5[i] + power5[i] * num;\n\t\t}\n\t}\n\tstd::tuple<unsigned long long,\
    \ unsigned long long, unsigned long long, unsigned long long, unsigned long long>\
    \ hash(int l, int r) {\n\t\tmint1 val1 = (hash1[r] - hash1[l]) * inv1[l];\n\t\t\
    mint2 val2 = (hash2[r] - hash2[l]) * inv2[l];\n\t\tmint3 val3 = (hash3[r] - hash3[l])\
    \ * inv3[l];\n\t\tmint4 val4 = (hash4[r] - hash4[l]) * inv4[l];\n\t\tmint5 val5\
    \ = (hash5[r] - hash5[l]) * inv5[l];\n\t\treturn std::make_tuple(val1.value, val2.value,\
    \ val3.value, val4.value, val5.value);\n\t}\n};\n"
  code: "#include <vector>\n#include <string>\n#include <random>\n#include <tuple>\n\
    #include \"mod/modint.cpp\"\n\n/**\n * @brief Rolling Hash\n */\n\nstruct rolling_hash\
    \ {\n\tusing mint1 = modint<998244353>;\n\tusing mint2 = modint<1000000007>;\n\
    \tusing mint3 = modint<1000000009>;\n\tusing mint4 = modint<1000000021>;\n\tusing\
    \ mint5 = modint<1000000033>;\n\tstd::vector<long long> BASE;\n\tstd::vector<mint1>\
    \ power1, hash1, inv1;\n\tstd::vector<mint2> power2, hash2, inv2;\n\tstd::vector<mint3>\
    \ power3, hash3, inv3;\n\tstd::vector<mint4> power4, hash4, inv4;\n\tstd::vector<mint5>\
    \ power5, hash5, inv5;\n\trolling_hash(std::string s, std::vector<long long> base\
    \ = {}) {\n\t\tint n = s.size();\n\t\tstd::mt19937 rng(time(0));\n\t\tBASE.resize(5);\n\
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
    \ 1] = hash5[i] + power5[i] * num;\n\t\t}\n\t}\n\tstd::tuple<unsigned long long,\
    \ unsigned long long, unsigned long long, unsigned long long, unsigned long long>\
    \ hash(int l, int r) {\n\t\tmint1 val1 = (hash1[r] - hash1[l]) * inv1[l];\n\t\t\
    mint2 val2 = (hash2[r] - hash2[l]) * inv2[l];\n\t\tmint3 val3 = (hash3[r] - hash3[l])\
    \ * inv3[l];\n\t\tmint4 val4 = (hash4[r] - hash4[l]) * inv4[l];\n\t\tmint5 val5\
    \ = (hash5[r] - hash5[l]) * inv5[l];\n\t\treturn std::make_tuple(val1.value, val2.value,\
    \ val3.value, val4.value, val5.value);\n\t}\n};"
  dependsOn:
  - mod/modint.cpp
  isVerificationFile: false
  path: string/rolling_hash.cpp
  requiredBy: []
  timestamp: '2024-01-25 11:55:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/rolling_hash.cpp
layout: document
redirect_from:
- /library/string/rolling_hash.cpp
- /library/string/rolling_hash.cpp.html
title: Rolling Hash
---
