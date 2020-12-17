#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	set<int> st;
	vector<int> ans;
	for(int i=0;i<n;i++){
		int size = ans.size();
		for(int j=0;j<size;j++){
			if(st.find(ans[j] + arr[i])==st.end()){
				ans.push_back(ans[j]+arr[i]);
				st.insert(ans[j]+arr[i]);
			}
		}
		ans.push_back(arr[i]);
		st.insert(arr[i]);
	}
	cout<<st.size()<<"\n";
	for(auto x: st){
		cout<<x<<" ";
	}
}