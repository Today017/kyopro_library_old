#include <bits/stdc++.h>
using namespace std;

template <class T>
using matrix = vector<vector<T>>;
template <class T>
matrix<T> make_matrix(int n) {
	vector<vector<T>> ret(n, vector<T>(n));
	return ret;
}
template <class T>
matrix<T> operator*(const matrix<T>& a, const matrix<T>& b) {
	int n = a.size();
	matrix<T> ret(n, vector<T>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				ret[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	return ret;
}
template <class T>
matrix<T> operator^(matrix<T> a, long long b) {
	int n = a.size();
	matrix<T> ret(n, vector<T>(n));
	for (int i = 0; i < n; i++) {
		ret[i][i] = 1;
	}
	while (b > 0) {
		if (b % 2 == 1) {
			ret = ret * a;
		}
		a = a * a;
		b /= 2;
	}
	return ret;
}
