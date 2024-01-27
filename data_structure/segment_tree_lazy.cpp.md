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
  bundledCode: "#line 1 \"data_structure/segment_tree_lazy.cpp\"\n#include <iostream>\n\
    #include <utility>\n#include <vector>\n#include <functional>\n#include <limits>\n\
    \n/**\n * @brief Segment Tree Lazy\n */\n\ntemplate <typename T, typename U>\n\
    struct segment_tree_lazy {\n    template <typename F, typename G, typename H>\n\
    \    segment_tree_lazy(int n, F f, G g, H h, T et, U eu) {\n        this->n =\
    \ 1;\n        while (this->n < n) {\n            this->n *= 2;\n        }\n  \
    \      this->f = f;\n        this->g = g;\n        this->h = h;\n        this->et\
    \ = et;\n        this->eu = eu;\n        dat.resize(this->n * 2 - 1, this->et);\n\
    \        lazy.resize(this->n * 2 - 1, this->eu);\n    }\n    void build(const\
    \ std::vector<T> &A) {\n        for (int i = 0; i < (int)A.size(); i++) {\n  \
    \          dat[i + n - 1] = A[i];\n        }\n        for (int i = n - 2; i >=\
    \ 0; i--) {\n            dat[i] = f(dat[i * 2 + 1], dat[i * 2 + 2]);\n       \
    \ }\n    }\n    void set(int i, T x) {\n        evaluate(i);\n        i += n -\
    \ 1;\n        dat[i] = x;\n        while (i > 0) {\n            i = (i - 1) /\
    \ 2;\n            dat[i] = f(dat[i * 2 + 1], dat[i * 2 + 2]);\n        }\n   \
    \ }\n    void apply(int l, int r, U x) {\n        apply(l, r, 0, x, 0, n);\n \
    \   }\n    T query(int l, int r) {\n        return query(l, r, 0, 0, n);\n   \
    \ }\n    T operator[](int i) {\n        return query(i, i + 1, 0, 0, n);\n   \
    \ }\n    friend std::ostream &operator<<(std::ostream &os, segment_tree_lazy A)\
    \ {\n        int n = A.n;\n        os << \"[ \";\n        for (int i = 0; i <\
    \ n; i++) {\n            os << A[i];\n            if (i != n - 1) {\n        \
    \        os << \", \";\n            }\n        }\n        os << \" ]\";\n    \
    \    return os;\n    }\n\nprivate:\n    int n;\n    std::vector<T> dat;\n    std::vector<U>\
    \ lazy;\n    using F = std::function<T(T, T)>;\n    using G = std::function<T(U,\
    \ T)>;\n    using H = std::function<U(U, U)>;\n    F f;\n    G g;\n    H h;\n\
    \    T et;\n    U eu;\n    void evaluate(int i) {\n        if (lazy[i] == eu)\
    \ {\n            return;\n        }\n        if (i < n - 1) {\n            lazy[i\
    \ * 2 + 1] = h(lazy[i], lazy[i * 2 + 1]);\n            lazy[i * 2 + 2] = h(lazy[i],\
    \ lazy[i * 2 + 2]);\n        }\n        dat[i] = g(lazy[i], dat[i]);\n       \
    \ lazy[i] = eu;\n    }\n    void apply(int left, int right, int i, U x, int l,\
    \ int r) {\n        evaluate(i);\n        if (left <= l && r <= right) {\n   \
    \         lazy[i] = h(x, lazy[i]);\n            evaluate(i);\n        } else if\
    \ (left < r && l < right) {\n            int mid = (l + r) / 2;\n            apply(left,\
    \ right, i * 2 + 1, x, l, mid);\n            apply(left, right, i * 2 + 2, x,\
    \ mid, r);\n            dat[i] = f(dat[i * 2 + 1], dat[i * 2 + 2]);\n        }\n\
    \    }\n    T query(int left, int right, int i, int l, int r) {\n        evaluate(i);\n\
    \        if (r <= left || right <= l) {\n            return et;\n        } else\
    \ if (left <= l && r <= right) {\n            return dat[i];\n        } else {\n\
    \            int mid = (l + r) / 2;\n            return f(query(left, right, i\
    \ * 2 + 1, l, mid), query(left, right, i * 2 + 2, mid, r));\n        }\n    }\n\
    };\n\ntemplate <typename T, typename U>\nsegment_tree_lazy<T, U> range_add_range_min(int\
    \ n) {\n    const T et = std::numeric_limits<T>::max();\n    const U eu = 0;\n\
    \    auto f = [](T a, T b) {\n        return std::min(a, b);\n    };\n    auto\
    \ g = [](U f, T x) {\n        return f + x;\n    };\n    auto h = [](U f, U g)\
    \ {\n        return f + g;\n    };\n    return segment_tree_lazy<T, U>(n, f, g,\
    \ h, et, eu);\n}\n\ntemplate <typename T, typename U>\nsegment_tree_lazy<T, U>\
    \ range_add_range_max(int n) {\n    const T et = std::numeric_limits<T>::min();\n\
    \    const U eu = 0;\n    auto f = [](T a, T b) {\n        return std::max(a,\
    \ b);\n    };\n    auto g = [](U f, T x) {\n        return f + x;\n    };\n  \
    \  auto h = [](U f, U g) {\n        return f + g;\n    };\n    return segment_tree_lazy<T,\
    \ U>(n, f, g, h, et, eu);\n}\n\ntemplate <typename T, typename U>\nsegment_tree_lazy<std::pair<T,\
    \ int>, U> range_add_range_sum(int n) {\n    using T2 = std::pair<T, int>;\n \
    \   const T2 et = std::make_pair(T(0), 0);\n    const U eu = 0;\n    auto f =\
    \ [](T2 a, T2 b) {\n        return std::make_pair(a.first + b.first, a.second\
    \ + b.second);\n    };\n    auto g = [](U f, T2 x) {\n        return std::make_pair(x.first\
    \ + (T)f * x.second, x.second);\n    };\n    auto h = [](U f, U g) {\n       \
    \ return f + g;\n    };\n    return segment_tree_lazy<T2, U>(n, f, g, h, et, eu);\n\
    }\n\ntemplate <typename T>\nsegment_tree_lazy<T, T> range_update_range_min(int\
    \ n, T eu = std::numeric_limits<T>::max()) {\n    const T et = std::numeric_limits<T>::max();\n\
    \    auto f = [](T a, T b) {\n        return std::min(a, b);\n    };\n    auto\
    \ g = [eu](T f, T x) {\n        if (f == eu) return x;\n        return f;\n  \
    \  };\n    return segment_tree_lazy<T, T>(n, f, g, g, et, eu);\n}\n\ntemplate\
    \ <typename T>\nsegment_tree_lazy<T, T> range_update_range_max(int n, T eu = std::numeric_limits<T>::max())\
    \ {\n    const T et = std::numeric_limits<T>::min();\n    auto f = [](T a, T b)\
    \ {\n        return std::max(a, b);\n    };\n    auto g = [eu](T f, T x) {\n \
    \       if (f == eu) return x;\n        return f;\n    };\n    return segment_tree_lazy<T,\
    \ T>(n, f, g, g, et, eu);\n}\n\ntemplate <typename T>\nsegment_tree_lazy<std::pair<T,\
    \ int>, T> range_update_range_sum(int n, T eu = std::numeric_limits<T>::max())\
    \ {\n    using T2 = std::pair<T, int>;\n    const T2 et = std::make_pair(T(0),\
    \ 0);\n    auto f = [](T2 a, T2 b) {\n        return std::make_pair(a.first +\
    \ b.first, a.second + b.second);\n    };\n    auto g = [eu](T f, T2 x) {\n   \
    \     if (f == eu) return x;\n        return std::make_pair(f * x.second, x.second);\n\
    \    };\n    auto h = [eu](T f, T g) {\n        if (f == eu) return g;\n     \
    \   return f;\n    };\n    return segment_tree_lazy<T, T>(n, f, g, h, et, eu);\n\
    }\n"
  code: "#include <iostream>\n#include <utility>\n#include <vector>\n#include <functional>\n\
    #include <limits>\n\n/**\n * @brief Segment Tree Lazy\n */\n\ntemplate <typename\
    \ T, typename U>\nstruct segment_tree_lazy {\n    template <typename F, typename\
    \ G, typename H>\n    segment_tree_lazy(int n, F f, G g, H h, T et, U eu) {\n\
    \        this->n = 1;\n        while (this->n < n) {\n            this->n *= 2;\n\
    \        }\n        this->f = f;\n        this->g = g;\n        this->h = h;\n\
    \        this->et = et;\n        this->eu = eu;\n        dat.resize(this->n *\
    \ 2 - 1, this->et);\n        lazy.resize(this->n * 2 - 1, this->eu);\n    }\n\
    \    void build(const std::vector<T> &A) {\n        for (int i = 0; i < (int)A.size();\
    \ i++) {\n            dat[i + n - 1] = A[i];\n        }\n        for (int i =\
    \ n - 2; i >= 0; i--) {\n            dat[i] = f(dat[i * 2 + 1], dat[i * 2 + 2]);\n\
    \        }\n    }\n    void set(int i, T x) {\n        evaluate(i);\n        i\
    \ += n - 1;\n        dat[i] = x;\n        while (i > 0) {\n            i = (i\
    \ - 1) / 2;\n            dat[i] = f(dat[i * 2 + 1], dat[i * 2 + 2]);\n       \
    \ }\n    }\n    void apply(int l, int r, U x) {\n        apply(l, r, 0, x, 0,\
    \ n);\n    }\n    T query(int l, int r) {\n        return query(l, r, 0, 0, n);\n\
    \    }\n    T operator[](int i) {\n        return query(i, i + 1, 0, 0, n);\n\
    \    }\n    friend std::ostream &operator<<(std::ostream &os, segment_tree_lazy\
    \ A) {\n        int n = A.n;\n        os << \"[ \";\n        for (int i = 0; i\
    \ < n; i++) {\n            os << A[i];\n            if (i != n - 1) {\n      \
    \          os << \", \";\n            }\n        }\n        os << \" ]\";\n  \
    \      return os;\n    }\n\nprivate:\n    int n;\n    std::vector<T> dat;\n  \
    \  std::vector<U> lazy;\n    using F = std::function<T(T, T)>;\n    using G =\
    \ std::function<T(U, T)>;\n    using H = std::function<U(U, U)>;\n    F f;\n \
    \   G g;\n    H h;\n    T et;\n    U eu;\n    void evaluate(int i) {\n       \
    \ if (lazy[i] == eu) {\n            return;\n        }\n        if (i < n - 1)\
    \ {\n            lazy[i * 2 + 1] = h(lazy[i], lazy[i * 2 + 1]);\n            lazy[i\
    \ * 2 + 2] = h(lazy[i], lazy[i * 2 + 2]);\n        }\n        dat[i] = g(lazy[i],\
    \ dat[i]);\n        lazy[i] = eu;\n    }\n    void apply(int left, int right,\
    \ int i, U x, int l, int r) {\n        evaluate(i);\n        if (left <= l &&\
    \ r <= right) {\n            lazy[i] = h(x, lazy[i]);\n            evaluate(i);\n\
    \        } else if (left < r && l < right) {\n            int mid = (l + r) /\
    \ 2;\n            apply(left, right, i * 2 + 1, x, l, mid);\n            apply(left,\
    \ right, i * 2 + 2, x, mid, r);\n            dat[i] = f(dat[i * 2 + 1], dat[i\
    \ * 2 + 2]);\n        }\n    }\n    T query(int left, int right, int i, int l,\
    \ int r) {\n        evaluate(i);\n        if (r <= left || right <= l) {\n   \
    \         return et;\n        } else if (left <= l && r <= right) {\n        \
    \    return dat[i];\n        } else {\n            int mid = (l + r) / 2;\n  \
    \          return f(query(left, right, i * 2 + 1, l, mid), query(left, right,\
    \ i * 2 + 2, mid, r));\n        }\n    }\n};\n\ntemplate <typename T, typename\
    \ U>\nsegment_tree_lazy<T, U> range_add_range_min(int n) {\n    const T et = std::numeric_limits<T>::max();\n\
    \    const U eu = 0;\n    auto f = [](T a, T b) {\n        return std::min(a,\
    \ b);\n    };\n    auto g = [](U f, T x) {\n        return f + x;\n    };\n  \
    \  auto h = [](U f, U g) {\n        return f + g;\n    };\n    return segment_tree_lazy<T,\
    \ U>(n, f, g, h, et, eu);\n}\n\ntemplate <typename T, typename U>\nsegment_tree_lazy<T,\
    \ U> range_add_range_max(int n) {\n    const T et = std::numeric_limits<T>::min();\n\
    \    const U eu = 0;\n    auto f = [](T a, T b) {\n        return std::max(a,\
    \ b);\n    };\n    auto g = [](U f, T x) {\n        return f + x;\n    };\n  \
    \  auto h = [](U f, U g) {\n        return f + g;\n    };\n    return segment_tree_lazy<T,\
    \ U>(n, f, g, h, et, eu);\n}\n\ntemplate <typename T, typename U>\nsegment_tree_lazy<std::pair<T,\
    \ int>, U> range_add_range_sum(int n) {\n    using T2 = std::pair<T, int>;\n \
    \   const T2 et = std::make_pair(T(0), 0);\n    const U eu = 0;\n    auto f =\
    \ [](T2 a, T2 b) {\n        return std::make_pair(a.first + b.first, a.second\
    \ + b.second);\n    };\n    auto g = [](U f, T2 x) {\n        return std::make_pair(x.first\
    \ + (T)f * x.second, x.second);\n    };\n    auto h = [](U f, U g) {\n       \
    \ return f + g;\n    };\n    return segment_tree_lazy<T2, U>(n, f, g, h, et, eu);\n\
    }\n\ntemplate <typename T>\nsegment_tree_lazy<T, T> range_update_range_min(int\
    \ n, T eu = std::numeric_limits<T>::max()) {\n    const T et = std::numeric_limits<T>::max();\n\
    \    auto f = [](T a, T b) {\n        return std::min(a, b);\n    };\n    auto\
    \ g = [eu](T f, T x) {\n        if (f == eu) return x;\n        return f;\n  \
    \  };\n    return segment_tree_lazy<T, T>(n, f, g, g, et, eu);\n}\n\ntemplate\
    \ <typename T>\nsegment_tree_lazy<T, T> range_update_range_max(int n, T eu = std::numeric_limits<T>::max())\
    \ {\n    const T et = std::numeric_limits<T>::min();\n    auto f = [](T a, T b)\
    \ {\n        return std::max(a, b);\n    };\n    auto g = [eu](T f, T x) {\n \
    \       if (f == eu) return x;\n        return f;\n    };\n    return segment_tree_lazy<T,\
    \ T>(n, f, g, g, et, eu);\n}\n\ntemplate <typename T>\nsegment_tree_lazy<std::pair<T,\
    \ int>, T> range_update_range_sum(int n, T eu = std::numeric_limits<T>::max())\
    \ {\n    using T2 = std::pair<T, int>;\n    const T2 et = std::make_pair(T(0),\
    \ 0);\n    auto f = [](T2 a, T2 b) {\n        return std::make_pair(a.first +\
    \ b.first, a.second + b.second);\n    };\n    auto g = [eu](T f, T2 x) {\n   \
    \     if (f == eu) return x;\n        return std::make_pair(f * x.second, x.second);\n\
    \    };\n    auto h = [eu](T f, T g) {\n        if (f == eu) return g;\n     \
    \   return f;\n    };\n    return segment_tree_lazy<T, T>(n, f, g, h, et, eu);\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/segment_tree_lazy.cpp
  requiredBy: []
  timestamp: '2024-01-28 02:06:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/segment_tree_lazy.cpp
layout: document
redirect_from:
- /library/data_structure/segment_tree_lazy.cpp
- /library/data_structure/segment_tree_lazy.cpp.html
title: Segment Tree Lazy
---
