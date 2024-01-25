#include <vector>
#include <queue>
#include <utility>
#include <limits>

/**
 * @brief Dijkstra
 * @attention O(Elog(E))
 */

template <typename T>
std::vector<T> dijkstra(const std::vector<std::vector<std::pair<int, T>>> &G, int start = 0, T INF = std::numeric_limits<T>::max()) {
    int n = G.size();
    std::vector<T> dst(n, INF);
    std::priority_queue<std::pair<T, int>> pq;
    dst[start] = 0;
    pq.push(std::make_pair(0, start));
    while (!pq.empty()) {
        T dst_sum = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        dst_sum = -dst_sum;
        if (dst[now] < dst_sum) {
            continue;
        }
        for (std::pair<int, T> P : G[now]) {
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
