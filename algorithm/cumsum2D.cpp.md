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
  bundledCode: "#line 1 \"algorithm/cumsum2D.cpp\"\n#include <vector>\n\ntemplate\
    \ <typename U, typename T>\nstruct cumsum2D {\n    int n, m;\n    std::vector<std::vector<T>>\
    \ S;\n    cumsum2D(std::vector<vector<U>> &A) {\n        n = A.size();\n     \
    \   m = A.front().size();\n        S.resize(n + 1);\n        for (int i = 0; i\
    \ <= n; i++) {\n            S[i].resize(m + 1);\n        }\n        for (int i\
    \ = 0; i < n; i++) {\n            for (int j = 0; j < m; j++) {\n            \
    \    S[i + 1][j + 1] = S[i][j + 1] + S[i + 1][j] - S[i][j] + A[i][j];\n      \
    \      }\n        }\n    }\n    T sum(int a, int b, int c, int d) {\n        return\
    \ S[b][d] - S[a][d] - S[b][c] + S[a][c];\n    }\n};\n"
  code: "#include <vector>\n\ntemplate <typename U, typename T>\nstruct cumsum2D {\n\
    \    int n, m;\n    std::vector<std::vector<T>> S;\n    cumsum2D(std::vector<vector<U>>\
    \ &A) {\n        n = A.size();\n        m = A.front().size();\n        S.resize(n\
    \ + 1);\n        for (int i = 0; i <= n; i++) {\n            S[i].resize(m + 1);\n\
    \        }\n        for (int i = 0; i < n; i++) {\n            for (int j = 0;\
    \ j < m; j++) {\n                S[i + 1][j + 1] = S[i][j + 1] + S[i + 1][j] -\
    \ S[i][j] + A[i][j];\n            }\n        }\n    }\n    T sum(int a, int b,\
    \ int c, int d) {\n        return S[b][d] - S[a][d] - S[b][c] + S[a][c];\n   \
    \ }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/cumsum2D.cpp
  requiredBy: []
  timestamp: '2024-01-25 11:55:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/cumsum2D.cpp
layout: document
redirect_from:
- /library/algorithm/cumsum2D.cpp
- /library/algorithm/cumsum2D.cpp.html
title: algorithm/cumsum2D.cpp
---
