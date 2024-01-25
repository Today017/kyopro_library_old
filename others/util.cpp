#include <bits/stdc++.h>
using namespace std;

// pow
long long pow_ll(long long n, int x) {
    long long ret = 1;
    for (int i = 0; i < x; i++) {
        ret *= n;
    }
    return ret;
}

// a以上最小のbの倍数
long long ceil_mod(long long a, long long b) {
    long long rem = a % b;
    if (rem == 0) {
        return a;
    }
    return a + (b - rem);
}

// グリッドを回転
template <typename T>
vector<vector<T>> rotate_grid(vector<vector<T>> &G) {
    int n = G.size();
    int m = G.front().size();
    vector<vector<T>> ret(m, vector<T>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ret[j][n - i - 1] = G[i][j];
        }
    }
    return ret;
}

// 数列を回転
template <typename T>
vector<T> rotate_seq(vector<T> &A, int d) {
    int n = A.size();
    vector<T> ret(n);
    for (int i = 0; i < n; i++) {
        ret[(i + d) % n] = A[i];
    }
    return ret;
}

// a/bの切り上げ
long long ceil_div(long long a, long long b) {
    if (b <= 0) {
        cerr << "bが非正整数です！！！！\n";
        assert(false);
    }
    return (a + b - 1) / b;
}

// pow_mod
long long pow_mod(long long n, long long x, long long m) {
    long long ret = 1;
    while (x > 0) {
        if (x % 2 == 1) {
            ret *= n;
            ret %= m;
        }
        n *= n;
        n %= m;
        x /= 2;
    }
    return ret;
}

// 等差数列の和
long long arithmetic_sum_goal(long long start, long long goal, long long n) {
    return (start + goal) * n / 2;
}

long long arithmetic_sum_step(long long start, long long step, long long n) {
    return n * (2ll * start + (n - 1) * step) / 2;
}

long long arithmetic_sum_range(long long start, long long goal, long long step) {
    if (step <= 0) {
        cerr << "stepが非正整数です！！！！\n";
        assert(false);
    }
    // [a, b)
    long long n = abs(goal - start + step - 1) / step;
    return n * (2ll * start + (n - 1) * step) / 2;
}

vector<vector<long long>> cumsum2D(vector<vector<long long>> &A) {
    int n = A.size();
    int m = A[0].size();
    vector<vector<long long>> ret(n + 1, vector<long long>(m + 1, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ret[i + 1][j + 1] = ret[i][j + 1] + ret[i + 1][j] - ret[i][j] + A[i][j];
        }
    }
    return ret;
}

long long cumsum2D_query(int x1, int y1, int x2, int y2, vector<vector<long long>> &S) {
    return S[x2][y2] - S[x1][y2] - S[x2][y1] + S[x1][y1];
}

// 二部グラフ判定
bool is_bipartial_graph(vector<vector<int>> &G) {
    int n = G.size();
    bool ret = true;
    vector<int> color(n, -1);
    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {
            color[i] = 0;
            queue<int> Q;
            Q.push(i);
            while (!Q.empty()) {
                int now = Q.front();
                Q.pop();
                for (int nxt : G[now]) {
                    if (color[nxt] == -1) {
                        color[nxt] = 1 - color[now];
                        Q.push(nxt);
                    } else if (color[nxt] == color[now]) {
                        ret = false;
                    }
                }
            }
        }
    }
    return ret;
}

// 長さN-2,各要素が0~N-1の数列から木を生成する
vector<vector<int>> prufer_sequence(vector<int> &A) {
    int n = A.size() + 2;
    vector<int> d(n, 1);
    for (int i = 0; i < n - 2; i++) {
        d[A[i]]++;
    }
    set<int> pq;
    for (int i = 0; i < n; i++) {
        if (d[i] == 1) {
            pq.insert(i);
        }
    }
    vector<vector<int>> G(n);
    for (int i = 0; i < n - 2; i++) {
        int v = (*pq.begin());
        pq.erase(v);
        G[v].push_back(A[i]);
        G[A[i]].push_back(v);
        d[v]--;
        d[A[i]]--;
        if (d[A[i]] == 1) {
            pq.insert(A[i]);
        } else if (d[A[i]] == 0) {
            pq.erase(A[i]);
        }
    }
    for (int i = 0; i < n; i++) {
        if (d[i] == 1) {
            for (int j = i + 1; j < n; j++) {
                if (d[j] == 1) {
                    G[i].push_back(j);
                    G[j].push_back(i);
                    break;
                }
            }
            break;
        }
    }
    return G;
}

long long my_sqrt(long long x) {
    long long ret = sqrt(x);
    while (ret * ret > x) {
        ret--;
    }
    while ((ret + 1) * (ret + 1) <= x) {
        ret++;
    }
    return ret;
}
