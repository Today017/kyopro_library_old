#include <tuple>
#include <vector>
#include <algorithm>

/**
 * @brief Strongly Connected Components Decomposition
 */

std::tuple<std::vector<std::vector<int>>, std::vector<std::vector<int>>, std::vector<int>> strongly_connected_components_decomposition(const std::vector<std::vector<int>> &G) {
	int n = G.size();
	std::vector<std::vector<int>> G2(n);
	for (int i = 0; i < n; i++) {
		for (int nxt : G[i]) {
			G2[nxt].push_back(i);
		}
	}
	std::vector<int> order(n), component(n, -1);
	std::vector<bool> vst(n);
	auto F = [&](auto F, int now) -> void {
		vst[now] = true;
		for (int nxt : G[now]) {
			if (!vst[nxt]) {
				F(F, nxt);
			}
		}
		order.push_back(now);
	};
	auto F2 = [&](auto F2, int now, int idx) -> void {
		component[now] = idx;
		for (int nxt : G2[now]) {
			if (component[nxt] == -1) {
				F2(F2, nxt, idx);
			}
		}
	};
	for (int i = 0; i < n; i++) {
		if (!vst[i]) {
			F(F, i);
		}
	}
	int idx = 0;
	std::reverse(order.begin(), order.end());
	for (int now : order) {
		if (component[now] == -1) {
			F2(F2, now, idx);
			idx++;
		}
	}
	int n_n = *std::max_element(component.begin(), component.end()) + 1;
	std::vector<std::vector<int>> ret(n_n);
	for (int i = 0; i < n; i++) {
		ret[component[i]].push_back(i);
	}
	std::vector<std::vector<int>> ret2(n_n);
	for (int i = 0; i < n; i++) {
		for (int j : G[i]) {
			if (component[i] != component[j]) {
				ret2[component[i]].push_back(component[j]);
			}
		}
	}
	for (int i = 0; i < n_n; i++) {
		sort(ret2[i].begin(), ret2[i].end());
		ret2[i].erase(std::unique(ret2[i].begin(), ret2[i].end()), ret2[i].end());
	}
	return std::make_tuple(ret, ret2, component);
}
