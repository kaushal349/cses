#include<bits/stdc++.h>
using namespace std;
vector<int> B,C,D;
int edges[10001];
int parent[10001];
int size[10001];
int As,Q;
int mxi;
int fans[10001];
int find(int a){
	if(parent[a] < 0) return a;
	// apply path compression
	else{
		return parent[a] = find(parent[a]);
	}
}

void unioN(int a, int b){
	a = find(a);
	b = find(b);
	if(a==b) return;
	// apply rank union
	if(size[a] > size[b]){
		parent[a]+=parent[b];
		parent[b] = a;
		mxi = min(parent[a], mxi);
	}
	else{
		parent[b]+=parent[a];
		parent[a] = b;
		mxi = min(parent[b], mxi);
	}
	return;
}
int main(){
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);  cout.tie(NULL);
	#ifndef ONLINE_JUDGE 
	    freopen("input.txt", "r", stdin); 
	    freopen("error.txt", "w", stderr); 
	    freopen("output.txt", "w", stdout); 
	#endif 
	int temp;
	cin>>As>>Q;
	for(int i=0;i<As-1;i++){
		cin>>temp;
		parent[i] = -1;
		size[i] = 1;
		B.push_back(temp);
	}
	parent[As-1]=-1;
	size[As-1] = 1;
	for(int i=0;i<As-1;i++){
		cin>>temp;
		C.push_back(temp);
	}
	for(int i=0;i<Q;i++){
		cin>>temp;
		D.push_back(temp);
		// for i it represents i+1 edge
		edges[temp-1] = 1;
	}
	for(int i=0;i<As-1;i++){
		if(edges[i]==1) continue;
		int x = B[i], y = C[i];
		unioN(x,y);
	}
	for(int i = D.size()-1;i>=0;i--){
		fans[i] = (-mxi);
		unioN(B[D[i]-1], C[D[i]-1]);
	}
	for(int i=0;i<Q;i++){
		cout<<fans[i]<<" ";
	}
}