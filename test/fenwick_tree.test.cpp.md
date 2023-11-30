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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: Today's/fenwick_tree.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    #include <bits/stdc++.h>\nusing namespace std;\n#include \"Today's/fenwick_tree.cpp\"\
    \n\nint main(){\n\tint N,Q;cin>>N>>Q;\n\tfenwick_tree<long long>FT(N);\n\tfor(int\
    \ i=0;i<N;i++){\n\t\tint a;cin>>a;\n\t\tFT.add(i,a);\n\t}\n\twhile(Q--){\n\t\t\
    int t;\n\t\tcin>>t;\n\t\tif(t==0){\n\t\t\tint p,x;\n\t\t\tcin>>p>>x;\n\t\t\tFT.add(p,x);\n\
    \t\t}\n\t\telse{\n\t\t\tint l,r;\n\t\t\tcin>>l>>r;\n\t\t\tcout<<FT.sum(l,r)<<'\\\
    n';\n\t\t}\n\t}\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/fenwick_tree.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/fenwick_tree.test.cpp
layout: document
redirect_from:
- /verify/test/fenwick_tree.test.cpp
- /verify/test/fenwick_tree.test.cpp.html
title: test/fenwick_tree.test.cpp
---
