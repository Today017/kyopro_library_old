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
    ostream &operator<<(ostream &os, const vector<T> &A) {\n\tint n = A.size();\n\t\
    os << \"[ \";\n\tfor (int i = 0; i < n; i++) {\n\t\tos << A[i];\n\t\tif (i !=\
    \ n - 1) {\n\t\t\tos << \", \";\n\t\t}\n\t}\n\tos << \" ]\";\n\treturn os;\n}\n\
    template <class T>\nostream &operator<<(ostream &os, const vector<vector<T>> &A)\
    \ {\n\tos << \"[\\n\";\n\tint n = A.size();\n\tfor (int i = 0; i < n; i++) {\n\
    \t\tos << \"      \";\n\t\tos << A[i];\n\t\tos << \", \\n\";\n\t}\n\tos << \"\
    \ ]\";\n\treturn os;\n}\ntemplate <class T>\nostream &operator<<(ostream &os,\
    \ const set<T> &A) {\n\tint n = A.size();\n\tos << \"[ \";\n\tfor (T x : A) {\n\
    \t\tos << x << \", \";\n\t}\n\tos << \" ]\";\n\treturn os;\n}\ntemplate <class\
    \ T>\nostream &operator<<(ostream &os, const multiset<T> &A) {\n\tint n = A.size();\n\
    \tos << \"[ \";\n\tfor (T x : A) {\n\t\tos << x << \", \";\n\t}\n\tos << \" ]\"\
    ;\n\treturn os;\n}\ntemplate <class T1, class T2>\nostream &operator<<(ostream\
    \ &os, const pair<T1, T2> &p) {\n\tos << \"( \" << p.first << \", \" << p.second\
    \ << \" )\";\n\treturn os;\n}\ntemplate <class T>\nostream &operator<<(ostream\
    \ &os, queue<T> A) {\n\tint n = A.size();\n\tos << \"[ \";\n\twhile (!A.empty())\
    \ {\n\t\tos << A.front() << \", \";\n\t\tA.pop();\n\t}\n\tos << \" ]\";\n\treturn\
    \ os;\n}\ntemplate <class T>\nostream &operator<<(ostream &os, priority_queue<T>\
    \ A) {\n\tint n = A.size();\n\tos << \"[ \";\n\twhile (!A.empty()) {\n\t\tos <<\
    \ A.top() << \", \";\n\t\tA.pop();\n\t}\n\tos << \" ]\";\n\treturn os;\n}\ntemplate\
    \ <class T>\nostream &operator<<(ostream &os, fenwick_tree<T> A) {\n\tint n =\
    \ A._n;\n\tos << \"[ \";\n\tfor (int i = 0; i < n; i++) {\n\t\tos << A.sum(i,\
    \ i + 1);\n\t\tif (i != n - 1) {\n\t\t\tos << \", \";\n\t\t}\n\t}\n\tos << \"\
    \ ]\";\n\treturn os;\n}\ntemplate <class S, S (*op)(S, S), S (*e)()>\nostream\
    \ &operator<<(ostream &os, segtree<S, op, e> A) {\n\tint n = A._n;\n\tos << \"\
    [ \";\n\tfor (int i = 0; i < n; i++) {\n\t\tos << A.prod(i, i + 1);\n\t\tif (i\
    \ != n - 1) {\n\t\t\tos << \", \";\n\t\t}\n\t}\n\tos << \" ]\";\n\treturn os;\n\
    }\nostream &operator<<(ostream &os, dsu ds) {\n\tos << ds.groups();\n\treturn\
    \ os;\n}\nostream &operator<<(ostream &os, modint998244353 x) {\n\tos << x.val();\n\
    \treturn os;\n}\nostream &operator<<(ostream &os, modint1000000007 x) {\n\tos\
    \ << x.val();\n\treturn os;\n}\n\n#define print_line cerr << \"--------------------\"\
    \ << __LINE__ << \"--------------------\" \\\n\t\t\t\t\t\t\t\t\t\t\t\t<< \"\\\
    n\"\n#define debug(...) debug_print(0, #__VA_ARGS__, __VA_ARGS__)\n#define get_name(VariableName)\
    \ #VariableName\ntemplate <typename T>\nvoid debug_print(int i, T name) {\n\t\
    cerr << endl;\n}\ntemplate <typename T1, typename T2, typename... T3>\nvoid debug_print(int\
    \ i, const T1 &name, const T2 &a, const T3 &...b) {\n\tfor (; name[i] != ',' &&\
    \ name[i] != '\\0'; i++) {\n\t\tcerr << name[i];\n\t}\n\tcerr << \" : \" << a\
    \ << \", \";\n\tdebug_print(i + 1, name, b...);\n}\ntemplate <typename T>\nvoid\
    \ debugc(T a, string sep = \", \") {\n\tcerr << get_name(a) << \" : [\";\n\tfor\
    \ (auto x : a) {\n\t\tcerr << x << sep;\n\t}\n\tcerr << \"]\" << endl;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n#include <atcoder/all>\n\
    using namespace atcoder;\n\ntemplate <class T>\nostream &operator<<(ostream &os,\
    \ const vector<T> &A) {\n\tint n = A.size();\n\tos << \"[ \";\n\tfor (int i =\
    \ 0; i < n; i++) {\n\t\tos << A[i];\n\t\tif (i != n - 1) {\n\t\t\tos << \", \"\
    ;\n\t\t}\n\t}\n\tos << \" ]\";\n\treturn os;\n}\ntemplate <class T>\nostream &operator<<(ostream\
    \ &os, const vector<vector<T>> &A) {\n\tos << \"[\\n\";\n\tint n = A.size();\n\
    \tfor (int i = 0; i < n; i++) {\n\t\tos << \"      \";\n\t\tos << A[i];\n\t\t\
    os << \", \\n\";\n\t}\n\tos << \" ]\";\n\treturn os;\n}\ntemplate <class T>\n\
    ostream &operator<<(ostream &os, const set<T> &A) {\n\tint n = A.size();\n\tos\
    \ << \"[ \";\n\tfor (T x : A) {\n\t\tos << x << \", \";\n\t}\n\tos << \" ]\";\n\
    \treturn os;\n}\ntemplate <class T>\nostream &operator<<(ostream &os, const multiset<T>\
    \ &A) {\n\tint n = A.size();\n\tos << \"[ \";\n\tfor (T x : A) {\n\t\tos << x\
    \ << \", \";\n\t}\n\tos << \" ]\";\n\treturn os;\n}\ntemplate <class T1, class\
    \ T2>\nostream &operator<<(ostream &os, const pair<T1, T2> &p) {\n\tos << \"(\
    \ \" << p.first << \", \" << p.second << \" )\";\n\treturn os;\n}\ntemplate <class\
    \ T>\nostream &operator<<(ostream &os, queue<T> A) {\n\tint n = A.size();\n\t\
    os << \"[ \";\n\twhile (!A.empty()) {\n\t\tos << A.front() << \", \";\n\t\tA.pop();\n\
    \t}\n\tos << \" ]\";\n\treturn os;\n}\ntemplate <class T>\nostream &operator<<(ostream\
    \ &os, priority_queue<T> A) {\n\tint n = A.size();\n\tos << \"[ \";\n\twhile (!A.empty())\
    \ {\n\t\tos << A.top() << \", \";\n\t\tA.pop();\n\t}\n\tos << \" ]\";\n\treturn\
    \ os;\n}\ntemplate <class T>\nostream &operator<<(ostream &os, fenwick_tree<T>\
    \ A) {\n\tint n = A._n;\n\tos << \"[ \";\n\tfor (int i = 0; i < n; i++) {\n\t\t\
    os << A.sum(i, i + 1);\n\t\tif (i != n - 1) {\n\t\t\tos << \", \";\n\t\t}\n\t\
    }\n\tos << \" ]\";\n\treturn os;\n}\ntemplate <class S, S (*op)(S, S), S (*e)()>\n\
    ostream &operator<<(ostream &os, segtree<S, op, e> A) {\n\tint n = A._n;\n\tos\
    \ << \"[ \";\n\tfor (int i = 0; i < n; i++) {\n\t\tos << A.prod(i, i + 1);\n\t\
    \tif (i != n - 1) {\n\t\t\tos << \", \";\n\t\t}\n\t}\n\tos << \" ]\";\n\treturn\
    \ os;\n}\nostream &operator<<(ostream &os, dsu ds) {\n\tos << ds.groups();\n\t\
    return os;\n}\nostream &operator<<(ostream &os, modint998244353 x) {\n\tos <<\
    \ x.val();\n\treturn os;\n}\nostream &operator<<(ostream &os, modint1000000007\
    \ x) {\n\tos << x.val();\n\treturn os;\n}\n\n#define print_line cerr << \"--------------------\"\
    \ << __LINE__ << \"--------------------\" \\\n\t\t\t\t\t\t\t\t\t\t\t\t<< \"\\\
    n\"\n#define debug(...) debug_print(0, #__VA_ARGS__, __VA_ARGS__)\n#define get_name(VariableName)\
    \ #VariableName\ntemplate <typename T>\nvoid debug_print(int i, T name) {\n\t\
    cerr << endl;\n}\ntemplate <typename T1, typename T2, typename... T3>\nvoid debug_print(int\
    \ i, const T1 &name, const T2 &a, const T3 &...b) {\n\tfor (; name[i] != ',' &&\
    \ name[i] != '\\0'; i++) {\n\t\tcerr << name[i];\n\t}\n\tcerr << \" : \" << a\
    \ << \", \";\n\tdebug_print(i + 1, name, b...);\n}\ntemplate <typename T>\nvoid\
    \ debugc(T a, string sep = \", \") {\n\tcerr << get_name(a) << \" : [\";\n\tfor\
    \ (auto x : a) {\n\t\tcerr << x << sep;\n\t}\n\tcerr << \"]\" << endl;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: others/debug.cpp
  requiredBy: []
  timestamp: '2023-11-30 19:42:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: others/debug.cpp
layout: document
redirect_from:
- /library/others/debug.cpp
- /library/others/debug.cpp.html
title: others/debug.cpp
---
