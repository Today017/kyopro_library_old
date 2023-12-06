#include <vector>

/**
 * @brief 木の深さ
 */

std::vector<int> tree_depth(std::vector<std::vector<int>> &G, int root = 0) {
	int n = G.size();
	std::vector<int> depth(n);
	auto dfs = [&](auto &&dfs, int now, int pre) -> void {
		for (int nxt : G[now]) {
			if (nxt != pre) {
				depth[nxt] = depth[now] + 1;
				dfs(dfs, nxt, now);
			}
		}
	};
	dfs(dfs, root, -1);
	return depth;
}