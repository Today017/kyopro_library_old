---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/hl_decomposition/hld.test.cpp
    title: test/graph/hl_decomposition/hld.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/hl_decomposition.md
    document_title: Heavy-Light Decomposition
    links: []
  bundledCode: "#line 1 \"graph/hl_decomposition.cpp\"\n/**\r\n * @brief Heavy-Light\
    \ Decomposition\r\n * @docs docs/graph/hl_decomposition.md\r\n*/\r\n\r\nstruct\
    \ heavy_light_decomposition {\r\n\tvector<vector<int>> G;\r\n\tvector<int> sz,\
    \ parent, depth, hld, pos, head;\r\n\theavy_light_decomposition(int n) {\r\n\t\
    \tG.resize(n);\r\n\t\tsz.resize(n);\r\n\t\tparent.resize(n);\r\n\t\tdepth.resize(n);\r\
    \n\t\tpos.resize(n);\r\n\t\thead.resize(n);\r\n\t}\r\n\tvoid add_edge(int a, int\
    \ b) {\r\n\t\tG[a].push_back(b);\r\n\t\tG[b].push_back(a);\r\n\t}\r\n\theavy_light_decomposition(const\
    \ vector<vector<int>>& G) {\r\n\t\tint n = G.size();\r\n\t\tthis->G = G;\r\n\t\
    \tsz.resize(n);\r\n\t\tparent.resize(n);\r\n\t\tdepth.resize(n);\r\n\t\tpos.resize(n);\r\
    \n\t\thead.resize(n);\r\n\t}\r\n\tvector<int> hld_start(int root = 0) {\r\n\t\t\
    dfs1(root);\r\n\t\tdfs2(root);\r\n\t\tdfs(root, root);\r\n\t\treturn hld;\r\n\t\
    }\r\n\tvoid dfs(int now, int a, int pre = -1) {\r\n\t\tpos[now] = hld.size();\r\
    \n\t\thld.push_back(now);\r\n\t\thead[now] = a;\r\n\t\tif (sz[now] == 1) {\r\n\
    \t\t\treturn;\r\n\t\t}\r\n\t\tint mx = 0;\r\n\t\tint mx_idx = 0;\r\n\t\tfor (int\
    \ nxt : G[now]) {\r\n\t\t\tif (nxt == pre) {\r\n\t\t\t\tcontinue;\r\n\t\t\t}\r\
    \n\t\t\tif (mx < sz[nxt]) {\r\n\t\t\t\tmx = sz[nxt];\r\n\t\t\t\tmx_idx = nxt;\r\
    \n\t\t\t}\r\n\t\t}\r\n\t\tdfs(mx_idx, a, now);\r\n\t\tfor (int nxt : G[now]) {\r\
    \n\t\t\tif (nxt == pre) {\r\n\t\t\t\tcontinue;\r\n\t\t\t}\r\n\t\t\tif (nxt ==\
    \ mx_idx) {\r\n\t\t\t\tcontinue;\r\n\t\t\t}\r\n\t\t\tdfs(nxt, nxt, now);\r\n\t\
    \t}\r\n\t}\r\n\tvoid dfs1(int now, int pre = -1) {\r\n\t\tint res = 1;\r\n\t\t\
    for (int nxt : G[now]) {\r\n\t\t\tif (nxt == pre) {\r\n\t\t\t\tcontinue;\r\n\t\
    \t\t}\r\n\t\t\tdfs1(nxt, now);\r\n\t\t\tres += sz[nxt];\r\n\t\t}\r\n\t\tsz[now]\
    \ = res;\r\n\t}\r\n\tvoid dfs2(int now, int pre = -1) {\r\n\t\tparent[now] = pre;\r\
    \n\t\tfor (int nxt : G[now]) {\r\n\t\t\tif (nxt == pre) {\r\n\t\t\t\tcontinue;\r\
    \n\t\t\t}\r\n\t\t\tdepth[nxt] = depth[now] + 1;\r\n\t\t\tdfs2(nxt, now);\r\n\t\
    \t}\r\n\t}\r\n\tint lca(int u, int v) {\r\n\t\twhile (head[u] != head[v]) {\r\n\
    \t\t\tif (depth[head[u]] > depth[head[v]]) {\r\n\t\t\t\tu = parent[head[u]];\r\
    \n\t\t\t} else {\r\n\t\t\t\tv = parent[head[v]];\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn\
    \ depth[u] < depth[v] ? u : v;\r\n\t}\r\n\ttemplate <typename U>\r\n\tvoid update(int\
    \ x, U& Update) {\r\n\t\tUpdate(x, pos[x]);\r\n\t}\r\n\ttemplate <typename Q,\
    \ typename F, typename T>\r\n\tT query(int u, int v, Q& Query, F& f, T e) {\r\n\
    \t\tT ret = e;\r\n\t\twhile (head[u] != head[v]) {\r\n\t\t\tif (depth[head[u]]\
    \ < depth[head[v]]) {\r\n\t\t\t\tswap(u, v);\r\n\t\t\t}\r\n\t\t\tret = f(ret,\
    \ Query(pos[head[u]], pos[u] + 1));\r\n\t\t\tu = parent[head[u]];\r\n\t\t}\r\n\
    \t\tif (depth[u] > depth[v]) {\r\n\t\t\tswap(u, v);\r\n\t\t}\r\n\t\tret = f(ret,\
    \ Query(pos[u], pos[v] + 1));\r\n\t\treturn ret;\r\n\t}\r\n};\r\n"
  code: "/**\r\n * @brief Heavy-Light Decomposition\r\n * @docs docs/graph/hl_decomposition.md\r\
    \n*/\r\n\r\nstruct heavy_light_decomposition {\r\n\tvector<vector<int>> G;\r\n\
    \tvector<int> sz, parent, depth, hld, pos, head;\r\n\theavy_light_decomposition(int\
    \ n) {\r\n\t\tG.resize(n);\r\n\t\tsz.resize(n);\r\n\t\tparent.resize(n);\r\n\t\
    \tdepth.resize(n);\r\n\t\tpos.resize(n);\r\n\t\thead.resize(n);\r\n\t}\r\n\tvoid\
    \ add_edge(int a, int b) {\r\n\t\tG[a].push_back(b);\r\n\t\tG[b].push_back(a);\r\
    \n\t}\r\n\theavy_light_decomposition(const vector<vector<int>>& G) {\r\n\t\tint\
    \ n = G.size();\r\n\t\tthis->G = G;\r\n\t\tsz.resize(n);\r\n\t\tparent.resize(n);\r\
    \n\t\tdepth.resize(n);\r\n\t\tpos.resize(n);\r\n\t\thead.resize(n);\r\n\t}\r\n\
    \tvector<int> hld_start(int root = 0) {\r\n\t\tdfs1(root);\r\n\t\tdfs2(root);\r\
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
    ret = f(ret, Query(pos[u], pos[v] + 1));\r\n\t\treturn ret;\r\n\t}\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/hl_decomposition.cpp
  requiredBy: []
  timestamp: '2023-12-01 06:34:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/hl_decomposition/hld.test.cpp
