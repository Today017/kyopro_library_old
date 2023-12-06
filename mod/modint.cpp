#include <iostream>

/**
 * @brief Modint
 */

template <unsigned long long MOD>
struct modint {
	unsigned long long value;
	constexpr modint(const long long x = 0) {
		value = x % MOD;
	}
	constexpr modint<MOD> operator+(const modint<MOD> other) {
		return modint<MOD>(*this) += other;
	}
	constexpr modint<MOD> operator-(const modint<MOD> other) {
		return modint<MOD>(*this) -= other;
	}
	constexpr modint<MOD> operator*(const modint<MOD> other) {
		return modint<MOD>(*this) *= other;
	}
	constexpr modint<MOD> operator/(const modint<MOD> other) {
		return modint<MOD>(*this) /= other;
	}
	constexpr modint<MOD> &operator+=(const modint<MOD> other) {
		value += other.value;
		if (value >= MOD) {
			value -= MOD;
		}
		return *this;
	}
	constexpr modint<MOD> &operator-=(const modint<MOD> other) {
		if (value < other.value) {
			value += MOD;
		}
		value -= other.value;
		return *this;
	}
	constexpr modint<MOD> &operator*=(const modint<MOD> other) {
		value = value * other.value % MOD;
		return *this;
	}
	constexpr modint<MOD> &operator/=(modint<MOD> other) {
		(*this) *= other.inv();
		return *this;
	}
	constexpr modint<MOD> pow(long long x) {
		modint<MOD> ret(1), _this(*this);
		for (; x; x >>= 1, _this *= _this) {
			if (x & 1) {
				ret *= _this;
			}
		}
		return ret;
	}
	constexpr modint<MOD> inv() {
		return pow(MOD - 2);
	}
	constexpr friend std::ostream &operator<<(ostream &os, const modint<MOD> &x) {
		return os << x.value;
	}
	constexpr friend std::istream &operator>>(istream &is, modint<MOD> &x) {
		is >> x.value;
		x.value %= MOD;
		if (x.value < 0) {
			x.value += MOD;
		}
		return is;
	}
};
using mod998 = modint<998244353>;
using mod107 = modint<1000000007>;