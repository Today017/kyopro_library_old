#include <vector>

/**
 * @brief Fenwick Tree
 * @docs docs/data_structure/fenwick_tree.md
 */

template <typename T>
struct fenwick_tree {
	int n;
	std::vector<T> dat;
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
	T sum(int l, int r) {
		return sum(r) - sum(l);
	}
	T sum(int r) {
		T ret = 0;
		while (r > 0) {
			ret += dat[r - 1];
			r -= r & -r;
		}
		return ret;
	}
	T operator[](int i) {
		return sum(i, i + 1);
	}
};