documentation_of: graph/hl_decomposition.cpp
layout: document
redirect_from:
- /library/graph/hl_decomposition.cpp
- /library/graph/hl_decomposition.cpp.html
title: Heavy-Light Decomposition
---
詳しい解説は[こちら](https://hcpc-hokudai.github.io/archive/graph_tree_001.pdf)がわかりやすいです。使用例は[こちら](https://atcoder.jp/contests/abc294/submissions/46419196)。

```heavy_light_decomposition　hld(int n)```

```heavy_light_decomposition　hld(vector<vector<int>> G)```



```hld.start(int root)```
- 頂点`root`を根として木をHL分解する。
- $0\le root<n$
- $O(n)$


```hld.lca(int u, int v)```
- 頂点`u`,`v`のLCAを返す。
- $0\le u, v < n$
- $O(\log{n})$

```hld.update(int x, U Update)```
- 頂点`x`に対して、更新処理`Update`を適用する。
- $0\le x < n$
- $O(\log{n}f(n))$
- ```Update(int x, int pos_x)```
	- 頂点`x`,HLD後の列における`x`の位置を`pos_x`として、列の位置`pos_x`に対して更新処理を行う。
	- $O(f(n))$

```hld.query(int u, int v, Q Query, F f, T e)```
- パス`u`,`v`に対して、取得処理`Query`を適用する。
- $0\le u, v < n$
- $O(\log{n}g(n))$
- ```Query(int x, int y)```
	- HLD後の列の区間`[x,y)`に対して取得処理を行う。
	- $O(g(n))$
- ```F(T a, T b)```
	- `Query`による取得結果をまとめる演算を行う。RSQなら和、RMQならMin/Max演算を行う。
- ```e```
	- 演算`F`の単位元。

#### メンバ
`vector<int> sz`
- 頂点の部分木の大きさ

`vector<int> parent`
- 頂点の親

`vector<int> depth`
- 頂点の深さ

`vector<int> hld`
- HLD結果としての配列

`vector<int> pos`
- `hld`における頂点の位置

`vector<int> head`
- 頂点の属する連結成分の最も浅い頂点