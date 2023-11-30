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
  bundledCode: "#line 1 \"others/change_base_to_N.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n// 10\u9032\u6570\u975E\u8CA0\u6574\u6570\u3092N\u9032\
    \u6570\u306B\u5909\u63DB\u3059\u308B\n// Size \u6841\u6570\n// n    \u5909\u63DB\
    \u5BFE\u8C61\u306E10\u9032\u6570\n// base \u57FA\u6570\n// rev  \u5909\u63DB\u5F8C\
    \u306E\u6570\u3092\u53CD\u8EE2\u3055\u305B\u305F\u307E\u307E\u306B\u3059\u308B\
    \u304B\u5426\u304B\ntemplate<int Size = -1>\nstring change_base(long long n, int\
    \ base = 2, bool rev = true) {\n\tstring ret;\n\tif (n == 0) {\n\t\tret.push_back('0');\n\
    \t}\n\twhile (n > 0) {\n\t\tret.push_back(n % base + '0');\n\t\tn /= base;\n\t\
    }\n\tif (Size != -1) {\n\t\twhile (ret.size() < Size) {\n\t\t\tret.push_back('0');\n\
    \t\t}\n\t}\n\tif (rev) {\n\t\treverse(ret.begin(), ret.end());\n\t}\n\treturn\
    \ ret;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n// 10\u9032\u6570\u975E\
    \u8CA0\u6574\u6570\u3092N\u9032\u6570\u306B\u5909\u63DB\u3059\u308B\n// Size \u6841\
    \u6570\n// n    \u5909\u63DB\u5BFE\u8C61\u306E10\u9032\u6570\n// base \u57FA\u6570\
    \n// rev  \u5909\u63DB\u5F8C\u306E\u6570\u3092\u53CD\u8EE2\u3055\u305B\u305F\u307E\
    \u307E\u306B\u3059\u308B\u304B\u5426\u304B\ntemplate<int Size = -1>\nstring change_base(long\
    \ long n, int base = 2, bool rev = true) {\n\tstring ret;\n\tif (n == 0) {\n\t\
    \tret.push_back('0');\n\t}\n\twhile (n > 0) {\n\t\tret.push_back(n % base + '0');\n\
    \t\tn /= base;\n\t}\n\tif (Size != -1) {\n\t\twhile (ret.size() < Size) {\n\t\t\
    \tret.push_back('0');\n\t\t}\n\t}\n\tif (rev) {\n\t\treverse(ret.begin(), ret.end());\n\
    \t}\n\treturn ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: others/change_base_to_N.cpp
  requiredBy: []
  timestamp: '2023-11-30 19:42:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: others/change_base_to_N.cpp
layout: document
redirect_from:
- /library/others/change_base_to_N.cpp
- /library/others/change_base_to_N.cpp.html
title: others/change_base_to_N.cpp
---
