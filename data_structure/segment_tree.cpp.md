---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Segment Tree
    links: []
  bundledCode: "#line 1 \"data_structure/segment_tree.cpp\"\n#include <vector>\r\n\
    #include <functional>\r\n#include <limits>\r\n\r\n/**\r\n * @brief Segment Tree\r\
    \n */\r\n\r\ntemplate <typename T>\r\nstruct segment_tree {\r\n\tint n;\r\n\t\
    std::vector<T> dat;\r\n\tusing F = std::function<T(T, T)>;\r\n\tF f;\r\n\tT e;\r\
    \n\tsegment_tree(int n, F f, T e) {\r\n\t\tthis->n = 1;\r\n\t\twhile (this->n\
    \ < n) {\r\n\t\t\tthis->n *= 2;\r\n\t\t}\r\n\t\tthis->f = f;\r\n\t\tthis->e =\
    \ e;\r\n\t\tdat.resize(this->n * 2 - 1, e);\r\n\t}\r\n\tvoid build(const std::vector<T>\
    \ &A) {\r\n\t\tfor (int i = 0; i < (int)A.size(); i++) {\r\n\t\t\tdat[i + n -\
    \ 1] = A[i];\r\n\t\t}\r\n\t\tfor (int i = n - 2; i >= 0; i--) {\r\n\t\t\tdat[i]\
    \ = f(dat[i * 2 + 1], dat[i * 2 + 2]);\r\n\t\t}\r\n\t}\r\n\tT operator[](int i)\
    \ {\r\n\t\treturn dat[n - 1 + i];\r\n\t}\r\n\tvoid set(int i, T x) {\r\n\t\ti\
    \ += n - 1;\r\n\t\tdat[i] = x;\r\n\t\twhile (i > 0) {\r\n\t\t\ti = (i - 1) / 2;\r\
    \n\t\t\tdat[i] = f(dat[i * 2 + 1], dat[i * 2 + 2]);\r\n\t\t}\r\n\t}\r\n\tT query(int\
    \ left, int right, int i, int l, int r) {\r\n\t\tif (r <= left || right <= l)\
    \ {\r\n\t\t\treturn e;\r\n\t\t} else if (left <= l && r <= right) {\r\n\t\t\t\
    return dat[i];\r\n\t\t} else {\r\n\t\t\tint mid = (l + r) / 2;\r\n\t\t\treturn\
    \ f(query(left, right, i * 2 + 1, l, mid), query(left, right, i * 2 + 2, mid,\
    \ r));\r\n\t\t}\r\n\t}\r\n\tT query(int l, int r) {\r\n\t\treturn query(l, r,\
    \ 0, 0, n);\r\n\t}\r\n};\r\n\r\ntemplate <typename U>\r\nsegment_tree<U> range_min_query(int\
    \ n, U e = std::numeric_limits<U>::max()) {\r\n\tauto f = [](U a, U b) {\r\n\t\
    \treturn std::min(a, b);\r\n\t};\r\n\treturn segment_tree<U>(n, f, e);\r\n}\r\n\
    \r\ntemplate <typename U>\r\nsegment_tree<U> range_max_query(int n, U e = std::numeric_limits<U>::min())\
    \ {\r\n\tauto f = [](U a, U b) {\r\n\t\treturn std::max(a, b);\r\n\t};\r\n\treturn\
    \ segment_tree<U>(n, f, e);\r\n}\n"
  code: "#include <vector>\r\n#include <functional>\r\n#include <limits>\r\n\r\n/**\r\
    \n * @brief Segment Tree\r\n */\r\n\r\ntemplate <typename T>\r\nstruct segment_tree\
    \ {\r\n\tint n;\r\n\tstd::vector<T> dat;\r\n\tusing F = std::function<T(T, T)>;\r\
    \n\tF f;\r\n\tT e;\r\n\tsegment_tree(int n, F f, T e) {\r\n\t\tthis->n = 1;\r\n\
    \t\twhile (this->n < n) {\r\n\t\t\tthis->n *= 2;\r\n\t\t}\r\n\t\tthis->f = f;\r\
    \n\t\tthis->e = e;\r\n\t\tdat.resize(this->n * 2 - 1, e);\r\n\t}\r\n\tvoid build(const\
    \ std::vector<T> &A) {\r\n\t\tfor (int i = 0; i < (int)A.size(); i++) {\r\n\t\t\
    \tdat[i + n - 1] = A[i];\r\n\t\t}\r\n\t\tfor (int i = n - 2; i >= 0; i--) {\r\n\
    \t\t\tdat[i] = f(dat[i * 2 + 1], dat[i * 2 + 2]);\r\n\t\t}\r\n\t}\r\n\tT operator[](int\
    \ i) {\r\n\t\treturn dat[n - 1 + i];\r\n\t}\r\n\tvoid set(int i, T x) {\r\n\t\t\
    i += n - 1;\r\n\t\tdat[i] = x;\r\n\t\twhile (i > 0) {\r\n\t\t\ti = (i - 1) / 2;\r\
    \n\t\t\tdat[i] = f(dat[i * 2 + 1], dat[i * 2 + 2]);\r\n\t\t}\r\n\t}\r\n\tT query(int\
    \ left, int right, int i, int l, int r) {\r\n\t\tif (r <= left || right <= l)\
    \ {\r\n\t\t\treturn e;\r\n\t\t} else if (left <= l && r <= right) {\r\n\t\t\t\
    return dat[i];\r\n\t\t} else {\r\n\t\t\tint mid = (l + r) / 2;\r\n\t\t\treturn\
    \ f(query(left, right, i * 2 + 1, l, mid), query(left, right, i * 2 + 2, mid,\
    \ r));\r\n\t\t}\r\n\t}\r\n\tT query(int l, int r) {\r\n\t\treturn query(l, r,\
    \ 0, 0, n);\r\n\t}\r\n};\r\n\r\ntemplate <typename U>\r\nsegment_tree<U> range_min_query(int\
    \ n, U e = std::numeric_limits<U>::max()) {\r\n\tauto f = [](U a, U b) {\r\n\t\
    \treturn std::min(a, b);\r\n\t};\r\n\treturn segment_tree<U>(n, f, e);\r\n}\r\n\
    \r\ntemplate <typename U>\r\nsegment_tree<U> range_max_query(int n, U e = std::numeric_limits<U>::min())\
    \ {\r\n\tauto f = [](U a, U b) {\r\n\t\treturn std::max(a, b);\r\n\t};\r\n\treturn\
    \ segment_tree<U>(n, f, e);\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/segment_tree.cpp
  requiredBy: []
  timestamp: '2023-12-13 14:53:29+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/segment_tree.cpp
layout: document
redirect_from:
- /library/data_structure/segment_tree.cpp
- /library/data_structure/segment_tree.cpp.html
title: Segment Tree
---
