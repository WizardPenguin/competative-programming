// node which are only forming cycle in their component have degree == 2
// so check for each connected component weather their all nodes have degree == 2 or not
#include <bits/stdc++.h> 
#include <complex>
#include <cmath>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
bool found; 
void dfs(vv32 &graph,v32 &ind,v32 &vis,int node){
    if(ind[node] != 2) found = false; 
    vis[node] = 1; 
    for(auto &nbr: graph[node]){
        if(vis[nbr] == 0){
            dfs(graph,ind,vis,nbr); 
        }
    }
}
int main()
{
    fast_cin();
    ll test=1;
    while(test--){
        int n,m; 
        cin>>n>>m; 
        vv32 graph(n + 1); 
        v32 deg(n+1,0); 
        v32 visited(n+1,0);
        int x,y; 
        while(m--){
            cin>>x>>y; 
            deg[x]++; 
            deg[y]++; 
            graph[x].push_back(y); 
            graph[y].push_back(x); 
        }
        int ans = 0; 
        for(int i=1;i<=n;i++){
            if(visited[i] == 0){
                found = true; 
                dfs(graph,deg,visited,i); 
                // dbg(found);
                ans += found; 
            }
        }
        cout<<ans<<endl; 
    }
    return 0;
}