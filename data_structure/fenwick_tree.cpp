#include <iostream>
#include <vector>

/**
 * @brief Fenwick Tree
 * @docs docs/data_structure/fenwick_tree.md
 */

template <typename T>
struct fenwick_tree {
    fenwick_tree(int n) {
        this->n = n;
        dat.resize(n);
    }
    void add(int i, T x) {
        i++;
        while (i <= n) {
            dat[i - 1] += x;
            i += i & -i;
        }
    }
    T operator[](int i) {
        return sum(i, i + 1);
    }
    T sum(int l, int r) {
        return sum(r) - sum(l);
    }
    friend std::ostream &operator<<(std::ostream &os, fenwick_tree A) {
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
    T sum(int r) {
        T ret = 0;
        while (r > 0) {
            ret += dat[r - 1];
            r -= r & -r;
        }
        return ret;
    }
};