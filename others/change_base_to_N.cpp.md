---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "N\u9032\u6570\u3078\u306E\u5909\u63DB"
    links: []
  bundledCode: "#line 1 \"others/change_base_to_N.cpp\"\n#include <string>\n#include\
    \ <algorithm>\n\n/**\n * @brief N\u9032\u6570\u3078\u306E\u5909\u63DB\n * @param\
    \ Size \u6841\u6570\n * @param base \u57FA\u6570\n * @param rev \u5909\u63DB\u5F8C\
    \u306E\u6570\u3092\u53CD\u8EE2\u3055\u305B\u3066\u5143\u306B\u623B\u3059\u304B\
    \u5426\u304B\n*/\n\ntemplate <int Size = -1>\nstd::string change_base(long long\
    \ n, int base = 2, bool rev = true) {\n    std::string ret;\n    if (n == 0) {\n\
    \        ret.push_back('0');\n    }\n    while (n > 0) {\n        ret.push_back(n\
    \ % base + '0');\n        n /= base;\n    }\n    if (Size != -1) {\n        while\
    \ (ret.size() < Size) {\n            ret.push_back('0');\n        }\n    }\n \
    \   if (rev) {\n        std::reverse(ret.begin(), ret.end());\n    }\n    return\
    \ ret;\n}\n"
  code: "#include <string>\n#include <algorithm>\n\n/**\n * @brief N\u9032\u6570\u3078\
    \u306E\u5909\u63DB\n * @param Size \u6841\u6570\n * @param base \u57FA\u6570\n\
    \ * @param rev \u5909\u63DB\u5F8C\u306E\u6570\u3092\u53CD\u8EE2\u3055\u305B\u3066\
    \u5143\u306B\u623B\u3059\u304B\u5426\u304B\n*/\n\ntemplate <int Size = -1>\nstd::string\
    \ change_base(long long n, int base = 2, bool rev = true) {\n    std::string ret;\n\
    \    if (n == 0) {\n        ret.push_back('0');\n    }\n    while (n > 0) {\n\
    \        ret.push_back(n % base + '0');\n        n /= base;\n    }\n    if (Size\
    \ != -1) {\n        while (ret.size() < Size) {\n            ret.push_back('0');\n\
    \        }\n    }\n    if (rev) {\n        std::reverse(ret.begin(), ret.end());\n\
    \    }\n    return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: others/change_base_to_N.cpp
  requiredBy: []
  timestamp: '2024-01-25 11:55:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: others/change_base_to_N.cpp
layout: document
redirect_from:
- /library/others/change_base_to_N.cpp
- /library/others/change_base_to_N.cpp.html
title: "N\u9032\u6570\u3078\u306E\u5909\u63DB"
---
