#include <vector>

template <typename U, typename T>
struct cumsum2D {
	int n, m;
	std::vector<std::vector<T>> S;
	cumsum2D(std::vector<vector<U>> &A) {
		n = A.size();
		m = A.front().size();
		S.resize(n + 1);
		for (int i = 0; i <= n; i++) {
			S[i].resize(m + 1);
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				S[i + 1][j + 1] = S[i][j + 1] + S[i + 1][j] - S[i][j] + A[i][j];
			}
		}
	}
	T sum(int a, int b, int c, int d) {
		return S[b][d] - S[a][d] - S[b][c] + S[a][c];
	}
};
