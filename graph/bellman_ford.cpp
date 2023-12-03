// ベルマンフォード法 (負のコストの辺を含む重み付き有向グラフに対して、単一始点最短経路問題を解く)
// O(NM)
// return 負のサイクルが存在しないか否か
bool bellman_ford(const vector<tuple<int, int, long long>> &E, int n, int start, vector<long long> &dst, long long INF = LLONG_MAX) {
	dst = vector<long long>(n, INF);
	dst[start] = 0;
	int cnt = 0;
	while (cnt < n) {
		bool fin = true;
		for (tuple<int, int, long long> T : E) {
			int a, b;
			long long c;
			tie(a, b, c) = T;
			if (dst[a] != INF && dst[a] + c < dst[b]) {
				dst[b] = dst[a] + c;
				fin = false;
			}
		}
		if (fin) {
			break;
		}
		cnt++;
	}
	return cnt == n;
}