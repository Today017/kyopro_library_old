#include <vector>
#include <utility>

/**
 * @brief Lowest Common Ancestor
 * @docs docs/graph/lca.md
 */

struct lowest_common_ancestor {
    lowest_common_ancestor(std::vector<std::vector<int>> &G, int root = 0) {
        int n = G.size();
        int k = 1;
        while ((1 << k) < n) {
            k++;
        }
        parent = std::vector<std::vector<int>>(k, std::vector<int>(n, -1));
        dst = std::vector<int>(n, -1);
        dfs(G, root, -1, 0);
        for (int i = 0; i + 1 < k; i++) {
            for (int j = 0; j < n; j++) {
                if (parent[i][j] < 0) {
                    parent[i + 1][j] = -1;
                } else {
                    parent[i + 1][j] = parent[i][parent[i][j]];
                }
            }
        }
    }
    int lca(int u, int v) {
        if (dst[u] < dst[v]) {
            std::swap(u, v);
        }
        int k = parent.size();
        for (int i = 0; i < k; i++) {
            if ((dst[u] - dst[v]) >> i & 1) {
                u = parent[i][u];
            }
        }
        if (u == v) {
            return u;
        }
        for (int i = k - 1; i >= 0; i--) {
            if (parent[i][u] != parent[i][v]) {
                u = parent[i][u];
                v = parent[i][v];
            }
        }
        return parent[0][u];
    }
    int distance(int u, int v) {
        return dst[u] + dst[v] - 2 * dst[lca(u, v)];
    }
    bool is_on_path(int u, int v, int x) {
        return distance(u, x) + distance(x, v) == distance(u, v);
    }
    int climb(int u, int d) {
        int k = parent.size();
        for (int i = k - 1; i >= 0; i--) {
            if (d >> i & 1) {
                u = parent[i][u];
            }
        }
        return u;
    }

private:
    std::vector<std::vector<int>> parent;
    std::vector<int> dst;
    void dfs(std::vector<std::vector<int>> &G, int now, int pre, int tmp) {
        parent[0][now] = pre;
        dst[now] = tmp;
        for (int nxt : G[now]) {
            if (nxt != pre) {
                dfs(G, nxt, now, tmp + 1);
            }
        }
    }
};
