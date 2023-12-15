#include <utility>
#include <cassert>

/**
 * @brief Binary Trie
 */

template <typename T = unsigned int, int LOG = 32>
struct binary_trie {
	binary_trie() {
		root = nullptr;
	}
	int size() const {
		if (root == nullptr) {
			return 0;
		}
		return root->size;
	}
	void insert(T x, int cnt = 1) {
		root = insert(root, x, LOG - 1, cnt);
	}
	void erase(T x, int cnt = 1) {
		cnt = std::min(cnt, count(x));
		if (cnt == 0) {
			return;
		}
		root = erase(root, x, LOG - 1, cnt);
	}
	void apply_xor(T x) {
		if (root != nullptr) {
			root->lazy ^= x;
		}
	}
	T max_element(T bias = 0) {
		return get_min(root, ~bias, LOG - 1);
	}
	T min_element(T bias = 0) {
		return get_min(root, bias, LOG - 1);
	}
	T operator[](int k) {
		assert(0 <= k && k < size());
		return get(root, k, LOG - 1);
	}
	int lower_bound(T x) {
		return count_lower(root, x, LOG - 1);
	}
	int upper_bound(T x) {
		return count_lower(root, x + 1, LOG - 1);
	}
	int count(T x) {
		if (root == nullptr) {
			return 0;
		}
		node* v = root;
		for (int i = LOG - 1; i >= 0; i--) {
			evaluate(v, i);
			v = v->next[(x >> i) & 1];
			if (v == nullptr) {
				return 0;
			}
		}
		return v->size;
	}

	private:
	struct node {
		node* next[2];
		int size;
		T lazy;
		node() {
			size = 0;
			lazy = 0;
			next[0] = next[1] = nullptr;
		}
	};
	node* root;
	void evaluate(node* v, int bit) {
		if ((v->lazy >> bit) & 1) {
			std::swap(v->next[0], v->next[1]);
		}
		if (v->next[0] != nullptr) {
			v->next[0]->lazy ^= v->lazy;
		}
		if (v->next[1] != nullptr) {
			v->next[1]->lazy ^= v->lazy;
		}
		v->lazy = 0;
	}
	node* insert(node* v, T x, int bit, int cnt) {
		if (v == nullptr) {
			v = new node;
		}
		v->size += cnt;
		if (bit < 0) {
			return v;
		}
		evaluate(v, bit);
		int lr = (x >> bit) & 1;
		v->next[lr] = insert(v->next[lr], x, bit - 1, cnt);
		return v;
	}
	node* erase(node* v, T x, int bit, int cnt) {
		assert(v != nullptr);
		v->size -= cnt;
		if (v->size == 0) {
			return nullptr;
		}
		if (bit < 0) {
			return v;
		}
		evaluate(v, bit);
		int lr = (x >> bit) & 1;
		v->next[lr] = erase(v->next[lr], x, bit - 1, cnt);
		return v;
	}
	T get_min(node* v, T x, int bit) {
		if (bit < 0) {
			return 0;
		}
		evaluate(v, bit);
		int lr = (x >> bit) & 1;
		if (v->next[lr] == nullptr) {
			lr = 1 - lr;
		}
		return get_min(v->next[lr], x, bit - 1) | ((T)lr << bit);
	}
	T get(node* v, int k, int bit) {
		if (bit < 0) {
			return 0;
		}
		evaluate(v, bit);
		int m = v->next[0] != nullptr ? v->next[0]->size : 0;
		if (k < m) {
			return get(v->next[0], k, bit - 1);
		} else {
			return get(v->next[1], k - m, bit - 1) | ((T)1 << bit);
		}
	}
	int count_lower(node* v, T x, int bit) {
		if (v == nullptr || bit < 0) {
			return 0;
		}
		evaluate(v, bit);
		int lr = (x >> bit) & 1;
		int ret = lr && v->next[0] != nullptr ? v->next[0]->size : 0;
		return ret + count_lower(v->next[lr], x, bit - 1);
	}
};
