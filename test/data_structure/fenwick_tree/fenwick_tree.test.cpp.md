---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/fenwick_tree.cpp
    title: Fenwick Tree
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
  bundledCode: "#line 1 \"test/data_structure/fenwick_tree/fenwick_tree.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"data_structure/fenwick_tree.cpp\"\
    \n\r\n/**\r\n * @brief Fenwick Tree\r\n * @docs docs/data_structure/fenwick_tree.md\r\
    \n */\r\n\r\ntemplate <typename T>\r\nstruct fenwick_tree {\r\n\tfenwick_tree(int\
    \ n) {\r\n\t\tthis->n = n;\r\n\t\tdat.resize(n);\r\n\t}\r\n\tvoid add(int i, T\
    \ x) {\r\n\t\ti++;\r\n\t\twhile (i <= n) {\r\n\t\t\tdat[i - 1] += x;\r\n\t\t\t\
    i += i & -i;\r\n\t\t}\r\n\t}\r\n\tT operator[](int i) {\r\n\t\treturn sum(i, i\
    \ + 1);\r\n\t}\r\n\tT sum(int l, int r) {\r\n\t\treturn sum(r) - sum(l);\r\n\t\
    }\r\n\r\n\tprivate:\r\n\tint n;\r\n\tstd::vector<T> dat;\r\n\tT sum(int r) {\r\
    \n\t\tT ret = 0;\r\n\t\twhile (r > 0) {\r\n\t\t\tret += dat[r - 1];\r\n\t\t\t\
    r -= r & -r;\r\n\t\t}\r\n\t\treturn ret;\r\n\t}\r\n};\n#line 6 \"test/data_structure/fenwick_tree/fenwick_tree.test.cpp\"\
    \n\nint main() {\n\tint N, Q;\n\tcin >> N >> Q;\n\tfenwick_tree<long long> ft(N);\n\
    \tfor (int i = 0; i < N; i++) {\n\t\tint a;\n\t\tcin >> a;\n\t\tft.add(i, a);\n\
    \t}\n\twhile (Q--) {\n\t\tint t;\n\t\tcin >> t;\n\t\tif (t == 0) {\n\t\t\tint\
    \ p, x;\n\t\t\tcin >> p >> x;\n\t\t\tft.add(p, x);\n\t\t} else {\n\t\t\tint l,\
    \ r;\n\t\t\tcin >> l >> r;\n\t\t\tcout << ft.sum(l, r) << '\\n';\n\t\t}\n\t}\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../data_structure/fenwick_tree.cpp\"\
    \n\nint main() {\n\tint N, Q;\n\tcin >> N >> Q;\n\tfenwick_tree<long long> ft(N);\n\
    \tfor (int i = 0; i < N; i++) {\n\t\tint a;\n\t\tcin >> a;\n\t\tft.add(i, a);\n\
    \t}\n\twhile (Q--) {\n\t\tint t;\n\t\tcin >> t;\n\t\tif (t == 0) {\n\t\t\tint\
    \ p, x;\n\t\t\tcin >> p >> x;\n\t\t\tft.add(p, x);\n\t\t} else {\n\t\t\tint l,\
    \ r;\n\t\t\tcin >> l >> r;\n\t\t\tcout << ft.sum(l, r) << '\\n';\n\t\t}\n\t}\n\
    }\n"
  dependsOn:
  - data_structure/fenwick_tree.cpp
  isVerificationFile: true
  path: test/data_structure/fenwick_tree/fenwick_tree.test.cpp
  requiredBy: []
  timestamp: '2023-12-24 07:38:27+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/fenwick_tree/fenwick_tree.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/fenwick_tree/fenwick_tree.test.cpp
- /verify/test/data_structure/fenwick_tree/fenwick_tree.test.cpp.html
title: test/data_structure/fenwick_tree/fenwick_tree.test.cpp
---
