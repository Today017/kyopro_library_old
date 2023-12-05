/**
 * @brief Z-algorithm
*/

vector<int> z_algorithm(string s) {
	int n = s.size();
	int c = 0;
	vector<int> ret(n, 0);
	for (int i = 1; i < n; i++) {
		int l = i - c;
		if (i + ret[i] < c + ret[c]) {
			ret[i] = ret[l];
		} else {
			int j = max(c + ret[c] - i, 0);
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
