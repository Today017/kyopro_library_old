struct range_update_query {
	int n;
	int t;
	vector<pair<int, int>> dat;
	range_update_query(int n) {
		this->n = 1;
		while (this->n < n) {
			this->n *= 2;
		}
		this->t = 0;
		dat.resize(this->n * 2 - 1, make_pair(0, -1));
	}
	int operator[](int i) {
		i += n - 1;
		int ret = dat[i].first;
		int last = dat[i].second;
		while (i > 0) {
			i = (i - 1) / 2;
			if (dat[i].second > last) {
				last = dat[i].second;
				ret = dat[i].first;
			}
		}
	}
	void query(int left, int right, int i, int c, int l, int r) {
		if (r <= left || right <= l) {
			return;
		} else if (left <= l && r <= right) {
			dat[i] = make_pair(c, t);
		} else {
			int mid = (l + r) / 2;
			query(left, right, i * 2 + 1, c, l, mid);
			query(left, right, i * 2 + 2, c, mid, r);
		}
	}
	void query(int l, int r, int c) {
		query(l, r, 0, c, 0, n);
		t++;
	}
};
