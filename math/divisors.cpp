#include <vector>
#include <algorithm>

/**
 * @brief 約数列挙
 * @attention O(sqrt(n))
 */

std::vector<long long> divisors(long long n) {
	std::vector<long long> ret;
	for (long long i = 1; i * i <= n; i++) {
		if (n % i) {
			continue;
		}
		ret.push_back(i);
		if (n / i != i) {
			ret.push_back(n / i);
		}
	}
	std::sort(ret.begin(), ret.end());
	return ret;
}