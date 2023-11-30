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
    - https://ei1333.hateblo.jp/entry/2017/09/11/211011
  bundledCode: "#line 1 \"algorithm/mo.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n// https://ei1333.hateblo.jp/entry/2017/09/11/211011\n// Mo\u304C\u4F7F\
    \u3048\u308B\u6761\u4EF6\n// 1.\u914D\u5217\u306E\u8981\u7D20\u304C\u4E0D\u5909\
    \n// 2.\u30AF\u30A8\u30EA\u5148\u8AAD\u307F\u53EF\u80FD\n// 3.[l,r)\u306E\u7D50\
    \u679C\u304B\u3089[l+1,r),[l-1,r),[l,r-1),[l,r+1)\u306E\u7D50\u679C\u3092\u5BB9\
    \u6613\u306B\u8A08\u7B97\u3067\u304D\u308B\n// O(xNsqrt(Q))\nstruct Mo {\n\tint\
    \ n;\n\tvector<pair<int, int> > lr;\n\n\texplicit Mo(int n)\n\t\t: n(n) {\n\t\
    }\n\n\tvoid add(int l, int r) { /* [l, r) */\n\t\tlr.emplace_back(l, r);\n\t}\n\
    \n\t// \u8981\u7D20\u306E\u8FFD\u52A0\u3001\u524A\u9664\u304C\u975E\u53EF\u63DB\
    \u306A\u5834\u5408\n\ttemplate <typename AL, typename AR, typename EL, typename\
    \ ER, typename O>\n\tvoid build(const AL &add_left, const AR &add_right, const\
    \ EL &erase_left, const ER &erase_right, const O &out) {\n\t\tint q = (int)lr.size();\n\
    \t\tint bs = n / min<int>(n, sqrt(q));\n\t\tvector<int> ord(q);\n\t\tiota(begin(ord),\
    \ end(ord), 0);\n\t\tsort(begin(ord), end(ord), [&](int a, int b) {\n\t\t\tint\
    \ ablock = lr[a].first / bs, bblock = lr[b].first / bs;\n\t\t\tif (ablock != bblock)\
    \ return ablock < bblock;\n\t\t\treturn (ablock & 1) ? lr[a].second > lr[b].second\
    \ : lr[a].second < lr[b].second;\n\t\t});\n\t\tint l = 0, r = 0;\n\t\tfor (auto\
    \ idx : ord) {\n\t\t\twhile (l > lr[idx].first) add_left(--l);\n\t\t\twhile (r\
    \ < lr[idx].second) add_right(r++);\n\t\t\twhile (l < lr[idx].first) erase_left(l++);\n\
    \t\t\twhile (r > lr[idx].second) erase_right(--r);\n\t\t\tout(idx);\n\t\t}\n\t\
    }\n\n\ttemplate <typename A, typename E, typename O>\n\tvoid build(const A &add,\
    \ const E &erase, const O &out) {\n\t\tbuild(add, add, erase, erase, out);\n\t\
    }\n};\n\nstruct Mo {\n\tint n, q, query_count;\n\tlong long max_n;\n\tvector<int>\
    \ _l, _r;\n\n\tMo(int n, int q) {\n\t\tmax_n = 1 << 25;\n\t\tquery_count = 0;\n\
    \t\t_l.reserve(q);\n\t\t_r.reserve(q);\n\t\tthis->n = n;\n\t\tthis->q = q;\n\t\
    }\n\n\tlong long hilbertorder(int x, int y) {\n\t\tlong long rx, ry, d = 0;\n\t\
    \tfor (long long s = max_n >> 1ll; s; s >>= 1ll) {\n\t\t\trx = (x & s) > 0, ry\
    \ = (y & s) > 0;\n\t\t\td += s * s * ((rx * 3) ^ ry);\n\t\t\tif (ry) continue;\n\
    \t\t\tif (rx) {\n\t\t\t\tx = max_n - 1 - x;\n\t\t\t\ty = max_n - 1 - y;\n\t\t\t\
    }\n\t\t\tswap(x, y);\n\t\t}\n\t\treturn d;\n\t}\n\n\tvoid add_query(int l, int\
    \ r) {\n\t\t++query_count;\n\t\t_l.emplace_back(l);\n\t\t_r.emplace_back(r);\n\
    \t}\n\n\t// F1~F5: lambda\u95A2\u6570\n\ttemplate <typename F1, typename F2, typename\
    \ F3, typename F4, typename F5>\n\tvoid run(F1 &&add_left, F2 &&add_right, F3\
    \ &&del_left, F4 &&del_right, F5 &&out) {\n\t\tassert(q == query_count);\n\t\t\
    vector<int> qi(q);\n\t\tiota(qi.begin(), qi.end(), 0);\n\t\tvector<long long>\
    \ eval(q);\n\t\tfor (int i = 0; i < q; ++i) {\n\t\t\teval[i] = hilbertorder(_l[i],\
    \ _r[i]);\n\t\t}\n\t\tsort(qi.begin(), qi.end(), [&](int i, int j) {\n\t\t\treturn\
    \ eval[i] < eval[j];\n\t\t});\n\t\tint nl = 0, nr = 0;\n\t\tfor (int &i : qi)\
    \ {\n\t\t\twhile (nl > _l[i]) add_left(--nl);\n\t\t\twhile (nr < _r[i]) add_right(nr++);\n\
    \t\t\twhile (nl < _l[i]) del_left(nl++);\n\t\t\twhile (nr > _r[i]) del_right(--nr);\n\
    \t\t\tout(i);\n\t\t}\n\t}\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n// https://ei1333.hateblo.jp/entry/2017/09/11/211011\n\
    // Mo\u304C\u4F7F\u3048\u308B\u6761\u4EF6\n// 1.\u914D\u5217\u306E\u8981\u7D20\
    \u304C\u4E0D\u5909\n// 2.\u30AF\u30A8\u30EA\u5148\u8AAD\u307F\u53EF\u80FD\n//\
    \ 3.[l,r)\u306E\u7D50\u679C\u304B\u3089[l+1,r),[l-1,r),[l,r-1),[l,r+1)\u306E\u7D50\
    \u679C\u3092\u5BB9\u6613\u306B\u8A08\u7B97\u3067\u304D\u308B\n// O(xNsqrt(Q))\n\
    struct Mo {\n\tint n;\n\tvector<pair<int, int> > lr;\n\n\texplicit Mo(int n)\n\
    \t\t: n(n) {\n\t}\n\n\tvoid add(int l, int r) { /* [l, r) */\n\t\tlr.emplace_back(l,\
    \ r);\n\t}\n\n\t// \u8981\u7D20\u306E\u8FFD\u52A0\u3001\u524A\u9664\u304C\u975E\
    \u53EF\u63DB\u306A\u5834\u5408\n\ttemplate <typename AL, typename AR, typename\
    \ EL, typename ER, typename O>\n\tvoid build(const AL &add_left, const AR &add_right,\
    \ const EL &erase_left, const ER &erase_right, const O &out) {\n\t\tint q = (int)lr.size();\n\
    \t\tint bs = n / min<int>(n, sqrt(q));\n\t\tvector<int> ord(q);\n\t\tiota(begin(ord),\
    \ end(ord), 0);\n\t\tsort(begin(ord), end(ord), [&](int a, int b) {\n\t\t\tint\
    \ ablock = lr[a].first / bs, bblock = lr[b].first / bs;\n\t\t\tif (ablock != bblock)\
    \ return ablock < bblock;\n\t\t\treturn (ablock & 1) ? lr[a].second > lr[b].second\
    \ : lr[a].second < lr[b].second;\n\t\t});\n\t\tint l = 0, r = 0;\n\t\tfor (auto\
    \ idx : ord) {\n\t\t\twhile (l > lr[idx].first) add_left(--l);\n\t\t\twhile (r\
    \ < lr[idx].second) add_right(r++);\n\t\t\twhile (l < lr[idx].first) erase_left(l++);\n\
    \t\t\twhile (r > lr[idx].second) erase_right(--r);\n\t\t\tout(idx);\n\t\t}\n\t\
    }\n\n\ttemplate <typename A, typename E, typename O>\n\tvoid build(const A &add,\
    \ const E &erase, const O &out) {\n\t\tbuild(add, add, erase, erase, out);\n\t\
    }\n};\n\nstruct Mo {\n\tint n, q, query_count;\n\tlong long max_n;\n\tvector<int>\
    \ _l, _r;\n\n\tMo(int n, int q) {\n\t\tmax_n = 1 << 25;\n\t\tquery_count = 0;\n\
    \t\t_l.reserve(q);\n\t\t_r.reserve(q);\n\t\tthis->n = n;\n\t\tthis->q = q;\n\t\
    }\n\n\tlong long hilbertorder(int x, int y) {\n\t\tlong long rx, ry, d = 0;\n\t\
    \tfor (long long s = max_n >> 1ll; s; s >>= 1ll) {\n\t\t\trx = (x & s) > 0, ry\
    \ = (y & s) > 0;\n\t\t\td += s * s * ((rx * 3) ^ ry);\n\t\t\tif (ry) continue;\n\
    \t\t\tif (rx) {\n\t\t\t\tx = max_n - 1 - x;\n\t\t\t\ty = max_n - 1 - y;\n\t\t\t\
    }\n\t\t\tswap(x, y);\n\t\t}\n\t\treturn d;\n\t}\n\n\tvoid add_query(int l, int\
    \ r) {\n\t\t++query_count;\n\t\t_l.emplace_back(l);\n\t\t_r.emplace_back(r);\n\
    \t}\n\n\t// F1~F5: lambda\u95A2\u6570\n\ttemplate <typename F1, typename F2, typename\
    \ F3, typename F4, typename F5>\n\tvoid run(F1 &&add_left, F2 &&add_right, F3\
    \ &&del_left, F4 &&del_right, F5 &&out) {\n\t\tassert(q == query_count);\n\t\t\
    vector<int> qi(q);\n\t\tiota(qi.begin(), qi.end(), 0);\n\t\tvector<long long>\
    \ eval(q);\n\t\tfor (int i = 0; i < q; ++i) {\n\t\t\teval[i] = hilbertorder(_l[i],\
    \ _r[i]);\n\t\t}\n\t\tsort(qi.begin(), qi.end(), [&](int i, int j) {\n\t\t\treturn\
    \ eval[i] < eval[j];\n\t\t});\n\t\tint nl = 0, nr = 0;\n\t\tfor (int &i : qi)\
    \ {\n\t\t\twhile (nl > _l[i]) add_left(--nl);\n\t\t\twhile (nr < _r[i]) add_right(nr++);\n\
    \t\t\twhile (nl < _l[i]) del_left(nl++);\n\t\t\twhile (nr > _r[i]) del_right(--nr);\n\
    \t\t\tout(i);\n\t\t}\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/mo.cpp
  requiredBy: []
  timestamp: '2023-11-30 18:16:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/mo.cpp
layout: document
redirect_from:
- /library/algorithm/mo.cpp
- /library/algorithm/mo.cpp.html
title: algorithm/mo.cpp
---
