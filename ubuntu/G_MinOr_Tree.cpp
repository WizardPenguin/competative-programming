// try greedily weather we can remove most significant bit 
// if yes then remove it otherwise try for other bit to make OR = minimum 
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
vvpll graph; 
ll mask; 
void dfs(vb &visited,int node){
    visited[node] = true; 
    for(auto &pr: graph[node]){
        auto nbr = pr.first; 
        auto wt = pr.second; 
        if((wt&mask) or visited[nbr]){
            continue;
        }
        dfs(visited,nbr); 
    }
}
void solve(){
    int n,m; 
    cin>>n>>m; 
    graph = vvpll(n+1); 
    mask = 0; 
    int u,v,w; 
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        graph[u].push_back({v,w}); 
        graph[v].push_back({u,w});
    }
    for(int i=31;i>=0;i--){
        mask += (1ll<<i); 
        vb visited(n+1,false); 
        dfs(visited,1); 
        for(int j=1;j<=n;j++){
            if(!visited[j]){
                mask -= (1ll<<i); 
                break; 
            }
        }
        // cout<<bitset<32>(mask)<<endl; 
        // otherwise mask remain same 
    }
    // now mask has all bits that can be removed from solution
    ll res = (1ll<<32) -1; 
    res -= mask; 
    cout<<res<<endl; 
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