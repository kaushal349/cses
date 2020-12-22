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
vi g[100001];
int visited[100001];
void solve();
// Driver Program 
ll dfs(int root){
	visited[root] = true;
	ll sum = 0;
	ll cm = INT_MIN;
	for(int child: g[root]){
		if(visited[child]==0){
			ll ts = dfs(child);
			// dfs return max passing through that node
			// without inversions right now
			cm = max(ts,cm);
		}
	}
	return max(cm+root)
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
    /*is Single Test case?*/ cin >> t; 
    while (t--) { 
        solve(); 
        cout<<"\n";
    } 
  
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0; 
} 


void solve(){
	cin>>n>>m;
	int i;
	rep(i,m){
		int a,b;
		cin>>a>>b;
		g[a].pb(b);
	}
	int root,k;
	cin>>root>>k;
	dfs(root);
}