---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Binary Trie
    links: []
  bundledCode: "#line 1 \"data_structure/binary_trie.cpp\"\n#include <utility>\n#include\
    \ <cassert>\n\n/**\n * @brief Binary Trie\n */\n\ntemplate <typename T = unsigned\
    \ int, int LOG = 32>\nstruct binary_trie {\n    binary_trie() {\n        root\
    \ = nullptr;\n    }\n    int size() const {\n        if (root == nullptr) {\n\
    \            return 0;\n        }\n        return root->size;\n    }\n    void\
    \ insert(T x, int cnt = 1) {\n        root = insert(root, x, LOG - 1, cnt);\n\
    \    }\n    void erase(T x, int cnt = 1) {\n        cnt = std::min(cnt, count(x));\n\
    \        if (cnt == 0) {\n            return;\n        }\n        root = erase(root,\
    \ x, LOG - 1, cnt);\n    }\n    void apply_xor(T x) {\n        if (root != nullptr)\
    \ {\n            root->lazy ^= x;\n        }\n    }\n    T max_element(T bias\
    \ = 0) {\n        return get_min(root, ~bias, LOG - 1);\n    }\n    T min_element(T\
    \ bias = 0) {\n        return get_min(root, bias, LOG - 1);\n    }\n    T operator[](int\
    \ k) {\n        assert(0 <= k && k < size());\n        return get(root, k, LOG\
    \ - 1);\n    }\n    int lower_bound(T x) {\n        return count_lower(root, x,\
    \ LOG - 1);\n    }\n    int upper_bound(T x) {\n        return count_lower(root,\
    \ x + 1, LOG - 1);\n    }\n    int count(T x) {\n        if (root == nullptr)\
    \ {\n            return 0;\n        }\n        node* v = root;\n        for (int\
    \ i = LOG - 1; i >= 0; i--) {\n            evaluate(v, i);\n            v = v->next[(x\
    \ >> i) & 1];\n            if (v == nullptr) {\n                return 0;\n  \
    \          }\n        }\n        return v->size;\n    }\n\nprivate:\n    struct\
    \ node {\n        node* next[2];\n        int size;\n        T lazy;\n       \
    \ node() {\n            size = 0;\n            lazy = 0;\n            next[0]\
    \ = next[1] = nullptr;\n        }\n    };\n    node* root;\n    void evaluate(node*\
    \ v, int bit) {\n        if ((v->lazy >> bit) & 1) {\n            std::swap(v->next[0],\
    \ v->next[1]);\n        }\n        if (v->next[0] != nullptr) {\n            v->next[0]->lazy\
    \ ^= v->lazy;\n        }\n        if (v->next[1] != nullptr) {\n            v->next[1]->lazy\
    \ ^= v->lazy;\n        }\n        v->lazy = 0;\n    }\n    node* insert(node*\
    \ v, T x, int bit, int cnt) {\n        if (v == nullptr) {\n            v = new\
    \ node;\n        }\n        v->size += cnt;\n        if (bit < 0) {\n        \
    \    return v;\n        }\n        evaluate(v, bit);\n        int lr = (x >> bit)\
    \ & 1;\n        v->next[lr] = insert(v->next[lr], x, bit - 1, cnt);\n        return\
    \ v;\n    }\n    node* erase(node* v, T x, int bit, int cnt) {\n        assert(v\
    \ != nullptr);\n        v->size -= cnt;\n        if (v->size == 0) {\n       \
    \     return nullptr;\n        }\n        if (bit < 0) {\n            return v;\n\
    \        }\n        evaluate(v, bit);\n        int lr = (x >> bit) & 1;\n    \
    \    v->next[lr] = erase(v->next[lr], x, bit - 1, cnt);\n        return v;\n \
    \   }\n    T get_min(node* v, T x, int bit) {\n        if (bit < 0) {\n      \
    \      return 0;\n        }\n        evaluate(v, bit);\n        int lr = (x >>\
    \ bit) & 1;\n        if (v->next[lr] == nullptr) {\n            lr = 1 - lr;\n\
    \        }\n        return get_min(v->next[lr], x, bit - 1) | ((T)lr << bit);\n\
    \    }\n    T get(node* v, int k, int bit) {\n        if (bit < 0) {\n       \
    \     return 0;\n        }\n        evaluate(v, bit);\n        int m = v->next[0]\
    \ != nullptr ? v->next[0]->size : 0;\n        if (k < m) {\n            return\
    \ get(v->next[0], k, bit - 1);\n        } else {\n            return get(v->next[1],\
    \ k - m, bit - 1) | ((T)1 << bit);\n        }\n    }\n    int count_lower(node*\
    \ v, T x, int bit) {\n        if (v == nullptr || bit < 0) {\n            return\
    \ 0;\n        }\n        evaluate(v, bit);\n        int lr = (x >> bit) & 1;\n\
    \        int ret = lr && v->next[0] != nullptr ? v->next[0]->size : 0;\n     \
    \   return ret + count_lower(v->next[lr], x, bit - 1);\n    }\n};\n"
  code: "#include <utility>\n#include <cassert>\n\n/**\n * @brief Binary Trie\n */\n\
    \ntemplate <typename T = unsigned int, int LOG = 32>\nstruct binary_trie {\n \
    \   binary_trie() {\n        root = nullptr;\n    }\n    int size() const {\n\
    \        if (root == nullptr) {\n            return 0;\n        }\n        return\
    \ root->size;\n    }\n    void insert(T x, int cnt = 1) {\n        root = insert(root,\
    \ x, LOG - 1, cnt);\n    }\n    void erase(T x, int cnt = 1) {\n        cnt =\
    \ std::min(cnt, count(x));\n        if (cnt == 0) {\n            return;\n   \
    \     }\n        root = erase(root, x, LOG - 1, cnt);\n    }\n    void apply_xor(T\
    \ x) {\n        if (root != nullptr) {\n            root->lazy ^= x;\n       \
    \ }\n    }\n    T max_element(T bias = 0) {\n        return get_min(root, ~bias,\
    \ LOG - 1);\n    }\n    T min_element(T bias = 0) {\n        return get_min(root,\
    \ bias, LOG - 1);\n    }\n    T operator[](int k) {\n        assert(0 <= k &&\
    \ k < size());\n        return get(root, k, LOG - 1);\n    }\n    int lower_bound(T\
    \ x) {\n        return count_lower(root, x, LOG - 1);\n    }\n    int upper_bound(T\
    \ x) {\n        return count_lower(root, x + 1, LOG - 1);\n    }\n    int count(T\
    \ x) {\n        if (root == nullptr) {\n            return 0;\n        }\n   \
    \     node* v = root;\n        for (int i = LOG - 1; i >= 0; i--) {\n        \
    \    evaluate(v, i);\n            v = v->next[(x >> i) & 1];\n            if (v\
    \ == nullptr) {\n                return 0;\n            }\n        }\n       \
    \ return v->size;\n    }\n\nprivate:\n    struct node {\n        node* next[2];\n\
    \        int size;\n        T lazy;\n        node() {\n            size = 0;\n\
    \            lazy = 0;\n            next[0] = next[1] = nullptr;\n        }\n\
    \    };\n    node* root;\n    void evaluate(node* v, int bit) {\n        if ((v->lazy\
    \ >> bit) & 1) {\n            std::swap(v->next[0], v->next[1]);\n        }\n\
    \        if (v->next[0] != nullptr) {\n            v->next[0]->lazy ^= v->lazy;\n\
    \        }\n        if (v->next[1] != nullptr) {\n            v->next[1]->lazy\
    \ ^= v->lazy;\n        }\n        v->lazy = 0;\n    }\n    node* insert(node*\
    \ v, T x, int bit, int cnt) {\n        if (v == nullptr) {\n            v = new\
    \ node;\n        }\n        v->size += cnt;\n        if (bit < 0) {\n        \
    \    return v;\n        }\n        evaluate(v, bit);\n        int lr = (x >> bit)\
    \ & 1;\n        v->next[lr] = insert(v->next[lr], x, bit - 1, cnt);\n        return\
    \ v;\n    }\n    node* erase(node* v, T x, int bit, int cnt) {\n        assert(v\
    \ != nullptr);\n        v->size -= cnt;\n        if (v->size == 0) {\n       \
    \     return nullptr;\n        }\n        if (bit < 0) {\n            return v;\n\
    \        }\n        evaluate(v, bit);\n        int lr = (x >> bit) & 1;\n    \
    \    v->next[lr] = erase(v->next[lr], x, bit - 1, cnt);\n        return v;\n \
    \   }\n    T get_min(node* v, T x, int bit) {\n        if (bit < 0) {\n      \
    \      return 0;\n        }\n        evaluate(v, bit);\n        int lr = (x >>\
    \ bit) & 1;\n        if (v->next[lr] == nullptr) {\n            lr = 1 - lr;\n\
    \        }\n        return get_min(v->next[lr], x, bit - 1) | ((T)lr << bit);\n\
    \    }\n    T get(node* v, int k, int bit) {\n        if (bit < 0) {\n       \
    \     return 0;\n        }\n        evaluate(v, bit);\n        int m = v->next[0]\
    \ != nullptr ? v->next[0]->size : 0;\n        if (k < m) {\n            return\
    \ get(v->next[0], k, bit - 1);\n        } else {\n            return get(v->next[1],\
    \ k - m, bit - 1) | ((T)1 << bit);\n        }\n    }\n    int count_lower(node*\
    \ v, T x, int bit) {\n        if (v == nullptr || bit < 0) {\n            return\
    \ 0;\n        }\n        evaluate(v, bit);\n        int lr = (x >> bit) & 1;\n\
    \        int ret = lr && v->next[0] != nullptr ? v->next[0]->size : 0;\n     \
    \   return ret + count_lower(v->next[lr], x, bit - 1);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/binary_trie.cpp
  requiredBy: []
  timestamp: '2024-01-25 11:55:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/binary_trie.cpp
layout: document
redirect_from:
- /library/data_structure/binary_trie.cpp
- /library/data_structure/binary_trie.cpp.html
title: Binary Trie
---
