#include <bits/stdc++.h>
using namespace std;

/**
 * vector<int> sz :
 * 	頂点の部分木の大きさ
 * vector<int> parent :
 * 	頂点の親
 * vector<int> depth :
 * 	頂点の深さ
 * vector<int> hld :
 * 	HLDした結果の配列
 * vector<int> pos :
 * 	元の頂点の位置
 * vector<int> head :
 * 	頂点の属する連結成分の最も浅い頂点
*/

// heavy-light decomposition
// https://hcpc-hokudai.github.io/archive/graph_tree_001.pdf
// https://atcoder.jp/contests/abc294/submissions/46419196
struct hld_graph {
	vector<vector<int>> G;
	vector<int> sz, parent, depth, hld, pos, head;
	hld_graph(int n) {
		G.resize(n);
		sz.resize(n);
		parent.resize(n);
		depth.resize(n);
		pos.resize(n);
		head.resize(n);
	}
	void add_edge(int a, int b) {
		G[a].push_back(b);
		G[b].push_back(a);
	}
	hld_graph(const vector<vector<int>>& G) {
		int n = G.size();
		this->G = G;
		sz.resize(n);
		parent.resize(n);
		depth.resize(n);
		pos.resize(n);
		head.resize(n);
	}
	vector<int> hld_start(int root = 0) {
		dfs1(root);
		dfs2(root);
		dfs(root, root);
		return hld;
	}
	void dfs(int now, int a, int pre = -1) {
		pos[now] = hld.size();
		hld.push_back(now);
		head[now] = a;
		if (sz[now] == 1) {
			return;
		}
		int mx = 0;
		int mx_idx = 0;
		for (int nxt : G[now]) {
			if (nxt == pre) {
				continue;
			}
			if (mx < sz[nxt]) {
				mx = sz[nxt];
				mx_idx = nxt;
			}
		}
		dfs(mx_idx, a, now);
		for (int nxt : G[now]) {
			if (nxt == pre) {
				continue;
			}
			if (nxt == mx_idx) {
				continue;
			}
			dfs(nxt, nxt, now);
		}
	}
	void dfs1(int now, int pre = -1) {
		int res = 1;
		for (int nxt : G[now]) {
			if (nxt == pre) {
				continue;
			}
			dfs1(nxt, now);
			res += sz[nxt];
		}
		sz[now] = res;
	}
	void dfs2(int now, int pre = -1) {
		parent[now] = pre;
		for (int nxt : G[now]) {
			if (nxt == pre) {
				continue;
			}
			depth[nxt] = depth[now] + 1;
			dfs2(nxt, now);
		}
	}
	int lca(int u, int v) {
		while (head[u] != head[v]) {
			if (depth[head[u]] > depth[head[v]]) {
				u = parent[head[u]];
			} else {
				v = parent[head[v]];
			}
		}
		return depth[u] < depth[v] ? u : v;
	}
	// Update(x, pos_x) 頂点xに対する処理
	// pos_x            頂点xのHLD後の位置
	// 列を管理するデータ構造Aに対して、xに対しての処理をUpdate内でA[pos_x]に対して行う
	template <typename U>
	void update(int x, U& Update) {
		Update(x, pos[x]);
	}
	// u, v         処理/取得を行うパス
	// Query(x, y)  区間[x,y)に対する処理
	// F            演算
	// e            Fの単位元
	// 列を管理するデータ構造Aに対して、x,yに対しての処理/取得をQuery内で行う
	// 演算結果をFでまとめる
	template <typename Q, typename F, typename T>
	T query(int u, int v, Q& Query, F& f, T e) {
		T ret = e;
		while (head[u] != head[v]) {
			if (depth[head[u]] < depth[head[v]]) {
				swap(u, v);
			}
			ret = f(ret, Query(pos[head[u]], pos[u] + 1));
			u = parent[head[u]];
		}
		if (depth[u] > depth[v]) {
			swap(u, v);
		}
		ret = f(ret, Query(pos[u], pos[v] + 1));
		return ret;
	}
};
