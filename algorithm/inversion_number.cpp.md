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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: data_stracture/fenwick_tree.cpp:\
    \ line -1: no such header\n"
  code: "#include <bits/stdc++.h>\r\nusing namespace std;\r\n#include \"data_stracture/fenwick_tree.cpp\"\
    \r\n\r\nlong long inversion_number(const vector<int> &A) {\r\n\tint n = A.size();\r\
    \n\tfenwick_tree<int> ft(n);\r\n\tlong long ret = 0;\r\n\tfor (int i = 0; i <\
    \ n; i++) {\r\n\t\tret += i - ft.sum(0, A[i]);\r\n\t\tft.add(A[i], 1);\r\n\t}\r\
    \n\treturn ret;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/inversion_number.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/inversion_number.cpp
layout: document
redirect_from:
- /library/algorithm/inversion_number.cpp
- /library/algorithm/inversion_number.cpp.html
title: algorithm/inversion_number.cpp
---
