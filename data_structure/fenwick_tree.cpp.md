---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/fenwick_tree/fenwick_tree.test.cpp
    title: test/data_structure/fenwick_tree/fenwick_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data_structure/fenwick_tree.md
    document_title: Fenwick Tree
    links: []
  bundledCode: "#line 1 \"data_structure/fenwick_tree.cpp\"\n/**\r\n * @brief Fenwick\
    \ Tree\r\n * @docs docs/data_structure/fenwick_tree.md\r\n*/\r\n\r\ntemplate <typename\
    \ T>\r\nstruct fenwick_tree {\r\n\tint n;\r\n\tvector<T> dat;\r\n\tfenwick_tree(int\
    \ n) {\r\n\t\tthis->n = n;\r\n\t\tdat.resize(n);\r\n\t}\r\n\tvoid add(int i, T\
    \ x) {\r\n\t\ti++;\r\n\t\twhile (i <= n) {\r\n\t\t\tdat[i - 1] += x;\r\n\t\t\t\
    i += i & -i;\r\n\t\t}\r\n\t}\r\n\tT sum(int l, int r) {\r\n\t\treturn sum(r) -\
    \ sum(l);\r\n\t}\r\n\tT sum(int r) {\r\n\t\tT ret = 0;\r\n\t\twhile (r > 0) {\r\
    \n\t\t\tret += dat[r - 1];\r\n\t\t\tr -= r & -r;\r\n\t\t}\r\n\t\treturn ret;\r\
    \n\t}\r\n\tT operator[](int i) {\r\n\t\treturn sum(i, i + 1);\r\n\t}\r\n};\n"
  code: "/**\r\n * @brief Fenwick Tree\r\n * @docs docs/data_structure/fenwick_tree.md\r\
    \n*/\r\n\r\ntemplate <typename T>\r\nstruct fenwick_tree {\r\n\tint n;\r\n\tvector<T>\
    \ dat;\r\n\tfenwick_tree(int n) {\r\n\t\tthis->n = n;\r\n\t\tdat.resize(n);\r\n\
    \t}\r\n\tvoid add(int i, T x) {\r\n\t\ti++;\r\n\t\twhile (i <= n) {\r\n\t\t\t\
    dat[i - 1] += x;\r\n\t\t\ti += i & -i;\r\n\t\t}\r\n\t}\r\n\tT sum(int l, int r)\
    \ {\r\n\t\treturn sum(r) - sum(l);\r\n\t}\r\n\tT sum(int r) {\r\n\t\tT ret = 0;\r\
    \n\t\twhile (r > 0) {\r\n\t\t\tret += dat[r - 1];\r\n\t\t\tr -= r & -r;\r\n\t\t\
    }\r\n\t\treturn ret;\r\n\t}\r\n\tT operator[](int i) {\r\n\t\treturn sum(i, i\
    \ + 1);\r\n\t}\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/fenwick_tree.cpp
  requiredBy: []
  timestamp: '2023-11-30 20:49:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/fenwick_tree/fenwick_tree.test.cpp
documentation_of: data_structure/fenwick_tree.cpp
layout: document
redirect_from:
- /library/data_structure/fenwick_tree.cpp
- /library/data_structure/fenwick_tree.cpp.html
title: Fenwick Tree
---

ac-library/fenwicktreeと仕様はほぼ同じです。

```fenwick_tree<T> ft(int n)```
- $O(n)$


```ft.add(int i, T x)```
- 位置`i`に`x`を加算する。
- $0\le p<n$
- $O(\log{n})$


```ft.sum(int l, int r)```
- 区間`[l,r)`の総和を返す。
- $0\le l \le r\le n$
- $O(\log{n})$

#### 区間加算1点取得をしたい場合
```cpp
fenwick_tree<int> ft(N + 1);

// 区間加算
ft.add(l, x);
ft.add(r + 1, x);

// 取得
ft.sum(i + 1);
```