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
// Driver Program 
map<int,int> mp;
int fxn(int n, int m){
	cerr<<"n: "<<n<<" m: "<<m<<endl;
	mp[n] = 1;
	if(m==n) return 0;
	if(n<0 && m>=0) return -1;
	if(n<0){
		// m<0 case left
		// handling negative cases too-----);
		if(m>n){
			// eg m=-1 and n=-3
			return -1;
		}	
		else{
			// eg m=-3 and n=-1
			if(2*n >= m) {
				if(mp[2*n]==1) return -1;
				return 1+fxn(2*n,m);	
			}
			else {
				if(mp[n-1]==1) return -1;
				return 1+fxn(n-1,m);
			}
		}
	}
	if(n==0){
		if(m>0) return -1;
		else{
			// m==n==0 already considered
			// eg m==-2 and n==0
			if(mp[n-1]==1) return -1;
			return 1+fxn(n-1,m);
		}
	}
	else{
		// n>0
		if(m>n){
			// eg m==2 and n==1
			if(2*n <= m) {
				int ans1,ans2;
				if(mp[n-1]==1) ans1=-1;
				else{
					ans1 = 1+fxn(n-1,m);
				}
				if(mp[2*n]==1) ans2=-1;
				else{
					ans2 = 1+fxn(2*n,m);
				}
				if(ans1==-1 && ans2==-1) return -1;
				if(ans1==-1 || ans2==-1){
					if(ans1==-1) return ans2;
					else return ans1;
				}
				return min(ans1,ans2);
			}
		}
		else{
			// eg m==1 and n==2
			return 1+fxn(n-1,m);
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
    // /*is Single Test case?*/ cin >> t; 
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