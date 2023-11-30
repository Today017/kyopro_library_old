#include <bits/stdc++.h>
using namespace std;

template <typename T>
vector<T> compress(vector<T> &A) {
	int n = A.size();
	vector<T> ret(n);
	for (int i = 0; i < n; i++) {
		ret[i] = A[i];
	}
	sort(ret.begin(), ret.end());
	ret.erase(unique(ret.begin(), ret.end()), ret.end());
	for (int i = 0; i < n; i++) {
		A[i] = lower_bound(ret.begin(), ret.end(), A[i]) - ret.begin();
	}
	return ret;
}