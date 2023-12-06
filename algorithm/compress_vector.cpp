#include <vector>
#include <algorithm>

template <typename T>
std::vector<T> compress(std::vector<T> &A) {
	int n = A.size();
	std::vector<T> ret(n);
	for (int i = 0; i < n; i++) {
		ret[i] = A[i];
	}
	std::sort(ret.begin(), ret.end());
	ret.erase(std::unique(ret.begin(), ret.end()), ret.end());
	for (int i = 0; i < n; i++) {
		A[i] = std::lower_bound(ret.begin(), ret.end(), A[i]) - ret.begin();
	}
	return ret;
}