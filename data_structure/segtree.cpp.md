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
  bundledCode: "#line 1 \"data_structure/segtree.cpp\"\n#include <bits/stdc++.h>\r\
    \nusing namespace std;\r\n\r\ntemplate <typename T>\r\nstruct segtree {\r\n\t\
    int n;\r\n\tvector<T> dat;\r\n\tfunction<T(T, T)> f;\r\n\tT e;\r\n\tsegtree(int\
    \ n, function<T(T, T)> f, T e) {\r\n\t\tthis->n = 1;\r\n\t\twhile (this->n < n)\
    \ {\r\n\t\t\tthis->n *= 2;\r\n\t\t}\r\n\t\tdat.resize(this->n * 2 - 1, e);\r\n\
    \t\tthis->f = f;\r\n\t\tthis->e = e;\r\n\t}\r\n\tT operator[](int i) {\r\n\t\t\
    return dat[n - 1 + i];\r\n\t}\r\n\tvoid set(int i, T x) {\r\n\t\ti += n - 1;\r\
    \n\t\tdat[i] = x;\r\n\t\twhile (i > 0) {\r\n\t\t\ti = (i - 1) / 2;\r\n\t\t\tdat[i]\
    \ = f(dat[i * 2 + 1], dat[i * 2 + 2]);\r\n\t\t}\r\n\t}\r\n\tT query(int left,\
    \ int right, int i, int l, int r) {\r\n\t\tif (r <= left || right <= l) {\r\n\t\
    \t\treturn e;\r\n\t\t} else if (left <= l && r <= right) {\r\n\t\t\treturn dat[i];\r\
    \n\t\t} else {\r\n\t\t\tint mid = (l + r) / 2;\r\n\t\t\treturn f(query(left, right,\
    \ i * 2 + 1, l, mid), query(left, right, i * 2 + 2, mid, r));\r\n\t\t}\r\n\t}\r\
    \n\tT query(int l, int r) {\r\n\t\treturn query(l, r, 0, 0, n);\r\n\t}\r\n};\r\
    \n\r\n#line 46 \"data_structure/segtree.cpp\"\nusing namespace std;\r\n\r\nstruct\
    \ segment_tree {\r\n\tint n;\r\n\tvector<int> dat;\r\n\tsegment_tree(int n) {\r\
    \n\t\tthis->n = 1;\r\n\t\twhile (this->n < n) {\r\n\t\t\tthis->n *= 2;\r\n\t\t\
    }\r\n\t\tdat.resize(this->n * 2 - 1, INT_MAX);\r\n\t}\r\n\tint operator[](int\
    \ i) {\r\n\t\treturn dat[n - 1 + i];\r\n\t}\r\n\tvoid set(int i, int x) {\r\n\t\
    \ti += n - 1;\r\n\t\tdat[i] = x;\r\n\t\twhile (i > 0) {\r\n\t\t\ti = (i - 1) /\
    \ 2;\r\n\t\t\tdat[i] = min(dat[i * 2 + 1], dat[i * 2 + 2]);\r\n\t\t}\r\n\t}\r\n\
    \tint query(int left, int right, int i, int l, int r) {\r\n\t\tif (r <= left ||\
    \ right <= l) {\r\n\t\t\treturn INT_MAX;\r\n\t\t} else if (left <= l && r <= right)\
    \ {\r\n\t\t\treturn dat[i];\r\n\t\t} else {\r\n\t\t\tint mid = (l + r) / 2;\r\n\
    \t\t\treturn min(query(left, right, i * 2 + 1, l, mid), query(left, right, i *\
    \ 2 + 2, mid, r));\r\n\t\t}\r\n\t}\r\n\tint query(int l, int r) {\r\n\t\treturn\
    \ query(l, r, 0, 0, n);\r\n\t}\r\n};\r\n"
  code: "#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\ntemplate <typename\
    \ T>\r\nstruct segtree {\r\n\tint n;\r\n\tvector<T> dat;\r\n\tfunction<T(T, T)>\
    \ f;\r\n\tT e;\r\n\tsegtree(int n, function<T(T, T)> f, T e) {\r\n\t\tthis->n\
    \ = 1;\r\n\t\twhile (this->n < n) {\r\n\t\t\tthis->n *= 2;\r\n\t\t}\r\n\t\tdat.resize(this->n\
    \ * 2 - 1, e);\r\n\t\tthis->f = f;\r\n\t\tthis->e = e;\r\n\t}\r\n\tT operator[](int\
    \ i) {\r\n\t\treturn dat[n - 1 + i];\r\n\t}\r\n\tvoid set(int i, T x) {\r\n\t\t\
    i += n - 1;\r\n\t\tdat[i] = x;\r\n\t\twhile (i > 0) {\r\n\t\t\ti = (i - 1) / 2;\r\
    \n\t\t\tdat[i] = f(dat[i * 2 + 1], dat[i * 2 + 2]);\r\n\t\t}\r\n\t}\r\n\tT query(int\
    \ left, int right, int i, int l, int r) {\r\n\t\tif (r <= left || right <= l)\
    \ {\r\n\t\t\treturn e;\r\n\t\t} else if (left <= l && r <= right) {\r\n\t\t\t\
    return dat[i];\r\n\t\t} else {\r\n\t\t\tint mid = (l + r) / 2;\r\n\t\t\treturn\
    \ f(query(left, right, i * 2 + 1, l, mid), query(left, right, i * 2 + 2, mid,\
    \ r));\r\n\t\t}\r\n\t}\r\n\tT query(int l, int r) {\r\n\t\treturn query(l, r,\
    \ 0, 0, n);\r\n\t}\r\n};\r\n\r\n#include <bits/stdc++.h>\r\nusing namespace std;\r\
    \n\r\nstruct segment_tree {\r\n\tint n;\r\n\tvector<int> dat;\r\n\tsegment_tree(int\
    \ n) {\r\n\t\tthis->n = 1;\r\n\t\twhile (this->n < n) {\r\n\t\t\tthis->n *= 2;\r\
    \n\t\t}\r\n\t\tdat.resize(this->n * 2 - 1, INT_MAX);\r\n\t}\r\n\tint operator[](int\
    \ i) {\r\n\t\treturn dat[n - 1 + i];\r\n\t}\r\n\tvoid set(int i, int x) {\r\n\t\
    \ti += n - 1;\r\n\t\tdat[i] = x;\r\n\t\twhile (i > 0) {\r\n\t\t\ti = (i - 1) /\
    \ 2;\r\n\t\t\tdat[i] = min(dat[i * 2 + 1], dat[i * 2 + 2]);\r\n\t\t}\r\n\t}\r\n\
    \tint query(int left, int right, int i, int l, int r) {\r\n\t\tif (r <= left ||\
    \ right <= l) {\r\n\t\t\treturn INT_MAX;\r\n\t\t} else if (left <= l && r <= right)\
    \ {\r\n\t\t\treturn dat[i];\r\n\t\t} else {\r\n\t\t\tint mid = (l + r) / 2;\r\n\
    \t\t\treturn min(query(left, right, i * 2 + 1, l, mid), query(left, right, i *\
    \ 2 + 2, mid, r));\r\n\t\t}\r\n\t}\r\n\tint query(int l, int r) {\r\n\t\treturn\
    \ query(l, r, 0, 0, n);\r\n\t}\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/segtree.cpp
  requiredBy: []
  timestamp: '2023-11-30 18:16:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/segtree.cpp
layout: document
redirect_from:
- /library/data_structure/segtree.cpp
- /library/data_structure/segtree.cpp.html
title: data_structure/segtree.cpp
---
