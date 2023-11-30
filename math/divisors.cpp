#include <bits/stdc++.h>
using namespace std;

vector<long long> divisors(long long n) {
	vector<long long> ret;
	for (long long i = 1; i * i <= n; i++) {
		if (n % i) {
			continue;
		}
		ret.push_back(i);
		if (n / i != i) {
			ret.push_back(n / i);
		}
	}
	sort(ret.begin(), ret.end());
	return ret;
}