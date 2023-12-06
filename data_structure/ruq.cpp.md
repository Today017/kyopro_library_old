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
  bundledCode: "#line 1 \"data_structure/ruq.cpp\"\n#include <vector>\n#include <utility>\n\
    \nstruct range_update_query {\n\tint n;\n\tint t;\n\tstd::vector<std::pair<int,\
    \ int>> dat;\n\trange_update_query(int n) {\n\t\tthis->n = 1;\n\t\twhile (this->n\
    \ < n) {\n\t\t\tthis->n *= 2;\n\t\t}\n\t\tthis->t = 0;\n\t\tdat.resize(this->n\
    \ * 2 - 1, std::make_pair(0, -1));\n\t}\n\tint operator[](int i) {\n\t\ti += n\
    \ - 1;\n\t\tint ret = dat[i].first;\n\t\tint last = dat[i].second;\n\t\twhile\
    \ (i > 0) {\n\t\t\ti = (i - 1) / 2;\n\t\t\tif (dat[i].second > last) {\n\t\t\t\
    \tlast = dat[i].second;\n\t\t\t\tret = dat[i].first;\n\t\t\t}\n\t\t}\n\t}\n\t\
    void query(int left, int right, int i, int c, int l, int r) {\n\t\tif (r <= left\
    \ || right <= l) {\n\t\t\treturn;\n\t\t} else if (left <= l && r <= right) {\n\
    \t\t\tdat[i] = std::make_pair(c, t);\n\t\t} else {\n\t\t\tint mid = (l + r) /\
    \ 2;\n\t\t\tquery(left, right, i * 2 + 1, c, l, mid);\n\t\t\tquery(left, right,\
    \ i * 2 + 2, c, mid, r);\n\t\t}\n\t}\n\tvoid query(int l, int r, int c) {\n\t\t\
    query(l, r, 0, c, 0, n);\n\t\tt++;\n\t}\n};\n"
  code: "#include <vector>\n#include <utility>\n\nstruct range_update_query {\n\t\
    int n;\n\tint t;\n\tstd::vector<std::pair<int, int>> dat;\n\trange_update_query(int\
    \ n) {\n\t\tthis->n = 1;\n\t\twhile (this->n < n) {\n\t\t\tthis->n *= 2;\n\t\t\
    }\n\t\tthis->t = 0;\n\t\tdat.resize(this->n * 2 - 1, std::make_pair(0, -1));\n\
    \t}\n\tint operator[](int i) {\n\t\ti += n - 1;\n\t\tint ret = dat[i].first;\n\
    \t\tint last = dat[i].second;\n\t\twhile (i > 0) {\n\t\t\ti = (i - 1) / 2;\n\t\
    \t\tif (dat[i].second > last) {\n\t\t\t\tlast = dat[i].second;\n\t\t\t\tret =\
    \ dat[i].first;\n\t\t\t}\n\t\t}\n\t}\n\tvoid query(int left, int right, int i,\
    \ int c, int l, int r) {\n\t\tif (r <= left || right <= l) {\n\t\t\treturn;\n\t\
    \t} else if (left <= l && r <= right) {\n\t\t\tdat[i] = std::make_pair(c, t);\n\
    \t\t} else {\n\t\t\tint mid = (l + r) / 2;\n\t\t\tquery(left, right, i * 2 + 1,\
    \ c, l, mid);\n\t\t\tquery(left, right, i * 2 + 2, c, mid, r);\n\t\t}\n\t}\n\t\
    void query(int l, int r, int c) {\n\t\tquery(l, r, 0, c, 0, n);\n\t\tt++;\n\t\
    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/ruq.cpp
  requiredBy: []
  timestamp: '2023-12-06 10:41:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/ruq.cpp
layout: document
redirect_from:
- /library/data_structure/ruq.cpp
- /library/data_structure/ruq.cpp.html
title: data_structure/ruq.cpp
---
