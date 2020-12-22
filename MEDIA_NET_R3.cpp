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
void solve();
map<int,int> mp;
map<int,int> visited;
// Driver Program 
int fxn(int n,int m){
	if(n==m) return 0;
	if(mp[n]!=0) return mp[n];
	if(visited[n]==1) return -1;
	visited[n] = 1;
	if(n<0){
		if(m>=0) return mp[n] = -1;
		else if(m>n){
			// m==-2 and n==-5
			return mp[n] = -1;
		}
		else{
			// m=-5 and n=-2
			if(2*n >= m) {
				int ans1 = fxn(2*n,m);
				int ans2 = fxn(n-1,m);
				if(ans1==-1 && ans2==-1) return mp[n]=-1;
				if(ans1==-1 || ans2==-1){
					if(ans1==-1) return mp[n] = 1+ans2;
					else return mp[n] = 1+ans1;
				}
				return mp[n] = 1+min(ans1,ans2);
			}
			else return mp[n] = 1 + fxn(2*n,m);
		}
	}
	if(n==0){
		if(m>0) return mp[n] = -1;
		else{
			return mp[n] = 1+fxn(n-1,m);
		}
	}
	else{
		if(m<=0){
			// n=4 and m=-1 , m=0
			return mp[n] = 1+fxn(n-1,m);
		}
		else{
			if(m>n){
				// m=5 and n=2
				int ans1 = fxn(2*n,m);
				int ans2 = fxn(n-1,m);
				if(ans1==-1 && ans2==-1) return mp[n]=-1;
				if(ans1==-1 || ans2==-1){
					if(ans1==-1) return mp[n] = 1+ans2;
					else return mp[n] = 1+ans1;
				}
				return mp[n] = 1+min(ans1,ans2);
			}
			else{
				// m=2 and n=5
				return mp[n] = 1+fxn(n-1,m);
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
    // is Single Test case? cin >> t; 
    while (t--) { 
        solve(); 
        cout<<"\n";
    } 
  
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0; 
} 


void solve(){
	int n,m;
	cin>>n>>m;
	int ans = fxn(n,m);
	cout<<ans;
}