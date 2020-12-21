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
int n,m;
int parent[100001];
bool ans_poss = true;
int find(int a){
	if(parent[a]<0) return a;
	return parent[a] = find(parent[a]);
}
void unioN(int a, int b){
	a = find(a);
	b = find(b);
	if(a==b){
		ans_poss=false; return;
	} 
	if(parent[a]<parent[b]){
		parent[a]+=parent[b];
		parent[b]=a;
	}
	else{
		parent[b]+=parent[a];
		parent[a]=b;
	}
}
void solve();
// Driver Program 
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
    // /*is Single Test case?*/ cin >> t; 
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
	if(!ans_poss){
		cout<<"IMPOSSIBLE"; return;
	}
	map<int, int> mp;
	int count = 1;
	for(int i=1;i<=n;i++){
		cerr<<parent[i]<<" ";
		if(parent[i] < 0){
			mp[i] = count;
			count++;
		}
	}
	cerr<<endl;
	for(pair<int,int> pp: mp){
		cerr<<pp.first<<" "<<pp.second<<endl;
	}
	cerr<<"count: "<<count<<endl;
	if(count>3){
		cout<<"IMPOSSIBLE"; return;
	}
	for(int i=1;i<=n;i++){
		int par = parent[i];
		if(par<0) cout<<mp[i]<<" ";
		else cout<<mp[par]<<" ";
	}
}