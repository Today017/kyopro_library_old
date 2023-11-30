#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct segtree {
	int n;
	vector<T> dat;
	function<T(T, T)> f;
	T e;
	segtree(int n, function<T(T, T)> f, T e) {
		this->n = 1;
		while (this->n < n) {
			this->n *= 2;
		}
		dat.resize(this->n * 2 - 1, e);
		this->f = f;
		this->e = e;
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
	T query(int l, int r) {
		return query(l, r, 0, 0, n);
	}
};

#include <bits/stdc++.h>
using namespace std;

struct segment_tree {
	int n;
	vector<int> dat;
	segment_tree(int n) {
		this->n = 1;
		while (this->n < n) {
			this->n *= 2;
		}
		dat.resize(this->n * 2 - 1, INT_MAX);
	}
	int operator[](int i) {
		return dat[n - 1 + i];
	}
	void set(int i, int x) {
		i += n - 1;
		dat[i] = x;
		while (i > 0) {
			i = (i - 1) / 2;
			dat[i] = min(dat[i * 2 + 1], dat[i * 2 + 2]);
		}
	}
	int query(int left, int right, int i, int l, int r) {
		if (r <= left || right <= l) {
			return INT_MAX;
		} else if (left <= l && r <= right) {
			return dat[i];
		} else {
			int mid = (l + r) / 2;
			return min(query(left, right, i * 2 + 1, l, mid), query(left, right, i * 2 + 2, mid, r));
		}
	}
	int query(int l, int r) {
		return query(l, r, 0, 0, n);
	}
};
