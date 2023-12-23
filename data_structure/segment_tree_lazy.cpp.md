---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Segment Tree Lazy
    links: []
  bundledCode: "#line 1 \"data_structure/segment_tree_lazy.cpp\"\n#include <vector>\n\
    #include <functional>\n\n/**\n * @brief Segment Tree Lazy\n */\n\ntemplate <typename\
    \ T, typename U>\nstruct segment_tree_lazy {\n\tsegment_tree_lazy(int n, F f,\
    \ G g, H h, T et, U eu) {\n\t\tthis->n = 1;\n\t\twhile (this->n < n) {\n\t\t\t\
    this->n *= 2;\n\t\t}\n\t\tthis->f = f;\n\t\tthis->g = g;\n\t\tthis->h = h;\n\t\
    \tthis->et = et;\n\t\tthis->eu = eu;\n\t\tdat.resize(this->n * 2 - 1, this->et);\n\
    \t\tlazy.resize(this->n * 2 - 1, this->eu);\n\t}\n\tvoid build(const vector<T>\
    \ &A) {\n\t\tfor (int i = 0; i < (int)A.size(); i++) {\n\t\t\tdat[i + n - 1] =\
    \ A[i];\n\t\t}\n\t\tfor (int i = n - 2; i >= 0; i--) {\n\t\t\tdat[i] = f(dat[i\
    \ * 2 + 1], dat[i * 2 + 2]);\n\t\t}\n\t}\n\tvoid set(int i, T x) {\n\t\tevaluate(i);\n\
    \t\ti += n - 1;\n\t\tdat[i] = x;\n\t\twhile (i > 0) {\n\t\t\ti = (i - 1) / 2;\n\
    \t\t\tdat[i] = f(dat[i * 2 + 1], dat[i * 2 + 2]);\n\t\t}\n\t}\n\tvoid apply(int\
    \ l, int r, U x) {\n\t\tapply(l, r, 0, x, 0, n);\n\t}\n\tT query(int l, int r)\
    \ {\n\t\treturn query(l, r, 0, 0, n);\n\t}\n\tT operator[](int i) {\n\t\treturn\
    \ query(i, i + 1, 0, 0, n);\n\t}\n\n\tprivate:\n\tint n;\n\tstd::vector<T> dat;\n\
    \tstd::vector<U> lazy;\n\tusing F = std::function<T(T, T)>;\n\tusing G = std::function<T(U,\
    \ T)>;\n\tusing H = std::function<U(U, U)>;\n\tF f;\n\tG g;\n\tH h;\n\tT et;\n\
    \tU eu;\n\tvoid evaluate(int i) {\n\t\tif (lazy[i] == eu) {\n\t\t\treturn;\n\t\
    \t}\n\t\tif (i < n - 1) {\n\t\t\tlazy[i * 2 + 1] = h(lazy[i], lazy[i * 2 + 1]);\n\
    \t\t\tlazy[i * 2 + 2] = h(lazy[i], lazy[i * 2 + 2]);\n\t\t}\n\t\tdat[i] = g(lazy[i],\
    \ dat[i]);\n\t\tlazy[i] = eu;\n\t}\n\tvoid apply(int left, int right, int i, U\
    \ x, int l, int r) {\n\t\tevaluate(i);\n\t\tif (left <= l && r <= right) {\n\t\
    \t\tlazy[i] = h(x, lazy[i]);\n\t\t\tevaluate(i);\n\t\t} else if (left < r && l\
    \ < right) {\n\t\t\tint mid = (l + r) / 2;\n\t\t\tapply(left, right, i * 2 + 1,\
    \ x, l, mid);\n\t\t\tapply(left, right, i * 2 + 2, x, mid, r);\n\t\t\tdat[i] =\
    \ f(dat[i * 2 + 1], dat[i * 2 + 2]);\n\t\t}\n\t}\n\tT query(int left, int right,\
    \ int i, int l, int r) {\n\t\tevaluate(i);\n\t\tif (r <= left || right <= l) {\n\
    \t\t\treturn et;\n\t\t} else if (left <= l && r <= right) {\n\t\t\treturn dat[i];\n\
    \t\t} else {\n\t\t\tint mid = (l + r) / 2;\n\t\t\treturn f(query(left, right,\
    \ i * 2 + 1, l, mid), query(left, right, i * 2 + 2, mid, r));\n\t\t}\n\t}\n};\n"
  code: "#include <vector>\n#include <functional>\n\n/**\n * @brief Segment Tree Lazy\n\
    \ */\n\ntemplate <typename T, typename U>\nstruct segment_tree_lazy {\n\tsegment_tree_lazy(int\
    \ n, F f, G g, H h, T et, U eu) {\n\t\tthis->n = 1;\n\t\twhile (this->n < n) {\n\
    \t\t\tthis->n *= 2;\n\t\t}\n\t\tthis->f = f;\n\t\tthis->g = g;\n\t\tthis->h =\
    \ h;\n\t\tthis->et = et;\n\t\tthis->eu = eu;\n\t\tdat.resize(this->n * 2 - 1,\
    \ this->et);\n\t\tlazy.resize(this->n * 2 - 1, this->eu);\n\t}\n\tvoid build(const\
    \ vector<T> &A) {\n\t\tfor (int i = 0; i < (int)A.size(); i++) {\n\t\t\tdat[i\
    \ + n - 1] = A[i];\n\t\t}\n\t\tfor (int i = n - 2; i >= 0; i--) {\n\t\t\tdat[i]\
    \ = f(dat[i * 2 + 1], dat[i * 2 + 2]);\n\t\t}\n\t}\n\tvoid set(int i, T x) {\n\
    \t\tevaluate(i);\n\t\ti += n - 1;\n\t\tdat[i] = x;\n\t\twhile (i > 0) {\n\t\t\t\
    i = (i - 1) / 2;\n\t\t\tdat[i] = f(dat[i * 2 + 1], dat[i * 2 + 2]);\n\t\t}\n\t\
    }\n\tvoid apply(int l, int r, U x) {\n\t\tapply(l, r, 0, x, 0, n);\n\t}\n\tT query(int\
    \ l, int r) {\n\t\treturn query(l, r, 0, 0, n);\n\t}\n\tT operator[](int i) {\n\
    \t\treturn query(i, i + 1, 0, 0, n);\n\t}\n\n\tprivate:\n\tint n;\n\tstd::vector<T>\
    \ dat;\n\tstd::vector<U> lazy;\n\tusing F = std::function<T(T, T)>;\n\tusing G\
    \ = std::function<T(U, T)>;\n\tusing H = std::function<U(U, U)>;\n\tF f;\n\tG\
    \ g;\n\tH h;\n\tT et;\n\tU eu;\n\tvoid evaluate(int i) {\n\t\tif (lazy[i] == eu)\
    \ {\n\t\t\treturn;\n\t\t}\n\t\tif (i < n - 1) {\n\t\t\tlazy[i * 2 + 1] = h(lazy[i],\
    \ lazy[i * 2 + 1]);\n\t\t\tlazy[i * 2 + 2] = h(lazy[i], lazy[i * 2 + 2]);\n\t\t\
    }\n\t\tdat[i] = g(lazy[i], dat[i]);\n\t\tlazy[i] = eu;\n\t}\n\tvoid apply(int\
    \ left, int right, int i, U x, int l, int r) {\n\t\tevaluate(i);\n\t\tif (left\
    \ <= l && r <= right) {\n\t\t\tlazy[i] = h(x, lazy[i]);\n\t\t\tevaluate(i);\n\t\
    \t} else if (left < r && l < right) {\n\t\t\tint mid = (l + r) / 2;\n\t\t\tapply(left,\
    \ right, i * 2 + 1, x, l, mid);\n\t\t\tapply(left, right, i * 2 + 2, x, mid, r);\n\
    \t\t\tdat[i] = f(dat[i * 2 + 1], dat[i * 2 + 2]);\n\t\t}\n\t}\n\tT query(int left,\
    \ int right, int i, int l, int r) {\n\t\tevaluate(i);\n\t\tif (r <= left || right\
    \ <= l) {\n\t\t\treturn et;\n\t\t} else if (left <= l && r <= right) {\n\t\t\t\
    return dat[i];\n\t\t} else {\n\t\t\tint mid = (l + r) / 2;\n\t\t\treturn f(query(left,\
    \ right, i * 2 + 1, l, mid), query(left, right, i * 2 + 2, mid, r));\n\t\t}\n\t\
    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/segment_tree_lazy.cpp
  requiredBy: []
  timestamp: '2023-12-24 07:38:27+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/segment_tree_lazy.cpp
layout: document
redirect_from:
- /library/data_structure/segment_tree_lazy.cpp
- /library/data_structure/segment_tree_lazy.cpp.html
title: Segment Tree Lazy
---
