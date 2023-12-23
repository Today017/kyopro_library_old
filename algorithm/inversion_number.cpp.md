---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data_structure/fenwick_tree.cpp
    title: Fenwick Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/algorithm/inversion_number.md
    document_title: Inversion Number
    links: []
  bundledCode: "#line 1 \"algorithm/inversion_number.cpp\"\n#include <vector>\r\n\
    #line 2 \"data_structure/fenwick_tree.cpp\"\n\r\n/**\r\n * @brief Fenwick Tree\r\
    \n * @docs docs/data_structure/fenwick_tree.md\r\n */\r\n\r\ntemplate <typename\
    \ T>\r\nstruct fenwick_tree {\r\n\tfenwick_tree(int n) {\r\n\t\tthis->n = n;\r\
    \n\t\tdat.resize(n);\r\n\t}\r\n\tvoid add(int i, T x) {\r\n\t\ti++;\r\n\t\twhile\
    \ (i <= n) {\r\n\t\t\tdat[i - 1] += x;\r\n\t\t\ti += i & -i;\r\n\t\t}\r\n\t}\r\
    \n\tT operator[](int i) {\r\n\t\treturn sum(i, i + 1);\r\n\t}\r\n\tT sum(int l,\
    \ int r) {\r\n\t\treturn sum(r) - sum(l);\r\n\t}\r\n\r\n\tprivate:\r\n\tint n;\r\
    \n\tstd::vector<T> dat;\r\n\tT sum(int r) {\r\n\t\tT ret = 0;\r\n\t\twhile (r\
    \ > 0) {\r\n\t\t\tret += dat[r - 1];\r\n\t\t\tr -= r & -r;\r\n\t\t}\r\n\t\treturn\
    \ ret;\r\n\t}\r\n};\n#line 3 \"algorithm/inversion_number.cpp\"\n\r\n/**\r\n *\
    \ @brief Inversion Number\r\n * @docs docs/algorithm/inversion_number.md\r\n */\r\
    \n\r\nlong long inversion_number(const std::vector<int> &A) {\r\n\tint n = A.size();\r\
    \n\tfenwick_tree<int> ft(n);\r\n\tlong long ret = 0;\r\n\tfor (int i = 0; i <\
    \ n; i++) {\r\n\t\tret += i - ft.sum(0, A[i]);\r\n\t\tft.add(A[i], 1);\r\n\t}\r\
    \n\treturn ret;\r\n}\r\n"
  code: "#include <vector>\r\n#include \"data_structure/fenwick_tree.cpp\"\r\n\r\n\
    /**\r\n * @brief Inversion Number\r\n * @docs docs/algorithm/inversion_number.md\r\
    \n */\r\n\r\nlong long inversion_number(const std::vector<int> &A) {\r\n\tint\
    \ n = A.size();\r\n\tfenwick_tree<int> ft(n);\r\n\tlong long ret = 0;\r\n\tfor\
    \ (int i = 0; i < n; i++) {\r\n\t\tret += i - ft.sum(0, A[i]);\r\n\t\tft.add(A[i],\
    \ 1);\r\n\t}\r\n\treturn ret;\r\n}\r\n"
  dependsOn:
  - data_structure/fenwick_tree.cpp
  isVerificationFile: false
  path: algorithm/inversion_number.cpp
  requiredBy: []
  timestamp: '2023-12-24 07:38:27+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/inversion_number.cpp
layout: document
redirect_from:
- /library/algorithm/inversion_number.cpp
- /library/algorithm/inversion_number.cpp.html
title: Inversion Number
---
