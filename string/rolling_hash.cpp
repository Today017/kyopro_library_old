#include <vector>
#include <string>
#include <random>
#include <tuple>
#include "mod/modint.cpp"

/**
 * @brief Rolling Hash
 */

struct rolling_hash {
	using mint1 = modint<998244353>;
	using mint2 = modint<1000000007>;
	using mint3 = modint<1000000009>;
	using mint4 = modint<1000000021>;
	using mint5 = modint<1000000033>;
	std::vector<long long> BASE;
	std::vector<mint1> power1, hash1, inv1;
	std::vector<mint2> power2, hash2, inv2;
	std::vector<mint3> power3, hash3, inv3;
	std::vector<mint4> power4, hash4, inv4;
	std::vector<mint5> power5, hash5, inv5;
	rolling_hash(std::string s, std::vector<long long> base = {}) {
		int n = s.size();
		std::mt19937 rng(time(0));
		BASE.resize(5);
		if (base.size() != 5) {
			BASE[0] = mint1(rng()).value + 30000;
			BASE[1] = mint2(rng()).value + 30000;
			BASE[2] = mint3(rng()).value + 30000;
			BASE[3] = mint4(rng()).value + 30000;
			BASE[4] = mint5(rng()).value + 30000;
		} else {
			BASE = base;
		}
		power1.resize(n + 1);
		hash1.resize(n + 1);
		inv1.resize(n + 1);
		power2.resize(n + 1);
		hash2.resize(n + 1);
		inv2.resize(n + 1);
		power3.resize(n + 1);
		hash3.resize(n + 1);
		inv3.resize(n + 1);
		power4.resize(n + 1);
		hash4.resize(n + 1);
		inv4.resize(n + 1);
		power5.resize(n + 1);
		hash5.resize(n + 1);
		inv5.resize(n + 1);
		power1[0] = 1;
		inv1[n] = mint1(BASE[0]).pow(n).inv();
		power2[0] = 1;
		inv2[n] = mint2(BASE[1]).pow(n).inv();
		power3[0] = 1;
		inv3[n] = mint3(BASE[2]).pow(n).inv();
		power4[0] = 1;
		inv4[n] = mint4(BASE[3]).pow(n).inv();
		power5[0] = 1;
		inv5[n] = mint5(BASE[4]).pow(n).inv();
		for (int i = 0; i < n; i++) {
			int num = s[i] - 'A';
			power1[i + 1] = power1[i] * BASE[0];
			inv1[n - i - 1] = inv1[n - i] * BASE[0];
			hash1[i + 1] = hash1[i] + power1[i] * num;
			power2[i + 1] = power2[i] * BASE[1];
			inv2[n - i - 1] = inv2[n - i] * BASE[1];
			hash2[i + 1] = hash2[i] + power2[i] * num;
			power3[i + 1] = power3[i] * BASE[2];
			inv3[n - i - 1] = inv3[n - i] * BASE[2];
			hash3[i + 1] = hash3[i] + power3[i] * num;
			power4[i + 1] = power4[i] * BASE[3];
			inv4[n - i - 1] = inv4[n - i] * BASE[3];
			hash4[i + 1] = hash4[i] + power4[i] * num;
			power5[i + 1] = power5[i] * BASE[4];
			inv5[n - i - 1] = inv5[n - i] * BASE[4];
			hash5[i + 1] = hash5[i] + power5[i] * num;
		}
	}
	std::tuple<unsigned long long, unsigned long long, unsigned long long, unsigned long long, unsigned long long> hash(int l, int r) {
		mint1 val1 = (hash1[r] - hash1[l]) * inv1[l];
		mint2 val2 = (hash2[r] - hash2[l]) * inv2[l];
		mint3 val3 = (hash3[r] - hash3[l]) * inv3[l];
		mint4 val4 = (hash4[r] - hash4[l]) * inv4[l];
		mint5 val5 = (hash5[r] - hash5[l]) * inv5[l];
		return std::make_tuple(val1.value, val2.value, val3.value, val4.value, val5.value);
	}
};