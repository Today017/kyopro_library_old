#include <vector>
#include <functional>
#include <limits>

/**
 * @brief Segment Tree
 */

template <typename T>
struct segment_tree {
	template<typename F>
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
	T operator[](int i) {
		return dat[n - 1 + i];
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

template <typename U>
segment_tree<U> range_min_query(int n, U e = std::numeric_limits<U>::max()) {
	auto f = [](U a, U b) {
		return std::min(a, b);
	};
	return segment_tree<U>(n, f, e);
}

template <typename U>
segment_tree<U> range_max_query(int n, U e = std::numeric_limits<U>::min()) {
	auto f = [](U a, U b) {
		return std::max(a, b);
	};
	return segment_tree<U>(n, f, e);
}

template <typename U>
segment_tree<U> range_sum_query(int n, U e = 0) {
	auto f = [](U a, U b) {
		return a + b;
	};
	return segment_tree<U>(n, f, e);
}
