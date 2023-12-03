---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/algorithm/inversion_number.md
    document_title: Inversion Number
    links: []
  bundledCode: "#line 1 \"algorithm/inversion_number.cpp\"\n#include <../data_structure/fenwick_tree.cpp>\r\
    \n\r\n/**\r\n * @brief Inversion Number\r\n * @docs docs/algorithm/inversion_number.md\r\
    \n*/\r\n\r\nlong long inversion_number(const vector<int> &A) {\r\n\tint n = A.size();\r\
    \n\tfenwick_tree<int> ft(n);\r\n\tlong long ret = 0;\r\n\tfor (int i = 0; i <\
    \ n; i++) {\r\n\t\tret += i - ft.sum(0, A[i]);\r\n\t\tft.add(A[i], 1);\r\n\t}\r\
    \n\treturn ret;\r\n}\r\n"
  code: "#include <../data_structure/fenwick_tree.cpp>\r\n\r\n/**\r\n * @brief Inversion\
    \ Number\r\n * @docs docs/algorithm/inversion_number.md\r\n*/\r\n\r\nlong long\
    \ inversion_number(const vector<int> &A) {\r\n\tint n = A.size();\r\n\tfenwick_tree<int>\
    \ ft(n);\r\n\tlong long ret = 0;\r\n\tfor (int i = 0; i < n; i++) {\r\n\t\tret\
    \ += i - ft.sum(0, A[i]);\r\n\t\tft.add(A[i], 1);\r\n\t}\r\n\treturn ret;\r\n\
    }\r\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/inversion_number.cpp
  requiredBy: []
  timestamp: '2023-12-04 01:54:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/inversion_number.cpp
layout: document
redirect_from:
- /library/algorithm/inversion_number.cpp
- /library/algorithm/inversion_number.cpp.html
title: Inversion Number
---
