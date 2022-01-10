// let's try to find solution for single value root = 1
// after then pass this solution in other dfs call to it's child and help them calculating their solutions 
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
vi res; 
// since there are only n-1 edges means we don't have problems like loop 
int dfs1(int node,int par){
    for(auto &nbr: graph[node]){
        auto &nd = nbr.first; 
        auto &val = nbr.second; 
        if(nd == par) continue; 
        res[node] += val + dfs1(nd,node); 
    }
    return res[node]; 
}
void dfs2(int node,int par){
    auto v = res[node]; 
    for(auto &nbr: graph[node]){
        auto &nd = nbr.first; 
        auto &val = nbr.second; 
        if(nd == par) continue; 
        res[nd] = v + (1-val) - val; // reverse affect of this edge since it needs to be considered in reverse 
        dfs2(nd,node); 
    }
    return; 
}
void solve(){
    int n; cin>>n; 
    graph = vvpll(n+1); 
    for(int i=1;i<n;i++){
        int x,y; 
        cin>>x>>y; 
        graph[x].push_back({y,0}); 
        graph[y].push_back({x,1}); 
    }
    res = vi(n+1,0); 
    dfs1(1,0); 
    dfs2(1,0); 
    // now output all nodes with min reverse 
    res[0] = INT_MAX; 
    int mini = *min_element(all(res)); 
    cout<<mini<<endl; 
    for(int i=1;i<=n;i++){
        if(res[i] == mini) cout<<i<<" "; 
    }
}
int main(){
    fast_cin();
    solve();
    return 0;
}