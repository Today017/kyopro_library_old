---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/fenwick_tree.cpp
    title: data_structure/fenwick_tree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"test/fenwick_tree.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n#line 1 \"data_structure/fenwick_tree.cpp\"\
    \ntemplate <typename T>\r\nstruct fenwick_tree {\r\n\tint n;\r\n\tvector<T> dat;\r\
    \n\tfenwick_tree(int n) {\r\n\t\tthis->n = n;\r\n\t\tdat.resize(n);\r\n\t}\r\n\
    \tvoid add(int i, T x) {\r\n\t\ti++;\r\n\t\twhile (i <= n) {\r\n\t\t\tdat[i -\
    \ 1] += x;\r\n\t\t\ti += i & -i;\r\n\t\t}\r\n\t}\r\n\tT sum(int l, int r) {\r\n\
    \t\treturn sum(r) - sum(l);\r\n\t}\r\n\tT sum(int r) {\r\n\t\tT ret = 0;\r\n\t\
    \twhile (r > 0) {\r\n\t\t\tret += dat[r - 1];\r\n\t\t\tr -= r & -r;\r\n\t\t}\r\
    \n\t\treturn ret;\r\n\t}\r\n\tT operator[](int i) {\r\n\t\treturn sum(i, i + 1);\r\
    \n\t}\r\n};\r\n#line 5 \"test/fenwick_tree.test.cpp\"\n\nint main() {\n\tint N,\
    \ Q;\n\tcin >> N >> Q;\n\tfenwick_tree<long long> FT(N);\n\tfor (int i = 0; i\
    \ < N; i++) {\n\t\tint a;\n\t\tcin >> a;\n\t\tFT.add(i, a);\n\t}\n\twhile (Q--)\
    \ {\n\t\tint t;\n\t\tcin >> t;\n\t\tif (t == 0) {\n\t\t\tint p, x;\n\t\t\tcin\
    \ >> p >> x;\n\t\t\tFT.add(p, x);\n\t\t} else {\n\t\t\tint l, r;\n\t\t\tcin >>\
    \ l >> r;\n\t\t\tcout << FT.sum(l, r) << '\\n';\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    #include <bits/stdc++.h>\nusing namespace std;\n#include \"../data_structure/fenwick_tree.cpp\"\
    \n\nint main() {\n\tint N, Q;\n\tcin >> N >> Q;\n\tfenwick_tree<long long> FT(N);\n\
    \tfor (int i = 0; i < N; i++) {\n\t\tint a;\n\t\tcin >> a;\n\t\tFT.add(i, a);\n\
    \t}\n\twhile (Q--) {\n\t\tint t;\n\t\tcin >> t;\n\t\tif (t == 0) {\n\t\t\tint\
    \ p, x;\n\t\t\tcin >> p >> x;\n\t\t\tFT.add(p, x);\n\t\t} else {\n\t\t\tint l,\
    \ r;\n\t\t\tcin >> l >> r;\n\t\t\tcout << FT.sum(l, r) << '\\n';\n\t\t}\n\t}\n\
    }\n"
  dependsOn:
  - data_structure/fenwick_tree.cpp
  isVerificationFile: true
  path: test/fenwick_tree.test.cpp
  requiredBy: []
  timestamp: '2023-11-30 18:34:27+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/fenwick_tree.test.cpp
layout: document
redirect_from:
- /verify/test/fenwick_tree.test.cpp
- /verify/test/fenwick_tree.test.cpp.html
title: test/fenwick_tree.test.cpp
---
