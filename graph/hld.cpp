#include <vector>

/**
 * @brief Heavy-Light Decomposition
 * @docs docs/graph/hld.md
 */

struct heavy_light_decomposition {
	heavy_light_decomposition(int n) {
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
	heavy_light_decomposition(const std::vector<std::vector<int>>& G) {
		int n = G.size();
		this->G = G;
		sz.resize(n);
		parent.resize(n);
		depth.resize(n);
		pos.resize(n);
		head.resize(n);
	}
	std::vector<int> hld_start(int root = 0) {
		dfs1(root);
		dfs2(root);
		dfs(root, root);
		return hld;
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
	template <typename U>
	void update(int x, U& Update) {
		Update(x, pos[x]);
	}
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

	private:
	std::vector<std::vector<int>> G;
	std::vector<int> sz, parent, depth, hld, pos, head;
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
};
