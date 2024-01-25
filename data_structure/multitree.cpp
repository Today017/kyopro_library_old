#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
template <typename T>
struct multitree : __gnu_pbds::tree<pair<T, int>, __gnu_pbds::null_type, less<pair<T, int>>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> {
    map<T, int> mp;
    set<T> st;
    T max() {
        return (*(this->rbegin())).first;
    }
    T min() {
        return (*(this->begin())).first;
    }
    void insert(T x) {
        st.insert(x);
        this->insert({x, mp[x]});
        mp[x]++;
    }
    T pop_max() {
        T ret = (*(this->rbegin())).first;
        mp[ret]--;
        if (mp[ret] == 0) st.erase(ret);
        this->erase(ret);
        return ret;
    }
    T pop_min() {
        T ret = (*(this->begin())).first;
        mp[ret]--;
        if (mp[ret] == 0) st.erase(ret);
        this->erase(ret);
        return ret;
    }
    void discard(T x) {
        if (!this->contains(x)) return;
        mp[x]--;
        if (mp[x] == 0) st.erase(x);
        this->erase(x);
    }
    // x以下最大の値
    T orless_max(T x) {
        auto itr = st.upper_bound(x);
        if (itr == st.begin()) return NULL;
        return *--itr;
    }
    // x未満最大の値
    T less_max(T x) {
        auto itr = st.lower_bound(x);
        if (itr == st.begin()) return NULL;
        return *--itr;
    }
    // x以上最小の値
    T ormore_min(T x) {
        auto itr = st.lower_bound(x);
        if (itr == st.end()) return NULL;
        return *itr;
    }
    // xより大きい最小の値
    T more_min(T x) {
        auto itr = st.upper_bound(x);
        if (itr == st.end()) return NULL;
        return *itr;
    }
    // k番目に小さい値(0-indexed)
    T kth_min(int x) {
        return (*(this->find_by_order(x))).first;
    }
    // k番目に大きい値(0-indexed)
    T kth_max(int x) {
        return (*(this->find_by_order(this->size() - x - 1))).first;
    }
    bool contains(T x) {
        return st.count(x) > 0;
    }
    // xが上から何番目か(0-indexed)
    int order_from_top(T x) {
        return this->size() - this->order_of_key({x, mp[x] - 1}) - 1;
    }
    int order_from_top_left(T x) {
        return this->size() - this->order_of_key({x, 0}) - 1;
    }
    // xが下から何番目か(0-indexed)
    int order_from_bottom(T x) {
        return this->order_of_key({x, 0});
    }
    int order_from_bottom_right(T x) {
        return this->order_of_key({x, mp[x] - 1});
    }
    int count(T x) {
        return mp[x];
    }
};
