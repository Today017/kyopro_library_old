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
  bundledCode: "#line 1 \"others/debug.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#include <atcoder/all>\nusing namespace atcoder;\n\ntemplate <class T>\n\
    ostream &operator<<(ostream &os, const vector<T> &A) {\n    int n = A.size();\n\
    \    os << \"[ \";\n    for (int i = 0; i < n; i++) {\n        os << A[i];\n \
    \       if (i != n - 1) {\n            os << \", \";\n        }\n    }\n    os\
    \ << \" ]\";\n    return os;\n}\ntemplate <class T>\nostream &operator<<(ostream\
    \ &os, const vector<vector<T>> &A) {\n    os << \"[\\n\";\n    int n = A.size();\n\
    \    for (int i = 0; i < n; i++) {\n        os << \"      \";\n        os << A[i];\n\
    \        os << \", \\n\";\n    }\n    os << \" ]\";\n    return os;\n}\ntemplate\
    \ <class T>\nostream &operator<<(ostream &os, const set<T> &A) {\n    int n =\
    \ A.size();\n    os << \"[ \";\n    for (T x : A) {\n        os << x << \", \"\
    ;\n    }\n    os << \" ]\";\n    return os;\n}\ntemplate <class T>\nostream &operator<<(ostream\
    \ &os, const multiset<T> &A) {\n    int n = A.size();\n    os << \"[ \";\n   \
    \ for (T x : A) {\n        os << x << \", \";\n    }\n    os << \" ]\";\n    return\
    \ os;\n}\ntemplate <class T1, class T2>\nostream &operator<<(ostream &os, const\
    \ pair<T1, T2> &p) {\n    os << \"( \" << p.first << \", \" << p.second << \"\
    \ )\";\n    return os;\n}\ntemplate <class T>\nostream &operator<<(ostream &os,\
    \ queue<T> A) {\n    int n = A.size();\n    os << \"[ \";\n    while (!A.empty())\
    \ {\n        os << A.front() << \", \";\n        A.pop();\n    }\n    os << \"\
    \ ]\";\n    return os;\n}\ntemplate <class T>\nostream &operator<<(ostream &os,\
    \ priority_queue<T> A) {\n    int n = A.size();\n    os << \"[ \";\n    while\
    \ (!A.empty()) {\n        os << A.top() << \", \";\n        A.pop();\n    }\n\
    \    os << \" ]\";\n    return os;\n}\ntemplate <class T>\nostream &operator<<(ostream\
    \ &os, fenwick_tree<T> A) {\n    int n = A._n;\n    os << \"[ \";\n    for (int\
    \ i = 0; i < n; i++) {\n        os << A.sum(i, i + 1);\n        if (i != n - 1)\
    \ {\n            os << \", \";\n        }\n    }\n    os << \" ]\";\n    return\
    \ os;\n}\ntemplate <class S, S (*op)(S, S), S (*e)()>\nostream &operator<<(ostream\
    \ &os, segtree<S, op, e> A) {\n    int n = A._n;\n    os << \"[ \";\n    for (int\
    \ i = 0; i < n; i++) {\n        os << A.prod(i, i + 1);\n        if (i != n -\
    \ 1) {\n            os << \", \";\n        }\n    }\n    os << \" ]\";\n    return\
    \ os;\n}\nostream &operator<<(ostream &os, dsu ds) {\n    os << ds.groups();\n\
    \    return os;\n}\nostream &operator<<(ostream &os, modint998244353 x) {\n  \
    \  os << x.val();\n    return os;\n}\nostream &operator<<(ostream &os, modint1000000007\
    \ x) {\n    os << x.val();\n    return os;\n}\n\n#define print_line cerr << \"\
    --------------------\" << __LINE__ << \"--------------------\" \\\n          \
    \              << \"\\n\"\n#define debug(...) debug_print(0, #__VA_ARGS__, __VA_ARGS__)\n\
    #define get_name(VariableName) #VariableName\ntemplate <typename T>\nvoid debug_print(int\
    \ i, T name) {\n    cerr << endl;\n}\ntemplate <typename T1, typename T2, typename...\
    \ T3>\nvoid debug_print(int i, const T1 &name, const T2 &a, const T3 &... b) {\n\
    \    for (; name[i] != ',' && name[i] != '\\0'; i++) {\n        cerr << name[i];\n\
    \    }\n    cerr << \" : \" << a << \", \";\n    debug_print(i + 1, name, b...);\n\
    }\ntemplate <typename T>\nvoid debugc(T a, string sep = \", \") {\n    cerr <<\
    \ get_name(a) << \" : [\";\n    for (auto x : a) {\n        cerr << x << sep;\n\
    \    }\n    cerr << \"]\" << endl;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n#include <atcoder/all>\n\
    using namespace atcoder;\n\ntemplate <class T>\nostream &operator<<(ostream &os,\
    \ const vector<T> &A) {\n    int n = A.size();\n    os << \"[ \";\n    for (int\
    \ i = 0; i < n; i++) {\n        os << A[i];\n        if (i != n - 1) {\n     \
    \       os << \", \";\n        }\n    }\n    os << \" ]\";\n    return os;\n}\n\
    template <class T>\nostream &operator<<(ostream &os, const vector<vector<T>> &A)\
    \ {\n    os << \"[\\n\";\n    int n = A.size();\n    for (int i = 0; i < n; i++)\
    \ {\n        os << \"      \";\n        os << A[i];\n        os << \", \\n\";\n\
    \    }\n    os << \" ]\";\n    return os;\n}\ntemplate <class T>\nostream &operator<<(ostream\
    \ &os, const set<T> &A) {\n    int n = A.size();\n    os << \"[ \";\n    for (T\
    \ x : A) {\n        os << x << \", \";\n    }\n    os << \" ]\";\n    return os;\n\
    }\ntemplate <class T>\nostream &operator<<(ostream &os, const multiset<T> &A)\
    \ {\n    int n = A.size();\n    os << \"[ \";\n    for (T x : A) {\n        os\
    \ << x << \", \";\n    }\n    os << \" ]\";\n    return os;\n}\ntemplate <class\
    \ T1, class T2>\nostream &operator<<(ostream &os, const pair<T1, T2> &p) {\n \
    \   os << \"( \" << p.first << \", \" << p.second << \" )\";\n    return os;\n\
    }\ntemplate <class T>\nostream &operator<<(ostream &os, queue<T> A) {\n    int\
    \ n = A.size();\n    os << \"[ \";\n    while (!A.empty()) {\n        os << A.front()\
    \ << \", \";\n        A.pop();\n    }\n    os << \" ]\";\n    return os;\n}\n\
    template <class T>\nostream &operator<<(ostream &os, priority_queue<T> A) {\n\
    \    int n = A.size();\n    os << \"[ \";\n    while (!A.empty()) {\n        os\
    \ << A.top() << \", \";\n        A.pop();\n    }\n    os << \" ]\";\n    return\
    \ os;\n}\ntemplate <class T>\nostream &operator<<(ostream &os, fenwick_tree<T>\
    \ A) {\n    int n = A._n;\n    os << \"[ \";\n    for (int i = 0; i < n; i++)\
    \ {\n        os << A.sum(i, i + 1);\n        if (i != n - 1) {\n            os\
    \ << \", \";\n        }\n    }\n    os << \" ]\";\n    return os;\n}\ntemplate\
    \ <class S, S (*op)(S, S), S (*e)()>\nostream &operator<<(ostream &os, segtree<S,\
    \ op, e> A) {\n    int n = A._n;\n    os << \"[ \";\n    for (int i = 0; i < n;\
    \ i++) {\n        os << A.prod(i, i + 1);\n        if (i != n - 1) {\n       \
    \     os << \", \";\n        }\n    }\n    os << \" ]\";\n    return os;\n}\n\
    ostream &operator<<(ostream &os, dsu ds) {\n    os << ds.groups();\n    return\
    \ os;\n}\nostream &operator<<(ostream &os, modint998244353 x) {\n    os << x.val();\n\
    \    return os;\n}\nostream &operator<<(ostream &os, modint1000000007 x) {\n \
    \   os << x.val();\n    return os;\n}\n\n#define print_line cerr << \"--------------------\"\
    \ << __LINE__ << \"--------------------\" \\\n                        << \"\\\
    n\"\n#define debug(...) debug_print(0, #__VA_ARGS__, __VA_ARGS__)\n#define get_name(VariableName)\
    \ #VariableName\ntemplate <typename T>\nvoid debug_print(int i, T name) {\n  \
    \  cerr << endl;\n}\ntemplate <typename T1, typename T2, typename... T3>\nvoid\
    \ debug_print(int i, const T1 &name, const T2 &a, const T3 &... b) {\n    for\
    \ (; name[i] != ',' && name[i] != '\\0'; i++) {\n        cerr << name[i];\n  \
    \  }\n    cerr << \" : \" << a << \", \";\n    debug_print(i + 1, name, b...);\n\
    }\ntemplate <typename T>\nvoid debugc(T a, string sep = \", \") {\n    cerr <<\
    \ get_name(a) << \" : [\";\n    for (auto x : a) {\n        cerr << x << sep;\n\
    \    }\n    cerr << \"]\" << endl;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: others/debug.cpp
  requiredBy: []
  timestamp: '2024-01-25 11:55:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: others/debug.cpp
layout: document
redirect_from:
- /library/others/debug.cpp
- /library/others/debug.cpp.html
title: others/debug.cpp
---
