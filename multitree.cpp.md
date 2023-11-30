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
  bundledCode: "#line 1 \"multitree.cpp\"\n#include <ext/pb_ds/assoc_container.hpp>\n\
    #include <ext/pb_ds/tree_policy.hpp>\ntemplate <typename T>\nstruct multitree\
    \ : __gnu_pbds::tree<pair<T, int>, __gnu_pbds::null_type, less<pair<T, int>>,\
    \ __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> {\n\t\
    map<T, int> mp;\n\tset<T> st;\n\tT max() {\n\t\treturn (*(this->rbegin())).first;\n\
    \t}\n\tT min() {\n\t\treturn (*(this->begin())).first;\n\t}\n\tvoid insert(T x)\
    \ {\n\t\tst.insert(x);\n\t\tthis->insert({x, mp[x]});\n\t\tmp[x]++;\n\t}\n\tT\
    \ pop_max() {\n\t\tT ret = (*(this->rbegin())).first;\n\t\tmp[ret]--;\n\t\tif\
    \ (mp[ret] == 0) st.erase(ret);\n\t\tthis->erase(ret);\n\t\treturn ret;\n\t}\n\
    \tT pop_min() {\n\t\tT ret = (*(this->begin())).first;\n\t\tmp[ret]--;\n\t\tif\
    \ (mp[ret] == 0) st.erase(ret);\n\t\tthis->erase(ret);\n\t\treturn ret;\n\t}\n\
    \tvoid discard(T x) {\n\t\tif (!this->contains(x)) return;\n\t\tmp[x]--;\n\t\t\
    if (mp[x] == 0) st.erase(x);\n\t\tthis->erase(x);\n\t}\n\t// x\u4EE5\u4E0B\u6700\
    \u5927\u306E\u5024\n\tT orless_max(T x) {\n\t\tauto itr = st.upper_bound(x);\n\
    \t\tif (itr == st.begin()) return NULL;\n\t\treturn *--itr;\n\t}\n\t// x\u672A\
    \u6E80\u6700\u5927\u306E\u5024\n\tT less_max(T x) {\n\t\tauto itr = st.lower_bound(x);\n\
    \t\tif (itr == st.begin()) return NULL;\n\t\treturn *--itr;\n\t}\n\t// x\u4EE5\
    \u4E0A\u6700\u5C0F\u306E\u5024\n\tT ormore_min(T x) {\n\t\tauto itr = st.lower_bound(x);\n\
    \t\tif (itr == st.end()) return NULL;\n\t\treturn *itr;\n\t}\n\t// x\u3088\u308A\
    \u5927\u304D\u3044\u6700\u5C0F\u306E\u5024\n\tT more_min(T x) {\n\t\tauto itr\
    \ = st.upper_bound(x);\n\t\tif (itr == st.end()) return NULL;\n\t\treturn *itr;\n\
    \t}\n\t// k\u756A\u76EE\u306B\u5C0F\u3055\u3044\u5024(0-indexed)\n\tT kth_min(int\
    \ x) {\n\t\treturn (*(this->find_by_order(x))).first;\n\t}\n\t// k\u756A\u76EE\
    \u306B\u5927\u304D\u3044\u5024(0-indexed)\n\tT kth_max(int x) {\n\t\treturn (*(this->find_by_order(this->size()\
    \ - x - 1))).first;\n\t}\n\tbool contains(T x) {\n\t\treturn st.count(x) > 0;\n\
    \t}\n\t// x\u304C\u4E0A\u304B\u3089\u4F55\u756A\u76EE\u304B(0-indexed)\n\tint\
    \ order_from_top(T x) {\n\t\treturn this->size() - this->order_of_key({x, mp[x]\
    \ - 1}) - 1;\n\t}\n\tint order_from_top_left(T x) {\n\t\treturn this->size() -\
    \ this->order_of_key({x, 0}) - 1;\n\t}\n\t// x\u304C\u4E0B\u304B\u3089\u4F55\u756A\
    \u76EE\u304B(0-indexed)\n\tint order_from_bottom(T x) {\n\t\treturn this->order_of_key({x,\
    \ 0});\n\t}\n\tint order_from_bottom_right(T x) {\n\t\treturn this->order_of_key({x,\
    \ mp[x] - 1});\n\t}\n\tint count(T x) {\n\t\treturn mp[x];\n\t}\n};\n"
  code: "#include <ext/pb_ds/assoc_container.hpp>\n#include <ext/pb_ds/tree_policy.hpp>\n\
    template <typename T>\nstruct multitree : __gnu_pbds::tree<pair<T, int>, __gnu_pbds::null_type,\
    \ less<pair<T, int>>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>\
    \ {\n\tmap<T, int> mp;\n\tset<T> st;\n\tT max() {\n\t\treturn (*(this->rbegin())).first;\n\
    \t}\n\tT min() {\n\t\treturn (*(this->begin())).first;\n\t}\n\tvoid insert(T x)\
    \ {\n\t\tst.insert(x);\n\t\tthis->insert({x, mp[x]});\n\t\tmp[x]++;\n\t}\n\tT\
    \ pop_max() {\n\t\tT ret = (*(this->rbegin())).first;\n\t\tmp[ret]--;\n\t\tif\
    \ (mp[ret] == 0) st.erase(ret);\n\t\tthis->erase(ret);\n\t\treturn ret;\n\t}\n\
    \tT pop_min() {\n\t\tT ret = (*(this->begin())).first;\n\t\tmp[ret]--;\n\t\tif\
    \ (mp[ret] == 0) st.erase(ret);\n\t\tthis->erase(ret);\n\t\treturn ret;\n\t}\n\
    \tvoid discard(T x) {\n\t\tif (!this->contains(x)) return;\n\t\tmp[x]--;\n\t\t\
    if (mp[x] == 0) st.erase(x);\n\t\tthis->erase(x);\n\t}\n\t// x\u4EE5\u4E0B\u6700\
    \u5927\u306E\u5024\n\tT orless_max(T x) {\n\t\tauto itr = st.upper_bound(x);\n\
    \t\tif (itr == st.begin()) return NULL;\n\t\treturn *--itr;\n\t}\n\t// x\u672A\
    \u6E80\u6700\u5927\u306E\u5024\n\tT less_max(T x) {\n\t\tauto itr = st.lower_bound(x);\n\
    \t\tif (itr == st.begin()) return NULL;\n\t\treturn *--itr;\n\t}\n\t// x\u4EE5\
    \u4E0A\u6700\u5C0F\u306E\u5024\n\tT ormore_min(T x) {\n\t\tauto itr = st.lower_bound(x);\n\
    \t\tif (itr == st.end()) return NULL;\n\t\treturn *itr;\n\t}\n\t// x\u3088\u308A\
    \u5927\u304D\u3044\u6700\u5C0F\u306E\u5024\n\tT more_min(T x) {\n\t\tauto itr\
    \ = st.upper_bound(x);\n\t\tif (itr == st.end()) return NULL;\n\t\treturn *itr;\n\
    \t}\n\t// k\u756A\u76EE\u306B\u5C0F\u3055\u3044\u5024(0-indexed)\n\tT kth_min(int\
    \ x) {\n\t\treturn (*(this->find_by_order(x))).first;\n\t}\n\t// k\u756A\u76EE\
    \u306B\u5927\u304D\u3044\u5024(0-indexed)\n\tT kth_max(int x) {\n\t\treturn (*(this->find_by_order(this->size()\
    \ - x - 1))).first;\n\t}\n\tbool contains(T x) {\n\t\treturn st.count(x) > 0;\n\
    \t}\n\t// x\u304C\u4E0A\u304B\u3089\u4F55\u756A\u76EE\u304B(0-indexed)\n\tint\
    \ order_from_top(T x) {\n\t\treturn this->size() - this->order_of_key({x, mp[x]\
    \ - 1}) - 1;\n\t}\n\tint order_from_top_left(T x) {\n\t\treturn this->size() -\
    \ this->order_of_key({x, 0}) - 1;\n\t}\n\t// x\u304C\u4E0B\u304B\u3089\u4F55\u756A\
    \u76EE\u304B(0-indexed)\n\tint order_from_bottom(T x) {\n\t\treturn this->order_of_key({x,\
    \ 0});\n\t}\n\tint order_from_bottom_right(T x) {\n\t\treturn this->order_of_key({x,\
    \ mp[x] - 1});\n\t}\n\tint count(T x) {\n\t\treturn mp[x];\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: multitree.cpp
  requiredBy: []
  timestamp: '2023-11-30 17:19:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: multitree.cpp
layout: document
redirect_from:
- /library/multitree.cpp
- /library/multitree.cpp.html
title: multitree.cpp
---
