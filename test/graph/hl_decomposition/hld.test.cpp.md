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
    using namespace std;\n\n#line 2 \"graph/hld.cpp\"\n\r\n/**\r\n * @brief Heavy-Light\
    \ Decomposition\r\n * @docs docs/graph/hld.md\r\n */\r\n\r\nstruct heavy_light_decomposition\
    \ {\r\n    heavy_light_decomposition(int n) {\r\n        G.resize(n);\r\n    \
    \    sz.resize(n);\r\n        parent.resize(n);\r\n        depth.resize(n);\r\n\
    \        pos.resize(n);\r\n        head.resize(n);\r\n    }\r\n    void add_edge(int\
    \ a, int b) {\r\n        G[a].push_back(b);\r\n        G[b].push_back(a);\r\n\
    \    }\r\n    heavy_light_decomposition(const std::vector<std::vector<int>>& G)\
    \ {\r\n        int n = G.size();\r\n        this->G = G;\r\n        sz.resize(n);\r\
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
    \ 1;\r\n            dfs2(nxt, now);\r\n        }\r\n    }\r\n};\r\n#line 3 \"\
    data_structure/fenwick_tree.cpp\"\n\r\n/**\r\n * @brief Fenwick Tree\r\n * @docs\
    \ docs/data_structure/fenwick_tree.md\r\n */\r\n\r\ntemplate <typename T>\r\n\
    struct fenwick_tree {\r\n    fenwick_tree(int n) {\r\n        this->n = n;\r\n\
    \        dat.resize(n);\r\n    }\r\n    void add(int i, T x) {\r\n        i++;\r\
    \n        while (i <= n) {\r\n            dat[i - 1] += x;\r\n            i +=\
    \ i & -i;\r\n        }\r\n    }\r\n    T operator[](int i) {\r\n        return\
    \ sum(i, i + 1);\r\n    }\r\n    T sum(int l, int r) {\r\n        return sum(r)\
    \ - sum(l);\r\n    }\r\n    friend std::ostream &operator<<(ostream &os, fenwick_tree\
    \ A) {\r\n        int n = A.n;\r\n        os << \"[ \";\r\n        for (int i\
    \ = 0; i < n; i++) {\r\n            os << A[i];\r\n            if (i != n - 1)\
    \ {\r\n                os << \", \";\r\n            }\r\n        }\r\n       \
    \ os << \" ]\";\r\n        return os;\r\n    }\r\n\r\nprivate:\r\n    int n;\r\
    \n    std::vector<T> dat;\r\n    T sum(int r) {\r\n        T ret = 0;\r\n    \
    \    while (r > 0) {\r\n            ret += dat[r - 1];\r\n            r -= r &\
    \ -r;\r\n        }\r\n        return ret;\r\n    }\r\n};\n#line 7 \"test/graph/hl_decomposition/hld.test.cpp\"\
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
  timestamp: '2024-01-25 12:07:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/hl_decomposition/hld.test.cpp
layout: document
redirect_from:
- /verify/test/graph/hl_decomposition/hld.test.cpp
- /verify/test/graph/hl_decomposition/hld.test.cpp.html
title: test/graph/hl_decomposition/hld.test.cpp
---
