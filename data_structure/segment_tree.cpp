#include <iostream>
#include <vector>
#include <functional>
#include <limits>

/**
 * @brief Segment Tree
 */

template <typename T>
struct segment_tree {
    template <typename F>
    segment_tree(int n, F f, T e) {
        this->n = 1;
        while (this->n < n) {
            this->n *= 2;
        }
        this->f = f;
        this->e = e;
        dat.resize(this->n * 2 - 1, e);
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
        i += n - 1;
        dat[i] = x;
        while (i > 0) {
            i = (i - 1) / 2;
            dat[i] = f(dat[i * 2 + 1], dat[i * 2 + 2]);
        }
    }
    T query(int l, int r) {
        return query(l, r, 0, 0, n);
    }
    T operator[](int i) {
        return dat[n - 1 + i];
    }
    friend std::ostream &operator<<(std::ostream &os, segment_tree A) {
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
    using F = std::function<T(T, T)>;
    F f;
    T e;
    T query(int left, int right, int i, int l, int r) {
        if (r <= left || right <= l) {
            return e;
        } else if (left <= l && r <= right) {
            return dat[i];
        } else {
            int mid = (l + r) / 2;
            return f(query(left, right, i * 2 + 1, l, mid), query(left, right, i * 2 + 2, mid, r));
        }
    }
};

template <typename T>
segment_tree<T> range_min_query(int n, T e = std::numeric_limits<T>::max()) {
    auto f = [](T a, T b) {
        return std::min(a, b);
    };
    return segment_tree<T>(n, f, e);
}

template <typename T>
segment_tree<T> range_max_query(int n, T e = std::numeric_limits<T>::min()) {
    auto f = [](T a, T b) {
        return std::max(a, b);
    };
    return segment_tree<T>(n, f, e);
}

template <typename T>
segment_tree<T> range_sum_query(int n, T e = 0) {
    auto f = [](T a, T b) {
        return a + b;
    };
    return segment_tree<T>(n, f, e);
}
