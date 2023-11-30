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
    \ std;\n\n// pow\nlong long pow_ll(long long n, int x) {\n\tlong long ret = 1;\n\
    \tfor (int i = 0; i < x; i++) {\n\t\tret *= n;\n\t}\n\treturn ret;\n}\n\n// a\u4EE5\
    \u4E0A\u6700\u5C0F\u306Eb\u306E\u500D\u6570\nlong long ceil_mod(long long a, long\
    \ long b) {\n\tlong long rem = a % b;\n\tif (rem == 0) {\n\t\treturn a;\n\t}\n\
    \treturn a + (b - rem);\n}\n\n// \u30B0\u30EA\u30C3\u30C9\u3092\u56DE\u8EE2\n\
    template <typename T>\nvector<vector<T>> rotate_grid(vector<vector<T>> &G) {\n\
    \tint n = G.size();\n\tint m = G.front().size();\n\tvector<vector<T>> ret(m, vector<T>(n));\n\
    \tfor (int i = 0; i < n; i++) {\n\t\tfor (int j = 0; j < m; j++) {\n\t\t\tret[j][n\
    \ - i - 1] = G[i][j];\n\t\t}\n\t}\n\treturn ret;\n}\n\n// \u6570\u5217\u3092\u56DE\
    \u8EE2\ntemplate <typename T>\nvector<T> rotate_seq(vector<T> &A, int d) {\n\t\
    int n = A.size();\n\tvector<T> ret(n);\n\tfor (int i = 0; i < n; i++) {\n\t\t\
    ret[(i + d) % n] = A[i];\n\t}\n\treturn ret;\n}\n\n// a/b\u306E\u5207\u308A\u4E0A\
    \u3052\nlong long ceil_div(long long a, long long b) {\n\tif (b <= 0) {\n\t\t\
    cerr << \"b\u304C\u975E\u6B63\u6574\u6570\u3067\u3059\uFF01\uFF01\uFF01\uFF01\\\
    n\";\n\t\tassert(false);\n\t}\n\treturn (a + b - 1) / b;\n}\n\n// pow_mod\nlong\
    \ long pow_mod(long long n, long long x, long long m) {\n\tlong long ret = 1;\n\
    \twhile (x > 0) {\n\t\tif (x % 2 == 1) {\n\t\t\tret *= n;\n\t\t\tret %= m;\n\t\
    \t}\n\t\tn *= n;\n\t\tn %= m;\n\t\tx /= 2;\n\t}\n\treturn ret;\n}\n\n// \u7B49\
    \u5DEE\u6570\u5217\u306E\u548C\nlong long arithmetic_sum_goal(long long start,\
    \ long long goal, long long n) {\n\treturn (start + goal) * n / 2;\n}\n\nlong\
    \ long arithmetic_sum_step(long long start, long long step, long long n) {\n\t\
    return n * (2ll * start + (n - 1) * step) / 2;\n}\n\nlong long arithmetic_sum_range(long\
    \ long start, long long goal, long long step) {\n\tif (step <= 0) {\n\t\tcerr\
    \ << \"step\u304C\u975E\u6B63\u6574\u6570\u3067\u3059\uFF01\uFF01\uFF01\uFF01\\\
    n\";\n\t\tassert(false);\n\t}\n\t// [a, b)\n\tlong long n = abs(goal - start +\
    \ step - 1) / step;\n\treturn n * (2ll * start + (n - 1) * step) / 2;\n}\n\nvector<vector<long\
    \ long>> cumsum2D(vector<vector<long long>> &A) {\n\tint n = A.size();\n\tint\
    \ m = A[0].size();\n\tvector<vector<long long>> ret(n + 1, vector<long long>(m\
    \ + 1, 0));\n\tfor (int i = 0; i < n; i++) {\n\t\tfor (int j = 0; j < m; j++)\
    \ {\n\t\t\tret[i + 1][j + 1] = ret[i][j + 1] + ret[i + 1][j] - ret[i][j] + A[i][j];\n\
    \t\t}\n\t}\n\treturn ret;\n}\n\nlong long cumsum2D_query(int x1, int y1, int x2,\
    \ int y2, vector<vector<long long>> &S) {\n\treturn S[x2][y2] - S[x1][y2] - S[x2][y1]\
    \ + S[x1][y1];\n}\n\n// \u4E8C\u90E8\u30B0\u30E9\u30D5\u5224\u5B9A\nbool is_bipartial_graph(vector<vector<int>>\
    \ &G) {\n\tint n = G.size();\n\tbool ret = true;\n\tvector<int> color(n, -1);\n\
    \tfor (int i = 0; i < n; i++) {\n\t\tif (color[i] == -1) {\n\t\t\tcolor[i] = 0;\n\
    \t\t\tqueue<int> Q;\n\t\t\tQ.push(i);\n\t\t\twhile (!Q.empty()) {\n\t\t\t\tint\
    \ now = Q.front();\n\t\t\t\tQ.pop();\n\t\t\t\tfor (int nxt : G[now]) {\n\t\t\t\
    \t\tif (color[nxt] == -1) {\n\t\t\t\t\t\tcolor[nxt] = 1 - color[now];\n\t\t\t\t\
    \t\tQ.push(nxt);\n\t\t\t\t\t} else if (color[nxt] == color[now]) {\n\t\t\t\t\t\
    \tret = false;\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\treturn ret;\n}\n\
    \n// \u9577\u3055N-2,\u5404\u8981\u7D20\u304C0~N-1\u306E\u6570\u5217\u304B\u3089\
    \u6728\u3092\u751F\u6210\u3059\u308B\nvector<vector<int>> prufer_sequence(vector<int>\
    \ &A) {\n\tint n = A.size() + 2;\n\tvector<int> d(n, 1);\n\tfor (int i = 0; i\
    \ < n - 2; i++) {\n\t\td[A[i]]++;\n\t}\n\tset<int> pq;\n\tfor (int i = 0; i <\
    \ n; i++) {\n\t\tif (d[i] == 1) {\n\t\t\tpq.insert(i);\n\t\t}\n\t}\n\tvector<vector<int>>\
    \ G(n);\n\tfor (int i = 0; i < n - 2; i++) {\n\t\tint v = (*pq.begin());\n\t\t\
    pq.erase(v);\n\t\tG[v].push_back(A[i]);\n\t\tG[A[i]].push_back(v);\n\t\td[v]--;\n\
    \t\td[A[i]]--;\n\t\tif (d[A[i]] == 1) {\n\t\t\tpq.insert(A[i]);\n\t\t} else if\
    \ (d[A[i]] == 0) {\n\t\t\tpq.erase(A[i]);\n\t\t}\n\t}\n\tfor (int i = 0; i < n;\
    \ i++) {\n\t\tif (d[i] == 1) {\n\t\t\tfor (int j = i + 1; j < n; j++) {\n\t\t\t\
    \tif (d[j] == 1) {\n\t\t\t\t\tG[i].push_back(j);\n\t\t\t\t\tG[j].push_back(i);\n\
    \t\t\t\t\tbreak;\n\t\t\t\t}\n\t\t\t}\n\t\t\tbreak;\n\t\t}\n\t}\n\treturn G;\n\
    }\n\n\nlong long my_sqrt(long long x){\n\tlong long ret=sqrt(x);\n\twhile(ret*ret>x){\n\
    \t\tret--;\n\t}\n\twhile((ret+1)*(ret+1)<=x){\n\t\tret++;\n\t}\n\treturn ret;\n\
    }\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n// pow\nlong long pow_ll(long\
    \ long n, int x) {\n\tlong long ret = 1;\n\tfor (int i = 0; i < x; i++) {\n\t\t\
    ret *= n;\n\t}\n\treturn ret;\n}\n\n// a\u4EE5\u4E0A\u6700\u5C0F\u306Eb\u306E\u500D\
    \u6570\nlong long ceil_mod(long long a, long long b) {\n\tlong long rem = a %\
    \ b;\n\tif (rem == 0) {\n\t\treturn a;\n\t}\n\treturn a + (b - rem);\n}\n\n//\
    \ \u30B0\u30EA\u30C3\u30C9\u3092\u56DE\u8EE2\ntemplate <typename T>\nvector<vector<T>>\
    \ rotate_grid(vector<vector<T>> &G) {\n\tint n = G.size();\n\tint m = G.front().size();\n\
    \tvector<vector<T>> ret(m, vector<T>(n));\n\tfor (int i = 0; i < n; i++) {\n\t\
    \tfor (int j = 0; j < m; j++) {\n\t\t\tret[j][n - i - 1] = G[i][j];\n\t\t}\n\t\
    }\n\treturn ret;\n}\n\n// \u6570\u5217\u3092\u56DE\u8EE2\ntemplate <typename T>\n\
    vector<T> rotate_seq(vector<T> &A, int d) {\n\tint n = A.size();\n\tvector<T>\
    \ ret(n);\n\tfor (int i = 0; i < n; i++) {\n\t\tret[(i + d) % n] = A[i];\n\t}\n\
    \treturn ret;\n}\n\n// a/b\u306E\u5207\u308A\u4E0A\u3052\nlong long ceil_div(long\
    \ long a, long long b) {\n\tif (b <= 0) {\n\t\tcerr << \"b\u304C\u975E\u6B63\u6574\
    \u6570\u3067\u3059\uFF01\uFF01\uFF01\uFF01\\n\";\n\t\tassert(false);\n\t}\n\t\
    return (a + b - 1) / b;\n}\n\n// pow_mod\nlong long pow_mod(long long n, long\
    \ long x, long long m) {\n\tlong long ret = 1;\n\twhile (x > 0) {\n\t\tif (x %\
    \ 2 == 1) {\n\t\t\tret *= n;\n\t\t\tret %= m;\n\t\t}\n\t\tn *= n;\n\t\tn %= m;\n\
    \t\tx /= 2;\n\t}\n\treturn ret;\n}\n\n// \u7B49\u5DEE\u6570\u5217\u306E\u548C\n\
    long long arithmetic_sum_goal(long long start, long long goal, long long n) {\n\
    \treturn (start + goal) * n / 2;\n}\n\nlong long arithmetic_sum_step(long long\
    \ start, long long step, long long n) {\n\treturn n * (2ll * start + (n - 1) *\
    \ step) / 2;\n}\n\nlong long arithmetic_sum_range(long long start, long long goal,\
    \ long long step) {\n\tif (step <= 0) {\n\t\tcerr << \"step\u304C\u975E\u6B63\u6574\
    \u6570\u3067\u3059\uFF01\uFF01\uFF01\uFF01\\n\";\n\t\tassert(false);\n\t}\n\t\
    // [a, b)\n\tlong long n = abs(goal - start + step - 1) / step;\n\treturn n *\
    \ (2ll * start + (n - 1) * step) / 2;\n}\n\nvector<vector<long long>> cumsum2D(vector<vector<long\
    \ long>> &A) {\n\tint n = A.size();\n\tint m = A[0].size();\n\tvector<vector<long\
    \ long>> ret(n + 1, vector<long long>(m + 1, 0));\n\tfor (int i = 0; i < n; i++)\
    \ {\n\t\tfor (int j = 0; j < m; j++) {\n\t\t\tret[i + 1][j + 1] = ret[i][j + 1]\
    \ + ret[i + 1][j] - ret[i][j] + A[i][j];\n\t\t}\n\t}\n\treturn ret;\n}\n\nlong\
    \ long cumsum2D_query(int x1, int y1, int x2, int y2, vector<vector<long long>>\
    \ &S) {\n\treturn S[x2][y2] - S[x1][y2] - S[x2][y1] + S[x1][y1];\n}\n\n// \u4E8C\
    \u90E8\u30B0\u30E9\u30D5\u5224\u5B9A\nbool is_bipartial_graph(vector<vector<int>>\
    \ &G) {\n\tint n = G.size();\n\tbool ret = true;\n\tvector<int> color(n, -1);\n\
    \tfor (int i = 0; i < n; i++) {\n\t\tif (color[i] == -1) {\n\t\t\tcolor[i] = 0;\n\
    \t\t\tqueue<int> Q;\n\t\t\tQ.push(i);\n\t\t\twhile (!Q.empty()) {\n\t\t\t\tint\
    \ now = Q.front();\n\t\t\t\tQ.pop();\n\t\t\t\tfor (int nxt : G[now]) {\n\t\t\t\
    \t\tif (color[nxt] == -1) {\n\t\t\t\t\t\tcolor[nxt] = 1 - color[now];\n\t\t\t\t\
    \t\tQ.push(nxt);\n\t\t\t\t\t} else if (color[nxt] == color[now]) {\n\t\t\t\t\t\
    \tret = false;\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\treturn ret;\n}\n\
    \n// \u9577\u3055N-2,\u5404\u8981\u7D20\u304C0~N-1\u306E\u6570\u5217\u304B\u3089\
    \u6728\u3092\u751F\u6210\u3059\u308B\nvector<vector<int>> prufer_sequence(vector<int>\
    \ &A) {\n\tint n = A.size() + 2;\n\tvector<int> d(n, 1);\n\tfor (int i = 0; i\
    \ < n - 2; i++) {\n\t\td[A[i]]++;\n\t}\n\tset<int> pq;\n\tfor (int i = 0; i <\
    \ n; i++) {\n\t\tif (d[i] == 1) {\n\t\t\tpq.insert(i);\n\t\t}\n\t}\n\tvector<vector<int>>\
    \ G(n);\n\tfor (int i = 0; i < n - 2; i++) {\n\t\tint v = (*pq.begin());\n\t\t\
    pq.erase(v);\n\t\tG[v].push_back(A[i]);\n\t\tG[A[i]].push_back(v);\n\t\td[v]--;\n\
    \t\td[A[i]]--;\n\t\tif (d[A[i]] == 1) {\n\t\t\tpq.insert(A[i]);\n\t\t} else if\
    \ (d[A[i]] == 0) {\n\t\t\tpq.erase(A[i]);\n\t\t}\n\t}\n\tfor (int i = 0; i < n;\
    \ i++) {\n\t\tif (d[i] == 1) {\n\t\t\tfor (int j = i + 1; j < n; j++) {\n\t\t\t\
    \tif (d[j] == 1) {\n\t\t\t\t\tG[i].push_back(j);\n\t\t\t\t\tG[j].push_back(i);\n\
    \t\t\t\t\tbreak;\n\t\t\t\t}\n\t\t\t}\n\t\t\tbreak;\n\t\t}\n\t}\n\treturn G;\n\
    }\n\n\nlong long my_sqrt(long long x){\n\tlong long ret=sqrt(x);\n\twhile(ret*ret>x){\n\
    \t\tret--;\n\t}\n\twhile((ret+1)*(ret+1)<=x){\n\t\tret++;\n\t}\n\treturn ret;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: others/util.cpp
  requiredBy: []
  timestamp: '2023-11-30 18:16:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: others/util.cpp
layout: document
redirect_from:
- /library/others/util.cpp
- /library/others/util.cpp.html
title: others/util.cpp
---
