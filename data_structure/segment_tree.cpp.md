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
    \n */\r\n\r\ntemplate <typename T>\r\nstruct segment_tree {\r\n    template <typename\
    \ F>\r\n    segment_tree(int n, F f, T e) {\r\n        this->n = 1;\r\n      \
    \  while (this->n < n) {\r\n            this->n *= 2;\r\n        }\r\n       \
    \ this->f = f;\r\n        this->e = e;\r\n        dat.resize(this->n * 2 - 1,\
    \ e);\r\n    }\r\n    void build(const std::vector<T> &A) {\r\n        for (int\
    \ i = 0; i < (int)A.size(); i++) {\r\n            dat[i + n - 1] = A[i];\r\n \
    \       }\r\n        for (int i = n - 2; i >= 0; i--) {\r\n            dat[i]\
    \ = f(dat[i * 2 + 1], dat[i * 2 + 2]);\r\n        }\r\n    }\r\n    T operator[](int\
    \ i) {\r\n        return dat[n - 1 + i];\r\n    }\r\n    void set(int i, T x)\
    \ {\r\n        i += n - 1;\r\n        dat[i] = x;\r\n        while (i > 0) {\r\
    \n            i = (i - 1) / 2;\r\n            dat[i] = f(dat[i * 2 + 1], dat[i\
    \ * 2 + 2]);\r\n        }\r\n    }\r\n    T query(int l, int r) {\r\n        return\
    \ query(l, r, 0, 0, n);\r\n    }\r\n\r\nprivate:\r\n    int n;\r\n    std::vector<T>\
    \ dat;\r\n    using F = std::function<T(T, T)>;\r\n    F f;\r\n    T e;\r\n  \
    \  T query(int left, int right, int i, int l, int r) {\r\n        if (r <= left\
    \ || right <= l) {\r\n            return e;\r\n        } else if (left <= l &&\
    \ r <= right) {\r\n            return dat[i];\r\n        } else {\r\n        \
    \    int mid = (l + r) / 2;\r\n            return f(query(left, right, i * 2 +\
    \ 1, l, mid), query(left, right, i * 2 + 2, mid, r));\r\n        }\r\n    }\r\n\
    };\r\n\r\ntemplate <typename U>\r\nsegment_tree<U> range_min_query(int n, U e\
    \ = std::numeric_limits<U>::max()) {\r\n    auto f = [](U a, U b) {\r\n      \
    \  return std::min(a, b);\r\n    };\r\n    return segment_tree<U>(n, f, e);\r\n\
    }\r\n\r\ntemplate <typename U>\r\nsegment_tree<U> range_max_query(int n, U e =\
    \ std::numeric_limits<U>::min()) {\r\n    auto f = [](U a, U b) {\r\n        return\
    \ std::max(a, b);\r\n    };\r\n    return segment_tree<U>(n, f, e);\r\n}\r\n\r\
    \ntemplate <typename U>\r\nsegment_tree<U> range_sum_query(int n, U e = 0) {\r\
    \n    auto f = [](U a, U b) {\r\n        return a + b;\r\n    };\r\n    return\
    \ segment_tree<U>(n, f, e);\r\n}\r\n"
  code: "#include <vector>\r\n#include <functional>\r\n#include <limits>\r\n\r\n/**\r\
    \n * @brief Segment Tree\r\n */\r\n\r\ntemplate <typename T>\r\nstruct segment_tree\
    \ {\r\n    template <typename F>\r\n    segment_tree(int n, F f, T e) {\r\n  \
    \      this->n = 1;\r\n        while (this->n < n) {\r\n            this->n *=\
    \ 2;\r\n        }\r\n        this->f = f;\r\n        this->e = e;\r\n        dat.resize(this->n\
    \ * 2 - 1, e);\r\n    }\r\n    void build(const std::vector<T> &A) {\r\n     \
    \   for (int i = 0; i < (int)A.size(); i++) {\r\n            dat[i + n - 1] =\
    \ A[i];\r\n        }\r\n        for (int i = n - 2; i >= 0; i--) {\r\n       \
    \     dat[i] = f(dat[i * 2 + 1], dat[i * 2 + 2]);\r\n        }\r\n    }\r\n  \
    \  T operator[](int i) {\r\n        return dat[n - 1 + i];\r\n    }\r\n    void\
    \ set(int i, T x) {\r\n        i += n - 1;\r\n        dat[i] = x;\r\n        while\
    \ (i > 0) {\r\n            i = (i - 1) / 2;\r\n            dat[i] = f(dat[i *\
    \ 2 + 1], dat[i * 2 + 2]);\r\n        }\r\n    }\r\n    T query(int l, int r)\
    \ {\r\n        return query(l, r, 0, 0, n);\r\n    }\r\n\r\nprivate:\r\n    int\
    \ n;\r\n    std::vector<T> dat;\r\n    using F = std::function<T(T, T)>;\r\n \
    \   F f;\r\n    T e;\r\n    T query(int left, int right, int i, int l, int r)\
    \ {\r\n        if (r <= left || right <= l) {\r\n            return e;\r\n   \
    \     } else if (left <= l && r <= right) {\r\n            return dat[i];\r\n\
    \        } else {\r\n            int mid = (l + r) / 2;\r\n            return\
    \ f(query(left, right, i * 2 + 1, l, mid), query(left, right, i * 2 + 2, mid,\
    \ r));\r\n        }\r\n    }\r\n};\r\n\r\ntemplate <typename U>\r\nsegment_tree<U>\
    \ range_min_query(int n, U e = std::numeric_limits<U>::max()) {\r\n    auto f\
    \ = [](U a, U b) {\r\n        return std::min(a, b);\r\n    };\r\n    return segment_tree<U>(n,\
    \ f, e);\r\n}\r\n\r\ntemplate <typename U>\r\nsegment_tree<U> range_max_query(int\
    \ n, U e = std::numeric_limits<U>::min()) {\r\n    auto f = [](U a, U b) {\r\n\
    \        return std::max(a, b);\r\n    };\r\n    return segment_tree<U>(n, f,\
    \ e);\r\n}\r\n\r\ntemplate <typename U>\r\nsegment_tree<U> range_sum_query(int\
    \ n, U e = 0) {\r\n    auto f = [](U a, U b) {\r\n        return a + b;\r\n  \
    \  };\r\n    return segment_tree<U>(n, f, e);\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/segment_tree.cpp
  requiredBy: []
  timestamp: '2024-01-25 11:55:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/segment_tree.cpp
layout: document
redirect_from:
- /library/data_structure/segment_tree.cpp
- /library/data_structure/segment_tree.cpp.html
title: Segment Tree
---
