#include <vector>
#include <algorithm>
#include <climits>

int longest_increasing_subsequence_length(std::vector<int> &A, bool strict = true) {
	int n = A.size();
	std::vector<int> dp(n, INT_MAX);
	for (int i = 0; i < n; i++) {
		std::vector<int>::iterator itr;
		if (strict) {
			itr = lower_bound(dp.begin(), dp.end(), A[i]);
		} else {
			itr = upper_bound(dp.begin(), dp.end(), A[i]);
		}
		*itr = A[i];
	}
	return find(dp.begin(), dp.end(), INT_MAX) - dp.begin();
}
