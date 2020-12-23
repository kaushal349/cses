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
vector<pair<int,int> > g[100001];
ll dp[100001][100];
int visited[100001];
int mxi = -1e9;
void solve();
// Driver Program 
int dfs(int root, int k){
	visited[root] = true;
	if(k<0) return -1e9;
	if(dp[root][k]!=-1e9) return dp[root][k];
	int cm1 = -1e9;
	int cm2 = -1e9;
	for(pair<int,int> child: g[root]){
		int node = child.first, dist = child.second;
		if(visited[node]==0){
			int ts;
			if(dist >= 0){
				ts = dist + dfs(node,k);
			}
			else{
				ts = dist + dfs(node,k);
				int ts2 = -dist + dfs(node,k-1);
				ts = max(ts,ts2);
			}
			cerr<<"node: "<<root<<"ts: "<<ts<<endl;
			// dfs return max passing through that node
			if(cm1==-1e9){
				cm1 = max(ts,cm1);
			}
			else{
				if(ts>cm1) {
					cm2 = cm1;
					cm1 = ts;
				}
				else cm2 = max(ts,cm2);
			}
			// cm = max(ts,cm);
			mxi = max(mxi,max(cm1,max(cm2,cm1+cm2)));
		}
	}
	if(cm1==-1e9) cm1=0;
	if(cm2==-1e9) cm2=0;
	return dp[root][k] = max(cm1,cm2); // max distance from this node....
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
    // /*is Single Test case?*/ cin >> t; 
    while (t--) { 
        solve(); 
        cout<<"\n";
    } 
  
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0; 
} 


void solve(){
	// memset(dp,-1e9,sizeof(dp));
	for(int i=0;i<100001;i++){
		for(int j=0;j<100;j++){
			dp[i][j]=-1e9;
			// cerr<<dp[i][j]<<" ";
		}
	}
	// cout<<"HI\n";
	int n,m;
	cin>>n>>m;
	int i;
	rep(i,m){
		int a,b,c;
		cin>>a>>b>>c;
		g[a].pb({b,c});
		g[b].pb({a,c});
	}
	int root,k;
	cin>>root>>k;
	dfs(root,k);
	cout<<mxi;
}