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
    // is Single Test case? cin >> t; 
    while (t--) { 
        solve(); 
        cout<<"\n";
    } 
  
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0; 
} 


void solve(){
	int n;
	cin>>n;
	int arr1[n], arr2[n];
	int i,sp=0,fp=0,sum=0;
	int mneg = -INT_MIN, minPos = INT_MAX;
	rep(i,n){
		cin>>arr1[i];
		if(arr1[i] > 0) sum+=arr1[i],fp++,minPos = min(minPos,arr1[i]);
		else mneg = max(mneg,arr1[i]);
	}
	rep(i,n){
		cin>>arr2[i];
		if(arr2[i] > 0) sp++;
	}
	if(sp%2 == fp%2){
		cout<<sum; return;
	}
	// add 1
	// if adding 1 we need to include 1 negative
	if(minPos + mneg >=0 ){
		cout<< sum+mneg; return;
	}
	// remove 1
	else cout<< sum-minPos;
}