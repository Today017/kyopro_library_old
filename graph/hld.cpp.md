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
    _deprecated_at_docs: docs/graph/hld.md
    document_title: Heavy-Light Decomposition
    links: []
  bundledCode: "#line 1 \"graph/hld.cpp\"\n#include <vector>\r\n\r\n/**\r\n * @brief\
    \ Heavy-Light Decomposition\r\n * @docs docs/graph/hld.md\r\n */\r\n\r\nstruct\
    \ heavy_light_decomposition {\r\n    heavy_light_decomposition(int n) {\r\n  \
    \      G.resize(n);\r\n        sz.resize(n);\r\n        parent.resize(n);\r\n\
    \        depth.resize(n);\r\n        pos.resize(n);\r\n        head.resize(n);\r\
    \n    }\r\n    void add_edge(int a, int b) {\r\n        G[a].push_back(b);\r\n\
    \        G[b].push_back(a);\r\n    }\r\n    heavy_light_decomposition(const std::vector<std::vector<int>>&\
    \ G) {\r\n        int n = G.size();\r\n        this->G = G;\r\n        sz.resize(n);\r\
    \n        parent.resize(n);\r\n        depth.resize(n);\r\n        pos.resize(n);\r\
    \n        head.resize(n);\r\n    }\r\n    std::vector<int> hld_start(int root\
    \ = 0) {\r\n        dfs1(root);\r\n        dfs2(root);\r\n        dfs(root, root);\r\
    \n        return hld;\r\n    }\r\n    int lca(int u, int v) {\r\n        while\
    \ (head[u] != head[v]) {\r\n            if (depth[head[u]] > depth[head[v]]) {\r\
    \n                u = parent[head[u]];\r\n            } else {\r\n           \
    \     v = parent[head[v]];\r\n            }\r\n        }\r\n        return depth[u]\
    \ < depth[v] ? u : v;\r\n    }\r\n    template <typename U>\r\n    void update(int\
    \ x, U& Update) {\r\n        Update(x, pos[x]);\r\n    }\r\n    template <typename\
    \ Q, typename F, typename T>\r\n    T query(int u, int v, Q& Query, F& f, T e)\
    \ {\r\n        T ret = e;\r\n        while (head[u] != head[v]) {\r\n        \
    \    if (depth[head[u]] < depth[head[v]]) {\r\n                swap(u, v);\r\n\
    \            }\r\n            ret = f(ret, Query(pos[head[u]], pos[u] + 1));\r\
    \n            u = parent[head[u]];\r\n        }\r\n        if (depth[u] > depth[v])\
    \ {\r\n            swap(u, v);\r\n        }\r\n        ret = f(ret, Query(pos[u],\
    \ pos[v] + 1));\r\n        return ret;\r\n    }\r\n\r\nprivate:\r\n    std::vector<std::vector<int>>\
    \ G;\r\n    std::vector<int> sz, parent, depth, hld, pos, head;\r\n    void dfs(int\
    \ now, int a, int pre = -1) {\r\n        pos[now] = hld.size();\r\n        hld.push_back(now);\r\
    \n        head[now] = a;\r\n        if (sz[now] == 1) {\r\n            return;\r\
    \n        }\r\n        int mx = 0;\r\n        int mx_idx = 0;\r\n        for (int\
    \ nxt : G[now]) {\r\n            if (nxt == pre) {\r\n                continue;\r\
    \n            }\r\n            if (mx < sz[nxt]) {\r\n                mx = sz[nxt];\r\
    \n                mx_idx = nxt;\r\n            }\r\n        }\r\n        dfs(mx_idx,\
    \ a, now);\r\n        for (int nxt : G[now]) {\r\n            if (nxt == pre)\
    \ {\r\n                continue;\r\n            }\r\n            if (nxt == mx_idx)\
    \ {\r\n                continue;\r\n            }\r\n            dfs(nxt, nxt,\
    \ now);\r\n        }\r\n    }\r\n    void dfs1(int now, int pre = -1) {\r\n  \
    \      int res = 1;\r\n        for (int nxt : G[now]) {\r\n            if (nxt\
    \ == pre) {\r\n                continue;\r\n            }\r\n            dfs1(nxt,\
    \ now);\r\n            res += sz[nxt];\r\n        }\r\n        sz[now] = res;\r\
    \n    }\r\n    void dfs2(int now, int pre = -1) {\r\n        parent[now] = pre;\r\
    \n        for (int nxt : G[now]) {\r\n            if (nxt == pre) {\r\n      \
    \          continue;\r\n            }\r\n            depth[nxt] = depth[now] +\
    \ 1;\r\n            dfs2(nxt, now);\r\n        }\r\n    }\r\n};\r\n"
  code: "#include <vector>\r\n\r\n/**\r\n * @brief Heavy-Light Decomposition\r\n *\
    \ @docs docs/graph/hld.md\r\n */\r\n\r\nstruct heavy_light_decomposition {\r\n\
    \    heavy_light_decomposition(int n) {\r\n        G.resize(n);\r\n        sz.resize(n);\r\
    \n        parent.resize(n);\r\n        depth.resize(n);\r\n        pos.resize(n);\r\
    \n        head.resize(n);\r\n    }\r\n    void add_edge(int a, int b) {\r\n  \
    \      G[a].push_back(b);\r\n        G[b].push_back(a);\r\n    }\r\n    heavy_light_decomposition(const\
    \ std::vector<std::vector<int>>& G) {\r\n        int n = G.size();\r\n       \
    \ this->G = G;\r\n        sz.resize(n);\r\n        parent.resize(n);\r\n     \
    \   depth.resize(n);\r\n        pos.resize(n);\r\n        head.resize(n);\r\n\
    \    }\r\n    std::vector<int> hld_start(int root = 0) {\r\n        dfs1(root);\r\
    \n        dfs2(root);\r\n        dfs(root, root);\r\n        return hld;\r\n \
    \   }\r\n    int lca(int u, int v) {\r\n        while (head[u] != head[v]) {\r\
    \n            if (depth[head[u]] > depth[head[v]]) {\r\n                u = parent[head[u]];\r\
    \n            } else {\r\n                v = parent[head[v]];\r\n           \
    \ }\r\n        }\r\n        return depth[u] < depth[v] ? u : v;\r\n    }\r\n \
    \   template <typename U>\r\n    void update(int x, U& Update) {\r\n        Update(x,\
    \ pos[x]);\r\n    }\r\n    template <typename Q, typename F, typename T>\r\n \
    \   T query(int u, int v, Q& Query, F& f, T e) {\r\n        T ret = e;\r\n   \
    \     while (head[u] != head[v]) {\r\n            if (depth[head[u]] < depth[head[v]])\
    \ {\r\n                swap(u, v);\r\n            }\r\n            ret = f(ret,\
    \ Query(pos[head[u]], pos[u] + 1));\r\n            u = parent[head[u]];\r\n  \
    \      }\r\n        if (depth[u] > depth[v]) {\r\n            swap(u, v);\r\n\
    \        }\r\n        ret = f(ret, Query(pos[u], pos[v] + 1));\r\n        return\
    \ ret;\r\n    }\r\n\r\nprivate:\r\n    std::vector<std::vector<int>> G;\r\n  \
    \  std::vector<int> sz, parent, depth, hld, pos, head;\r\n    void dfs(int now,\
    \ int a, int pre = -1) {\r\n        pos[now] = hld.size();\r\n        hld.push_back(now);\r\
    \n        head[now] = a;\r\n        if (sz[now] == 1) {\r\n            return;\r\
    \n        }\r\n        int mx = 0;\r\n        int mx_idx = 0;\r\n        for (int\
    \ nxt : G[now]) {\r\n            if (nxt == pre) {\r\n                continue;\r\
    \n            }\r\n            if (mx < sz[nxt]) {\r\n                mx = sz[nxt];\r\
    \n                mx_idx = nxt;\r\n            }\r\n        }\r\n        dfs(mx_idx,\
    \ a, now);\r\n        for (int nxt : G[now]) {\r\n            if (nxt == pre)\
    \ {\r\n                continue;\r\n            }\r\n            if (nxt == mx_idx)\
    \ {\r\n                continue;\r\n            }\r\n            dfs(nxt, nxt,\
    \ now);\r\n        }\r\n    }\r\n    void dfs1(int now, int pre = -1) {\r\n  \
    \      int res = 1;\r\n        for (int nxt : G[now]) {\r\n            if (nxt\
    \ == pre) {\r\n                continue;\r\n            }\r\n            dfs1(nxt,\
    \ now);\r\n            res += sz[nxt];\r\n        }\r\n        sz[now] = res;\r\
    \n    }\r\n    void dfs2(int now, int pre = -1) {\r\n        parent[now] = pre;\r\
    \n        for (int nxt : G[now]) {\r\n            if (nxt == pre) {\r\n      \
    \          continue;\r\n            }\r\n            depth[nxt] = depth[now] +\
    \ 1;\r\n            dfs2(nxt, now);\r\n        }\r\n    }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/hld.cpp
  requiredBy: []
  timestamp: '2024-01-25 11:55:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/hl_decomposition/hld.test.cpp
documentation_of: graph/hld.cpp
layout: document
redirect_from:
- /library/graph/hld.cpp
- /library/graph/hld.cpp.html
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