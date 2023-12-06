#include <tuple>
#include <utility>

/**
 * @brief ExtGCD, mod上の逆元, 不定一次方程式
*/

std::tuple<long long, long long, long long> extgcd(long long a, long long b) {
	if (b == 0) {
		return {a, 1, 0};
	}
	long long q = a / b, r = a % b;
	long long g, s, t;
	std::tie(g, s, t) = extgcd(b, r);
	long long x = t;
	long long y = s - q * t;
	return std::make_tuple(g, x, y);
}

long long modinv(long long a, long long mod) {
	long long g, x, y;
	std::tie(g, x, y) = extgcd(a, mod);
	if (g != 1) {
		return -1;
	}
	return x % mod;
}

struct bezout_equation {
	long long a, b, c, g;
	long long X, Y;
	bezout_equation(long long a, long long b, long long c) {
		if (a < b) {
			std::swap(a, b);
		}
		this->a = a;
		this->b = b;
		this->c = c;
	}
	std::tuple<long long, long long, long long> extgcd(long long a, long long b) {
		if (b == 0) {
			return {a, 1, 0};
		}
		long long q = a / b, r = a % b;
		long long g, s, t;
		std::tie(g, s, t) = extgcd(b, r);
		long long x = t;
		long long y = s - q * t;
		return std::make_tuple(g, x, y);
	}
	bool build() {
		long long g, X, Y;
		std::tie(g, X, Y) = extgcd(a, b);
		if (c % g != 0) {
			return false;
		}
		this->g = g;
		this->X = X;
		this->Y = Y;
		return true;
	}
	std::pair<long long, long long> general_solution(long long t) {
		long long x = b / g * t + X;
		long long y = -a / g * t + Y;
		return std::make_pair(x, y);
	}
};