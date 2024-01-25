#include <limits>
#include <tuple>
#include <utility>
#include <vector>

/**
 * @brief Min Cost Flow
 */

template <typename Cap, typename Cost>
struct min_cost_flow {
    min_cost_flow(int n) {
        this->n = n;
        this->G.resize(n);
    }
    void add_edge(int u, int v, Cap cap, Cost cost) {
        G[u].push_back(std::make_tuple(v, cap, cost, (int)G[v].size()));
        G[v].push_back(std::make_tuple(u, 0, -cost, (int)G[u].size() - 1));
    }
    Cost get_min_cost_flow(int start, int goal, Cap flow) {
        Cost ret = 0;
        while (flow > 0) {
            std::vector<Cost> dst;
            std::vector<int> pre_vertex, pre_edge;
            std::tie(dst, pre_vertex, pre_edge) = calculate_cost(start);
            if (dst[goal] == std::numeric_limits<Cost>::max()) {
                return std::numeric_limits<Cost>::max();
            }
            Cap now_flow = flow;
            int now_vertex = goal;
            while (now_vertex != start) {
                now_flow = min(now_flow, std::get<1>(G[pre_vertex[now_vertex]][pre_edge[now_vertex]]));
                now_vertex = pre_vertex[now_vertex];
            }
            ret += now_flow * dst[goal];
            flow -= now_flow;
            now_vertex = goal;
            while (now_vertex != start) {
                std::get<1>(G[pre_vertex[now_vertex]][pre_edge[now_vertex]]) -= now_flow;
                int rev = std::get<3>(G[pre_vertex[now_vertex]][pre_edge[now_vertex]]);
                std::get<1>(G[now_vertex][rev]) += now_flow;
                now_vertex = pre_vertex[now_vertex];
            }
        }
        return ret;
    }

private:
    int n;
    std::vector<std::vector<std::tuple<int, Cap, Cost, int>>> G;
    std::tuple<std::vector<Cost>, std::vector<int>, std::vector<int>> calculate_cost(int start) {
        std::vector<Cost> dst(n, std::numeric_limits<Cost>::max());
        std::vector<int> pre_vertex(n, 0), pre_edge(n, 0);
        dst[start] = 0;
        while (true) {
            bool update = false;
            for (int i = 0; i < n; i++) {
                if (dst[i] == std::numeric_limits<Cost>::max()) {
                    continue;
                }
                for (int j = 0; j < (int)G[i].size(); j++) {
                    int nxt;
                    Cap cap;
                    Cost cost;
                    std::tie(nxt, cap, cost, std::ignore) = G[i][j];
                    if (cap > 0 && dst[nxt] > dst[i] + cost) {
                        dst[nxt] = dst[i] + cost;
                        update = true;
                        pre_vertex[nxt] = i;
                        pre_edge[nxt] = j;
                    }
                }
            }
            if (!update) {
                break;
            }
        }
        return std::make_tuple(dst, pre_vertex, pre_edge);
    }
};
