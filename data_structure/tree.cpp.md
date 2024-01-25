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
  bundledCode: "#line 1 \"data_structure/tree.cpp\"\n#include <ext/pb_ds/assoc_container.hpp>\n\
    #include <ext/pb_ds/tree_policy.hpp>\ntemplate <typename T>\nstruct tree : __gnu_pbds::tree<T,\
    \ __gnu_pbds::null_type, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>\
    \ {\n    T max() {\n        return *this->rbegin();\n    }\n    T min() {\n  \
    \      return *this->begin();\n    }\n    T pop_max() {\n        T ret = *this->rbegin();\n\
    \        this->erase(ret);\n        return ret;\n    }\n    T pop_min() {\n  \
    \      T ret = *this->begin();\n        this->erase(ret);\n        return ret;\n\
    \    }\n    void discard(T x) {\n        if (!this->contains(x)) {\n         \
    \   return;\n        }\n        this->erase(x);\n    }\n    // x\u4EE5\u4E0B\u6700\
    \u5927\u306E\u5024\n    T orless_max(T x) {\n        auto itr = this->upper_bound(x);\n\
    \        if (itr == this->begin()) {\n            return NULL;\n        }\n  \
    \      return *--itr;\n    }\n    // x\u672A\u6E80\u6700\u5927\u306E\u5024\n \
    \   T less_max(T x) {\n        auto itr = this->lower_bound(x);\n        if (itr\
    \ == this->begin()) {\n            return NULL;\n        }\n        return *--itr;\n\
    \    }\n    // x\u4EE5\u4E0A\u6700\u5C0F\u306E\u5024\n    T ormore_min(T x) {\n\
    \        auto itr = this->lower_bound(x);\n        if (itr == this->end()) {\n\
    \            return NULL;\n        }\n        return *itr;\n    }\n    // x\u3088\
    \u308A\u5927\u304D\u3044\u6700\u5C0F\u306E\u5024\n    T more_min(T x) {\n    \
    \    auto itr = this->upper_bound(x);\n        if (itr == this->end()) {\n   \
    \         return NULL;\n        }\n        return *itr;\n    }\n    // k\u756A\
    \u76EE\u306B\u5C0F\u3055\u3044\u5024(0-indexed)\n    T kth_min(int x) {\n    \
    \    return *this->find_by_order(x);\n    }\n    // k\u756A\u76EE\u306B\u5927\u304D\
    \u3044\u5024(0-indexed)\n    T kth_max(int x) {\n        return *this->find_by_order(this->size()\
    \ - x - 1);\n    }\n    bool contains(T x) {\n        auto itr = this->find(x);\n\
    \        return itr != this->end();\n    }\n    // x\u304C\u4E0A\u304B\u3089\u4F55\
    \u756A\u76EE\u304B(0-indexed) / x\u3088\u308A\u5927\u304D\u3044\u5024\u304C\u3044\
    \u304F\u3064\u5B58\u5728\u3059\u308B\u304B\n    int order_from_top(T x) {\n  \
    \      return this->size() - this->order_of_key(x) - 1;\n    }\n    // x\u304C\
    \u4E0B\u304B\u3089\u4F55\u756A\u76EE\u304B(0-indexed) / x\u3088\u308A\u5C0F\u3055\
    \u3044\u5024\u304C\u3044\u304F\u3064\u5B58\u5728\u3059\u308B\u304B\n    int order_from_bottom(T\
    \ x) {\n        return this->order_of_key(x);\n    }\n};\n"
  code: "#include <ext/pb_ds/assoc_container.hpp>\n#include <ext/pb_ds/tree_policy.hpp>\n\
    template <typename T>\nstruct tree : __gnu_pbds::tree<T, __gnu_pbds::null_type,\
    \ less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>\
    \ {\n    T max() {\n        return *this->rbegin();\n    }\n    T min() {\n  \
    \      return *this->begin();\n    }\n    T pop_max() {\n        T ret = *this->rbegin();\n\
    \        this->erase(ret);\n        return ret;\n    }\n    T pop_min() {\n  \
    \      T ret = *this->begin();\n        this->erase(ret);\n        return ret;\n\
    \    }\n    void discard(T x) {\n        if (!this->contains(x)) {\n         \
    \   return;\n        }\n        this->erase(x);\n    }\n    // x\u4EE5\u4E0B\u6700\
    \u5927\u306E\u5024\n    T orless_max(T x) {\n        auto itr = this->upper_bound(x);\n\
    \        if (itr == this->begin()) {\n            return NULL;\n        }\n  \
    \      return *--itr;\n    }\n    // x\u672A\u6E80\u6700\u5927\u306E\u5024\n \
    \   T less_max(T x) {\n        auto itr = this->lower_bound(x);\n        if (itr\
    \ == this->begin()) {\n            return NULL;\n        }\n        return *--itr;\n\
    \    }\n    // x\u4EE5\u4E0A\u6700\u5C0F\u306E\u5024\n    T ormore_min(T x) {\n\
    \        auto itr = this->lower_bound(x);\n        if (itr == this->end()) {\n\
    \            return NULL;\n        }\n        return *itr;\n    }\n    // x\u3088\
    \u308A\u5927\u304D\u3044\u6700\u5C0F\u306E\u5024\n    T more_min(T x) {\n    \
    \    auto itr = this->upper_bound(x);\n        if (itr == this->end()) {\n   \
    \         return NULL;\n        }\n        return *itr;\n    }\n    // k\u756A\
    \u76EE\u306B\u5C0F\u3055\u3044\u5024(0-indexed)\n    T kth_min(int x) {\n    \
    \    return *this->find_by_order(x);\n    }\n    // k\u756A\u76EE\u306B\u5927\u304D\
    \u3044\u5024(0-indexed)\n    T kth_max(int x) {\n        return *this->find_by_order(this->size()\
    \ - x - 1);\n    }\n    bool contains(T x) {\n        auto itr = this->find(x);\n\
    \        return itr != this->end();\n    }\n    // x\u304C\u4E0A\u304B\u3089\u4F55\
    \u756A\u76EE\u304B(0-indexed) / x\u3088\u308A\u5927\u304D\u3044\u5024\u304C\u3044\
    \u304F\u3064\u5B58\u5728\u3059\u308B\u304B\n    int order_from_top(T x) {\n  \
    \      return this->size() - this->order_of_key(x) - 1;\n    }\n    // x\u304C\
    \u4E0B\u304B\u3089\u4F55\u756A\u76EE\u304B(0-indexed) / x\u3088\u308A\u5C0F\u3055\
    \u3044\u5024\u304C\u3044\u304F\u3064\u5B58\u5728\u3059\u308B\u304B\n    int order_from_bottom(T\
    \ x) {\n        return this->order_of_key(x);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/tree.cpp
  requiredBy: []
  timestamp: '2024-01-25 11:55:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/tree.cpp
layout: document
redirect_from:
- /library/data_structure/tree.cpp
- /library/data_structure/tree.cpp.html
title: data_structure/tree.cpp
---
