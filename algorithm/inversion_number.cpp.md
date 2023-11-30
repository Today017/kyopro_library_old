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
  bundledCode: "#line 1 \"algorithm/inversion_number.cpp\"\n#include <bits/stdc++.h>\r\
    \nusing namespace std;\r\n#include <atcoder/fenwicktree>\r\nusing namespace atcoder;\r\
    \n\r\nlong long inversion_number(const vector<int> &A) {\r\n\tint n = A.size();\r\
    \n\tfenwick_tree<int> ft(n);\r\n\tlong long ret = 0;\r\n\tfor (int i = 0; i <\
    \ n; i++) {\r\n\t\tret += i - ft.sum(0, A[i]);\r\n\t\tft.add(A[i], 1);\r\n\t}\r\
    \n\treturn ret;\r\n}\r\n"
  code: "#include <bits/stdc++.h>\r\nusing namespace std;\r\n#include <atcoder/fenwicktree>\r\
    \nusing namespace atcoder;\r\n\r\nlong long inversion_number(const vector<int>\
    \ &A) {\r\n\tint n = A.size();\r\n\tfenwick_tree<int> ft(n);\r\n\tlong long ret\
    \ = 0;\r\n\tfor (int i = 0; i < n; i++) {\r\n\t\tret += i - ft.sum(0, A[i]);\r\
    \n\t\tft.add(A[i], 1);\r\n\t}\r\n\treturn ret;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/inversion_number.cpp
  requiredBy: []
  timestamp: '2023-11-30 18:30:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/inversion_number.cpp
layout: document
redirect_from:
- /library/algorithm/inversion_number.cpp
- /library/algorithm/inversion_number.cpp.html
title: algorithm/inversion_number.cpp
---
