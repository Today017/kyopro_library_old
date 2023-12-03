vector<vector<int>> strongly_connected_components_decomposition(const vector<vector<int>> &G) {
	int n = G.size();
	vector<vector<int>> G2(n);
	for (int i = 0; i < n; i++) {
		for (int nxt : G[i]) {
			G2[nxt].push_back(i);
		}
	}
	vector<int> order(n), component(n, -1);
	vector<bool> vst(n);
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
	reverse(order.begin(), order.end());
	for (int now : order) {
		if (component[now] == -1) {
			F2(F2, now, idx);
			idx++;
		}
	}
	int n_n = *max_element(component.begin(), component.end()) + 1;
	vector<vector<int>> ret(n_n);
	for (int i = 0; i < n; i++) {
		ret[component[i]].push_back(i);
	}
	return ret;
}