---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u6728\u306E\u76F4\u5F84"
    links: []
  bundledCode: "#line 1 \"graph/tree_diameter.cpp\"\n#include <vector>\n#include <algorithm>\n\
    \n/**\n * @brief \u6728\u306E\u76F4\u5F84\n */\n\nstd::vector<int> tree_diameter(std::vector<std::vector<int>>&\
    \ G) {\n    int n = G.size();\n    const int INF = 1001001001;\n    std::vector<int>\
    \ dst(n, INF);\n    dst[0] = 0;\n    auto F1 = [&](auto&& F1, int now, int pre)\
    \ -> void {\n        for (int nxt : G[now]) {\n            if (nxt != pre) {\n\
    \                dst[nxt] = dst[now] + 1;\n                F1(F1, nxt, now);\n\
    \            }\n        }\n    };\n    F1(F1, 0, -1);\n    int l = std::max_element(dst.begin(),\
    \ dst.end()) - dst.begin();\n    dst = std::vector<int>(n, INF);\n    dst[l] =\
    \ 0;\n    F1(F1, l, -1);\n    int r = max_element(dst.begin(), dst.end()) - dst.begin();\n\
    \    std::vector<int> path;\n    auto F2 = [&](auto&& F2, int now, int pre) ->\
    \ bool {\n        if (now == l) {\n            path.push_back(now);\n        \
    \    return true;\n        }\n        bool ret = false;\n        for (int nxt\
    \ : G[now]) {\n            if (nxt != pre) {\n                if (F2(F2, nxt,\
    \ now)) {\n                    ret = true;\n                }\n            }\n\
    \        }\n        if (ret) {\n            path.push_back(now);\n        }\n\
    \        return ret;\n    };\n    F2(F2, r, -1);\n    return path;\n}\n"
  code: "#include <vector>\n#include <algorithm>\n\n/**\n * @brief \u6728\u306E\u76F4\
    \u5F84\n */\n\nstd::vector<int> tree_diameter(std::vector<std::vector<int>>& G)\
    \ {\n    int n = G.size();\n    const int INF = 1001001001;\n    std::vector<int>\
    \ dst(n, INF);\n    dst[0] = 0;\n    auto F1 = [&](auto&& F1, int now, int pre)\
    \ -> void {\n        for (int nxt : G[now]) {\n            if (nxt != pre) {\n\
    \                dst[nxt] = dst[now] + 1;\n                F1(F1, nxt, now);\n\
    \            }\n        }\n    };\n    F1(F1, 0, -1);\n    int l = std::max_element(dst.begin(),\
    \ dst.end()) - dst.begin();\n    dst = std::vector<int>(n, INF);\n    dst[l] =\
    \ 0;\n    F1(F1, l, -1);\n    int r = max_element(dst.begin(), dst.end()) - dst.begin();\n\
    \    std::vector<int> path;\n    auto F2 = [&](auto&& F2, int now, int pre) ->\
    \ bool {\n        if (now == l) {\n            path.push_back(now);\n        \
    \    return true;\n        }\n        bool ret = false;\n        for (int nxt\
    \ : G[now]) {\n            if (nxt != pre) {\n                if (F2(F2, nxt,\
    \ now)) {\n                    ret = true;\n                }\n            }\n\
    \        }\n        if (ret) {\n            path.push_back(now);\n        }\n\
    \        return ret;\n    };\n    F2(F2, r, -1);\n    return path;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/tree_diameter.cpp
  requiredBy: []
  timestamp: '2024-01-25 11:55:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/tree_diameter.cpp
layout: document
redirect_from:
- /library/graph/tree_diameter.cpp
- /library/graph/tree_diameter.cpp.html
title: "\u6728\u306E\u76F4\u5F84"
---
