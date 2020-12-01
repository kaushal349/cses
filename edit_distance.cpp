#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
// state1 = i,j
// state2 = i+1,j || i,j+1 || i+1,j+1
// option1 possible when removing character
// option2 possible when inserting character
// option3 possible when characters are same 
// option3 possible also when replacing the characters
// dp[i][j] = 1 + min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1]);
// if characters are equal dp[i][j] = dp[i-1][j-1];
// just think about base case!!!!!
int main(){
	string a,b;
	cin>>a>>b;
	int l1 = a.size(), l2 = b.size();
	int dp[l1+1][l2+1];
	for(int i=0;i<=l1;i++){
		for(int j=0;j<=l2;j++){
			if(i==0){
				// s1 is empty so we need to push all j elements to string.
				dp[i][j] = j;
			}
			else if(j==0){
				// s2 is empty now so we need to remove all the i elements from s1.
				dp[i][j] = i;
			}
			else if(a[i-1]==b[j-1]){
				dp[i][j] = dp[i-1][j-1];
			}
			else{
				dp[i][j] = 1 + min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
			}
		}	
	}
	cout<<dp[l1][l2];
}