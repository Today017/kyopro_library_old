---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/fenwick_tree.test.cpp
    title: test/fenwick_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/fenwick_tree.cpp\"\n#include <bits/stdc++.h>\r\
    \nusing namespace std;\r\n\r\ntemplate <typename T>\r\nstruct fenwick_tree {\r\
    \n\tint n;\r\n\tvector<T> dat;\r\n\tfenwick_tree(int n) {\r\n\t\tthis->n = n;\r\
    \n\t\tdat.resize(n);\r\n\t}\r\n\tvoid add(int i, T x) {\r\n\t\ti++;\r\n\t\twhile\
    \ (i <= n) {\r\n\t\t\tdat[i - 1] += x;\r\n\t\t\ti += i & -i;\r\n\t\t}\r\n\t}\r\
    \n\tT sum(int l, int r) {\r\n\t\treturn sum(r) - sum(l);\r\n\t}\r\n\tT sum(int\
    \ r) {\r\n\t\tT ret = 0;\r\n\t\twhile (r > 0) {\r\n\t\t\tret += dat[r - 1];\r\n\
    \t\t\tr -= r & -r;\r\n\t\t}\r\n\t\treturn ret;\r\n\t}\r\n\tT operator[](int i)\
    \ {\r\n\t\treturn sum(i, i + 1);\r\n\t}\r\n};\n"
  code: "#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\ntemplate <typename\
    \ T>\r\nstruct fenwick_tree {\r\n\tint n;\r\n\tvector<T> dat;\r\n\tfenwick_tree(int\
    \ n) {\r\n\t\tthis->n = n;\r\n\t\tdat.resize(n);\r\n\t}\r\n\tvoid add(int i, T\
    \ x) {\r\n\t\ti++;\r\n\t\twhile (i <= n) {\r\n\t\t\tdat[i - 1] += x;\r\n\t\t\t\
    i += i & -i;\r\n\t\t}\r\n\t}\r\n\tT sum(int l, int r) {\r\n\t\treturn sum(r) -\
    \ sum(l);\r\n\t}\r\n\tT sum(int r) {\r\n\t\tT ret = 0;\r\n\t\twhile (r > 0) {\r\
    \n\t\t\tret += dat[r - 1];\r\n\t\t\tr -= r & -r;\r\n\t\t}\r\n\t\treturn ret;\r\
    \n\t}\r\n\tT operator[](int i) {\r\n\t\treturn sum(i, i + 1);\r\n\t}\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/fenwick_tree.cpp
  requiredBy: []
  timestamp: '2023-11-30 18:16:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/fenwick_tree.test.cpp
documentation_of: data_structure/fenwick_tree.cpp
layout: document
redirect_from:
- /library/data_structure/fenwick_tree.cpp
- /library/data_structure/fenwick_tree.cpp.html
title: data_structure/fenwick_tree.cpp
---
