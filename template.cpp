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
	
}