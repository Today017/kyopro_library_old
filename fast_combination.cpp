#include <bits/stdc++.h>
using namespace std;

template <typename T>
vector<vector<T>> combination(int n) {
	vector<vector<T>> nCr(n + 1, vector<T>(n + 1));
	for (int i = 0; i <= n; i++) {
		nCr[i][0] = nCr[i][i] = 1;
		for (int j = 1; j < i; j++) {
			nCr[i][j] = nCr[i - 1][j - 1] + nCr[i - 1][j];
		}
	}
	return nCr;
}