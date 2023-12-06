#include <iostream>
#include <vector>
#include <math.h>

/**
 * @brief For Geometry
 */

using Real = long double;
const Real RINF = 1e20;
const Real EPS = 1e-10;
const Real PI = M_PI;
const Real to_radian(Real degree) {
	return degree * PI / 180;
}
const Real to_degree(Real radian) {
	return radian * 180 / PI;
}
struct point {
	Real x, y;
	constexpr point(Real x = 0.0, Real y = 0.0)
		: x(x), y(x){};
	constexpr inline point operator+(const point other) {
		return point(x + other.x, y + other.y);
	}
	constexpr inline point operator-(const point other) {
		return point(x - other.x, y - other.y);
	}
	constexpr inline point operator*(const Real k) {
		return point(x * k, y * k);
	}
	constexpr inline point operator*(const point other) {
		return point(x * other.x - y * other.y, x * other.y + y * other.x);
	}
	constexpr inline point operator/(const Real k) {
		return point(x / k, y / k);
	}
	constexpr inline bool operator==(const point other) {
		return (*this - other).abs() < EPS;
	}
	constexpr inline bool operator<(const point other) {
		return (*this - other).abs() > EPS ? x < other.x : y < other.y;
	}
	constexpr inline bool operator>(const point other) {
		return (*this - other).abs() > EPS ? x > other.x : y > other.y;
	}
	constexpr Real norm() {
		return x * x + y * y;
	}
	constexpr Real abs() {
		return sqrt(norm());
	}
	constexpr friend std::ostream &operator<<(std::ostream &os, const point &p) {
		return os << p.x << ' ' << p.y;
	}
	constexpr friend std::istream &operator>>(std::istream &is, point &p) {
		is >> p.x >> p.y;
		return is;
	}
	constexpr friend Real cross(const point &p, const point &q) {
		return p.x * q.y - p.y * q.x;
	}
	constexpr friend Real dot(const point &p, const point &q) {
		return p.x * q.x + p.y * q.y;
	}
	constexpr friend point rot90(const point &p) {
		return point(-p.y, p.x);
	}
};
const point PINF = point(RINF, RINF);
struct line : std::vector<point> {
	line(point a = point(0.0, 0.0), point b = point(0.0, 0.0)) {
		this->push_back(a);
		this->push_back(b);
	}
};
point cross_point(line &a, line &b) {
	point ret;
	Real d = cross(b[1] - b[0], a[1] - a[0]);
	if (abs(d) < EPS) return point(RINF, RINF);
	return (a[0] + (a[1] - a[0]) * cross(b[1] - b[0], b[1] - a[0]) / d);
}