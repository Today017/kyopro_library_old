---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/abc294/submissions/46419196
    - https://hcpc-hokudai.github.io/archive/graph_tree_001.pdf
  bundledCode: "#line 1 \"graph/hld_graph.cpp\"\n#include <bits/stdc++.h>\r\nusing\
    \ namespace std;\r\n\r\n/**\r\n * vector<int> sz :\r\n * \t\u9802\u70B9\u306E\u90E8\
    \u5206\u6728\u306E\u5927\u304D\u3055\r\n * vector<int> parent :\r\n * \t\u9802\
    \u70B9\u306E\u89AA\r\n * vector<int> depth :\r\n * \t\u9802\u70B9\u306E\u6DF1\u3055\
    \r\n * vector<int> hld :\r\n * \tHLD\u3057\u305F\u7D50\u679C\u306E\u914D\u5217\
    \r\n * vector<int> pos :\r\n * \t\u5143\u306E\u9802\u70B9\u306E\u4F4D\u7F6E\r\n\
    \ * vector<int> head :\r\n * \t\u9802\u70B9\u306E\u5C5E\u3059\u308B\u9023\u7D50\
    \u6210\u5206\u306E\u6700\u3082\u6D45\u3044\u9802\u70B9\r\n*/\r\n\r\n// heavy-light\
    \ decomposition\r\n// https://hcpc-hokudai.github.io/archive/graph_tree_001.pdf\r\
    \n// https://atcoder.jp/contests/abc294/submissions/46419196\r\nstruct hld_graph\
    \ {\r\n\tvector<vector<int>> G;\r\n\tvector<int> sz, parent, depth, hld, pos,\
    \ head;\r\n\thld_graph(int n) {\r\n\t\tG.resize(n);\r\n\t\tsz.resize(n);\r\n\t\
    \tparent.resize(n);\r\n\t\tdepth.resize(n);\r\n\t\tpos.resize(n);\r\n\t\thead.resize(n);\r\
    \n\t}\r\n\tvoid add_edge(int a, int b) {\r\n\t\tG[a].push_back(b);\r\n\t\tG[b].push_back(a);\r\
    \n\t}\r\n\thld_graph(const vector<vector<int>>& G) {\r\n\t\tint n = G.size();\r\
    \n\t\tthis->G = G;\r\n\t\tsz.resize(n);\r\n\t\tparent.resize(n);\r\n\t\tdepth.resize(n);\r\
    \n\t\tpos.resize(n);\r\n\t\thead.resize(n);\r\n\t}\r\n\tvector<int> hld_start(int\
    \ root = 0) {\r\n\t\tdfs1(root);\r\n\t\tdfs2(root);\r\n\t\tdfs(root, root);\r\n\
    \t\treturn hld;\r\n\t}\r\n\tvoid dfs(int now, int a, int pre = -1) {\r\n\t\tpos[now]\
    \ = hld.size();\r\n\t\thld.push_back(now);\r\n\t\thead[now] = a;\r\n\t\tif (sz[now]\
    \ == 1) {\r\n\t\t\treturn;\r\n\t\t}\r\n\t\tint mx = 0;\r\n\t\tint mx_idx = 0;\r\
    \n\t\tfor (int nxt : G[now]) {\r\n\t\t\tif (nxt == pre) {\r\n\t\t\t\tcontinue;\r\
    \n\t\t\t}\r\n\t\t\tif (mx < sz[nxt]) {\r\n\t\t\t\tmx = sz[nxt];\r\n\t\t\t\tmx_idx\
    \ = nxt;\r\n\t\t\t}\r\n\t\t}\r\n\t\tdfs(mx_idx, a, now);\r\n\t\tfor (int nxt :\
    \ G[now]) {\r\n\t\t\tif (nxt == pre) {\r\n\t\t\t\tcontinue;\r\n\t\t\t}\r\n\t\t\
    \tif (nxt == mx_idx) {\r\n\t\t\t\tcontinue;\r\n\t\t\t}\r\n\t\t\tdfs(nxt, nxt,\
    \ now);\r\n\t\t}\r\n\t}\r\n\tvoid dfs1(int now, int pre = -1) {\r\n\t\tint res\
    \ = 1;\r\n\t\tfor (int nxt : G[now]) {\r\n\t\t\tif (nxt == pre) {\r\n\t\t\t\t\
    continue;\r\n\t\t\t}\r\n\t\t\tdfs1(nxt, now);\r\n\t\t\tres += sz[nxt];\r\n\t\t\
    }\r\n\t\tsz[now] = res;\r\n\t}\r\n\tvoid dfs2(int now, int pre = -1) {\r\n\t\t\
    parent[now] = pre;\r\n\t\tfor (int nxt : G[now]) {\r\n\t\t\tif (nxt == pre) {\r\
    \n\t\t\t\tcontinue;\r\n\t\t\t}\r\n\t\t\tdepth[nxt] = depth[now] + 1;\r\n\t\t\t\
    dfs2(nxt, now);\r\n\t\t}\r\n\t}\r\n\tint lca(int u, int v) {\r\n\t\twhile (head[u]\
    \ != head[v]) {\r\n\t\t\tif (depth[head[u]] > depth[head[v]]) {\r\n\t\t\t\tu =\
    \ parent[head[u]];\r\n\t\t\t} else {\r\n\t\t\t\tv = parent[head[v]];\r\n\t\t\t\
    }\r\n\t\t}\r\n\t\treturn depth[u] < depth[v] ? u : v;\r\n\t}\r\n\t// Update(x,\
    \ pos_x) \u9802\u70B9x\u306B\u5BFE\u3059\u308B\u51E6\u7406\r\n\t// pos_x     \
    \       \u9802\u70B9x\u306EHLD\u5F8C\u306E\u4F4D\u7F6E\r\n\t// \u5217\u3092\u7BA1\
    \u7406\u3059\u308B\u30C7\u30FC\u30BF\u69CB\u9020A\u306B\u5BFE\u3057\u3066\u3001\
    x\u306B\u5BFE\u3057\u3066\u306E\u51E6\u7406\u3092Update\u5185\u3067A[pos_x]\u306B\
    \u5BFE\u3057\u3066\u884C\u3046\r\n\ttemplate <typename U>\r\n\tvoid update(int\
    \ x, U& Update) {\r\n\t\tUpdate(x, pos[x]);\r\n\t}\r\n\t// u, v         \u51E6\
    \u7406/\u53D6\u5F97\u3092\u884C\u3046\u30D1\u30B9\r\n\t// Query(x, y)  \u533A\u9593\
    [x,y)\u306B\u5BFE\u3059\u308B\u51E6\u7406\r\n\t// F            \u6F14\u7B97\r\n\
    \t// e            F\u306E\u5358\u4F4D\u5143\r\n\t// \u5217\u3092\u7BA1\u7406\u3059\
    \u308B\u30C7\u30FC\u30BF\u69CB\u9020A\u306B\u5BFE\u3057\u3066\u3001x,y\u306B\u5BFE\
    \u3057\u3066\u306E\u51E6\u7406/\u53D6\u5F97\u3092Query\u5185\u3067\u884C\u3046\
    \r\n\t// \u6F14\u7B97\u7D50\u679C\u3092F\u3067\u307E\u3068\u3081\u308B\r\n\ttemplate\
    \ <typename Q, typename F, typename T>\r\n\tT query(int u, int v, Q& Query, F&\
    \ f, T e) {\r\n\t\tT ret = e;\r\n\t\twhile (head[u] != head[v]) {\r\n\t\t\tif\
    \ (depth[head[u]] < depth[head[v]]) {\r\n\t\t\t\tswap(u, v);\r\n\t\t\t}\r\n\t\t\
    \tret = f(ret, Query(pos[head[u]], pos[u] + 1));\r\n\t\t\tu = parent[head[u]];\r\
    \n\t\t}\r\n\t\tif (depth[u] > depth[v]) {\r\n\t\t\tswap(u, v);\r\n\t\t}\r\n\t\t\
    ret = f(ret, Query(pos[u], pos[v] + 1));\r\n\t\treturn ret;\r\n\t}\r\n};\r\n"
  code: "#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\n/**\r\n * vector<int>\
    \ sz :\r\n * \t\u9802\u70B9\u306E\u90E8\u5206\u6728\u306E\u5927\u304D\u3055\r\n\
    \ * vector<int> parent :\r\n * \t\u9802\u70B9\u306E\u89AA\r\n * vector<int> depth\
    \ :\r\n * \t\u9802\u70B9\u306E\u6DF1\u3055\r\n * vector<int> hld :\r\n * \tHLD\u3057\
    \u305F\u7D50\u679C\u306E\u914D\u5217\r\n * vector<int> pos :\r\n * \t\u5143\u306E\
    \u9802\u70B9\u306E\u4F4D\u7F6E\r\n * vector<int> head :\r\n * \t\u9802\u70B9\u306E\
    \u5C5E\u3059\u308B\u9023\u7D50\u6210\u5206\u306E\u6700\u3082\u6D45\u3044\u9802\
    \u70B9\r\n*/\r\n\r\n// heavy-light decomposition\r\n// https://hcpc-hokudai.github.io/archive/graph_tree_001.pdf\r\
    \n// https://atcoder.jp/contests/abc294/submissions/46419196\r\nstruct hld_graph\
    \ {\r\n\tvector<vector<int>> G;\r\n\tvector<int> sz, parent, depth, hld, pos,\
    \ head;\r\n\thld_graph(int n) {\r\n\t\tG.resize(n);\r\n\t\tsz.resize(n);\r\n\t\
    \tparent.resize(n);\r\n\t\tdepth.resize(n);\r\n\t\tpos.resize(n);\r\n\t\thead.resize(n);\r\
    \n\t}\r\n\tvoid add_edge(int a, int b) {\r\n\t\tG[a].push_back(b);\r\n\t\tG[b].push_back(a);\r\
    \n\t}\r\n\thld_graph(const vector<vector<int>>& G) {\r\n\t\tint n = G.size();\r\
    \n\t\tthis->G = G;\r\n\t\tsz.resize(n);\r\n\t\tparent.resize(n);\r\n\t\tdepth.resize(n);\r\
    \n\t\tpos.resize(n);\r\n\t\thead.resize(n);\r\n\t}\r\n\tvector<int> hld_start(int\
    \ root = 0) {\r\n\t\tdfs1(root);\r\n\t\tdfs2(root);\r\n\t\tdfs(root, root);\r\n\
    \t\treturn hld;\r\n\t}\r\n\tvoid dfs(int now, int a, int pre = -1) {\r\n\t\tpos[now]\
    \ = hld.size();\r\n\t\thld.push_back(now);\r\n\t\thead[now] = a;\r\n\t\tif (sz[now]\
    \ == 1) {\r\n\t\t\treturn;\r\n\t\t}\r\n\t\tint mx = 0;\r\n\t\tint mx_idx = 0;\r\
    \n\t\tfor (int nxt : G[now]) {\r\n\t\t\tif (nxt == pre) {\r\n\t\t\t\tcontinue;\r\
    \n\t\t\t}\r\n\t\t\tif (mx < sz[nxt]) {\r\n\t\t\t\tmx = sz[nxt];\r\n\t\t\t\tmx_idx\
    \ = nxt;\r\n\t\t\t}\r\n\t\t}\r\n\t\tdfs(mx_idx, a, now);\r\n\t\tfor (int nxt :\
    \ G[now]) {\r\n\t\t\tif (nxt == pre) {\r\n\t\t\t\tcontinue;\r\n\t\t\t}\r\n\t\t\
    \tif (nxt == mx_idx) {\r\n\t\t\t\tcontinue;\r\n\t\t\t}\r\n\t\t\tdfs(nxt, nxt,\
    \ now);\r\n\t\t}\r\n\t}\r\n\tvoid dfs1(int now, int pre = -1) {\r\n\t\tint res\
    \ = 1;\r\n\t\tfor (int nxt : G[now]) {\r\n\t\t\tif (nxt == pre) {\r\n\t\t\t\t\
    continue;\r\n\t\t\t}\r\n\t\t\tdfs1(nxt, now);\r\n\t\t\tres += sz[nxt];\r\n\t\t\
    }\r\n\t\tsz[now] = res;\r\n\t}\r\n\tvoid dfs2(int now, int pre = -1) {\r\n\t\t\
    parent[now] = pre;\r\n\t\tfor (int nxt : G[now]) {\r\n\t\t\tif (nxt == pre) {\r\
    \n\t\t\t\tcontinue;\r\n\t\t\t}\r\n\t\t\tdepth[nxt] = depth[now] + 1;\r\n\t\t\t\
    dfs2(nxt, now);\r\n\t\t}\r\n\t}\r\n\tint lca(int u, int v) {\r\n\t\twhile (head[u]\
    \ != head[v]) {\r\n\t\t\tif (depth[head[u]] > depth[head[v]]) {\r\n\t\t\t\tu =\
    \ parent[head[u]];\r\n\t\t\t} else {\r\n\t\t\t\tv = parent[head[v]];\r\n\t\t\t\
    }\r\n\t\t}\r\n\t\treturn depth[u] < depth[v] ? u : v;\r\n\t}\r\n\t// Update(x,\
    \ pos_x) \u9802\u70B9x\u306B\u5BFE\u3059\u308B\u51E6\u7406\r\n\t// pos_x     \
    \       \u9802\u70B9x\u306EHLD\u5F8C\u306E\u4F4D\u7F6E\r\n\t// \u5217\u3092\u7BA1\
    \u7406\u3059\u308B\u30C7\u30FC\u30BF\u69CB\u9020A\u306B\u5BFE\u3057\u3066\u3001\
    x\u306B\u5BFE\u3057\u3066\u306E\u51E6\u7406\u3092Update\u5185\u3067A[pos_x]\u306B\
    \u5BFE\u3057\u3066\u884C\u3046\r\n\ttemplate <typename U>\r\n\tvoid update(int\
    \ x, U& Update) {\r\n\t\tUpdate(x, pos[x]);\r\n\t}\r\n\t// u, v         \u51E6\
    \u7406/\u53D6\u5F97\u3092\u884C\u3046\u30D1\u30B9\r\n\t// Query(x, y)  \u533A\u9593\
    [x,y)\u306B\u5BFE\u3059\u308B\u51E6\u7406\r\n\t// F            \u6F14\u7B97\r\n\
    \t// e            F\u306E\u5358\u4F4D\u5143\r\n\t// \u5217\u3092\u7BA1\u7406\u3059\
    \u308B\u30C7\u30FC\u30BF\u69CB\u9020A\u306B\u5BFE\u3057\u3066\u3001x,y\u306B\u5BFE\
    \u3057\u3066\u306E\u51E6\u7406/\u53D6\u5F97\u3092Query\u5185\u3067\u884C\u3046\
    \r\n\t// \u6F14\u7B97\u7D50\u679C\u3092F\u3067\u307E\u3068\u3081\u308B\r\n\ttemplate\
    \ <typename Q, typename F, typename T>\r\n\tT query(int u, int v, Q& Query, F&\
    \ f, T e) {\r\n\t\tT ret = e;\r\n\t\twhile (head[u] != head[v]) {\r\n\t\t\tif\
    \ (depth[head[u]] < depth[head[v]]) {\r\n\t\t\t\tswap(u, v);\r\n\t\t\t}\r\n\t\t\
    \tret = f(ret, Query(pos[head[u]], pos[u] + 1));\r\n\t\t\tu = parent[head[u]];\r\
    \n\t\t}\r\n\t\tif (depth[u] > depth[v]) {\r\n\t\t\tswap(u, v);\r\n\t\t}\r\n\t\t\
    ret = f(ret, Query(pos[u], pos[v] + 1));\r\n\t\treturn ret;\r\n\t}\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/hld_graph.cpp
  requiredBy: []
  timestamp: '2023-11-30 18:16:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/hld_graph.cpp
layout: document
redirect_from:
- /library/graph/hld_graph.cpp
- /library/graph/hld_graph.cpp.html
title: graph/hld_graph.cpp
---
