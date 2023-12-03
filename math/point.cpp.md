---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/point.cpp\"\nusing Real = long double;\r\nconst Real\
    \ RINF = 1e20;\r\nconst Real EPS = 1e-10;\r\nconst Real PI = M_PI;\r\nconst Real\
    \ to_radian(Real degree) {\r\n\treturn degree * PI / 180;\r\n}\r\nconst Real to_degree(Real\
    \ radian) {\r\n\treturn radian * 180 / PI;\r\n}\r\nstruct point {\r\n\tReal x,\
    \ y;\r\n\tconstexpr point(Real x = 0.0, Real y = 0.0)\r\n\t\t: x(x), y(x){};\r\
    \n\tconstexpr inline point operator+(const point other) {\r\n\t\treturn point(x\
    \ + other.x, y + other.y);\r\n\t}\r\n\tconstexpr inline point operator-(const\
    \ point other) {\r\n\t\treturn point(x - other.x, y - other.y);\r\n\t}\r\n\tconstexpr\
    \ inline point operator*(const Real k) {\r\n\t\treturn point(x * k, y * k);\r\n\
    \t}\r\n\tconstexpr inline point operator*(const point other) {\r\n\t\treturn point(x\
    \ * other.x - y * other.y, x * other.y + y * other.x);\r\n\t}\r\n\tconstexpr inline\
    \ point operator/(const Real k) {\r\n\t\treturn point(x / k, y / k);\r\n\t}\r\n\
    \tconstexpr inline bool operator==(const point other) {\r\n\t\treturn (*this -\
    \ other).abs() < EPS;\r\n\t}\r\n\tconstexpr inline bool operator<(const point\
    \ other) {\r\n\t\treturn (*this - other).abs() > EPS ? x < other.x : y < other.y;\r\
    \n\t}\r\n\tconstexpr inline bool operator>(const point other) {\r\n\t\treturn\
    \ (*this - other).abs() > EPS ? x > other.x : y > other.y;\r\n\t}\r\n\tconstexpr\
    \ Real norm() {\r\n\t\treturn x * x + y * y;\r\n\t}\r\n\tconstexpr Real abs()\
    \ {\r\n\t\treturn sqrt(norm());\r\n\t}\r\n\tconstexpr friend ostream &operator<<(ostream\
    \ &os, const point &p) {\r\n\t\treturn os << p.x << ' ' << p.y;\r\n\t}\r\n\tconstexpr\
    \ friend istream &operator>>(istream &is, point &p) {\r\n\t\tis >> p.x >> p.y;\r\
    \n\t\treturn is;\r\n\t}\r\n\tconstexpr friend Real cross(const point &p, const\
    \ point &q) {\r\n\t\treturn p.x * q.y - p.y * q.x;\r\n\t}\r\n\tconstexpr friend\
    \ Real dot(const point &p, const point &q) {\r\n\t\treturn p.x * q.x + p.y * q.y;\r\
    \n\t}\r\n\tconstexpr friend point rot90(const point &p) {\r\n\t\treturn point(-p.y,\
    \ p.x);\r\n\t}\r\n};\r\nconst point PINF = point(RINF, RINF);\r\nstruct line :\
    \ vector<point> {\r\n\tline(point a = point(0.0, 0.0), point b = point(0.0, 0.0))\
    \ {\r\n\t\tthis->push_back(a);\r\n\t\tthis->push_back(b);\r\n\t}\r\n};\r\npoint\
    \ cross_point(line &a, line &b) {\r\n\tpoint ret;\r\n\tReal d = cross(b[1] - b[0],\
    \ a[1] - a[0]);\r\n\tif (abs(d) < EPS) return point(RINF, RINF);\r\n\treturn (a[0]\
    \ + (a[1] - a[0]) * cross(b[1] - b[0], b[1] - a[0]) / d);\r\n}\n"
  code: "using Real = long double;\r\nconst Real RINF = 1e20;\r\nconst Real EPS =\
    \ 1e-10;\r\nconst Real PI = M_PI;\r\nconst Real to_radian(Real degree) {\r\n\t\
    return degree * PI / 180;\r\n}\r\nconst Real to_degree(Real radian) {\r\n\treturn\
    \ radian * 180 / PI;\r\n}\r\nstruct point {\r\n\tReal x, y;\r\n\tconstexpr point(Real\
    \ x = 0.0, Real y = 0.0)\r\n\t\t: x(x), y(x){};\r\n\tconstexpr inline point operator+(const\
    \ point other) {\r\n\t\treturn point(x + other.x, y + other.y);\r\n\t}\r\n\tconstexpr\
    \ inline point operator-(const point other) {\r\n\t\treturn point(x - other.x,\
    \ y - other.y);\r\n\t}\r\n\tconstexpr inline point operator*(const Real k) {\r\
    \n\t\treturn point(x * k, y * k);\r\n\t}\r\n\tconstexpr inline point operator*(const\
    \ point other) {\r\n\t\treturn point(x * other.x - y * other.y, x * other.y +\
    \ y * other.x);\r\n\t}\r\n\tconstexpr inline point operator/(const Real k) {\r\
    \n\t\treturn point(x / k, y / k);\r\n\t}\r\n\tconstexpr inline bool operator==(const\
    \ point other) {\r\n\t\treturn (*this - other).abs() < EPS;\r\n\t}\r\n\tconstexpr\
    \ inline bool operator<(const point other) {\r\n\t\treturn (*this - other).abs()\
    \ > EPS ? x < other.x : y < other.y;\r\n\t}\r\n\tconstexpr inline bool operator>(const\
    \ point other) {\r\n\t\treturn (*this - other).abs() > EPS ? x > other.x : y >\
    \ other.y;\r\n\t}\r\n\tconstexpr Real norm() {\r\n\t\treturn x * x + y * y;\r\n\
    \t}\r\n\tconstexpr Real abs() {\r\n\t\treturn sqrt(norm());\r\n\t}\r\n\tconstexpr\
    \ friend ostream &operator<<(ostream &os, const point &p) {\r\n\t\treturn os <<\
    \ p.x << ' ' << p.y;\r\n\t}\r\n\tconstexpr friend istream &operator>>(istream\
    \ &is, point &p) {\r\n\t\tis >> p.x >> p.y;\r\n\t\treturn is;\r\n\t}\r\n\tconstexpr\
    \ friend Real cross(const point &p, const point &q) {\r\n\t\treturn p.x * q.y\
    \ - p.y * q.x;\r\n\t}\r\n\tconstexpr friend Real dot(const point &p, const point\
    \ &q) {\r\n\t\treturn p.x * q.x + p.y * q.y;\r\n\t}\r\n\tconstexpr friend point\
    \ rot90(const point &p) {\r\n\t\treturn point(-p.y, p.x);\r\n\t}\r\n};\r\nconst\
    \ point PINF = point(RINF, RINF);\r\nstruct line : vector<point> {\r\n\tline(point\
    \ a = point(0.0, 0.0), point b = point(0.0, 0.0)) {\r\n\t\tthis->push_back(a);\r\
    \n\t\tthis->push_back(b);\r\n\t}\r\n};\r\npoint cross_point(line &a, line &b)\
    \ {\r\n\tpoint ret;\r\n\tReal d = cross(b[1] - b[0], a[1] - a[0]);\r\n\tif (abs(d)\
    \ < EPS) return point(RINF, RINF);\r\n\treturn (a[0] + (a[1] - a[0]) * cross(b[1]\
    \ - b[0], b[1] - a[0]) / d);\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/point.cpp
  requiredBy: []
  timestamp: '2023-12-04 01:54:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/point.cpp
layout: document
redirect_from:
- /library/math/point.cpp
- /library/math/point.cpp.html
title: math/point.cpp
---
