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
vi graph[100001];
int visited[100001];
int parent[100001];
void solve();
// Driver Program
void djk(int src){
	queue<int> que;
	que.push(src);
	parent[src] = -1;
	visited[src] = 1;
	cerr<<"inside djk..\n";
	while(!que.empty()){
		int par = que.front();
		que.pop();
		for(int child: graph[par]){
			if(visited[child]==0){
				que.push(child);
				visited[child] = 1;
				parent[child] = par;
				// distance vector
			}
		}
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
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		graph[a].pb(b); graph[b].pb(a);
	}
	cerr<<"Inside this..\n";
	djk(1);
	if(parent[n]==0){
		cout<<"IMPOSSIBLE"; return;
	}
	else{
		int temp = parent[n];
		vi fans;
		fans.pb(n);
		while(temp!=-1){
			fans.pb(temp);
			temp = parent[temp];
		}
		cout<<fans.size()<<"\n";
		for(int i=fans.size()-1;i>=0;i--) cout<<fans[i]<<" ";
	}
}