struct rolling_hash {
	const long long base = 1000000007;
	const long long mod = 998244353;
	vector<long long> hashed, power;
	rolling_hash(string s) {
		int n = s.size();
		hashed.resize(n + 1);
		power.resize(n + 1);
		power[0] = 1;
		for (int i = 0; i < n; i++) {
			power[i + 1] = power[i] * base % mod;
			hashed[i + 1] = ((hashed[i] * base) + (s[i] - 'a')) % mod;
		}
	}
	long long hash(int l, int r) {
		long long ret = mod + hashed[r] - (hashed[l] * power[r - l]) % mod;
		ret %= mod;
		return ret;
	}
};