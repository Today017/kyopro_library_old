---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: For Geometry
    links: []
  bundledCode: "#line 1 \"math/point.cpp\"\n#include <iostream>\r\n#include <vector>\r\
    \n#include <math.h>\r\n\r\n/**\r\n * @brief For Geometry\r\n */\r\n\r\nusing Real\
    \ = long double;\r\nconst Real RINF = 1e20;\r\nconst Real EPS = 1e-10;\r\nconst\
    \ Real PI = M_PI;\r\nconst Real to_radian(Real degree) {\r\n    return degree\
    \ * PI / 180;\r\n}\r\nconst Real to_degree(Real radian) {\r\n    return radian\
    \ * 180 / PI;\r\n}\r\nstruct point {\r\n    Real x, y;\r\n    constexpr point(Real\
    \ x = 0.0, Real y = 0.0)\r\n        : x(x), y(x){};\r\n    constexpr inline point\
    \ operator+(const point other) {\r\n        return point(x + other.x, y + other.y);\r\
    \n    }\r\n    constexpr inline point operator-(const point other) {\r\n     \
    \   return point(x - other.x, y - other.y);\r\n    }\r\n    constexpr inline point\
    \ operator*(const Real k) {\r\n        return point(x * k, y * k);\r\n    }\r\n\
    \    constexpr inline point operator*(const point other) {\r\n        return point(x\
    \ * other.x - y * other.y, x * other.y + y * other.x);\r\n    }\r\n    constexpr\
    \ inline point operator/(const Real k) {\r\n        return point(x / k, y / k);\r\
    \n    }\r\n    constexpr inline bool operator==(const point other) {\r\n     \
    \   return (*this - other).abs() < EPS;\r\n    }\r\n    constexpr inline bool\
    \ operator<(const point other) {\r\n        return (*this - other).abs() > EPS\
    \ ? x < other.x : y < other.y;\r\n    }\r\n    constexpr inline bool operator>(const\
    \ point other) {\r\n        return (*this - other).abs() > EPS ? x > other.x :\
    \ y > other.y;\r\n    }\r\n    constexpr Real norm() {\r\n        return x * x\
    \ + y * y;\r\n    }\r\n    constexpr Real abs() {\r\n        return sqrt(norm());\r\
    \n    }\r\n    constexpr friend std::ostream &operator<<(std::ostream &os, const\
    \ point &p) {\r\n        return os << p.x << ' ' << p.y;\r\n    }\r\n    constexpr\
    \ friend std::istream &operator>>(std::istream &is, point &p) {\r\n        is\
    \ >> p.x >> p.y;\r\n        return is;\r\n    }\r\n    constexpr friend Real cross(const\
    \ point &p, const point &q) {\r\n        return p.x * q.y - p.y * q.x;\r\n   \
    \ }\r\n    constexpr friend Real dot(const point &p, const point &q) {\r\n   \
    \     return p.x * q.x + p.y * q.y;\r\n    }\r\n    constexpr friend point rot90(const\
    \ point &p) {\r\n        return point(-p.y, p.x);\r\n    }\r\n};\r\nconst point\
    \ PINF = point(RINF, RINF);\r\nstruct line : std::vector<point> {\r\n    line(point\
    \ a = point(0.0, 0.0), point b = point(0.0, 0.0)) {\r\n        this->push_back(a);\r\
    \n        this->push_back(b);\r\n    }\r\n};\r\npoint cross_point(line &a, line\
    \ &b) {\r\n    point ret;\r\n    Real d = cross(b[1] - b[0], a[1] - a[0]);\r\n\
    \    if (abs(d) < EPS) return point(RINF, RINF);\r\n    return (a[0] + (a[1] -\
    \ a[0]) * cross(b[1] - b[0], b[1] - a[0]) / d);\r\n}\n"
  code: "#include <iostream>\r\n#include <vector>\r\n#include <math.h>\r\n\r\n/**\r\
    \n * @brief For Geometry\r\n */\r\n\r\nusing Real = long double;\r\nconst Real\
    \ RINF = 1e20;\r\nconst Real EPS = 1e-10;\r\nconst Real PI = M_PI;\r\nconst Real\
    \ to_radian(Real degree) {\r\n    return degree * PI / 180;\r\n}\r\nconst Real\
    \ to_degree(Real radian) {\r\n    return radian * 180 / PI;\r\n}\r\nstruct point\
    \ {\r\n    Real x, y;\r\n    constexpr point(Real x = 0.0, Real y = 0.0)\r\n \
    \       : x(x), y(x){};\r\n    constexpr inline point operator+(const point other)\
    \ {\r\n        return point(x + other.x, y + other.y);\r\n    }\r\n    constexpr\
    \ inline point operator-(const point other) {\r\n        return point(x - other.x,\
    \ y - other.y);\r\n    }\r\n    constexpr inline point operator*(const Real k)\
    \ {\r\n        return point(x * k, y * k);\r\n    }\r\n    constexpr inline point\
    \ operator*(const point other) {\r\n        return point(x * other.x - y * other.y,\
    \ x * other.y + y * other.x);\r\n    }\r\n    constexpr inline point operator/(const\
    \ Real k) {\r\n        return point(x / k, y / k);\r\n    }\r\n    constexpr inline\
    \ bool operator==(const point other) {\r\n        return (*this - other).abs()\
    \ < EPS;\r\n    }\r\n    constexpr inline bool operator<(const point other) {\r\
    \n        return (*this - other).abs() > EPS ? x < other.x : y < other.y;\r\n\
    \    }\r\n    constexpr inline bool operator>(const point other) {\r\n       \
    \ return (*this - other).abs() > EPS ? x > other.x : y > other.y;\r\n    }\r\n\
    \    constexpr Real norm() {\r\n        return x * x + y * y;\r\n    }\r\n   \
    \ constexpr Real abs() {\r\n        return sqrt(norm());\r\n    }\r\n    constexpr\
    \ friend std::ostream &operator<<(std::ostream &os, const point &p) {\r\n    \
    \    return os << p.x << ' ' << p.y;\r\n    }\r\n    constexpr friend std::istream\
    \ &operator>>(std::istream &is, point &p) {\r\n        is >> p.x >> p.y;\r\n \
    \       return is;\r\n    }\r\n    constexpr friend Real cross(const point &p,\
    \ const point &q) {\r\n        return p.x * q.y - p.y * q.x;\r\n    }\r\n    constexpr\
    \ friend Real dot(const point &p, const point &q) {\r\n        return p.x * q.x\
    \ + p.y * q.y;\r\n    }\r\n    constexpr friend point rot90(const point &p) {\r\
    \n        return point(-p.y, p.x);\r\n    }\r\n};\r\nconst point PINF = point(RINF,\
    \ RINF);\r\nstruct line : std::vector<point> {\r\n    line(point a = point(0.0,\
    \ 0.0), point b = point(0.0, 0.0)) {\r\n        this->push_back(a);\r\n      \
    \  this->push_back(b);\r\n    }\r\n};\r\npoint cross_point(line &a, line &b) {\r\
    \n    point ret;\r\n    Real d = cross(b[1] - b[0], a[1] - a[0]);\r\n    if (abs(d)\
    \ < EPS) return point(RINF, RINF);\r\n    return (a[0] + (a[1] - a[0]) * cross(b[1]\
    \ - b[0], b[1] - a[0]) / d);\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/point.cpp
  requiredBy: []
  timestamp: '2024-01-25 11:55:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/point.cpp
layout: document
redirect_from:
- /library/math/point.cpp
- /library/math/point.cpp.html
title: For Geometry
---
