#include <vector>
#include <queue>
#include <tuple>
#include <limits>

/**
 * @brief Max Flow
 */

template <typename Cap>
struct max_flow {
	max_flow(int n) {
		this->n = n;
		G.resize(n);
	}
	void add_edge(int u, int v, Cap c) {
		G[u].push_back(std::make_tuple(v, G[v].size(), c));
		G[v].push_back(std::make_tuple(u, (int)G[u].size() - 1, 0));
	}
	Cap get_max_flow(int start, int goal) {
		Cap ret = 0;
		while (true) {
			vector<int> dst = calculate_distance(start);
			if (dst[goal] < 0) {
				return ret;
			}
			vector<int> removed(n, 0);
			while (true) {
				Cap add = flowing(start, goal, std::numeric_limits<Cap>::max(), removed, dst);
				if (add == 0) {
					break;
				}
				ret += add;
			}
		}
		return ret;
	}

	private:
	int n;
	std::vector<std::vector<std::tuple<int, int, Cap>>> G;
	vector<int> calculate_distance(int start) {
		std::vector<int> dst(n, -1);
		dst[start] = 0;
		std::queue<int> que;
		que.push(start);
		while (!que.empty()) {
			int now = que.front();
			que.pop();
			for (std::tuple<int, int, Cap> tup : G[now]) {
				int nxt;
				Cap cap;
				std::tie(nxt, ignore, cap) = tup;
				if (cap > 0 && dst[nxt] == -1) {
					dst[nxt] = dst[now] + 1;
					que.push(nxt);
				}
			}
		}
		return dst;
	}
	Cap flowing(int now, int goal, Cap limit, std::vector<int> &removed, std::vector<int> &dst) {
		if (now == goal) {
			return limit;
		}
		while (removed[now] < (int)G[now].size()) {
			int nxt, rev;
			Cap cap;
			std::tie(nxt, rev, cap) = G[now][removed[now]];
			if (cap > 0 && dst[now] < dst[nxt]) {
				Cap flow = flowing(nxt, goal, std::min(limit, cap), removed, dst);
				if (flow > 0) {
					std::get<2>(G[now][removed[now]]) -= flow;
					std::get<2>(G[nxt][rev]) += flow;
					return flow;
				}
			}
			removed[now]++;
		}
		return 0;
	}
};
