#include <bits/stdc++.h>
using namespace std;

// Dijkstra法 
// O(Mlog(N)) (M:辺の本数, N:頂点数)
// INF minの単位元
template<typename T>
struct dijkstra_graph {
	T INF;
	int n;
	vector<vector<pair<int, T>>> G;
	dijkstra_graph(int n) {
		this->n = n;
		G.resize(n);
	};
	void add_edge(int from, int to, T cost) {
		G[from].push_back(make_pair(to, cost));
	}
	dijkstra_graph(const vector<vector<pair<int, T>>> &G, T INF = LLONG_MAX) {
		n = G.size();
		this->G = G;
		this->INF = INF;
	}
	vector<T> dijkstra(int start) {
		vector<T> dst(n, this->INF);
		priority_queue<pair<T, int>> pq;
		dst[start] = 0;
		pq.push(make_pair(0, start));
		while (!pq.empty()) {
			T dst_sum = -pq.top().first;
			int now = pq.top().second;
			pq.pop();
			if (dst[now] < dst_sum) {
				continue;
			}
			for (pair<int, T> P : G[now]) {
				int nxt = P.first;
				int cost = P.second;
				if (dst[nxt] > dst[now] + cost) {
					dst[nxt] = dst[now] + cost;
					pq.push(make_pair(-dst[nxt], nxt));
				}
			}
		}
		return dst;
	}
};