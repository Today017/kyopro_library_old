#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
template <typename T>
struct tree : __gnu_pbds::tree<T, __gnu_pbds::null_type, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> {
	T max() {
		return *this->rbegin();
	}
	T min() {
		return *this->begin();
	}
	T pop_max() {
		T ret = *this->rbegin();
		this->erase(ret);
		return ret;
	}
	T pop_min() {
		T ret = *this->begin();
		this->erase(ret);
		return ret;
	}
	void discard(T x) {
		if (!this->contains(x)) {
			return;
		}
		this->erase(x);
	}
	// x以下最大の値
	T orless_max(T x) {
		auto itr = this->upper_bound(x);
		if (itr == this->begin()) {
			return NULL;
		}
		return *--itr;
	}
	// x未満最大の値
	T less_max(T x) {
		auto itr = this->lower_bound(x);
		if (itr == this->begin()) {
			return NULL;
		}
		return *--itr;
	}
	// x以上最小の値
	T ormore_min(T x) {
		auto itr = this->lower_bound(x);
		if (itr == this->end()) {
			return NULL;
		}
		return *itr;
	}
	// xより大きい最小の値
	T more_min(T x) {
		auto itr = this->upper_bound(x);
		if (itr == this->end()) {
			return NULL;
		}
		return *itr;
	}
	// k番目に小さい値(0-indexed)
	T kth_min(int x) {
		return *this->find_by_order(x);
	}
	// k番目に大きい値(0-indexed)
	T kth_max(int x) {
		return *this->find_by_order(this->size() - x - 1);
	}
	bool contains(T x) {
		auto itr = this->find(x);
		return itr != this->end();
	}
	// xが上から何番目か(0-indexed) / xより大きい値がいくつ存在するか
	int order_from_top(T x) {
		return this->size() - this->order_of_key(x) - 1;
	}
	// xが下から何番目か(0-indexed) / xより小さい値がいくつ存在するか
	int order_from_bottom(T x) {
		return this->order_of_key(x);
	}
};
