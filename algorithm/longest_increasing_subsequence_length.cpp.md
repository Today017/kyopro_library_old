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
  bundledCode: "#line 1 \"algorithm/longest_increasing_subsequence_length.cpp\"\n\
    #include <vector>\n#include <algorithm>\n#include <climits>\n\nint longest_increasing_subsequence_length(std::vector<int>\
    \ &A, bool strict = true) {\n\tint n = A.size();\n\tstd::vector<int> dp(n, INT_MAX);\n\
    \tfor (int i = 0; i < n; i++) {\n\t\tstd::vector<int>::iterator itr;\n\t\tif (strict)\
    \ {\n\t\t\titr = lower_bound(dp.begin(), dp.end(), A[i]);\n\t\t} else {\n\t\t\t\
    itr = upper_bound(dp.begin(), dp.end(), A[i]);\n\t\t}\n\t\t*itr = A[i];\n\t}\n\
    \treturn find(dp.begin(), dp.end(), INT_MAX) - dp.begin();\n}\n"
  code: "#include <vector>\n#include <algorithm>\n#include <climits>\n\nint longest_increasing_subsequence_length(std::vector<int>\
    \ &A, bool strict = true) {\n\tint n = A.size();\n\tstd::vector<int> dp(n, INT_MAX);\n\
    \tfor (int i = 0; i < n; i++) {\n\t\tstd::vector<int>::iterator itr;\n\t\tif (strict)\
    \ {\n\t\t\titr = lower_bound(dp.begin(), dp.end(), A[i]);\n\t\t} else {\n\t\t\t\
    itr = upper_bound(dp.begin(), dp.end(), A[i]);\n\t\t}\n\t\t*itr = A[i];\n\t}\n\
    \treturn find(dp.begin(), dp.end(), INT_MAX) - dp.begin();\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/longest_increasing_subsequence_length.cpp
  requiredBy: []
  timestamp: '2023-12-06 10:41:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/longest_increasing_subsequence_length.cpp
layout: document
redirect_from:
- /library/algorithm/longest_increasing_subsequence_length.cpp
- /library/algorithm/longest_increasing_subsequence_length.cpp.html
title: algorithm/longest_increasing_subsequence_length.cpp
---
