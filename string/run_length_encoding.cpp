#include <vector>
#include <utility>
#include <string>

/**
 * @brief Run Length Encode
 */

std::vector<std::pair<char, int>> run_length_encoding(std::string s) {
	int n = s.size();
	std::vector<std::pair<char, int>> ret;
	for (int l = 0, r; l < n;) {
		r = l + 1;
		while (r < n && s[l] == s[r]) {
			r++;
		}
		ret.push_back(std::make_pair(s[l], r - l));
		l = r;
	}
	return ret;
}
