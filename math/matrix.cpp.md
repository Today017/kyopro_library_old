---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Matrix
    links: []
  bundledCode: "#line 1 \"math/matrix.cpp\"\n#include <vector>\r\n\r\n/**\r\n * @brief\
    \ Matrix\r\n */\r\n\r\ntemplate <class T>\r\nusing matrix = std::vector<std::vector<T>>;\r\
    \ntemplate <class T>\r\nmatrix<T> make_matrix(int n) {\r\n    vector<vector<T>>\
    \ ret(n, vector<T>(n));\r\n    return ret;\r\n}\r\ntemplate <class T>\r\nmatrix<T>\
    \ operator*(const matrix<T>& a, const matrix<T>& b) {\r\n    int n = a.size();\r\
    \n    matrix<T> ret(n, vector<T>(n));\r\n    for (int i = 0; i < n; i++) {\r\n\
    \        for (int j = 0; j < n; j++) {\r\n            for (int k = 0; k < n; k++)\
    \ {\r\n                ret[i][j] += a[i][k] * b[k][j];\r\n            }\r\n  \
    \      }\r\n    }\r\n    return ret;\r\n}\r\ntemplate <class T>\r\nmatrix<T> operator^(matrix<T>\
    \ a, long long b) {\r\n    int n = a.size();\r\n    matrix<T> ret(n, vector<T>(n));\r\
    \n    for (int i = 0; i < n; i++) {\r\n        ret[i][i] = 1;\r\n    }\r\n   \
    \ while (b > 0) {\r\n        if (b % 2 == 1) {\r\n            ret = ret * a;\r\
    \n        }\r\n        a = a * a;\r\n        b /= 2;\r\n    }\r\n    return ret;\r\
    \n}\r\n"
  code: "#include <vector>\r\n\r\n/**\r\n * @brief Matrix\r\n */\r\n\r\ntemplate <class\
    \ T>\r\nusing matrix = std::vector<std::vector<T>>;\r\ntemplate <class T>\r\n\
    matrix<T> make_matrix(int n) {\r\n    vector<vector<T>> ret(n, vector<T>(n));\r\
    \n    return ret;\r\n}\r\ntemplate <class T>\r\nmatrix<T> operator*(const matrix<T>&\
    \ a, const matrix<T>& b) {\r\n    int n = a.size();\r\n    matrix<T> ret(n, vector<T>(n));\r\
    \n    for (int i = 0; i < n; i++) {\r\n        for (int j = 0; j < n; j++) {\r\
    \n            for (int k = 0; k < n; k++) {\r\n                ret[i][j] += a[i][k]\
    \ * b[k][j];\r\n            }\r\n        }\r\n    }\r\n    return ret;\r\n}\r\n\
    template <class T>\r\nmatrix<T> operator^(matrix<T> a, long long b) {\r\n    int\
    \ n = a.size();\r\n    matrix<T> ret(n, vector<T>(n));\r\n    for (int i = 0;\
    \ i < n; i++) {\r\n        ret[i][i] = 1;\r\n    }\r\n    while (b > 0) {\r\n\
    \        if (b % 2 == 1) {\r\n            ret = ret * a;\r\n        }\r\n    \
    \    a = a * a;\r\n        b /= 2;\r\n    }\r\n    return ret;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/matrix.cpp
  requiredBy: []
  timestamp: '2024-01-25 11:55:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/matrix.cpp
layout: document
redirect_from:
- /library/math/matrix.cpp
- /library/math/matrix.cpp.html
title: Matrix
---
