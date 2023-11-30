#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include <bits/stdc++.h>
using namespace std;

#include "../../../graph/dsu.cpp"

int main() {
	int N, Q;
	cin >> N >> Q;

	dsu ds(N);

	while (Q--) {
		int t, u, v;
		cin >> t >> u >> v;

		if (t == 0) {
			ds.unite(u, v);
		} else {
			cout << ds.is_united(u, v) << '\n';
		}
	}
}
