#include <iostream>
#include <utility>
#include <vector>
#include <functional>
#include <limits>

/**
 * @brief Segment Tree Lazy
 */

template <typename T, typename U>
struct segment_tree_lazy {
    template <typename F, typename G, typename H>
    segment_tree_lazy(int n, F f, G g, H h, T et, U eu) {
        this->n = 1;
        while (this->n < n) {
            this->n *= 2;
        }
        this->f = f;
        this->g = g;
        this->h = h;
        this->et = et;
        this->eu = eu;
        dat.resize(this->n * 2 - 1, this->et);
        lazy.resize(this->n * 2 - 1, this->eu);
    }
    void build(const std::vector<T> &A) {
        for (int i = 0; i < (int)A.size(); i++) {
            dat[i + n - 1] = A[i];
        }
        for (int i = n - 2; i >= 0; i--) {
            dat[i] = f(dat[i * 2 + 1], dat[i * 2 + 2]);
        }
    }
    void set(int i, T x) {
        evaluate(i);
        i += n - 1;
        dat[i] = x;
        while (i > 0) {
            i = (i - 1) / 2;
            dat[i] = f(dat[i * 2 + 1], dat[i * 2 + 2]);
        }
    }
    void apply(int l, int r, U x) {
        apply(l, r, 0, x, 0, n);
    }
    T query(int l, int r) {
        return query(l, r, 0, 0, n);
    }
    T operator[](int i) {
        return query(i, i + 1, 0, 0, n);
    }
    friend std::ostream &operator<<(std::ostream &os, segment_tree_lazy A) {
        int n = A.n;
        os << "[ ";
        for (int i = 0; i < n; i++) {
            os << A[i];
            if (i != n - 1) {
                os << ", ";
            }
        }
        os << " ]";
        return os;
    }

private:
    int n;
    std::vector<T> dat;
    std::vector<U> lazy;
    using F = std::function<T(T, T)>;
    using G = std::function<T(U, T)>;
    using H = std::function<U(U, U)>;
    F f;
    G g;
    H h;
    T et;
    U eu;
    void evaluate(int i) {
        if (lazy[i] == eu) {
            return;
        }
        if (i < n - 1) {
            lazy[i * 2 + 1] = h(lazy[i], lazy[i * 2 + 1]);
            lazy[i * 2 + 2] = h(lazy[i], lazy[i * 2 + 2]);
        }
        dat[i] = g(lazy[i], dat[i]);
        lazy[i] = eu;
    }
    void apply(int left, int right, int i, U x, int l, int r) {
        evaluate(i);
        if (left <= l && r <= right) {
            lazy[i] = h(x, lazy[i]);
            evaluate(i);
        } else if (left < r && l < right) {
            int mid = (l + r) / 2;
            apply(left, right, i * 2 + 1, x, l, mid);
            apply(left, right, i * 2 + 2, x, mid, r);
            dat[i] = f(dat[i * 2 + 1], dat[i * 2 + 2]);
        }
    }
    T query(int left, int right, int i, int l, int r) {
        evaluate(i);
        if (r <= left || right <= l) {
            return et;
        } else if (left <= l && r <= right) {
            return dat[i];
        } else {
            int mid = (l + r) / 2;
            return f(query(left, right, i * 2 + 1, l, mid), query(left, right, i * 2 + 2, mid, r));
        }
    }
};

template <typename T, typename U>
segment_tree_lazy<T, U> range_add_range_min(int n) {
    const T et = std::numeric_limits<T>::max();
    const U eu = 0;
    auto f = [](T a, T b) {
        return std::min(a, b);
    };
    auto g = [](U f, T x) {
        return f + x;
    };
    auto h = [](U f, U g) {
        return f + g;
    };
    return segment_tree_lazy<T, U>(n, f, g, h, et, eu);
}

template <typename T, typename U>
segment_tree_lazy<T, U> range_add_range_max(int n) {
    const T et = std::numeric_limits<T>::min();
    const U eu = 0;
    auto f = [](T a, T b) {
        return std::max(a, b);
    };
    auto g = [](U f, T x) {
        return f + x;
    };
    auto h = [](U f, U g) {
        return f + g;
    };
    return segment_tree_lazy<T, U>(n, f, g, h, et, eu);
}

template <typename T, typename U>
segment_tree_lazy<std::pair<T, int>, U> range_add_range_sum(int n) {
    using T2 = std::pair<T, int>;
    const T2 et = std::make_pair(T(0), 0);
    const U eu = 0;
    auto f = [](T2 a, T2 b) {
        return std::make_pair(a.first + b.first, a.second + b.second);
    };
    auto g = [](U f, T2 x) {
        return std::make_pair(x.first + (T)f * x.second, x.second);
    };
    auto h = [](U f, U g) {
        return f + g;
    };
    return segment_tree_lazy<T2, U>(n, f, g, h, et, eu);
}

template <typename T>
segment_tree_lazy<T, T> range_update_range_min(int n, T eu = std::numeric_limits<T>::max()) {
    const T et = std::numeric_limits<T>::max();
    auto f = [](T a, T b) {
        return std::min(a, b);
    };
    auto g = [eu](T f, T x) {
        if (f == eu) return x;
        return f;
    };
    return segment_tree_lazy<T, T>(n, f, g, g, et, eu);
}

template <typename T>
segment_tree_lazy<T, T> range_update_range_max(int n, T eu = std::numeric_limits<T>::max()) {
    const T et = std::numeric_limits<T>::min();
    auto f = [](T a, T b) {
        return std::max(a, b);
    };
    auto g = [eu](T f, T x) {
        if (f == eu) return x;
        return f;
    };
    return segment_tree_lazy<T, T>(n, f, g, g, et, eu);
}

template <typename T>
segment_tree_lazy<std::pair<T, int>, T> range_update_range_sum(int n, T eu = std::numeric_limits<T>::max()) {
    using T2 = std::pair<T, int>;
    const T2 et = std::make_pair(T(0), 0);
    auto f = [](T2 a, T2 b) {
        return std::make_pair(a.first + b.first, a.second + b.second);
    };
    auto g = [eu](T f, T2 x) {
        if (f == eu) return x;
        return std::make_pair(f * x.second, x.second);
    };
    auto h = [eu](T f, T g) {
        if (f == eu) return g;
        return f;
    };
    return segment_tree_lazy<T, T>(n, f, g, h, et, eu);
}
