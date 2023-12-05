#include "mod/modint.cpp"

/**
 * @brief Combination
 */

template <typename T>
struct combination {
	vector<T> fact, factinv;
	combination(int n) {
		fact.resize(n + 1);
		factinv.resize(n + 1);
		fact[0] = 1;
		for (int i = 1; i <= n; i++) {
			fact[i] = fact[i - 1] * i;
		}
		for (int i = 0; i <= n; i++) {
			factinv[i] = fact[i].inv();
		}
	}
	T nCr(long long n, long long r) {
		if (n < 0 || r < 0 || n - r < 0) {
			return 0;
		}
		return fact[n] * factinv[r] * factinv[n - r];
	}
	T nPr(long long n, long long r) {
		if (n < 0 || r < 0 || n - r < 0) {
			return 0;
		}
		return fact[n] * factinv[n - r];
	}
};