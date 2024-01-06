---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Z-algorithm
    links: []
  bundledCode: "#line 1 \"string/z_algo.cpp\"\n#include <vector>\n#include <string>\n\
    #include <algorithm>\n\n/**\n * @brief Z-algorithm\n */\n\nstd::vector<int> z_algorithm(std::string\
    \ s) {\n\tint n = s.size();\n\tint c = 0;\n\tstd::vector<int> ret(n, 0);\n\tfor\
    \ (int i = 1; i < n; i++) {\n\t\tint l = i - c;\n\t\tif (i + ret[l] < c + ret[c])\
    \ {\n\t\t\tret[i] = ret[l];\n\t\t} else {\n\t\t\tint j = std::max(c + ret[c] -\
    \ i, 0);\n\t\t\twhile (i + j < n && s[j] == s[i + j]) {\n\t\t\t\tj++;\n\t\t\t\
    }\n\t\t\tret[i] = j;\n\t\t\tc = i;\n\t\t}\n\t}\n\tret[0] = n;\n\treturn ret;\n\
    }\n"
  code: "#include <vector>\n#include <string>\n#include <algorithm>\n\n/**\n * @brief\
    \ Z-algorithm\n */\n\nstd::vector<int> z_algorithm(std::string s) {\n\tint n =\
    \ s.size();\n\tint c = 0;\n\tstd::vector<int> ret(n, 0);\n\tfor (int i = 1; i\
    \ < n; i++) {\n\t\tint l = i - c;\n\t\tif (i + ret[l] < c + ret[c]) {\n\t\t\t\
    ret[i] = ret[l];\n\t\t} else {\n\t\t\tint j = std::max(c + ret[c] - i, 0);\n\t\
    \t\twhile (i + j < n && s[j] == s[i + j]) {\n\t\t\t\tj++;\n\t\t\t}\n\t\t\tret[i]\
    \ = j;\n\t\t\tc = i;\n\t\t}\n\t}\n\tret[0] = n;\n\treturn ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: string/z_algo.cpp
  requiredBy: []
  timestamp: '2024-01-07 08:33:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/z_algo.cpp
layout: document
redirect_from:
- /library/string/z_algo.cpp
- /library/string/z_algo.cpp.html
title: Z-algorithm
---
