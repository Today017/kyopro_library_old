#include <vector>
#include <string>

/**
 * @brief Manacher
 */

std::vector<int> manacher(std::string s) {
	int n = s.size();
	int c = 0;
	std::vector<int> ret(n, 1);
	for (int i = 0; i < n; i++) {
		int l = 2 * c - i;
		if (i + ret[l] < c + ret[c]) {
			ret[i] = ret[l];
		} else {
			int j = c + ret[c] - i;
			while (i - j >= 0 && i + j < n && s[i - j] == s[i + j]) {
				j++;
			}
			ret[i] = j;
			c = i;
		}
	}
	return ret;
}
