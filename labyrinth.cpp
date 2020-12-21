#include <bits/stdc++.h> 
using namespace std;
#define rep(i,n) for (i = 0; i < n; ++i) 
#define REP(i,k,n) for (i = k; i <= n; ++i) 
#define REPR(i,k,n) for (i = k; i >= n; --i)
#define ll long long
#define pb push_back
#define mod 1e9+7
#define present(c,x) ((c).find(x)!=(c).end())
typedef vector<int> vi;
typedef vector<ll> vll;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
char grid[1001][1001];
int visited[1001][1001];
char track[1001][1001];
int m,n;
int srcX,srcY,destX,destY;
map<int ,char> dirt;
void solve();
// Driver Program 
bool isValid(int x, int y){
    if(x<0 || y<0 || x>=m || y>=n || grid[x][y]=='#' || visited[x][y]==1) return false;
    return true;
}
void bfs(){
    queue<pair<int, int> > que;
    que.push({srcX,srcY});
    visited[srcX][srcY] = 1;
    track[srcX][srcY] = 'X';
    track[destX][destY] = 'X';
    while(!que.empty()){
        int oldX = que.front().first;
        int oldY = que.front().second;
        que.pop();
        for(int i=0;i<4;i++){
            int newX = oldX + dx[i];
            int newY = oldY + dy[i];
            if(isValid(newX,newY)){
                track[newX][newY] = dirt[i];
                que.push({newX,newY});
                visited[newX][newY] = 1;
            }
        }
    }
}
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
    // cin >> t; 
    while (t--) { 
        solve(); 
        cout<<"\n";
    } 
  
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0; 
} 


void solve(){
    dirt[0] = 'U';
    dirt[1] = 'R';
    dirt[2] = 'D';
    dirt[3] = 'L';
	cin>>m>>n;
    int i,j;
    rep(i,m){
        rep(j,n){
            cin>>grid[i][j];
            track[i][j] = -1;
            if(grid[i][j]=='A') srcX = i, srcY = j;
            if(grid[i][j]=='B') destX = i, destY = j;
        }
    }
    bfs();
    vector<char> fans;
    while(track[destX][destY] != 'X'){
        char dir = track[destX][destY];
        fans.push_back(dir);
        if(dir=='U') destX++;
        else if(dir=='R') destY--;
        else if(dir=='D') destX--;
        else destY++;
    }
    if(fans.size()==0){
        cout<<"NO";
        return;
    }
    cout<<"YES\n";
    cout<<fans.size()<<"\n";
    for(int i=fans.size()-1;i>=0;i--){
        cout<<fans[i];
    }
}