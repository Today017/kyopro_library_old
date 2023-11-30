#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

template <class T>
ostream &operator<<(ostream &os, const vector<T> &A) {
	int n = A.size();
	os << "[ ";
	for (int i = 0; i < n; i++) {
		os << A[i];
		if (i != n - 1) {
			os << ", ";
		}
	}
	os << " ]";
	return os;
}
template <class T>
ostream &operator<<(ostream &os, const vector<vector<T>> &A) {
	os << "[\n";
	int n = A.size();
	for (int i = 0; i < n; i++) {
		os << "      ";
		os << A[i];
		os << ", \n";
	}
	os << " ]";
	return os;
}
template <class T>
ostream &operator<<(ostream &os, const set<T> &A) {
	int n = A.size();
	os << "[ ";
	for (T x : A) {
		os << x << ", ";
	}
	os << " ]";
	return os;
}
template <class T>
ostream &operator<<(ostream &os, const multiset<T> &A) {
	int n = A.size();
	os << "[ ";
	for (T x : A) {
		os << x << ", ";
	}
	os << " ]";
	return os;
}
template <class T1, class T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
	os << "( " << p.first << ", " << p.second << " )";
	return os;
}
template <class T>
ostream &operator<<(ostream &os, queue<T> A) {
	int n = A.size();
	os << "[ ";
	while (!A.empty()) {
		os << A.front() << ", ";
		A.pop();
	}
	os << " ]";
	return os;
}
template <class T>
ostream &operator<<(ostream &os, priority_queue<T> A) {
	int n = A.size();
	os << "[ ";
	while (!A.empty()) {
		os << A.top() << ", ";
		A.pop();
	}
	os << " ]";
	return os;
}
template <class T>
ostream &operator<<(ostream &os, fenwick_tree<T> A) {
	int n = A._n;
	os << "[ ";
	for (int i = 0; i < n; i++) {
		os << A.sum(i, i + 1);
		if (i != n - 1) {
			os << ", ";
		}
	}
	os << " ]";
	return os;
}
template <class S, S (*op)(S, S), S (*e)()>
ostream &operator<<(ostream &os, segtree<S, op, e> A) {
	int n = A._n;
	os << "[ ";
	for (int i = 0; i < n; i++) {
		os << A.prod(i, i + 1);
		if (i != n - 1) {
			os << ", ";
		}
	}
	os << " ]";
	return os;
}
ostream &operator<<(ostream &os, dsu ds) {
	os << ds.groups();
	return os;
}
ostream &operator<<(ostream &os, modint998244353 x) {
	os << x.val();
	return os;
}
ostream &operator<<(ostream &os, modint1000000007 x) {
	os << x.val();
	return os;
}

#define print_line cerr << "--------------------" << __LINE__ << "--------------------" \
												<< "\n"
#define debug(...) debug_print(0, #__VA_ARGS__, __VA_ARGS__)
#define get_name(VariableName) #VariableName
template <typename T>
void debug_print(int i, T name) {
	cerr << endl;
}
template <typename T1, typename T2, typename... T3>
void debug_print(int i, const T1 &name, const T2 &a, const T3 &...b) {
	for (; name[i] != ',' && name[i] != '\0'; i++) {
		cerr << name[i];
	}
	cerr << " : " << a << ", ";
	debug_print(i + 1, name, b...);
}
template <typename T>
void debugc(T a, string sep = ", ") {
	cerr << get_name(a) << " : [";
	for (auto x : a) {
		cerr << x << sep;
	}
	cerr << "]" << endl;
}
