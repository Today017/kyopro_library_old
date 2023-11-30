#include <bits/stdc++.h>
using namespace std;

struct topological_sort_graph {
	int n;
	vector<vector<int>> G;
	vector<int> indeg;
	vector<int> sorted;
	bool is_u = true;
	topological_sort_graph(int n) {
		this->n = n;
		G.resize(n);
		indeg.resize(n);
	}
	void add_edge(int from, int to) {
		G[from].push_back(to);
		indeg[to]++;
	}
	topological_sort_graph(const vector<vector<int>> &G) {
		n = G.size();
		this->G = G;
		indeg.resize(n);
		for (int i = 0; i < n; i++) {
			for (int nxt : G[i]) {
				indeg[nxt]++;
			}
		}
	}
	// トポロジカルソート
	vector<int> sort() {
		vector<int> _indeg = indeg;
		sorted.clear();
		queue<int> q;
		for (int i = 0; i < n; i++) {
			if (_indeg[i] == 0) {
				q.push(i);
			}
		}
		while (!q.empty()) {
			int now = q.front();
			q.pop();
			is_u &= q.size() == 0;
			for (int nxt : G[now]) {
				_indeg[nxt]--;
				if (_indeg[nxt] == 0) {
					q.push(nxt);
				}
			}
			sorted.push_back(now);
		}
		return sorted;
	}
	// 辞書順最大のトポロジカルソート
	vector<int> sort_max() {
		vector<int> _indeg = indeg;
		sorted.clear();
		priority_queue<int> q;
		for (int i = 0; i < n; i++) {
			if (_indeg[i] == 0) {
				q.push(i);
			}
		}
		while (!q.empty()) {
			int now = q.top();
			q.pop();
			for (int nxt : G[now]) {
				_indeg[nxt]--;
				if (_indeg[nxt] == 0) {
					q.push(nxt);
				}
			}
			sorted.push_back(now);
		}
		return sorted;
	}
	// 辞書順最小のトポロジカルソート
	vector<int> sort_min() {
		vector<int> _indeg = indeg;
		sorted.clear();
		priority_queue<int> q;
		for (int i = 0; i < n; i++) {
			if (_indeg[i] == 0) {
				q.push(-i);
			}
		}
		while (!q.empty()) {
			int now = -q.top();
			q.pop();
			for (int nxt : G[now]) {
				_indeg[nxt]--;
				if (_indeg[nxt] == 0) {
					q.push(-nxt);
				}
			}
			sorted.push_back(now);
		}
		return sorted;
	}
	// 閉路検出
	bool is_closed() {
		return sorted.size() != n;
	}
	// トポロジカルソートが一意であるか
	bool is_unique() {
		return is_u;
	}
};