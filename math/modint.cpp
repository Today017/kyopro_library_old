template <unsigned long long MOD>
struct modint {
	unsigned long long value;
	constexpr modint(const unsigned long long x = 0) {
		value = x % MOD;
	}
	constexpr modint raw(const unsigned long long x = 0) {
		return modint(x);
	}
	constexpr modint operator+(const modint other) {
		return modint(*this) += other;
	}
	constexpr modint operator-(const modint other) {
		return modint(*this) -= other;
	}
	constexpr modint operator*(const modint other) {
		return modint(*this) *= other;
	}
	constexpr modint operator/(const modint other) {
		return modint(*this) /= other;
	}
	constexpr modint &operator+=(const modint other) {
		value += other.value;
		if (value >= MOD) {
			value -= MOD;
		}
		return *this;
	}
	constexpr modint &operator-=(const modint other) {
		if (value < other.value) {
			value += MOD;
		}
		value -= other.value;
		return *this;
	}
	constexpr modint &operator*=(const modint other) {
		value = value * other.value % MOD;
		return *this;
	}
	constexpr modint &operator/=(modint other) {
		(*this) *= other.inv();
		return *this;
	}
	constexpr modint pow(long long x) {
		modint ret(1), _this(*this);
		for (; x; x >>= 1, _this *= _this) {
			if (x & 1) {
				ret *= _this;
			}
		}
		return ret;
	}
	constexpr modint inv() {
		return pow(MOD - 2);
	}
	friend ostream &operator<<(ostream &os, const modint &x) {
		return os << x.value;
	}
	friend istream &operator>>(istream &is, modint &x) {
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