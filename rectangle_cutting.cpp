#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b;
	cin>>a>>b;
	// for rectangle of length a and b I have options as 
	// dp[a][b] = 1+dp[a][i]+dp[a][b-i] for i=1:b-1
	//  and 1+dp[i][b]+dp[a-i][b] for i=1:a-1
	int dp[a+1][b+1];
	for(int i=1;i<=a;i++){
		for(int j=1;j<=b;j++){
			if(i==j){
				dp[i][j] = 0; continue;
			}
			else{
				int ans = 1e9;
				for(int k=1;k<j;k++){
					ans = min(ans, 1+dp[i][k]+dp[i][j-k]);
				}
				for(int k=1;k<i;k++){
					ans = min(ans, 1+dp[k][j]+dp[i-k][j]);
				}
				dp[i][j] = ans;
			}
		}
	}
	cout<<dp[a][b];
}