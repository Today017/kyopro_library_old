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
  bundledCode: "#line 1 \"math/matrix.cpp\"\ntemplate <class T>\r\nusing matrix =\
    \ vector<vector<T>>;\r\ntemplate <class T>\r\nmatrix<T> make_matrix(int n) {\r\
    \n\tvector<vector<T>> ret(n, vector<T>(n));\r\n\treturn ret;\r\n}\r\ntemplate\
    \ <class T>\r\nmatrix<T> operator*(const matrix<T>& a, const matrix<T>& b) {\r\
    \n\tint n = a.size();\r\n\tmatrix<T> ret(n, vector<T>(n));\r\n\tfor (int i = 0;\
    \ i < n; i++) {\r\n\t\tfor (int j = 0; j < n; j++) {\r\n\t\t\tfor (int k = 0;\
    \ k < n; k++) {\r\n\t\t\t\tret[i][j] += a[i][k] * b[k][j];\r\n\t\t\t}\r\n\t\t\
    }\r\n\t}\r\n\treturn ret;\r\n}\r\ntemplate <class T>\r\nmatrix<T> operator^(matrix<T>\
    \ a, long long b) {\r\n\tint n = a.size();\r\n\tmatrix<T> ret(n, vector<T>(n));\r\
    \n\tfor (int i = 0; i < n; i++) {\r\n\t\tret[i][i] = 1;\r\n\t}\r\n\twhile (b >\
    \ 0) {\r\n\t\tif (b % 2 == 1) {\r\n\t\t\tret = ret * a;\r\n\t\t}\r\n\t\ta = a\
    \ * a;\r\n\t\tb /= 2;\r\n\t}\r\n\treturn ret;\r\n}\r\n"
  code: "template <class T>\r\nusing matrix = vector<vector<T>>;\r\ntemplate <class\
    \ T>\r\nmatrix<T> make_matrix(int n) {\r\n\tvector<vector<T>> ret(n, vector<T>(n));\r\
    \n\treturn ret;\r\n}\r\ntemplate <class T>\r\nmatrix<T> operator*(const matrix<T>&\
    \ a, const matrix<T>& b) {\r\n\tint n = a.size();\r\n\tmatrix<T> ret(n, vector<T>(n));\r\
    \n\tfor (int i = 0; i < n; i++) {\r\n\t\tfor (int j = 0; j < n; j++) {\r\n\t\t\
    \tfor (int k = 0; k < n; k++) {\r\n\t\t\t\tret[i][j] += a[i][k] * b[k][j];\r\n\
    \t\t\t}\r\n\t\t}\r\n\t}\r\n\treturn ret;\r\n}\r\ntemplate <class T>\r\nmatrix<T>\
    \ operator^(matrix<T> a, long long b) {\r\n\tint n = a.size();\r\n\tmatrix<T>\
    \ ret(n, vector<T>(n));\r\n\tfor (int i = 0; i < n; i++) {\r\n\t\tret[i][i] =\
    \ 1;\r\n\t}\r\n\twhile (b > 0) {\r\n\t\tif (b % 2 == 1) {\r\n\t\t\tret = ret *\
    \ a;\r\n\t\t}\r\n\t\ta = a * a;\r\n\t\tb /= 2;\r\n\t}\r\n\treturn ret;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/matrix.cpp
  requiredBy: []
  timestamp: '2023-12-04 01:54:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/matrix.cpp
layout: document
redirect_from:
- /library/math/matrix.cpp
- /library/math/matrix.cpp.html
title: math/matrix.cpp
---
