#include <bits/stdc++.h>
using namespace std;

vector<pair<char, int>> run_length_encoding(string s) {
	int n = s.size();
	vector<pair<char, int>> ret;
	for (int l = 0, r; l < n;) {
		r = l + 1;
		while (r < n && s[l] == s[r]) {
			r++;
		}
		ret.push_back(make_pair(s[l], r - l));
		l = r;
	}
	return ret;
}
