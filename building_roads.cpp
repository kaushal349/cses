#include <bits/stdc++.h> 
using namespace std;
#define rep(i,n) for (i = 0; i < n; ++i) 
#define REP(i,k,n) for (i = k; i <= n; ++i) 
#define REPR(i,k,n) for (i = k; i >= n; --i)
#define ll long long
#define pb push_back
#define mod 1e9+7
#define present(c,x) ((c).find(x)!=(c).end())
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
typedef vector<int> vi;
typedef vector<ll> vll;
int parent[100001];
int n,m;
void solve();
// Driver Program 
int find(int a){
	if(parent[a] < 0) return a;
	else return parent[a] = find(parent[a]);
}
void unioN(int a, int b){
	a = find(a);
	b = find(b);
	if(a==b) return;
	if(parent[a]<parent[b]){
		parent[a]+=parent[b];
		parent[b] = a;	
	}
	else{
		parent[b]+=parent[a];
		parent[a] = b;
	}
}
int main() 
{ 
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
  	cout.tie(NULL);
#ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("error.txt", "w", stderr); 
    freopen("output.txt", "w", stdout); 
#endif 
  
    int t = 1; 
     // cin >> t; 
    while (t--) { 
        solve(); 
        cout<<"\n";
    } 
  
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0; 
} 


void solve(){
	cin>>n>>m;
	for(int i=0;i<=n;i++) parent[i] = -1;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		unioN(a,b);
	}
	vector<int> fans;
	int comp = 0;
	for(int i=1;i<=n;i++){
		if(parent[i] <0){
			comp++;
			fans.pb(i);
		}
	}
	int sans = fans.size()-1;
	if(sans<=0){
		cout<<"0";
		return;
	}
	else{
		cout<<sans<<"\n";
		for(int i=1;i<fans.size();i++){
			cout<<fans[i-1]<<" "<<fans[i]<<"\n";
		}
	}
}