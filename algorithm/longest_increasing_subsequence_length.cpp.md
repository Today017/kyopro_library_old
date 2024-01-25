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
    \ &A, bool strict = true) {\n    int n = A.size();\n    std::vector<int> dp(n,\
    \ INT_MAX);\n    for (int i = 0; i < n; i++) {\n        std::vector<int>::iterator\
    \ itr;\n        if (strict) {\n            itr = lower_bound(dp.begin(), dp.end(),\
    \ A[i]);\n        } else {\n            itr = upper_bound(dp.begin(), dp.end(),\
    \ A[i]);\n        }\n        *itr = A[i];\n    }\n    return find(dp.begin(),\
    \ dp.end(), INT_MAX) - dp.begin();\n}\n"
  code: "#include <vector>\n#include <algorithm>\n#include <climits>\n\nint longest_increasing_subsequence_length(std::vector<int>\
    \ &A, bool strict = true) {\n    int n = A.size();\n    std::vector<int> dp(n,\
    \ INT_MAX);\n    for (int i = 0; i < n; i++) {\n        std::vector<int>::iterator\
    \ itr;\n        if (strict) {\n            itr = lower_bound(dp.begin(), dp.end(),\
    \ A[i]);\n        } else {\n            itr = upper_bound(dp.begin(), dp.end(),\
    \ A[i]);\n        }\n        *itr = A[i];\n    }\n    return find(dp.begin(),\
    \ dp.end(), INT_MAX) - dp.begin();\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/longest_increasing_subsequence_length.cpp
  requiredBy: []
  timestamp: '2024-01-25 11:55:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/longest_increasing_subsequence_length.cpp
layout: document
redirect_from:
- /library/algorithm/longest_increasing_subsequence_length.cpp
- /library/algorithm/longest_increasing_subsequence_length.cpp.html
title: algorithm/longest_increasing_subsequence_length.cpp
---
