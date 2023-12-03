#include "data_structure/fenwick_tree.cpp"

/**
 * @brief Inversion Number
 * @docs docs/algorithm/inversion_number.md
*/

long long inversion_number(const vector<int> &A) {
	int n = A.size();
	fenwick_tree<int> ft(n);
	long long ret = 0;
	for (int i = 0; i < n; i++) {
		ret += i - ft.sum(0, A[i]);
		ft.add(A[i], 1);
	}
	return ret;
}
