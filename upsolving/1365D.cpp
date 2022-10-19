// we need to block every bad one by placing # at every current available nbr 
// then check weather all G are able to reach end and all B are not able to reach end using bfs
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
#define FOUND 3
#define VISITED 1
#define NOTFOUND 2
int n,m; 
vpii moves = {{0,1},{1,0},{0,-1},{-1,0}}; 
void solve(){
    cin>>n>>m; 
    vector<vector<char> > v(n,vector<char>(m)); 
    vvb visited(n,vb(m,false)); 
    bool foundG = false; 
    for(int i=0;i<n;i+=1){
        for(int j=0;j<m;j+=1){
            cin>>v[i][j]; 
            if(v[i][j] == '#'){
                visited[i][j] = true; 
            }
            else if(v[i][j] == 'G') foundG = true; 
        }
    }
    for(int i=0;i<n;i+=1){
        for(int j=0;j<m;j+=1){
            if(v[i][j] == 'B'){
                for(auto &[dx,dy] : moves){
                    int x = i + dx; 
                    int y = j + dy; 
                    if(x >=0 and y >=0 and x < n and y < m and v[x][y] == '.'){
                        v[x][y] = '#'; 
                        visited[x][y] = true; 
                    }
                }
            }
        }
    }
    queue<pii> q; 
    if(v[n-1][m-1] != '#'){
        q.push({n-1,m-1});
    }
    visited[n-1][m-1] = true; 
    bool found = true; 
    while(not q.empty()){
        auto [i,j] = q.front(); q.pop();
        for(auto &[dx,dy]: moves){
            int x = i + dx; 
            int y = j + dy; 
            if(x >=0 and y>=0 and x < n and y < m and not visited[x][y]){
                visited[x][y] = true; 
                q.push({x,y}); 
            }
        }
    }
    // now check weather we have visited valid nodes or not 
    for(int i=0;i<n;i+=1){
        for(int j=0;j<m;j+=1){
            if((visited[i][j] and v[i][j] == 'B' )or ((not visited[i][j]) and v[i][j] == 'G')){
                cout<<"No"<<endl; 
                return; 
            }
        }
    }
    cout<<"Yes"<<endl; 
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