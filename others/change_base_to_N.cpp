#include <string>
#include <algorithm>

/**
 * @brief N進数への変換
 * @param Size 桁数
 * @param base 基数
 * @param rev 変換後の数を反転させて元に戻すか否か
*/

template <int Size = -1>
std::string change_base(long long n, int base = 2, bool rev = true) {
    std::string ret;
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
        std::reverse(ret.begin(), ret.end());
    }
    return ret;
}
