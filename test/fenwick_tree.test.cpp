#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include <bits/stdc++.h>
using namespace std;
#include "data_structure/fenwick_tree.cpp"

int main(){
	int N,Q;cin>>N>>Q;
	fenwick_tree<long long>FT(N);
	for(int i=0;i<N;i++){
		int a;cin>>a;
		FT.add(i,a);
	}
	while(Q--){
		int t;
		cin>>t;
		if(t==0){
			int p,x;
			cin>>p>>x;
			FT.add(p,x);
		}
		else{
			int l,r;
			cin>>l>>r;
			cout<<FT.sum(l,r)<<'\n';
		}
	}
}
