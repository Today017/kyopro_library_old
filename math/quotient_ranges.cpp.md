---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Quotient Ranges
    links: []
  bundledCode: "#line 1 \"math/quotient_ranges.cpp\"\n#include <vector>\n#include\
    \ <utility>\n\n/**\n * @brief Quotient Ranges\n */\n\ntemplate <typename T>\n\
    std::vector<std::pair<std::pair<T, T>, T>> quotient_ranges(T n) {\n    std::vector<std::pair<std::pair<T,\
    \ T>, T>> ret;\n    T l = 1;\n    while (l <= n) {\n        T q = n / l;\n   \
    \     T r = n / q + 1;\n        ret.push_back(std::make_pair(l, r), q);\n    \
    \    l = r;\n    }\n    return ret;\n}\n"
  code: "#include <vector>\n#include <utility>\n\n/**\n * @brief Quotient Ranges\n\
    \ */\n\ntemplate <typename T>\nstd::vector<std::pair<std::pair<T, T>, T>> quotient_ranges(T\
    \ n) {\n    std::vector<std::pair<std::pair<T, T>, T>> ret;\n    T l = 1;\n  \
    \  while (l <= n) {\n        T q = n / l;\n        T r = n / q + 1;\n        ret.push_back(std::make_pair(l,\
    \ r), q);\n        l = r;\n    }\n    return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/quotient_ranges.cpp
  requiredBy: []
  timestamp: '2024-01-25 11:55:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/quotient_ranges.cpp
layout: document
redirect_from:
- /library/math/quotient_ranges.cpp
- /library/math/quotient_ranges.cpp.html
title: Quotient Ranges
---
