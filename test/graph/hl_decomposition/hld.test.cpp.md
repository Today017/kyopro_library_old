---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/fenwick_tree.cpp
    title: Fenwick Tree
  - icon: ':heavy_check_mark:'
    path: graph/hld.cpp
    title: Heavy-Light Decomposition
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_path_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_path_sum
  bundledCode: "#line 1 \"test/graph/hl_decomposition/hld.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 1 \"graph/hld.cpp\"\n/**\r\n * @brief Heavy-Light\
    \ Decomposition\r\n * @docs docs/graph/hld.md\r\n*/\r\n\r\nstruct heavy_light_decomposition\
    \ {\r\n\tvector<vector<int>> G;\r\n\tvector<int> sz, parent, depth, hld, pos,\
    \ head;\r\n\theavy_light_decomposition(int n) {\r\n\t\tG.resize(n);\r\n\t\tsz.resize(n);\r\
    \n\t\tparent.resize(n);\r\n\t\tdepth.resize(n);\r\n\t\tpos.resize(n);\r\n\t\t\
    head.resize(n);\r\n\t}\r\n\tvoid add_edge(int a, int b) {\r\n\t\tG[a].push_back(b);\r\
    \n\t\tG[b].push_back(a);\r\n\t}\r\n\theavy_light_decomposition(const vector<vector<int>>&\
    \ G) {\r\n\t\tint n = G.size();\r\n\t\tthis->G = G;\r\n\t\tsz.resize(n);\r\n\t\
    \tparent.resize(n);\r\n\t\tdepth.resize(n);\r\n\t\tpos.resize(n);\r\n\t\thead.resize(n);\r\
    \n\t}\r\n\tvector<int> hld_start(int root = 0) {\r\n\t\tdfs1(root);\r\n\t\tdfs2(root);\r\
    \n\t\tdfs(root, root);\r\n\t\treturn hld;\r\n\t}\r\n\tvoid dfs(int now, int a,\
    \ int pre = -1) {\r\n\t\tpos[now] = hld.size();\r\n\t\thld.push_back(now);\r\n\
    \t\thead[now] = a;\r\n\t\tif (sz[now] == 1) {\r\n\t\t\treturn;\r\n\t\t}\r\n\t\t\
    int mx = 0;\r\n\t\tint mx_idx = 0;\r\n\t\tfor (int nxt : G[now]) {\r\n\t\t\tif\
    \ (nxt == pre) {\r\n\t\t\t\tcontinue;\r\n\t\t\t}\r\n\t\t\tif (mx < sz[nxt]) {\r\
    \n\t\t\t\tmx = sz[nxt];\r\n\t\t\t\tmx_idx = nxt;\r\n\t\t\t}\r\n\t\t}\r\n\t\tdfs(mx_idx,\
    \ a, now);\r\n\t\tfor (int nxt : G[now]) {\r\n\t\t\tif (nxt == pre) {\r\n\t\t\t\
    \tcontinue;\r\n\t\t\t}\r\n\t\t\tif (nxt == mx_idx) {\r\n\t\t\t\tcontinue;\r\n\t\
    \t\t}\r\n\t\t\tdfs(nxt, nxt, now);\r\n\t\t}\r\n\t}\r\n\tvoid dfs1(int now, int\
    \ pre = -1) {\r\n\t\tint res = 1;\r\n\t\tfor (int nxt : G[now]) {\r\n\t\t\tif\
    \ (nxt == pre) {\r\n\t\t\t\tcontinue;\r\n\t\t\t}\r\n\t\t\tdfs1(nxt, now);\r\n\t\
    \t\tres += sz[nxt];\r\n\t\t}\r\n\t\tsz[now] = res;\r\n\t}\r\n\tvoid dfs2(int now,\
    \ int pre = -1) {\r\n\t\tparent[now] = pre;\r\n\t\tfor (int nxt : G[now]) {\r\n\
    \t\t\tif (nxt == pre) {\r\n\t\t\t\tcontinue;\r\n\t\t\t}\r\n\t\t\tdepth[nxt] =\
    \ depth[now] + 1;\r\n\t\t\tdfs2(nxt, now);\r\n\t\t}\r\n\t}\r\n\tint lca(int u,\
    \ int v) {\r\n\t\twhile (head[u] != head[v]) {\r\n\t\t\tif (depth[head[u]] > depth[head[v]])\
    \ {\r\n\t\t\t\tu = parent[head[u]];\r\n\t\t\t} else {\r\n\t\t\t\tv = parent[head[v]];\r\
    \n\t\t\t}\r\n\t\t}\r\n\t\treturn depth[u] < depth[v] ? u : v;\r\n\t}\r\n\ttemplate\
    \ <typename U>\r\n\tvoid update(int x, U& Update) {\r\n\t\tUpdate(x, pos[x]);\r\
    \n\t}\r\n\ttemplate <typename Q, typename F, typename T>\r\n\tT query(int u, int\
    \ v, Q& Query, F& f, T e) {\r\n\t\tT ret = e;\r\n\t\twhile (head[u] != head[v])\
    \ {\r\n\t\t\tif (depth[head[u]] < depth[head[v]]) {\r\n\t\t\t\tswap(u, v);\r\n\
    \t\t\t}\r\n\t\t\tret = f(ret, Query(pos[head[u]], pos[u] + 1));\r\n\t\t\tu = parent[head[u]];\r\
    \n\t\t}\r\n\t\tif (depth[u] > depth[v]) {\r\n\t\t\tswap(u, v);\r\n\t\t}\r\n\t\t\
    ret = f(ret, Query(pos[u], pos[v] + 1));\r\n\t\treturn ret;\r\n\t}\r\n};\r\n#line\
    \ 1 \"data_structure/fenwick_tree.cpp\"\n/**\r\n * @brief Fenwick Tree\r\n * @docs\
    \ docs/data_structure/fenwick_tree.md\r\n*/\r\n\r\ntemplate <typename T>\r\nstruct\
    \ fenwick_tree {\r\n\tint n;\r\n\tvector<T> dat;\r\n\tfenwick_tree(int n) {\r\n\
    \t\tthis->n = n;\r\n\t\tdat.resize(n);\r\n\t}\r\n\tvoid add(int i, T x) {\r\n\t\
    \ti++;\r\n\t\twhile (i <= n) {\r\n\t\t\tdat[i - 1] += x;\r\n\t\t\ti += i & -i;\r\
    \n\t\t}\r\n\t}\r\n\tT sum(int l, int r) {\r\n\t\treturn sum(r) - sum(l);\r\n\t\
    }\r\n\tT sum(int r) {\r\n\t\tT ret = 0;\r\n\t\twhile (r > 0) {\r\n\t\t\tret +=\
    \ dat[r - 1];\r\n\t\t\tr -= r & -r;\r\n\t\t}\r\n\t\treturn ret;\r\n\t}\r\n\tT\
    \ operator[](int i) {\r\n\t\treturn sum(i, i + 1);\r\n\t}\r\n};\n#line 7 \"test/graph/hl_decomposition/hld.test.cpp\"\
    \n\nint main() {\n\tint N, Q;\n\tcin >> N >> Q;\n\n\tfenwick_tree<long long> ft(N);\n\
    \theavy_light_decomposition hld(N);\n\n\tvector<int> A(N);\n\tfor (int i = 0;\
    \ i < N; i++) {\n\t\tcin >> A[i];\n\t}\n\tfor (int i = 0; i < N - 1; i++) {\n\t\
    \tint u, v;\n\t\tcin >> u >> v;\n\t\thld.add_edge(u, v);\n\t}\n\n\thld.hld_start();\n\
    \tfor (int i = 0; i < N; i++) {\n\t\tauto Update = [&](int i, int pos) {\n\t\t\
    \tft.add(pos, A[i]);\n\t\t};\n\t\thld.update(i, Update);\n\t}\n\n\twhile (Q--)\
    \ {\n\t\tint t;\n\t\tcin >> t;\n\n\t\tif (t == 0) {\n\t\t\tint p, x;\n\t\t\tcin\
    \ >> p >> x;\n\n\t\t\tauto Update = [&](int i, int pos) {\n\t\t\t\tft.add(pos,\
    \ x);\n\t\t\t};\n\n\t\t\thld.update(p, Update);\n\t\t}\n\n\t\telse {\n\t\t\tint\
    \ u, v;\n\t\t\tcin >> u >> v;\n\n\t\t\tauto Query = [&](int x, int y) {\n\t\t\t\
    \treturn ft.sum(x, y);\n\t\t\t};\n\t\t\tauto F = [&](long long a, long long b)\
    \ {\n\t\t\t\treturn a + b;\n\t\t\t};\n\t\t\tlong long e = 0;\n\n\t\t\tcout <<\
    \ hld.query(u, v, Query, F, e) << '\\n';\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../graph/hld.cpp\"\
    \n#include \"../../../data_structure/fenwick_tree.cpp\"\n\nint main() {\n\tint\
    \ N, Q;\n\tcin >> N >> Q;\n\n\tfenwick_tree<long long> ft(N);\n\theavy_light_decomposition\
    \ hld(N);\n\n\tvector<int> A(N);\n\tfor (int i = 0; i < N; i++) {\n\t\tcin >>\
    \ A[i];\n\t}\n\tfor (int i = 0; i < N - 1; i++) {\n\t\tint u, v;\n\t\tcin >> u\
    \ >> v;\n\t\thld.add_edge(u, v);\n\t}\n\n\thld.hld_start();\n\tfor (int i = 0;\
    \ i < N; i++) {\n\t\tauto Update = [&](int i, int pos) {\n\t\t\tft.add(pos, A[i]);\n\
    \t\t};\n\t\thld.update(i, Update);\n\t}\n\n\twhile (Q--) {\n\t\tint t;\n\t\tcin\
    \ >> t;\n\n\t\tif (t == 0) {\n\t\t\tint p, x;\n\t\t\tcin >> p >> x;\n\n\t\t\t\
    auto Update = [&](int i, int pos) {\n\t\t\t\tft.add(pos, x);\n\t\t\t};\n\n\t\t\
    \thld.update(p, Update);\n\t\t}\n\n\t\telse {\n\t\t\tint u, v;\n\t\t\tcin >> u\
    \ >> v;\n\n\t\t\tauto Query = [&](int x, int y) {\n\t\t\t\treturn ft.sum(x, y);\n\
    \t\t\t};\n\t\t\tauto F = [&](long long a, long long b) {\n\t\t\t\treturn a + b;\n\
    \t\t\t};\n\t\t\tlong long e = 0;\n\n\t\t\tcout << hld.query(u, v, Query, F, e)\
    \ << '\\n';\n\t\t}\n\t}\n}\n"
  dependsOn:
  - graph/hld.cpp
  - data_structure/fenwick_tree.cpp
  isVerificationFile: true
  path: test/graph/hl_decomposition/hld.test.cpp
  requiredBy: []
  timestamp: '2023-12-04 01:57:35+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/hl_decomposition/hld.test.cpp
layout: document
redirect_from:
- /verify/test/graph/hl_decomposition/hld.test.cpp
- /verify/test/graph/hl_decomposition/hld.test.cpp.html
title: test/graph/hl_decomposition/hld.test.cpp
---
