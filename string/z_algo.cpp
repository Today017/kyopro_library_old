#include <vector>
#include <string>
#include <algorithm>

/**
 * @brief Z-algorithm
 */

std::vector<int> z_algorithm(std::string s) {
	int n = s.size();
	int c = 0;
	std::vector<int> ret(n, 0);
	for (int i = 1; i < n; i++) {
		int l = i - c;
		if (i + ret[l] < c + ret[c]) {
			ret[i] = ret[l];
		} else {
			int j = std::max(c + ret[c] - i, 0);
			while (i + j < n && s[j] == s[i + j]) {
				j++;
			}
			ret[i] = j;
			c = i;
		}
	}
	ret[0] = n;
	return ret;
}
