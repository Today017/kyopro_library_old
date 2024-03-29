#include <numeric>

/**
 * @brief Fraction
 */

struct fraction {
    __int128_t p, q;
    fraction(__int128_t p = 0, __int128_t q = 1) {
        this->p = p;
        this->q = q;
    }
    void norm() {
        __int128_t g = std::gcd(p, q);
        p /= g;
        q /= g;
        if (q < 0) {
            p = -p;
            q = -q;
        }
    }
    bool operator<(const fraction &other) const {
        return p * other.q < other.p * q;
    }
    bool operator<=(const fraction &other) const {
        return p * other.q <= other.p * q;
    }
    bool operator>(const fraction &other) const {
        return p * other.q > other.p * q;
    }
    bool operator>=(const fraction &other) const {
        return p * other.q >= other.p * q;
    }
    bool operator==(const fraction &other) const {
        return p * other.q == other.p * q;
    }
};
