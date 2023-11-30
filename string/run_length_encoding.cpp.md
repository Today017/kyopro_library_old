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
  bundledCode: "#line 1 \"string/run_length_encoding.cpp\"\nvector<pair<char, int>>\
    \ run_length_encoding(string s) {\r\n\tint n = s.size();\r\n\tvector<pair<char,\
    \ int>> ret;\r\n\tfor (int l = 0, r; l < n;) {\r\n\t\tr = l + 1;\r\n\t\twhile\
    \ (r < n && s[l] == s[r]) {\r\n\t\t\tr++;\r\n\t\t}\r\n\t\tret.push_back(make_pair(s[l],\
    \ r - l));\r\n\t\tl = r;\r\n\t}\r\n\treturn ret;\r\n}\r\n"
  code: "vector<pair<char, int>> run_length_encoding(string s) {\r\n\tint n = s.size();\r\
    \n\tvector<pair<char, int>> ret;\r\n\tfor (int l = 0, r; l < n;) {\r\n\t\tr =\
    \ l + 1;\r\n\t\twhile (r < n && s[l] == s[r]) {\r\n\t\t\tr++;\r\n\t\t}\r\n\t\t\
    ret.push_back(make_pair(s[l], r - l));\r\n\t\tl = r;\r\n\t}\r\n\treturn ret;\r\
    \n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: string/run_length_encoding.cpp
  requiredBy: []
  timestamp: '2023-11-30 22:52:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/run_length_encoding.cpp
layout: document
redirect_from:
- /library/string/run_length_encoding.cpp
- /library/string/run_length_encoding.cpp.html
title: string/run_length_encoding.cpp
---
