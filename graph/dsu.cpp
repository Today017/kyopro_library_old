#include <vector>
#include <utility>

/**
 * @brief Disjoint Set Union
 * @docs docs/graph/dsu.md
 */

struct dsu {
	dsu(int n) {
		par.resize(n);
		sz.resize(n);
		for (int i = 0; i < n; i++) {
			par[i] = i;
			sz[i] = 1;
		}
	}
	int find(int x) {
		if (par[x] == x) {
			return x;
		}
		par[x] = find(par[x]);
		return par[x];
	}
	void unite(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y) {
			return;
		}
		if (sz[x] < sz[y]) {
			std::swap(x, y);
		}
		par[y] = x;
		sz[x] += sz[y];
	}
	int size(int x) {
		return sz[find(x)];
	}
	bool is_united(int x, int y) {
		return find(x) == find(y);
	}

	private:
	std::vector<int> par, sz;
};
