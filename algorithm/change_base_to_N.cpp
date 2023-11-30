#include <bits/stdc++.h>
using namespace std;

// 10進数非負整数をN進数に変換する
// Size 桁数
// n    変換対象の10進数
// base 基数
// rev  変換後の数を反転させたままにするか否か
template<int Size = -1>
string change_base(long long n, int base = 2, bool rev = true) {
	string ret;
	if (n == 0) {
		ret.push_back('0');
	}
	while (n > 0) {
		ret.push_back(n % base + '0');
		n /= base;
	}
	if (Size != -1) {
		while (ret.size() < Size) {
			ret.push_back('0');
		}
	}
	if (rev) {
		reverse(ret.begin(), ret.end());
	}
	return ret;
}