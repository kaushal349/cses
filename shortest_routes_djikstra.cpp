#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<ll,ll> > roads[501]; // first stores destination, second stores distance
int n,m,q;
int x,y;
ll mx = 1e18;
ll dist[501];
void dks(int src){
	priority_queue< pair<ll,ll>, vector<pair<ll,ll> >, greater<pair<ll,ll> > > que;
	// first int represents distance , second represents dest vertex
	que.push({0,src});
	while(!que.empty()){
		ll dist_old = que.top().first;
		ll new_src = que.top().second;
		que.pop();
		for(pair<ll,ll> pp: roads[new_src]){
			if(dist_old + pp.second < dist[pp.first]){
				que.push({dist_old + pp.second, pp.first});
				dist[pp.first] = dist_old + pp.second;
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
  
#ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("error.txt", "w", stderr); 
    freopen("output.txt", "w", stdout); 
#endif 
	cin>>n>>m>>q;
	for(int i=0;i<m;i++){
		int a,b; ll c;
		cin>>a>>b>>c;
		roads[a].push_back({b,c});
		roads[b].push_back({a,c});
	}
	while(q--){
		for(int i=0;i<501;i++) dist[i] = mx;
		cin>>x>>y;
		dks(x);
		if(dist[y]==mx) cout<<"-1\n";
		else cout<<dist[y]<<"\n";
	}
}