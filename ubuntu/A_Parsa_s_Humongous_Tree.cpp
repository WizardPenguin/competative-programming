// optimal to take li or ri as value of given node 
// we need recursively calculate which value if good to work for any node 
// it's a tree
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
vvi graph; 
vll l,r; 
pll dfs(int node,int par){
    pll ret = {0,0}; 
    for(auto &nbr: graph[node]){
        if(nbr == par) continue; 
        auto pr = dfs(nbr,node); 
        ret.first += max(abs(l[node] - r[nbr]) + pr.second,abs(l[node] - l[nbr]) +pr.first ); 
        ret.second +=max(abs(r[node] - r[nbr]) + pr.second,abs(r[node] - l[nbr]) +pr.first ); 
    }
    return ret; 
}
void solve(){
    int n; 
    cin>>n; 
    graph = vvi(n+1); 
    l = r = vll(n+1,0); 
    for(int i=1;i<=n;i++) cin>>l[i]>>r[i]; 
    for(int i=1;i<n;i++){
        int x,y; 
        cin>>x>>y; 
        graph[x].push_back(y); 
        graph[y].push_back(x); 
    }
    auto ret = dfs(1,-1); 
    cout<<max(ret.first,ret.second)<<endl; 
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