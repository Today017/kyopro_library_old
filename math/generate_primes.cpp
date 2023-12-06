#include <vector>

/**
 * @brief Generate primes
 * @attention O(nlog(log(n)))
*/

std::vector<int> generate_primes(int n) {
	std::vector<int> ret;
	std::vector<bool> vst(n + 1, false);
	vst[0] = vst[1] = true;
	for (int i = 2; i <= n; i++) {
		if (vst[i]) {
			continue;
		}
		ret.push_back(i);
		for (int j = 2 * i; j <= n; j += i) {
			vst[j] = true;
		}
	}
	return ret;
}