// each node returns 2 values 1-> value found if every child comes back to it
// 2-> value found if 1 child not returned to it
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
typedef vector<vector<pll>> vvpll;
typedef vector<pll> vpll;
typedef vector<pii> vpii;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<vector<bool>> vvb;
#define ln "\n"
#define dbg(x) cout << #x << " = " << x << ln
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
vvpll graph; 
pll dfs(int node,int par){
    vpll v; 
    ll res = 0; 
    for(auto &nbr: graph[node]){
        auto nb = nbr.first; 
        auto wt = nbr.second;
        if(nb == par) continue;  
        if(graph[nb].size() == 1){
            v.push_back({2*wt,wt}); 
        }
        else{
            auto ret = dfs(nb,node);
            v.push_back({ret.first + 2*wt,ret.second +wt}); 
        }
        res += v.back().first; 
    }
    // difference only seen due to different wt of each edge
    // so take the largest wt edge only once 
    // this largest wt can be found in O(1) without sorting 
    sort(all(v),[&](auto &a,auto &b){
        return (a.first-a.second) > (b.first-b.second); 
    });
    // take the one with largest difference 
    return {res,res - v[0].first + v[0].second}; 
}
void solve()
{
    int n; 
    cin>>n; 
    if(n == 1){
        cout<<0<<endl; 
        return; 
    }
    graph = vvpll(n+1); 
    int x,y,w; 
    for(int i=1;i<n;i++){
        cin>>x>>y>>w; 
        graph[x].push_back({y,w}); 
        graph[y].push_back({x,w}); 
    }
    auto ret = dfs(1,-1); 
    cout<<ret.second<<endl; // means we are allowing it to have a return 
}
int main()
{
    fast_cin();
    solve();
    return 0;
}