#include <vector>
#include <utility>

/**
 * @brief Quotient Ranges
 */

template <typename T>
std::vector<std::pair<std::pair<T, T>, T>> quotient_ranges(T n) {
    std::vector<std::pair<std::pair<T, T>, T>> ret;
    T l = 1;
    while (l <= n) {
        T q = n / l;
        T r = n / q + 1;
        ret.push_back(std::make_pair(l, r), q);
        l = r;
    }
    return ret;
}
