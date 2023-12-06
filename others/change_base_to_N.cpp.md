---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "N\u9032\u6570\u3078\u306E\u5909\u63DB"
    links: []
  bundledCode: "#line 1 \"others/change_base_to_N.cpp\"\n#include <string>\n\n/**\n\
    \ * @brief N\u9032\u6570\u3078\u306E\u5909\u63DB\n * @param Size \u6841\u6570\n\
    \ * @param base \u57FA\u6570\n * @param rev \u5909\u63DB\u5F8C\u306E\u6570\u3092\
    \u53CD\u8EE2\u3055\u305B\u305F\u307E\u307E\u306B\u3059\u308B\u304B\u5426\u304B\
    \n*/\ntemplate<int Size = -1>\nstd::string change_base(long long n, int base =\
    \ 2, bool rev = true) {\n\tstring ret;\n\tif (n == 0) {\n\t\tret.push_back('0');\n\
    \t}\n\twhile (n > 0) {\n\t\tret.push_back(n % base + '0');\n\t\tn /= base;\n\t\
    }\n\tif (Size != -1) {\n\t\twhile (ret.size() < Size) {\n\t\t\tret.push_back('0');\n\
    \t\t}\n\t}\n\tif (rev) {\n\t\treverse(ret.begin(), ret.end());\n\t}\n\treturn\
    \ ret;\n}\n"
  code: "#include <string>\n\n/**\n * @brief N\u9032\u6570\u3078\u306E\u5909\u63DB\
    \n * @param Size \u6841\u6570\n * @param base \u57FA\u6570\n * @param rev \u5909\
    \u63DB\u5F8C\u306E\u6570\u3092\u53CD\u8EE2\u3055\u305B\u305F\u307E\u307E\u306B\
    \u3059\u308B\u304B\u5426\u304B\n*/\ntemplate<int Size = -1>\nstd::string change_base(long\
    \ long n, int base = 2, bool rev = true) {\n\tstring ret;\n\tif (n == 0) {\n\t\
    \tret.push_back('0');\n\t}\n\twhile (n > 0) {\n\t\tret.push_back(n % base + '0');\n\
    \t\tn /= base;\n\t}\n\tif (Size != -1) {\n\t\twhile (ret.size() < Size) {\n\t\t\
    \tret.push_back('0');\n\t\t}\n\t}\n\tif (rev) {\n\t\treverse(ret.begin(), ret.end());\n\
    \t}\n\treturn ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: others/change_base_to_N.cpp
  requiredBy: []
  timestamp: '2023-12-06 10:41:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: others/change_base_to_N.cpp
layout: document
redirect_from:
- /library/others/change_base_to_N.cpp
- /library/others/change_base_to_N.cpp.html
title: "N\u9032\u6570\u3078\u306E\u5909\u63DB"
---
