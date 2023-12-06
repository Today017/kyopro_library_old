---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Manacher
    links: []
  bundledCode: "#line 1 \"string/manacher.cpp\"\n#include <vector>\n#include <string>\n\
    \n/**\n * @brief Manacher\n */\n\nstd::vector<int> manacher(std::string s) {\n\
    \tint n = s.size();\n\tint c = 0;\n\tstd::vector<int> ret(n, 1);\n\tfor (int i\
    \ = 0; i < n; i++) {\n\t\tint l = 2 * c - i;\n\t\tif (i + ret[l] < c + ret[c])\
    \ {\n\t\t\tret[i] = ret[l];\n\t\t} else {\n\t\t\tint j = c + ret[c] - i;\n\t\t\
    \twhile (i - j >= 0 && i + j < n && s[i - j] == s[i + j]) {\n\t\t\t\tj++;\n\t\t\
    \t}\n\t\t\tret[i] = j;\n\t\t\tc = i;\n\t\t}\n\t}\n\treturn ret;\n}\n"
  code: "#include <vector>\n#include <string>\n\n/**\n * @brief Manacher\n */\n\n\
    std::vector<int> manacher(std::string s) {\n\tint n = s.size();\n\tint c = 0;\n\
    \tstd::vector<int> ret(n, 1);\n\tfor (int i = 0; i < n; i++) {\n\t\tint l = 2\
    \ * c - i;\n\t\tif (i + ret[l] < c + ret[c]) {\n\t\t\tret[i] = ret[l];\n\t\t}\
    \ else {\n\t\t\tint j = c + ret[c] - i;\n\t\t\twhile (i - j >= 0 && i + j < n\
    \ && s[i - j] == s[i + j]) {\n\t\t\t\tj++;\n\t\t\t}\n\t\t\tret[i] = j;\n\t\t\t\
    c = i;\n\t\t}\n\t}\n\treturn ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: string/manacher.cpp
  requiredBy: []
  timestamp: '2023-12-06 10:41:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/manacher.cpp
layout: document
redirect_from:
- /library/string/manacher.cpp
- /library/string/manacher.cpp.html
title: Manacher
---
