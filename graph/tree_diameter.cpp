#include <vector>
#include <algorithm>

/**
 * @brief 木の直径
 */

std::vector<int> tree_diameter(std::vector<std::vector<int>>& G) {
    int n = G.size();
    const int INF = 1001001001;
    std::vector<int> dst(n, INF);
    dst[0] = 0;
    auto F1 = [&](auto&& F1, int now, int pre) -> void {
        for (int nxt : G[now]) {
            if (nxt != pre) {
                dst[nxt] = dst[now] + 1;
                F1(F1, nxt, now);
            }
        }
    };
    F1(F1, 0, -1);
    int l = std::max_element(dst.begin(), dst.end()) - dst.begin();
    dst = std::vector<int>(n, INF);
    dst[l] = 0;
    F1(F1, l, -1);
    int r = max_element(dst.begin(), dst.end()) - dst.begin();
    std::vector<int> path;
    auto F2 = [&](auto&& F2, int now, int pre) -> bool {
        if (now == l) {
            path.push_back(now);
            return true;
        }
        bool ret = false;
        for (int nxt : G[now]) {
            if (nxt != pre) {
                if (F2(F2, nxt, now)) {
                    ret = true;
                }
            }
        }
        if (ret) {
            path.push_back(now);
        }
        return ret;
    };
    F2(F2, r, -1);
    return path;
}