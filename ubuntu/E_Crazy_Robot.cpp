// start bfs from lab and if reachable node is having only 1 path in nonvisited and nonblocked node then it can be marked + 
// otherwise remove it 
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<vector<ll> > vvll;
typedef vector<vector<pll> > vvpll;
typedef vector<pll> vpll;
typedef vector<pii> vpii;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<vector<bool> > vvb;
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
vs graph; 
vvb vis; 
void solve(){
    int n,m; 
    cin>>n>>m; 
    graph = vs(n); 
    vis = vvb(n,vb(m,false)); 
    for(int i=0;i<n;i++) cin>>graph[i]; 
    queue<pii> q; 
    int moves[][2] = {1,0,-1,0,0,1,0,-1}; 
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(graph[i][j] == 'L'){
                auto tp = make_pair(i,j); 
                vis[i][j] = true; 
                for(int i=0;i<4;i++){
                    int x = tp.first + moves[i][0] ;
                    int y = tp.second + moves[i][1]; 
                    if(x >=0 and y >=0 and x < n and y < m and vis[x][y] == false and graph[x][y] == '.'){
                        q.push({x,y}); 
                        vis[x][y] = true; 
                    }
                }
            }
        }
    }
    // cout<<q.size()<<endl; 
    while(!q.empty()){
        auto tp = q.front(); 
        q.pop(); 
        int count = 0; 
        for(int i=0;i<4;i++){
            int x = tp.first + moves[i][0];
            int y = tp.second + moves[i][1]; 
            if(x >=0 and y >=0 and x < n and y < m and graph[x][y] == '.'){
                count++; 
            }
        }
        if(count <= 1){
            graph[tp.first][tp.second] = '+';
            for(int i=0;i<4;i++){
                int x = tp.first + moves[i][0] ;
                int y = tp.second + moves[i][1]; 
                if(x >=0 and y >=0 and x < n and y < m /*and vis[x][y] == false*/ and graph[x][y] == '.'){
                    q.push({x,y}); vis[x][y] = true; // if already visited even then this being soln affects its state
                }
            }
        }
    }
    for(int i=0;i<n;i++) cout<<graph[i]<<'\n'; 
}
int main(){
    fast_cin();
    ll test;
    cin >> test;
    while(test--){
        solve();
    }
    return 0;
}