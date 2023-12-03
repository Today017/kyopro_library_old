#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include <bits/stdc++.h>
using namespace std;

#include "../../../graph/lca.cpp"

int main() {
	int N, Q;
	cin >> N >> Q;

	vector<vector<int>> G(N);
	for (int i = 1; i < N; i++) {
		int p;
		cin >> p;
		G[p].push_back(i);
		G[i].push_back(p);
	}

	lowest_common_ancestor lca(G);

	while (Q--) {
		int u, v;
		cin >> u >> v;

		cout << lca.lca(u, v) << '\n';
	}
}