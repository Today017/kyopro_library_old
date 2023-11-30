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
  bundledCode: "#line 1 \"graph/topological_sort2.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nstruct topological_sort_graph {\n\tint n;\n\tvector<vector<int>>\
    \ G;\n\tvector<int> indeg;\n\tvector<int> sorted;\n\tbool is_u = true;\n\ttopological_sort_graph(int\
    \ n) {\n\t\tthis->n = n;\n\t\tG.resize(n);\n\t\tindeg.resize(n);\n\t}\n\tvoid\
    \ add_edge(int from, int to) {\n\t\tG[from].push_back(to);\n\t\tindeg[to]++;\n\
    \t}\n\ttopological_sort_graph(const vector<vector<int>> &G) {\n\t\tn = G.size();\n\
    \t\tthis->G = G;\n\t\tindeg.resize(n);\n\t\tfor (int i = 0; i < n; i++) {\n\t\t\
    \tfor (int nxt : G[i]) {\n\t\t\t\tindeg[nxt]++;\n\t\t\t}\n\t\t}\n\t}\n\t// \u30C8\
    \u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\n\tvector<int> sort() {\n\t\t\
    vector<int> _indeg = indeg;\n\t\tsorted.clear();\n\t\tqueue<int> q;\n\t\tfor (int\
    \ i = 0; i < n; i++) {\n\t\t\tif (_indeg[i] == 0) {\n\t\t\t\tq.push(i);\n\t\t\t\
    }\n\t\t}\n\t\twhile (!q.empty()) {\n\t\t\tint now = q.front();\n\t\t\tq.pop();\n\
    \t\t\tis_u &= q.size() == 0;\n\t\t\tfor (int nxt : G[now]) {\n\t\t\t\t_indeg[nxt]--;\n\
    \t\t\t\tif (_indeg[nxt] == 0) {\n\t\t\t\t\tq.push(nxt);\n\t\t\t\t}\n\t\t\t}\n\t\
    \t\tsorted.push_back(now);\n\t\t}\n\t\treturn sorted;\n\t}\n\t// \u8F9E\u66F8\u9806\
    \u6700\u5927\u306E\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\n\tvector<int>\
    \ sort_max() {\n\t\tvector<int> _indeg = indeg;\n\t\tsorted.clear();\n\t\tpriority_queue<int>\
    \ q;\n\t\tfor (int i = 0; i < n; i++) {\n\t\t\tif (_indeg[i] == 0) {\n\t\t\t\t\
    q.push(i);\n\t\t\t}\n\t\t}\n\t\twhile (!q.empty()) {\n\t\t\tint now = q.top();\n\
    \t\t\tq.pop();\n\t\t\tfor (int nxt : G[now]) {\n\t\t\t\t_indeg[nxt]--;\n\t\t\t\
    \tif (_indeg[nxt] == 0) {\n\t\t\t\t\tq.push(nxt);\n\t\t\t\t}\n\t\t\t}\n\t\t\t\
    sorted.push_back(now);\n\t\t}\n\t\treturn sorted;\n\t}\n\t// \u8F9E\u66F8\u9806\
    \u6700\u5C0F\u306E\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\n\tvector<int>\
    \ sort_min() {\n\t\tvector<int> _indeg = indeg;\n\t\tsorted.clear();\n\t\tpriority_queue<int>\
    \ q;\n\t\tfor (int i = 0; i < n; i++) {\n\t\t\tif (_indeg[i] == 0) {\n\t\t\t\t\
    q.push(-i);\n\t\t\t}\n\t\t}\n\t\twhile (!q.empty()) {\n\t\t\tint now = -q.top();\n\
    \t\t\tq.pop();\n\t\t\tfor (int nxt : G[now]) {\n\t\t\t\t_indeg[nxt]--;\n\t\t\t\
    \tif (_indeg[nxt] == 0) {\n\t\t\t\t\tq.push(-nxt);\n\t\t\t\t}\n\t\t\t}\n\t\t\t\
    sorted.push_back(now);\n\t\t}\n\t\treturn sorted;\n\t}\n\t// \u9589\u8DEF\u691C\
    \u51FA\n\tbool is_closed() {\n\t\treturn sorted.size() != n;\n\t}\n\t// \u30C8\
    \u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\u304C\u4E00\u610F\u3067\u3042\
    \u308B\u304B\n\tbool is_unique() {\n\t\treturn is_u;\n\t}\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\nstruct topological_sort_graph\
    \ {\n\tint n;\n\tvector<vector<int>> G;\n\tvector<int> indeg;\n\tvector<int> sorted;\n\
    \tbool is_u = true;\n\ttopological_sort_graph(int n) {\n\t\tthis->n = n;\n\t\t\
    G.resize(n);\n\t\tindeg.resize(n);\n\t}\n\tvoid add_edge(int from, int to) {\n\
    \t\tG[from].push_back(to);\n\t\tindeg[to]++;\n\t}\n\ttopological_sort_graph(const\
    \ vector<vector<int>> &G) {\n\t\tn = G.size();\n\t\tthis->G = G;\n\t\tindeg.resize(n);\n\
    \t\tfor (int i = 0; i < n; i++) {\n\t\t\tfor (int nxt : G[i]) {\n\t\t\t\tindeg[nxt]++;\n\
    \t\t\t}\n\t\t}\n\t}\n\t// \u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\
    \n\tvector<int> sort() {\n\t\tvector<int> _indeg = indeg;\n\t\tsorted.clear();\n\
    \t\tqueue<int> q;\n\t\tfor (int i = 0; i < n; i++) {\n\t\t\tif (_indeg[i] == 0)\
    \ {\n\t\t\t\tq.push(i);\n\t\t\t}\n\t\t}\n\t\twhile (!q.empty()) {\n\t\t\tint now\
    \ = q.front();\n\t\t\tq.pop();\n\t\t\tis_u &= q.size() == 0;\n\t\t\tfor (int nxt\
    \ : G[now]) {\n\t\t\t\t_indeg[nxt]--;\n\t\t\t\tif (_indeg[nxt] == 0) {\n\t\t\t\
    \t\tq.push(nxt);\n\t\t\t\t}\n\t\t\t}\n\t\t\tsorted.push_back(now);\n\t\t}\n\t\t\
    return sorted;\n\t}\n\t// \u8F9E\u66F8\u9806\u6700\u5927\u306E\u30C8\u30DD\u30ED\
    \u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\n\tvector<int> sort_max() {\n\t\tvector<int>\
    \ _indeg = indeg;\n\t\tsorted.clear();\n\t\tpriority_queue<int> q;\n\t\tfor (int\
    \ i = 0; i < n; i++) {\n\t\t\tif (_indeg[i] == 0) {\n\t\t\t\tq.push(i);\n\t\t\t\
    }\n\t\t}\n\t\twhile (!q.empty()) {\n\t\t\tint now = q.top();\n\t\t\tq.pop();\n\
    \t\t\tfor (int nxt : G[now]) {\n\t\t\t\t_indeg[nxt]--;\n\t\t\t\tif (_indeg[nxt]\
    \ == 0) {\n\t\t\t\t\tq.push(nxt);\n\t\t\t\t}\n\t\t\t}\n\t\t\tsorted.push_back(now);\n\
    \t\t}\n\t\treturn sorted;\n\t}\n\t// \u8F9E\u66F8\u9806\u6700\u5C0F\u306E\u30C8\
    \u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\n\tvector<int> sort_min() {\n\
    \t\tvector<int> _indeg = indeg;\n\t\tsorted.clear();\n\t\tpriority_queue<int>\
    \ q;\n\t\tfor (int i = 0; i < n; i++) {\n\t\t\tif (_indeg[i] == 0) {\n\t\t\t\t\
    q.push(-i);\n\t\t\t}\n\t\t}\n\t\twhile (!q.empty()) {\n\t\t\tint now = -q.top();\n\
    \t\t\tq.pop();\n\t\t\tfor (int nxt : G[now]) {\n\t\t\t\t_indeg[nxt]--;\n\t\t\t\
    \tif (_indeg[nxt] == 0) {\n\t\t\t\t\tq.push(-nxt);\n\t\t\t\t}\n\t\t\t}\n\t\t\t\
    sorted.push_back(now);\n\t\t}\n\t\treturn sorted;\n\t}\n\t// \u9589\u8DEF\u691C\
    \u51FA\n\tbool is_closed() {\n\t\treturn sorted.size() != n;\n\t}\n\t// \u30C8\
    \u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\u304C\u4E00\u610F\u3067\u3042\
    \u308B\u304B\n\tbool is_unique() {\n\t\treturn is_u;\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/topological_sort2.cpp
  requiredBy: []
  timestamp: '2023-11-30 18:16:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/topological_sort2.cpp
layout: document
redirect_from:
- /library/graph/topological_sort2.cpp
- /library/graph/topological_sort2.cpp.html
title: graph/topological_sort2.cpp
---
