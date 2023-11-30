
ac-library/fenwicktreeと仕様はほぼ同じです。

```fenwick_tree<T> ft(int n)```
- $O(n)$


```ft.add(int i, T x)```
- 位置`i`に`x`を加算する。
- $0\le p<n$
- $O(\log{n})$


```ft.sum(int l, int r)```
- 区間`[l,r)`の総和を返す。
- $0\le l \le r\le n$
- $O(\log{n})$

#### 区間加算1点取得をしたい場合
```cpp
fenwick_tree<int> ft(N + 1);

// 区間加算
ft.add(l, x);
ft.add(r + 1, x);

// 取得
ft.sum(i + 1);
```