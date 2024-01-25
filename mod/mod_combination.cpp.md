---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Combination
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: kyopro_library/mod/modint.cpp:\
    \ line -1: no such header\n"
  code: "#include \"kyopro_library/mod/modint.cpp\"\n#include <vector>\n\n/**\n *\
    \ @brief Combination\n */\n\ntemplate <typename T>\nstruct combination {\n   \
    \ std::vector<T> fact, factinv;\n    combination(int n) {\n        fact.resize(n\
    \ + 1);\n        factinv.resize(n + 1);\n        fact[0] = 1;\n        for (int\
    \ i = 1; i <= n; i++) {\n            fact[i] = fact[i - 1] * i;\n        }\n \
    \       for (int i = 0; i <= n; i++) {\n            factinv[i] = fact[i].inv();\n\
    \        }\n    }\n    T nCr(long long n, long long r) {\n        if (n < 0 ||\
    \ r < 0 || n - r < 0) {\n            return 0;\n        }\n        return fact[n]\
    \ * factinv[r] * factinv[n - r];\n    }\n    T nPr(long long n, long long r) {\n\
    \        if (n < 0 || r < 0 || n - r < 0) {\n            return 0;\n        }\n\
    \        return fact[n] * factinv[n - r];\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: mod/mod_combination.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: mod/mod_combination.cpp
layout: document
redirect_from:
- /library/mod/mod_combination.cpp
- /library/mod/mod_combination.cpp.html
title: Combination
---
