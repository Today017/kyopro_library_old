// Dijkstra法 
// O(Elog(E))
// INF minの単位元
template<typename T>
vector<T> dijkstra(const vector<vector<pair<int, T>>> &G, int start = 0, T INF = LLONG_MAX) {
	int n = G.size();
	vector<T> dst(n, INF);
	priority_queue<pair<T, int>> pq;
	dst[start] = 0;
	pq.push(make_pair(0, start));
	while (!pq.empty()) {
		T dst_sum = pq.top().first;
		int now = pq.top().second;
		pq.pop();
		dst_sum = -dst_sum;
		if (dst[now] < dst_sum) {
			continue;
		}
		for (pair<int, T> P : G[now]) {
			int nxt = P.first;
			T cost = P.second;
			if (dst[nxt] > dst[now] + cost) {
				dst[nxt] = dst[now] + cost;
				pq.push(make_pair(-dst[nxt], nxt));
			}
		}
	}
	return dst;
}
