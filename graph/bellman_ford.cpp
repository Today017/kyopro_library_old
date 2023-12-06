#include <vector>
#include <tuple>
#include <climits>

/**
 * @brief Bellman Ford
 * @attention O(VE)
 * @return 負のサイクルを含むか否か
 */

template <typename T>
bool bellman_ford(const std::vector<std::tuple<int, int, T>> &E, int n, int start, std::vector<T> &dst, T INF = LLONG_MAX) {
	dst = std::vector<T>(n, INF);
	dst[start] = 0;
	int cnt = 0;
	while (cnt < n) {
		bool fin = true;
		for (std::tuple<int, int, T> T : E) {
			int a, b;
			T c;
			std::tie(a, b, c) = T;
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