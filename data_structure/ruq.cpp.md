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
    \nstruct range_update_query {\n    int n;\n    int t;\n    std::vector<std::pair<int,\
    \ int>> dat;\n    range_update_query(int n) {\n        this->n = 1;\n        while\
    \ (this->n < n) {\n            this->n *= 2;\n        }\n        this->t = 0;\n\
    \        dat.resize(this->n * 2 - 1, std::make_pair(0, -1));\n    }\n    int operator[](int\
    \ i) {\n        i += n - 1;\n        int ret = dat[i].first;\n        int last\
    \ = dat[i].second;\n        while (i > 0) {\n            i = (i - 1) / 2;\n  \
    \          if (dat[i].second > last) {\n                last = dat[i].second;\n\
    \                ret = dat[i].first;\n            }\n        }\n    }\n    void\
    \ query(int left, int right, int i, int c, int l, int r) {\n        if (r <= left\
    \ || right <= l) {\n            return;\n        } else if (left <= l && r <=\
    \ right) {\n            dat[i] = std::make_pair(c, t);\n        } else {\n   \
    \         int mid = (l + r) / 2;\n            query(left, right, i * 2 + 1, c,\
    \ l, mid);\n            query(left, right, i * 2 + 2, c, mid, r);\n        }\n\
    \    }\n    void query(int l, int r, int c) {\n        query(l, r, 0, c, 0, n);\n\
    \        t++;\n    }\n};\n"
  code: "#include <vector>\n#include <utility>\n\nstruct range_update_query {\n  \
    \  int n;\n    int t;\n    std::vector<std::pair<int, int>> dat;\n    range_update_query(int\
    \ n) {\n        this->n = 1;\n        while (this->n < n) {\n            this->n\
    \ *= 2;\n        }\n        this->t = 0;\n        dat.resize(this->n * 2 - 1,\
    \ std::make_pair(0, -1));\n    }\n    int operator[](int i) {\n        i += n\
    \ - 1;\n        int ret = dat[i].first;\n        int last = dat[i].second;\n \
    \       while (i > 0) {\n            i = (i - 1) / 2;\n            if (dat[i].second\
    \ > last) {\n                last = dat[i].second;\n                ret = dat[i].first;\n\
    \            }\n        }\n    }\n    void query(int left, int right, int i, int\
    \ c, int l, int r) {\n        if (r <= left || right <= l) {\n            return;\n\
    \        } else if (left <= l && r <= right) {\n            dat[i] = std::make_pair(c,\
    \ t);\n        } else {\n            int mid = (l + r) / 2;\n            query(left,\
    \ right, i * 2 + 1, c, l, mid);\n            query(left, right, i * 2 + 2, c,\
    \ mid, r);\n        }\n    }\n    void query(int l, int r, int c) {\n        query(l,\
    \ r, 0, c, 0, n);\n        t++;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/ruq.cpp
  requiredBy: []
  timestamp: '2024-01-25 11:55:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/ruq.cpp
layout: document
redirect_from:
- /library/data_structure/ruq.cpp
- /library/data_structure/ruq.cpp.html
title: data_structure/ruq.cpp
---
