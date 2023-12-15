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
    \ int, int LOG = 32>\nstruct binary_trie {\n\tbinary_trie() {\n\t\troot = nullptr;\n\
    \t}\n\tint size() const {\n\t\tif (root == nullptr) {\n\t\t\treturn 0;\n\t\t}\n\
    \t\treturn root->size;\n\t}\n\tvoid insert(T x, int cnt = 1) {\n\t\troot = insert(root,\
    \ x, LOG - 1, cnt);\n\t}\n\tvoid erase(T x, int cnt = 1) {\n\t\tcnt = std::min(cnt,\
    \ count(x));\n\t\tif (cnt == 0) {\n\t\t\treturn;\n\t\t}\n\t\troot = erase(root,\
    \ x, LOG - 1, cnt);\n\t}\n\tvoid apply_xor(T x) {\n\t\tif (root != nullptr) {\n\
    \t\t\troot->lazy ^= x;\n\t\t}\n\t}\n\tT max_element(T bias = 0) {\n\t\treturn\
    \ get_min(root, ~bias, LOG - 1);\n\t}\n\tT min_element(T bias = 0) {\n\t\treturn\
    \ get_min(root, bias, LOG - 1);\n\t}\n\tT operator[](int k) {\n\t\tassert(0 <=\
    \ k && k < size());\n\t\treturn get(root, k, LOG - 1);\n\t}\n\tint lower_bound(T\
    \ x) {\n\t\treturn count_lower(root, x, LOG - 1);\n\t}\n\tint upper_bound(T x)\
    \ {\n\t\treturn count_lower(root, x + 1, LOG - 1);\n\t}\n\tint count(T x) {\n\t\
    \tif (root == nullptr) {\n\t\t\treturn 0;\n\t\t}\n\t\tnode* v = root;\n\t\tfor\
    \ (int i = LOG - 1; i >= 0; i--) {\n\t\t\tevaluate(v, i);\n\t\t\tv = v->next[(x\
    \ >> i) & 1];\n\t\t\tif (v == nullptr) {\n\t\t\t\treturn 0;\n\t\t\t}\n\t\t}\n\t\
    \treturn v->size;\n\t}\n\n\tprivate:\n\tstruct node {\n\t\tnode* next[2];\n\t\t\
    int size;\n\t\tT lazy;\n\t\tnode() {\n\t\t\tsize = 0;\n\t\t\tlazy = 0;\n\t\t\t\
    next[0] = next[1] = nullptr;\n\t\t}\n\t};\n\tnode* root;\n\tvoid evaluate(node*\
    \ v, int bit) {\n\t\tif ((v->lazy >> bit) & 1) {\n\t\t\tstd::swap(v->next[0],\
    \ v->next[1]);\n\t\t}\n\t\tif (v->next[0] != nullptr) {\n\t\t\tv->next[0]->lazy\
    \ ^= v->lazy;\n\t\t}\n\t\tif (v->next[1] != nullptr) {\n\t\t\tv->next[1]->lazy\
    \ ^= v->lazy;\n\t\t}\n\t\tv->lazy = 0;\n\t}\n\tnode* insert(node* v, T x, int\
    \ bit, int cnt) {\n\t\tif (v == nullptr) {\n\t\t\tv = new node;\n\t\t}\n\t\tv->size\
    \ += cnt;\n\t\tif (bit < 0) {\n\t\t\treturn v;\n\t\t}\n\t\tevaluate(v, bit);\n\
    \t\tint lr = (x >> bit) & 1;\n\t\tv->next[lr] = insert(v->next[lr], x, bit - 1,\
    \ cnt);\n\t\treturn v;\n\t}\n\tnode* erase(node* v, T x, int bit, int cnt) {\n\
    \t\tassert(v != nullptr);\n\t\tv->size -= cnt;\n\t\tif (v->size == 0) {\n\t\t\t\
    return nullptr;\n\t\t}\n\t\tif (bit < 0) {\n\t\t\treturn v;\n\t\t}\n\t\tevaluate(v,\
    \ bit);\n\t\tint lr = (x >> bit) & 1;\n\t\tv->next[lr] = erase(v->next[lr], x,\
    \ bit - 1, cnt);\n\t\treturn v;\n\t}\n\tT get_min(node* v, T x, int bit) {\n\t\
    \tif (bit < 0) {\n\t\t\treturn 0;\n\t\t}\n\t\tevaluate(v, bit);\n\t\tint lr =\
    \ (x >> bit) & 1;\n\t\tif (v->next[lr] == nullptr) {\n\t\t\tlr = 1 - lr;\n\t\t\
    }\n\t\treturn get_min(v->next[lr], x, bit - 1) | ((T)lr << bit);\n\t}\n\tT get(node*\
    \ v, int k, int bit) {\n\t\tif (bit < 0) {\n\t\t\treturn 0;\n\t\t}\n\t\tevaluate(v,\
    \ bit);\n\t\tint m = v->next[0] != nullptr ? v->next[0]->size : 0;\n\t\tif (k\
    \ < m) {\n\t\t\treturn get(v->next[0], k, bit - 1);\n\t\t} else {\n\t\t\treturn\
    \ get(v->next[1], k - m, bit - 1) | ((T)1 << bit);\n\t\t}\n\t}\n\tint count_lower(node*\
    \ v, T x, int bit) {\n\t\tif (v == nullptr || bit < 0) {\n\t\t\treturn 0;\n\t\t\
    }\n\t\tevaluate(v, bit);\n\t\tint lr = (x >> bit) & 1;\n\t\tint ret = lr && v->next[0]\
    \ != nullptr ? v->next[0]->size : 0;\n\t\treturn ret + count_lower(v->next[lr],\
    \ x, bit - 1);\n\t}\n};\n"
  code: "#include <utility>\n#include <cassert>\n\n/**\n * @brief Binary Trie\n */\n\
    \ntemplate <typename T = unsigned int, int LOG = 32>\nstruct binary_trie {\n\t\
    binary_trie() {\n\t\troot = nullptr;\n\t}\n\tint size() const {\n\t\tif (root\
    \ == nullptr) {\n\t\t\treturn 0;\n\t\t}\n\t\treturn root->size;\n\t}\n\tvoid insert(T\
    \ x, int cnt = 1) {\n\t\troot = insert(root, x, LOG - 1, cnt);\n\t}\n\tvoid erase(T\
    \ x, int cnt = 1) {\n\t\tcnt = std::min(cnt, count(x));\n\t\tif (cnt == 0) {\n\
    \t\t\treturn;\n\t\t}\n\t\troot = erase(root, x, LOG - 1, cnt);\n\t}\n\tvoid apply_xor(T\
    \ x) {\n\t\tif (root != nullptr) {\n\t\t\troot->lazy ^= x;\n\t\t}\n\t}\n\tT max_element(T\
    \ bias = 0) {\n\t\treturn get_min(root, ~bias, LOG - 1);\n\t}\n\tT min_element(T\
    \ bias = 0) {\n\t\treturn get_min(root, bias, LOG - 1);\n\t}\n\tT operator[](int\
    \ k) {\n\t\tassert(0 <= k && k < size());\n\t\treturn get(root, k, LOG - 1);\n\
    \t}\n\tint lower_bound(T x) {\n\t\treturn count_lower(root, x, LOG - 1);\n\t}\n\
    \tint upper_bound(T x) {\n\t\treturn count_lower(root, x + 1, LOG - 1);\n\t}\n\
    \tint count(T x) {\n\t\tif (root == nullptr) {\n\t\t\treturn 0;\n\t\t}\n\t\tnode*\
    \ v = root;\n\t\tfor (int i = LOG - 1; i >= 0; i--) {\n\t\t\tevaluate(v, i);\n\
    \t\t\tv = v->next[(x >> i) & 1];\n\t\t\tif (v == nullptr) {\n\t\t\t\treturn 0;\n\
    \t\t\t}\n\t\t}\n\t\treturn v->size;\n\t}\n\n\tprivate:\n\tstruct node {\n\t\t\
    node* next[2];\n\t\tint size;\n\t\tT lazy;\n\t\tnode() {\n\t\t\tsize = 0;\n\t\t\
    \tlazy = 0;\n\t\t\tnext[0] = next[1] = nullptr;\n\t\t}\n\t};\n\tnode* root;\n\t\
    void evaluate(node* v, int bit) {\n\t\tif ((v->lazy >> bit) & 1) {\n\t\t\tstd::swap(v->next[0],\
    \ v->next[1]);\n\t\t}\n\t\tif (v->next[0] != nullptr) {\n\t\t\tv->next[0]->lazy\
    \ ^= v->lazy;\n\t\t}\n\t\tif (v->next[1] != nullptr) {\n\t\t\tv->next[1]->lazy\
    \ ^= v->lazy;\n\t\t}\n\t\tv->lazy = 0;\n\t}\n\tnode* insert(node* v, T x, int\
    \ bit, int cnt) {\n\t\tif (v == nullptr) {\n\t\t\tv = new node;\n\t\t}\n\t\tv->size\
    \ += cnt;\n\t\tif (bit < 0) {\n\t\t\treturn v;\n\t\t}\n\t\tevaluate(v, bit);\n\
    \t\tint lr = (x >> bit) & 1;\n\t\tv->next[lr] = insert(v->next[lr], x, bit - 1,\
    \ cnt);\n\t\treturn v;\n\t}\n\tnode* erase(node* v, T x, int bit, int cnt) {\n\
    \t\tassert(v != nullptr);\n\t\tv->size -= cnt;\n\t\tif (v->size == 0) {\n\t\t\t\
    return nullptr;\n\t\t}\n\t\tif (bit < 0) {\n\t\t\treturn v;\n\t\t}\n\t\tevaluate(v,\
    \ bit);\n\t\tint lr = (x >> bit) & 1;\n\t\tv->next[lr] = erase(v->next[lr], x,\
    \ bit - 1, cnt);\n\t\treturn v;\n\t}\n\tT get_min(node* v, T x, int bit) {\n\t\
    \tif (bit < 0) {\n\t\t\treturn 0;\n\t\t}\n\t\tevaluate(v, bit);\n\t\tint lr =\
    \ (x >> bit) & 1;\n\t\tif (v->next[lr] == nullptr) {\n\t\t\tlr = 1 - lr;\n\t\t\
    }\n\t\treturn get_min(v->next[lr], x, bit - 1) | ((T)lr << bit);\n\t}\n\tT get(node*\
    \ v, int k, int bit) {\n\t\tif (bit < 0) {\n\t\t\treturn 0;\n\t\t}\n\t\tevaluate(v,\
    \ bit);\n\t\tint m = v->next[0] != nullptr ? v->next[0]->size : 0;\n\t\tif (k\
    \ < m) {\n\t\t\treturn get(v->next[0], k, bit - 1);\n\t\t} else {\n\t\t\treturn\
    \ get(v->next[1], k - m, bit - 1) | ((T)1 << bit);\n\t\t}\n\t}\n\tint count_lower(node*\
    \ v, T x, int bit) {\n\t\tif (v == nullptr || bit < 0) {\n\t\t\treturn 0;\n\t\t\
    }\n\t\tevaluate(v, bit);\n\t\tint lr = (x >> bit) & 1;\n\t\tint ret = lr && v->next[0]\
    \ != nullptr ? v->next[0]->size : 0;\n\t\treturn ret + count_lower(v->next[lr],\
    \ x, bit - 1);\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/binary_trie.cpp
  requiredBy: []
  timestamp: '2023-12-15 11:13:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/binary_trie.cpp
layout: document
redirect_from:
- /library/data_structure/binary_trie.cpp
- /library/data_structure/binary_trie.cpp.html
title: Binary Trie
---
