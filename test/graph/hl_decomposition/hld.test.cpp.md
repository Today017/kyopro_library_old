---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../../graph/hl_decomposition.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../graph/hl_decomposition.cpp\"\
    \n#include \"../../../data_structure/fenwick_tree.cpp\"\n\nint main() {\n\tint\
    \ N, Q;\n\tcin >> N >> Q;\n\n\tfenwick_tree<long long> ft(N);\n\theavy_light_decomposition\
    \ hld(N);\n\n\tvector<int> A(N);\n\tfor (int i = 0; i < N; i++) {\n\t\tcin >>\
    \ A[i];\n\t}\n\tfor (int i = 0; i < N - 1; i++) {\n\t\tint u, v;\n\t\tcin >> u\
    \ >> v;\n\t\thld.add_edge(u, v);\n\t}\n\n\thld.hld_start();\n\tfor (int i = 0;\
    \ i < N; i++) {\n\t\tauto Update = [&](int i, int pos) {\n\t\t\tft.add(pos, A[i]);\n\
    \t\t};\n\t\thld.update(i, Update);\n\t}\n\n\twhile (Q--) {\n\t\tint t;\n\t\tcin\
    \ >> t;\n\n\t\tif (t == 0) {\n\t\t\tint p, x;\n\t\t\tcin >> p >> x;\n\n\t\t\t\
    auto Update = [&](int i, int pos) {\n\t\t\t\tft.add(pos, x);\n\t\t\t};\n\n\t\t\
    \thld.update(p, Update);\n\t\t}\n\n\t\telse {\n\t\t\tint u, v;\n\t\t\tcin >> u\
    \ >> v;\n\n\t\t\tauto Query = [&](int x, int y) {\n\t\t\t\treturn ft.sum(x, y);\n\
    \t\t\t};\n\t\t\tauto F = [&](long long a, long long b) {\n\t\t\t\treturn a + b;\n\
    \t\t\t};\n\t\t\tlong long e = 0;\n\n\t\t\tcout << hld.query(u, v, Query, F, e)\
    \ << '\\n';\n\t\t}\n\t}\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/graph/hl_decomposition/hld.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/graph/hl_decomposition/hld.test.cpp
layout: document
redirect_from:
- /verify/test/graph/hl_decomposition/hld.test.cpp
- /verify/test/graph/hl_decomposition/hld.test.cpp.html
title: test/graph/hl_decomposition/hld.test.cpp
---
