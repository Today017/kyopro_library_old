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
    \ {\n\tT max() {\n\t\treturn *this->rbegin();\n\t}\n\tT min() {\n\t\treturn *this->begin();\n\
    \t}\n\tT pop_max() {\n\t\tT ret = *this->rbegin();\n\t\tthis->erase(ret);\n\t\t\
    return ret;\n\t}\n\tT pop_min() {\n\t\tT ret = *this->begin();\n\t\tthis->erase(ret);\n\
    \t\treturn ret;\n\t}\n\tvoid discard(T x) {\n\t\tif (!this->contains(x)) {\n\t\
    \t\treturn;\n\t\t}\n\t\tthis->erase(x);\n\t}\n\t// x\u4EE5\u4E0B\u6700\u5927\u306E\
    \u5024\n\tT orless_max(T x) {\n\t\tauto itr = this->upper_bound(x);\n\t\tif (itr\
    \ == this->begin()) {\n\t\t\treturn NULL;\n\t\t}\n\t\treturn *--itr;\n\t}\n\t\
    // x\u672A\u6E80\u6700\u5927\u306E\u5024\n\tT less_max(T x) {\n\t\tauto itr =\
    \ this->lower_bound(x);\n\t\tif (itr == this->begin()) {\n\t\t\treturn NULL;\n\
    \t\t}\n\t\treturn *--itr;\n\t}\n\t// x\u4EE5\u4E0A\u6700\u5C0F\u306E\u5024\n\t\
    T ormore_min(T x) {\n\t\tauto itr = this->lower_bound(x);\n\t\tif (itr == this->end())\
    \ {\n\t\t\treturn NULL;\n\t\t}\n\t\treturn *itr;\n\t}\n\t// x\u3088\u308A\u5927\
    \u304D\u3044\u6700\u5C0F\u306E\u5024\n\tT more_min(T x) {\n\t\tauto itr = this->upper_bound(x);\n\
    \t\tif (itr == this->end()) {\n\t\t\treturn NULL;\n\t\t}\n\t\treturn *itr;\n\t\
    }\n\t// k\u756A\u76EE\u306B\u5C0F\u3055\u3044\u5024(0-indexed)\n\tT kth_min(int\
    \ x) {\n\t\treturn *this->find_by_order(x);\n\t}\n\t// k\u756A\u76EE\u306B\u5927\
    \u304D\u3044\u5024(0-indexed)\n\tT kth_max(int x) {\n\t\treturn *this->find_by_order(this->size()\
    \ - x - 1);\n\t}\n\tbool contains(T x) {\n\t\tauto itr = this->find(x);\n\t\t\
    return itr != this->end();\n\t}\n\t// x\u304C\u4E0A\u304B\u3089\u4F55\u756A\u76EE\
    \u304B(0-indexed) / x\u3088\u308A\u5927\u304D\u3044\u5024\u304C\u3044\u304F\u3064\
    \u5B58\u5728\u3059\u308B\u304B\n\tint order_from_top(T x) {\n\t\treturn this->size()\
    \ - this->order_of_key(x) - 1;\n\t}\n\t// x\u304C\u4E0B\u304B\u3089\u4F55\u756A\
    \u76EE\u304B(0-indexed) / x\u3088\u308A\u5C0F\u3055\u3044\u5024\u304C\u3044\u304F\
    \u3064\u5B58\u5728\u3059\u308B\u304B\n\tint order_from_bottom(T x) {\n\t\treturn\
    \ this->order_of_key(x);\n\t}\n};\n"
  code: "#include <ext/pb_ds/assoc_container.hpp>\n#include <ext/pb_ds/tree_policy.hpp>\n\
    template <typename T>\nstruct tree : __gnu_pbds::tree<T, __gnu_pbds::null_type,\
    \ less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>\
    \ {\n\tT max() {\n\t\treturn *this->rbegin();\n\t}\n\tT min() {\n\t\treturn *this->begin();\n\
    \t}\n\tT pop_max() {\n\t\tT ret = *this->rbegin();\n\t\tthis->erase(ret);\n\t\t\
    return ret;\n\t}\n\tT pop_min() {\n\t\tT ret = *this->begin();\n\t\tthis->erase(ret);\n\
    \t\treturn ret;\n\t}\n\tvoid discard(T x) {\n\t\tif (!this->contains(x)) {\n\t\
    \t\treturn;\n\t\t}\n\t\tthis->erase(x);\n\t}\n\t// x\u4EE5\u4E0B\u6700\u5927\u306E\
    \u5024\n\tT orless_max(T x) {\n\t\tauto itr = this->upper_bound(x);\n\t\tif (itr\
    \ == this->begin()) {\n\t\t\treturn NULL;\n\t\t}\n\t\treturn *--itr;\n\t}\n\t\
    // x\u672A\u6E80\u6700\u5927\u306E\u5024\n\tT less_max(T x) {\n\t\tauto itr =\
    \ this->lower_bound(x);\n\t\tif (itr == this->begin()) {\n\t\t\treturn NULL;\n\
    \t\t}\n\t\treturn *--itr;\n\t}\n\t// x\u4EE5\u4E0A\u6700\u5C0F\u306E\u5024\n\t\
    T ormore_min(T x) {\n\t\tauto itr = this->lower_bound(x);\n\t\tif (itr == this->end())\
    \ {\n\t\t\treturn NULL;\n\t\t}\n\t\treturn *itr;\n\t}\n\t// x\u3088\u308A\u5927\
    \u304D\u3044\u6700\u5C0F\u306E\u5024\n\tT more_min(T x) {\n\t\tauto itr = this->upper_bound(x);\n\
    \t\tif (itr == this->end()) {\n\t\t\treturn NULL;\n\t\t}\n\t\treturn *itr;\n\t\
    }\n\t// k\u756A\u76EE\u306B\u5C0F\u3055\u3044\u5024(0-indexed)\n\tT kth_min(int\
    \ x) {\n\t\treturn *this->find_by_order(x);\n\t}\n\t// k\u756A\u76EE\u306B\u5927\
    \u304D\u3044\u5024(0-indexed)\n\tT kth_max(int x) {\n\t\treturn *this->find_by_order(this->size()\
    \ - x - 1);\n\t}\n\tbool contains(T x) {\n\t\tauto itr = this->find(x);\n\t\t\
    return itr != this->end();\n\t}\n\t// x\u304C\u4E0A\u304B\u3089\u4F55\u756A\u76EE\
    \u304B(0-indexed) / x\u3088\u308A\u5927\u304D\u3044\u5024\u304C\u3044\u304F\u3064\
    \u5B58\u5728\u3059\u308B\u304B\n\tint order_from_top(T x) {\n\t\treturn this->size()\
    \ - this->order_of_key(x) - 1;\n\t}\n\t// x\u304C\u4E0B\u304B\u3089\u4F55\u756A\
    \u76EE\u304B(0-indexed) / x\u3088\u308A\u5C0F\u3055\u3044\u5024\u304C\u3044\u304F\
    \u3064\u5B58\u5728\u3059\u308B\u304B\n\tint order_from_bottom(T x) {\n\t\treturn\
    \ this->order_of_key(x);\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/tree.cpp
  requiredBy: []
  timestamp: '2023-11-30 18:16:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/tree.cpp
layout: document
redirect_from:
- /library/data_structure/tree.cpp
- /library/data_structure/tree.cpp.html
title: data_structure/tree.cpp
---
