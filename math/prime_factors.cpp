vector<long long> prime_factors(long long n) {
	vector<long long> ret;
	for (long long i = 2; i * i <= n; i++) {
		if (n % i != 0) {
			continue;
		}
		while (n % i == 0) {
			n /= i;
		}
		ret.push_back(i);
	}
	if (n != 1) {
		ret.push_back(n);
	}
	return ret;
}