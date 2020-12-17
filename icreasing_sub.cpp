#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	int dp[n];int ans = 1;
	for(int i=0;i<n;i++){
		dp[i] = 1;
		for(int j=0;j<i;j++){
			if(arr[j]<arr[i]){
				dp[i] = max(dp[i], 1+dp[j]);
			}
		}
		ans= max(ans,dp[i]);
	}
	cout<<ans;
}