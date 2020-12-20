#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,q;
ll mx = 1e17;
ll graph[501][501];
ll dist[501][501];
int main(){
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
  
#ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("error.txt", "w", stderr); 
    freopen("output.txt", "w", stdout); 
#endif 
	cin>>n>>m>>q;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			if(i==j) graph[i][j]=0;
			else graph[i][j] = mx;
		}
	}

	for(int i=0;i<m;i++){
		int x,y,d;
		cin>>x>>y>>d;
		if(graph[x][y] > d)
		graph[x][y] = d, graph[y][x] = d;
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			dist[i][j] = graph[i][j];
		}
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			cerr<<graph[i][j]<<" ";
		}
		cerr<<endl;
	}

	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				ll dt = dist[i][k] + dist[k][j];
				if(dt < dist[i][j]){
					dist[i][j] = dt;
				}
			}
		}
	}
	while(q--){
		int p,q;
		cin>>p>>q;
		if(dist[p][q]==mx) cout<<"-1\n";
		else cout<<dist[p][q]<<"\n";
	}
}