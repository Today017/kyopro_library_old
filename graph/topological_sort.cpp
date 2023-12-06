#include <vector>
#include <queue>

/**
 * @brief Topological Sort
 */

std::vector<int> topological_sort(const std::vector<std::vector<int>> &G) {
	int n = G.size();
	std::vector<int> indeg(n);
	for (int i = 0; i < n; i++) {
		for (int nxt : G[i]) {
			indeg[nxt]++;
		}
	}
	std::queue<int> Q;
	for (int i = 0; i < n; i++) {
		if (indeg[i] == 0) {
			Q.push(i);
		}
	}
	std::vector<int> ret;
	while (!Q.empty()) {
		int now = Q.front();
		Q.pop();
		for (int nxt : G[now]) {
			indeg[nxt]--;
			if (indeg[nxt] == 0) {
				Q.push(nxt);
			}
		}
		ret.push_back(now);
	}
	return ret;
}
