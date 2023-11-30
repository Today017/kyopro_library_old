#include <bits/stdc++.h>
using namespace std;

// https://ei1333.hateblo.jp/entry/2017/09/11/211011
// Moが使える条件
// 1.配列の要素が不変
// 2.クエリ先読み可能
// 3.[l,r)の結果から[l+1,r),[l-1,r),[l,r-1),[l,r+1)の結果を容易に計算できる
// O(xNsqrt(Q))
struct Mo {
	int n;
	vector<pair<int, int> > lr;

	explicit Mo(int n)
		: n(n) {
	}

	void add(int l, int r) { /* [l, r) */
		lr.emplace_back(l, r);
	}

	// 要素の追加、削除が非可換な場合
	template <typename AL, typename AR, typename EL, typename ER, typename O>
	void build(const AL &add_left, const AR &add_right, const EL &erase_left, const ER &erase_right, const O &out) {
		int q = (int)lr.size();
		int bs = n / min<int>(n, sqrt(q));
		vector<int> ord(q);
		iota(begin(ord), end(ord), 0);
		sort(begin(ord), end(ord), [&](int a, int b) {
			int ablock = lr[a].first / bs, bblock = lr[b].first / bs;
			if (ablock != bblock) return ablock < bblock;
			return (ablock & 1) ? lr[a].second > lr[b].second : lr[a].second < lr[b].second;
		});
		int l = 0, r = 0;
		for (auto idx : ord) {
			while (l > lr[idx].first) add_left(--l);
			while (r < lr[idx].second) add_right(r++);
			while (l < lr[idx].first) erase_left(l++);
			while (r > lr[idx].second) erase_right(--r);
			out(idx);
		}
	}

	template <typename A, typename E, typename O>
	void build(const A &add, const E &erase, const O &out) {
		build(add, add, erase, erase, out);
	}
};

struct Mo {
	int n, q, query_count;
	long long max_n;
	vector<int> _l, _r;

	Mo(int n, int q) {
		max_n = 1 << 25;
		query_count = 0;
		_l.reserve(q);
		_r.reserve(q);
		this->n = n;
		this->q = q;
	}

	long long hilbertorder(int x, int y) {
		long long rx, ry, d = 0;
		for (long long s = max_n >> 1ll; s; s >>= 1ll) {
			rx = (x & s) > 0, ry = (y & s) > 0;
			d += s * s * ((rx * 3) ^ ry);
			if (ry) continue;
			if (rx) {
				x = max_n - 1 - x;
				y = max_n - 1 - y;
			}
			swap(x, y);
		}
		return d;
	}

	void add_query(int l, int r) {
		++query_count;
		_l.emplace_back(l);
		_r.emplace_back(r);
	}

	// F1~F5: lambda関数
	template <typename F1, typename F2, typename F3, typename F4, typename F5>
	void run(F1 &&add_left, F2 &&add_right, F3 &&del_left, F4 &&del_right, F5 &&out) {
		assert(q == query_count);
		vector<int> qi(q);
		iota(qi.begin(), qi.end(), 0);
		vector<long long> eval(q);
		for (int i = 0; i < q; ++i) {
			eval[i] = hilbertorder(_l[i], _r[i]);
		}
		sort(qi.begin(), qi.end(), [&](int i, int j) {
			return eval[i] < eval[j];
		});
		int nl = 0, nr = 0;
		for (int &i : qi) {
			while (nl > _l[i]) add_left(--nl);
			while (nr < _r[i]) add_right(nr++);
			while (nl < _l[i]) del_left(nl++);
			while (nr > _r[i]) del_right(--nr);
			out(i);
		}
	}
};
