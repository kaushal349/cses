#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
// state1 = i,j
// state represents no of valid arrays upto index i ending with j
// state2 = i+1,j+1 || i+1,j || i+1,j-1
// if ar[i]!=0 dp[i][j]=dp[i-1][j-1]
// dp[i][j] = dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1]
ll dp[100000+1][100+1];
int mm = 1e9+7;
int main(){
	int n,m;
	cin>>n>>m;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	// no need to start loop with 0
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i==1){
				if(arr[i-1]==0 || arr[i-1]==j) dp[i][j]=1;
				else dp[i][j]=0;
			}
			else{
				if(arr[i-1]==0 || arr[i-1]==j){
					dp[i][j] = ((dp[i-1][j-1]+dp[i-1][j])%mm + dp[i-1][j+1])%mm;
				}
				else{
					dp[i][j] = 0;
				}
			}
		}
	}
	ll ans=0;
	for(int i=1;i<=m;i++){
		ans = (ans+dp[n][i])%mm;
	}
	cout<<ans;
}