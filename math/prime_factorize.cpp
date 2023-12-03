vector<pair<long long, int>> prime_factorize(long long n) {
	vector<pair<long long, int>> ret;
	for (long long i = 2; i * i <= n; i++) {
		if (n % i != 0) {
			continue;
		}
		int ex = 0;
		while (n % i == 0) {
			ex++;
			n /= i;
		}
		ret.push_back({i, ex});
	}
	if (n != 1) {
		ret.push_back({n, 1});
	}
	return ret;
}