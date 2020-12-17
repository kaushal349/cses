#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int m = 1e9+7;
int main(){
	int n;
	cin>>n;
	ll sum = (n*(n+1))/2;
	if(sum%2!=0){
		cout<<"0";   0;
	}
	else{
		sum/=2;
		// recurrence relation
		// f(i,j) = f(i,j-1) + f(i-j,j-1)
		// i represents sum and j represents number from 1 to N.
		ll dp[sum+1][n+1];
		memset(dp,0, sizeof dp);
		// for(int i=0;i<=sum;i++){
		// 	for(int j=0;j<=n;j++) cout<<dp[i][j]<<" ";
		// 		cout<<endl;
		// }
		dp[0][0] = 1;
		for(int i=0;i<=sum;i++){
			for(int j=1;j<n;j++){
				dp[i][j] = dp[i][j-1];
				if( i-j >=0 )
					dp[i][j] += dp[i-j][j-1];
				dp[i][j]%=m;
			}
		}
		cout<<dp[sum][n-1];
	}
}