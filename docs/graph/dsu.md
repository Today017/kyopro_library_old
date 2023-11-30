
union by sizeにより実装しています。
以下アッカーマン関数の逆関数を$\alpha$とします。

```dsu ds(int n)```
- $O(n)$


```ds.find(int x)```
- 頂点`x`を含む連結成分の代表元を返す。
- $O(\alpha(n))$


```ds.unite(int x, int y)```
- 頂点`x`,`y`を連結する。
- $O(\alpha(n))$

```ds.size(int x)```
- 頂点`x`を含む連結成分のサイズを返す。
- $O(1)$

```ds.is_united(int x, int y)```
- 頂点のペア`(x, y)`が連結であるかを返す。
- $O(\alpha(n))$