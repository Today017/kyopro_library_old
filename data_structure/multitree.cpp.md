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
  bundledCode: "#line 1 \"data_structure/multitree.cpp\"\n#include <ext/pb_ds/assoc_container.hpp>\n\
    #include <ext/pb_ds/tree_policy.hpp>\ntemplate <typename T>\nstruct multitree\
    \ : __gnu_pbds::tree<pair<T, int>, __gnu_pbds::null_type, less<pair<T, int>>,\
    \ __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> {\n\
    \    map<T, int> mp;\n    set<T> st;\n    T max() {\n        return (*(this->rbegin())).first;\n\
    \    }\n    T min() {\n        return (*(this->begin())).first;\n    }\n    void\
    \ insert(T x) {\n        st.insert(x);\n        this->insert({x, mp[x]});\n  \
    \      mp[x]++;\n    }\n    T pop_max() {\n        T ret = (*(this->rbegin())).first;\n\
    \        mp[ret]--;\n        if (mp[ret] == 0) st.erase(ret);\n        this->erase(ret);\n\
    \        return ret;\n    }\n    T pop_min() {\n        T ret = (*(this->begin())).first;\n\
    \        mp[ret]--;\n        if (mp[ret] == 0) st.erase(ret);\n        this->erase(ret);\n\
    \        return ret;\n    }\n    void discard(T x) {\n        if (!this->contains(x))\
    \ return;\n        mp[x]--;\n        if (mp[x] == 0) st.erase(x);\n        this->erase(x);\n\
    \    }\n    // x\u4EE5\u4E0B\u6700\u5927\u306E\u5024\n    T orless_max(T x) {\n\
    \        auto itr = st.upper_bound(x);\n        if (itr == st.begin()) return\
    \ NULL;\n        return *--itr;\n    }\n    // x\u672A\u6E80\u6700\u5927\u306E\
    \u5024\n    T less_max(T x) {\n        auto itr = st.lower_bound(x);\n       \
    \ if (itr == st.begin()) return NULL;\n        return *--itr;\n    }\n    // x\u4EE5\
    \u4E0A\u6700\u5C0F\u306E\u5024\n    T ormore_min(T x) {\n        auto itr = st.lower_bound(x);\n\
    \        if (itr == st.end()) return NULL;\n        return *itr;\n    }\n    //\
    \ x\u3088\u308A\u5927\u304D\u3044\u6700\u5C0F\u306E\u5024\n    T more_min(T x)\
    \ {\n        auto itr = st.upper_bound(x);\n        if (itr == st.end()) return\
    \ NULL;\n        return *itr;\n    }\n    // k\u756A\u76EE\u306B\u5C0F\u3055\u3044\
    \u5024(0-indexed)\n    T kth_min(int x) {\n        return (*(this->find_by_order(x))).first;\n\
    \    }\n    // k\u756A\u76EE\u306B\u5927\u304D\u3044\u5024(0-indexed)\n    T kth_max(int\
    \ x) {\n        return (*(this->find_by_order(this->size() - x - 1))).first;\n\
    \    }\n    bool contains(T x) {\n        return st.count(x) > 0;\n    }\n   \
    \ // x\u304C\u4E0A\u304B\u3089\u4F55\u756A\u76EE\u304B(0-indexed)\n    int order_from_top(T\
    \ x) {\n        return this->size() - this->order_of_key({x, mp[x] - 1}) - 1;\n\
    \    }\n    int order_from_top_left(T x) {\n        return this->size() - this->order_of_key({x,\
    \ 0}) - 1;\n    }\n    // x\u304C\u4E0B\u304B\u3089\u4F55\u756A\u76EE\u304B(0-indexed)\n\
    \    int order_from_bottom(T x) {\n        return this->order_of_key({x, 0});\n\
    \    }\n    int order_from_bottom_right(T x) {\n        return this->order_of_key({x,\
    \ mp[x] - 1});\n    }\n    int count(T x) {\n        return mp[x];\n    }\n};\n"
  code: "#include <ext/pb_ds/assoc_container.hpp>\n#include <ext/pb_ds/tree_policy.hpp>\n\
    template <typename T>\nstruct multitree : __gnu_pbds::tree<pair<T, int>, __gnu_pbds::null_type,\
    \ less<pair<T, int>>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>\
    \ {\n    map<T, int> mp;\n    set<T> st;\n    T max() {\n        return (*(this->rbegin())).first;\n\
    \    }\n    T min() {\n        return (*(this->begin())).first;\n    }\n    void\
    \ insert(T x) {\n        st.insert(x);\n        this->insert({x, mp[x]});\n  \
    \      mp[x]++;\n    }\n    T pop_max() {\n        T ret = (*(this->rbegin())).first;\n\
    \        mp[ret]--;\n        if (mp[ret] == 0) st.erase(ret);\n        this->erase(ret);\n\
    \        return ret;\n    }\n    T pop_min() {\n        T ret = (*(this->begin())).first;\n\
    \        mp[ret]--;\n        if (mp[ret] == 0) st.erase(ret);\n        this->erase(ret);\n\
    \        return ret;\n    }\n    void discard(T x) {\n        if (!this->contains(x))\
    \ return;\n        mp[x]--;\n        if (mp[x] == 0) st.erase(x);\n        this->erase(x);\n\
    \    }\n    // x\u4EE5\u4E0B\u6700\u5927\u306E\u5024\n    T orless_max(T x) {\n\
    \        auto itr = st.upper_bound(x);\n        if (itr == st.begin()) return\
    \ NULL;\n        return *--itr;\n    }\n    // x\u672A\u6E80\u6700\u5927\u306E\
    \u5024\n    T less_max(T x) {\n        auto itr = st.lower_bound(x);\n       \
    \ if (itr == st.begin()) return NULL;\n        return *--itr;\n    }\n    // x\u4EE5\
    \u4E0A\u6700\u5C0F\u306E\u5024\n    T ormore_min(T x) {\n        auto itr = st.lower_bound(x);\n\
    \        if (itr == st.end()) return NULL;\n        return *itr;\n    }\n    //\
    \ x\u3088\u308A\u5927\u304D\u3044\u6700\u5C0F\u306E\u5024\n    T more_min(T x)\
    \ {\n        auto itr = st.upper_bound(x);\n        if (itr == st.end()) return\
    \ NULL;\n        return *itr;\n    }\n    // k\u756A\u76EE\u306B\u5C0F\u3055\u3044\
    \u5024(0-indexed)\n    T kth_min(int x) {\n        return (*(this->find_by_order(x))).first;\n\
    \    }\n    // k\u756A\u76EE\u306B\u5927\u304D\u3044\u5024(0-indexed)\n    T kth_max(int\
    \ x) {\n        return (*(this->find_by_order(this->size() - x - 1))).first;\n\
    \    }\n    bool contains(T x) {\n        return st.count(x) > 0;\n    }\n   \
    \ // x\u304C\u4E0A\u304B\u3089\u4F55\u756A\u76EE\u304B(0-indexed)\n    int order_from_top(T\
    \ x) {\n        return this->size() - this->order_of_key({x, mp[x] - 1}) - 1;\n\
    \    }\n    int order_from_top_left(T x) {\n        return this->size() - this->order_of_key({x,\
    \ 0}) - 1;\n    }\n    // x\u304C\u4E0B\u304B\u3089\u4F55\u756A\u76EE\u304B(0-indexed)\n\
    \    int order_from_bottom(T x) {\n        return this->order_of_key({x, 0});\n\
    \    }\n    int order_from_bottom_right(T x) {\n        return this->order_of_key({x,\
    \ mp[x] - 1});\n    }\n    int count(T x) {\n        return mp[x];\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/multitree.cpp
  requiredBy: []
  timestamp: '2024-01-25 11:55:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/multitree.cpp
layout: document
redirect_from:
- /library/data_structure/multitree.cpp
- /library/data_structure/multitree.cpp.html
title: data_structure/multitree.cpp
---
