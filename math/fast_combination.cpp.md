---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Pre-Calculated Combination
    links: []
  bundledCode: "#line 1 \"math/fast_combination.cpp\"\n#include <vector>\r\n\r\n/**\r\
    \n * @brief Pre-Calculated Combination\r\n*/\r\n\r\ntemplate <typename T>\r\n\
    std::vector<std::vector<T>> combination(int n) {\r\n\tstd::vector<std::vector<T>>\
    \ nCr(n + 1, std::vector<T>(n + 1));\r\n\tfor (int i = 0; i <= n; i++) {\r\n\t\
    \tnCr[i][0] = nCr[i][i] = 1;\r\n\t\tfor (int j = 1; j < i; j++) {\r\n\t\t\tnCr[i][j]\
    \ = nCr[i - 1][j - 1] + nCr[i - 1][j];\r\n\t\t}\r\n\t}\r\n\treturn nCr;\r\n}\n"
  code: "#include <vector>\r\n\r\n/**\r\n * @brief Pre-Calculated Combination\r\n\
    */\r\n\r\ntemplate <typename T>\r\nstd::vector<std::vector<T>> combination(int\
    \ n) {\r\n\tstd::vector<std::vector<T>> nCr(n + 1, std::vector<T>(n + 1));\r\n\
    \tfor (int i = 0; i <= n; i++) {\r\n\t\tnCr[i][0] = nCr[i][i] = 1;\r\n\t\tfor\
    \ (int j = 1; j < i; j++) {\r\n\t\t\tnCr[i][j] = nCr[i - 1][j - 1] + nCr[i - 1][j];\r\
    \n\t\t}\r\n\t}\r\n\treturn nCr;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/fast_combination.cpp
  requiredBy: []
  timestamp: '2023-12-06 10:41:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/fast_combination.cpp
layout: document
redirect_from:
- /library/math/fast_combination.cpp
- /library/math/fast_combination.cpp.html
title: Pre-Calculated Combination
---
