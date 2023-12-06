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
    \ <typename U, typename T>\nstruct cumsum2D {\n\tint n, m;\n\tstd::vector<std::vector<T>>\
    \ S;\n\tcumsum2D(std::vector<vector<U>> &A) {\n\t\tn = A.size();\n\t\tm = A.front().size();\n\
    \t\tS.resize(n + 1);\n\t\tfor (int i = 0; i <= n; i++) {\n\t\t\tS[i].resize(m\
    \ + 1);\n\t\t}\n\t\tfor (int i = 0; i < n; i++) {\n\t\t\tfor (int j = 0; j < m;\
    \ j++) {\n\t\t\t\tS[i + 1][j + 1] = S[i][j + 1] + S[i + 1][j] - S[i][j] + A[i][j];\n\
    \t\t\t}\n\t\t}\n\t}\n\tT sum(int a, int b, int c, int d) {\n\t\treturn S[b][d]\
    \ - S[a][d] - S[b][c] + S[a][c];\n\t}\n};\n"
  code: "#include <vector>\n\ntemplate <typename U, typename T>\nstruct cumsum2D {\n\
    \tint n, m;\n\tstd::vector<std::vector<T>> S;\n\tcumsum2D(std::vector<vector<U>>\
    \ &A) {\n\t\tn = A.size();\n\t\tm = A.front().size();\n\t\tS.resize(n + 1);\n\t\
    \tfor (int i = 0; i <= n; i++) {\n\t\t\tS[i].resize(m + 1);\n\t\t}\n\t\tfor (int\
    \ i = 0; i < n; i++) {\n\t\t\tfor (int j = 0; j < m; j++) {\n\t\t\t\tS[i + 1][j\
    \ + 1] = S[i][j + 1] + S[i + 1][j] - S[i][j] + A[i][j];\n\t\t\t}\n\t\t}\n\t}\n\
    \tT sum(int a, int b, int c, int d) {\n\t\treturn S[b][d] - S[a][d] - S[b][c]\
    \ + S[a][c];\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/cumsum2D.cpp
  requiredBy: []
  timestamp: '2023-12-06 10:41:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/cumsum2D.cpp
layout: document
redirect_from:
- /library/algorithm/cumsum2D.cpp
- /library/algorithm/cumsum2D.cpp.html
title: algorithm/cumsum2D.cpp
---
