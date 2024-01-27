---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/fenwick_tree.cpp
    title: Fenwick Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Inversion Number
    links: []
  bundledCode: "#line 1 \"algorithm/inversion_number.cpp\"\n#include <vector>\r\n\
    #line 1 \"data_structure/fenwick_tree.cpp\"\n#include <iostream>\r\n#line 3 \"\
    data_structure/fenwick_tree.cpp\"\n\r\n/**\r\n * @brief Fenwick Tree\r\n * @docs\
    \ docs/data_structure/fenwick_tree.md\r\n */\r\n\r\ntemplate <typename T>\r\n\
    struct fenwick_tree {\r\n    fenwick_tree(int n) {\r\n        this->n = n;\r\n\
    \        dat.resize(n);\r\n    }\r\n    void add(int i, T x) {\r\n        i++;\r\
    \n        while (i <= n) {\r\n            dat[i - 1] += x;\r\n            i +=\
    \ i & -i;\r\n        }\r\n    }\r\n    T operator[](int i) {\r\n        return\
    \ sum(i, i + 1);\r\n    }\r\n    T sum(int l, int r) {\r\n        return sum(r)\
    \ - sum(l);\r\n    }\r\n    friend std::ostream &operator<<(std::ostream &os,\
    \ fenwick_tree A) {\r\n        int n = A.n;\r\n        os << \"[ \";\r\n     \
    \   for (int i = 0; i < n; i++) {\r\n            os << A[i];\r\n            if\
    \ (i != n - 1) {\r\n                os << \", \";\r\n            }\r\n       \
    \ }\r\n        os << \" ]\";\r\n        return os;\r\n    }\r\n\r\nprivate:\r\n\
    \    int n;\r\n    std::vector<T> dat;\r\n    T sum(int r) {\r\n        T ret\
    \ = 0;\r\n        while (r > 0) {\r\n            ret += dat[r - 1];\r\n      \
    \      r -= r & -r;\r\n        }\r\n        return ret;\r\n    }\r\n};\n#line\
    \ 3 \"algorithm/inversion_number.cpp\"\n\r\n/**\r\n * @brief Inversion Number\r\
    \n */\r\n\r\nlong long inversion_number(const std::vector<int> &A) {\r\n    int\
    \ n = A.size();\r\n    fenwick_tree<int> ft(n);\r\n    long long ret = 0;\r\n\
    \    for (int i = 0; i < n; i++) {\r\n        ret += i - ft.sum(0, A[i]);\r\n\
    \        ft.add(A[i], 1);\r\n    }\r\n    return ret;\r\n}\r\n"
  code: "#include <vector>\r\n#include \"data_structure/fenwick_tree.cpp\"\r\n\r\n\
    /**\r\n * @brief Inversion Number\r\n */\r\n\r\nlong long inversion_number(const\
    \ std::vector<int> &A) {\r\n    int n = A.size();\r\n    fenwick_tree<int> ft(n);\r\
    \n    long long ret = 0;\r\n    for (int i = 0; i < n; i++) {\r\n        ret +=\
    \ i - ft.sum(0, A[i]);\r\n        ft.add(A[i], 1);\r\n    }\r\n    return ret;\r\
    \n}\r\n"
  dependsOn:
  - data_structure/fenwick_tree.cpp
  isVerificationFile: false
  path: algorithm/inversion_number.cpp
  requiredBy: []
  timestamp: '2024-01-28 02:06:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/inversion_number.cpp
layout: document
redirect_from:
- /library/algorithm/inversion_number.cpp
- /library/algorithm/inversion_number.cpp.html
title: Inversion Number
---
