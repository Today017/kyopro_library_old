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
  bundledCode: "#line 1 \"others/util.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n// pow\nlong long pow_ll(long long n, int x) {\n    long long ret =\
    \ 1;\n    for (int i = 0; i < x; i++) {\n        ret *= n;\n    }\n    return\
    \ ret;\n}\n\n// a\u4EE5\u4E0A\u6700\u5C0F\u306Eb\u306E\u500D\u6570\nlong long\
    \ ceil_mod(long long a, long long b) {\n    long long rem = a % b;\n    if (rem\
    \ == 0) {\n        return a;\n    }\n    return a + (b - rem);\n}\n\n// \u30B0\
    \u30EA\u30C3\u30C9\u3092\u56DE\u8EE2\ntemplate <typename T>\nvector<vector<T>>\
    \ rotate_grid(vector<vector<T>> &G) {\n    int n = G.size();\n    int m = G.front().size();\n\
    \    vector<vector<T>> ret(m, vector<T>(n));\n    for (int i = 0; i < n; i++)\
    \ {\n        for (int j = 0; j < m; j++) {\n            ret[j][n - i - 1] = G[i][j];\n\
    \        }\n    }\n    return ret;\n}\n\n// \u6570\u5217\u3092\u56DE\u8EE2\ntemplate\
    \ <typename T>\nvector<T> rotate_seq(vector<T> &A, int d) {\n    int n = A.size();\n\
    \    vector<T> ret(n);\n    for (int i = 0; i < n; i++) {\n        ret[(i + d)\
    \ % n] = A[i];\n    }\n    return ret;\n}\n\n// a/b\u306E\u5207\u308A\u4E0A\u3052\
    \nlong long ceil_div(long long a, long long b) {\n    if (b <= 0) {\n        cerr\
    \ << \"b\u304C\u975E\u6B63\u6574\u6570\u3067\u3059\uFF01\uFF01\uFF01\uFF01\\n\"\
    ;\n        assert(false);\n    }\n    return (a + b - 1) / b;\n}\n\n// pow_mod\n\
    long long pow_mod(long long n, long long x, long long m) {\n    long long ret\
    \ = 1;\n    while (x > 0) {\n        if (x % 2 == 1) {\n            ret *= n;\n\
    \            ret %= m;\n        }\n        n *= n;\n        n %= m;\n        x\
    \ /= 2;\n    }\n    return ret;\n}\n\n// \u7B49\u5DEE\u6570\u5217\u306E\u548C\n\
    long long arithmetic_sum_goal(long long start, long long goal, long long n) {\n\
    \    return (start + goal) * n / 2;\n}\n\nlong long arithmetic_sum_step(long long\
    \ start, long long step, long long n) {\n    return n * (2ll * start + (n - 1)\
    \ * step) / 2;\n}\n\nlong long arithmetic_sum_range(long long start, long long\
    \ goal, long long step) {\n    if (step <= 0) {\n        cerr << \"step\u304C\u975E\
    \u6B63\u6574\u6570\u3067\u3059\uFF01\uFF01\uFF01\uFF01\\n\";\n        assert(false);\n\
    \    }\n    // [a, b)\n    long long n = abs(goal - start + step - 1) / step;\n\
    \    return n * (2ll * start + (n - 1) * step) / 2;\n}\n\nvector<vector<long long>>\
    \ cumsum2D(vector<vector<long long>> &A) {\n    int n = A.size();\n    int m =\
    \ A[0].size();\n    vector<vector<long long>> ret(n + 1, vector<long long>(m +\
    \ 1, 0));\n    for (int i = 0; i < n; i++) {\n        for (int j = 0; j < m; j++)\
    \ {\n            ret[i + 1][j + 1] = ret[i][j + 1] + ret[i + 1][j] - ret[i][j]\
    \ + A[i][j];\n        }\n    }\n    return ret;\n}\n\nlong long cumsum2D_query(int\
    \ x1, int y1, int x2, int y2, vector<vector<long long>> &S) {\n    return S[x2][y2]\
    \ - S[x1][y2] - S[x2][y1] + S[x1][y1];\n}\n\n// \u4E8C\u90E8\u30B0\u30E9\u30D5\
    \u5224\u5B9A\nbool is_bipartial_graph(vector<vector<int>> &G) {\n    int n = G.size();\n\
    \    bool ret = true;\n    vector<int> color(n, -1);\n    for (int i = 0; i <\
    \ n; i++) {\n        if (color[i] == -1) {\n            color[i] = 0;\n      \
    \      queue<int> Q;\n            Q.push(i);\n            while (!Q.empty()) {\n\
    \                int now = Q.front();\n                Q.pop();\n            \
    \    for (int nxt : G[now]) {\n                    if (color[nxt] == -1) {\n \
    \                       color[nxt] = 1 - color[now];\n                       \
    \ Q.push(nxt);\n                    } else if (color[nxt] == color[now]) {\n \
    \                       ret = false;\n                    }\n                }\n\
    \            }\n        }\n    }\n    return ret;\n}\n\n// \u9577\u3055N-2,\u5404\
    \u8981\u7D20\u304C0~N-1\u306E\u6570\u5217\u304B\u3089\u6728\u3092\u751F\u6210\u3059\
    \u308B\nvector<vector<int>> prufer_sequence(vector<int> &A) {\n    int n = A.size()\
    \ + 2;\n    vector<int> d(n, 1);\n    for (int i = 0; i < n - 2; i++) {\n    \
    \    d[A[i]]++;\n    }\n    set<int> pq;\n    for (int i = 0; i < n; i++) {\n\
    \        if (d[i] == 1) {\n            pq.insert(i);\n        }\n    }\n    vector<vector<int>>\
    \ G(n);\n    for (int i = 0; i < n - 2; i++) {\n        int v = (*pq.begin());\n\
    \        pq.erase(v);\n        G[v].push_back(A[i]);\n        G[A[i]].push_back(v);\n\
    \        d[v]--;\n        d[A[i]]--;\n        if (d[A[i]] == 1) {\n          \
    \  pq.insert(A[i]);\n        } else if (d[A[i]] == 0) {\n            pq.erase(A[i]);\n\
    \        }\n    }\n    for (int i = 0; i < n; i++) {\n        if (d[i] == 1) {\n\
    \            for (int j = i + 1; j < n; j++) {\n                if (d[j] == 1)\
    \ {\n                    G[i].push_back(j);\n                    G[j].push_back(i);\n\
    \                    break;\n                }\n            }\n            break;\n\
    \        }\n    }\n    return G;\n}\n\nlong long my_sqrt(long long x) {\n    long\
    \ long ret = sqrt(x);\n    while (ret * ret > x) {\n        ret--;\n    }\n  \
    \  while ((ret + 1) * (ret + 1) <= x) {\n        ret++;\n    }\n    return ret;\n\
    }\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n// pow\nlong long pow_ll(long\
    \ long n, int x) {\n    long long ret = 1;\n    for (int i = 0; i < x; i++) {\n\
    \        ret *= n;\n    }\n    return ret;\n}\n\n// a\u4EE5\u4E0A\u6700\u5C0F\u306E\
    b\u306E\u500D\u6570\nlong long ceil_mod(long long a, long long b) {\n    long\
    \ long rem = a % b;\n    if (rem == 0) {\n        return a;\n    }\n    return\
    \ a + (b - rem);\n}\n\n// \u30B0\u30EA\u30C3\u30C9\u3092\u56DE\u8EE2\ntemplate\
    \ <typename T>\nvector<vector<T>> rotate_grid(vector<vector<T>> &G) {\n    int\
    \ n = G.size();\n    int m = G.front().size();\n    vector<vector<T>> ret(m, vector<T>(n));\n\
    \    for (int i = 0; i < n; i++) {\n        for (int j = 0; j < m; j++) {\n  \
    \          ret[j][n - i - 1] = G[i][j];\n        }\n    }\n    return ret;\n}\n\
    \n// \u6570\u5217\u3092\u56DE\u8EE2\ntemplate <typename T>\nvector<T> rotate_seq(vector<T>\
    \ &A, int d) {\n    int n = A.size();\n    vector<T> ret(n);\n    for (int i =\
    \ 0; i < n; i++) {\n        ret[(i + d) % n] = A[i];\n    }\n    return ret;\n\
    }\n\n// a/b\u306E\u5207\u308A\u4E0A\u3052\nlong long ceil_div(long long a, long\
    \ long b) {\n    if (b <= 0) {\n        cerr << \"b\u304C\u975E\u6B63\u6574\u6570\
    \u3067\u3059\uFF01\uFF01\uFF01\uFF01\\n\";\n        assert(false);\n    }\n  \
    \  return (a + b - 1) / b;\n}\n\n// pow_mod\nlong long pow_mod(long long n, long\
    \ long x, long long m) {\n    long long ret = 1;\n    while (x > 0) {\n      \
    \  if (x % 2 == 1) {\n            ret *= n;\n            ret %= m;\n        }\n\
    \        n *= n;\n        n %= m;\n        x /= 2;\n    }\n    return ret;\n}\n\
    \n// \u7B49\u5DEE\u6570\u5217\u306E\u548C\nlong long arithmetic_sum_goal(long\
    \ long start, long long goal, long long n) {\n    return (start + goal) * n /\
    \ 2;\n}\n\nlong long arithmetic_sum_step(long long start, long long step, long\
    \ long n) {\n    return n * (2ll * start + (n - 1) * step) / 2;\n}\n\nlong long\
    \ arithmetic_sum_range(long long start, long long goal, long long step) {\n  \
    \  if (step <= 0) {\n        cerr << \"step\u304C\u975E\u6B63\u6574\u6570\u3067\
    \u3059\uFF01\uFF01\uFF01\uFF01\\n\";\n        assert(false);\n    }\n    // [a,\
    \ b)\n    long long n = abs(goal - start + step - 1) / step;\n    return n * (2ll\
    \ * start + (n - 1) * step) / 2;\n}\n\nvector<vector<long long>> cumsum2D(vector<vector<long\
    \ long>> &A) {\n    int n = A.size();\n    int m = A[0].size();\n    vector<vector<long\
    \ long>> ret(n + 1, vector<long long>(m + 1, 0));\n    for (int i = 0; i < n;\
    \ i++) {\n        for (int j = 0; j < m; j++) {\n            ret[i + 1][j + 1]\
    \ = ret[i][j + 1] + ret[i + 1][j] - ret[i][j] + A[i][j];\n        }\n    }\n \
    \   return ret;\n}\n\nlong long cumsum2D_query(int x1, int y1, int x2, int y2,\
    \ vector<vector<long long>> &S) {\n    return S[x2][y2] - S[x1][y2] - S[x2][y1]\
    \ + S[x1][y1];\n}\n\n// \u4E8C\u90E8\u30B0\u30E9\u30D5\u5224\u5B9A\nbool is_bipartial_graph(vector<vector<int>>\
    \ &G) {\n    int n = G.size();\n    bool ret = true;\n    vector<int> color(n,\
    \ -1);\n    for (int i = 0; i < n; i++) {\n        if (color[i] == -1) {\n   \
    \         color[i] = 0;\n            queue<int> Q;\n            Q.push(i);\n \
    \           while (!Q.empty()) {\n                int now = Q.front();\n     \
    \           Q.pop();\n                for (int nxt : G[now]) {\n             \
    \       if (color[nxt] == -1) {\n                        color[nxt] = 1 - color[now];\n\
    \                        Q.push(nxt);\n                    } else if (color[nxt]\
    \ == color[now]) {\n                        ret = false;\n                   \
    \ }\n                }\n            }\n        }\n    }\n    return ret;\n}\n\n\
    // \u9577\u3055N-2,\u5404\u8981\u7D20\u304C0~N-1\u306E\u6570\u5217\u304B\u3089\
    \u6728\u3092\u751F\u6210\u3059\u308B\nvector<vector<int>> prufer_sequence(vector<int>\
    \ &A) {\n    int n = A.size() + 2;\n    vector<int> d(n, 1);\n    for (int i =\
    \ 0; i < n - 2; i++) {\n        d[A[i]]++;\n    }\n    set<int> pq;\n    for (int\
    \ i = 0; i < n; i++) {\n        if (d[i] == 1) {\n            pq.insert(i);\n\
    \        }\n    }\n    vector<vector<int>> G(n);\n    for (int i = 0; i < n -\
    \ 2; i++) {\n        int v = (*pq.begin());\n        pq.erase(v);\n        G[v].push_back(A[i]);\n\
    \        G[A[i]].push_back(v);\n        d[v]--;\n        d[A[i]]--;\n        if\
    \ (d[A[i]] == 1) {\n            pq.insert(A[i]);\n        } else if (d[A[i]] ==\
    \ 0) {\n            pq.erase(A[i]);\n        }\n    }\n    for (int i = 0; i <\
    \ n; i++) {\n        if (d[i] == 1) {\n            for (int j = i + 1; j < n;\
    \ j++) {\n                if (d[j] == 1) {\n                    G[i].push_back(j);\n\
    \                    G[j].push_back(i);\n                    break;\n        \
    \        }\n            }\n            break;\n        }\n    }\n    return G;\n\
    }\n\nlong long my_sqrt(long long x) {\n    long long ret = sqrt(x);\n    while\
    \ (ret * ret > x) {\n        ret--;\n    }\n    while ((ret + 1) * (ret + 1) <=\
    \ x) {\n        ret++;\n    }\n    return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: others/util.cpp
  requiredBy: []
  timestamp: '2024-01-25 11:55:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: others/util.cpp
layout: document
redirect_from:
- /library/others/util.cpp
- /library/others/util.cpp.html
title: others/util.cpp
---
