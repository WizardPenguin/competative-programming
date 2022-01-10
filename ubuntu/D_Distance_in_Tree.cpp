#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
// we should return number of nodes at each distance since all are required to compute solution at any node
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
typedef vector<vector<bool> > vvb;
typedef vector<string> vs;
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
ll n,k; 
vvll graph; 
vvll dp; 
ll ans =0 ; 
// overall complexity is O(n*k)
// since for each nbr we are making computation k times 
void dfs(int node,int par){
    if(graph[node].size() == 1 and par != -1){
        dp[node][0] = 1; // means node at distance = 0 from this node is 1 all others are still 0; 
        return; 
    }
    dp[node][0] = 1; 
    for(auto &nbr: graph[node]){
        if(nbr == par) continue; 
        dfs(nbr,node); 
        for(int i=1;i<=k;i++){ // this update causes for some node parent value also updated
            // so in 2nd loop we have to take care of par since parent value are not all 0 
            // nodes at i-1 distance from nbr are at i distance from current node 
            dp[node][i] += dp[nbr][i-1]; 
        }
    }
    // now compute number of nodes which are exactly at distance == k from each other 
    // such nodes might having pair(u,v) such that u = node and v is some node in it's subtree dp[u][k]
    // or u and v both are in subtree but deriving from different child 
    ll t = 0;  
    for(auto &nbr: graph[node]){
        if(nbr == par) continue; 
        for(int i=1;i<k;i++){
            // let child of nbr be of size == i from node then other should be at k-i in some other nbr 
            t += dp[nbr][i-1]*(dp[node][k-i] - dp[nbr][k-i-1]); 
            // i.e node of size i from this nbr 
            // and node of remaining size from other child i.e. remove it from dp[node][dist] 
        }
    }
    // direct distance = k from current node to subtree node
    ans += dp[node][k]; 
    // for each u node we have considered every v possible 
    // similarly we have considered for node v so we have computed pairs twice 
    ans += t/2;  
}
void solve(){
    cin>>n>>k; 
    dp = vvll(n+1,vll(k+1,0)); 
    graph = vvll(n+1);
    int x,y; 
    for(int i=1;i<n;i++){
        cin>>x>>y; 
        graph[x].push_back(y); 
        graph[y].push_back(x); 
    }
    dfs(1,-1); 
    cout<<ans<<endl; 
}
int main(){
    fast_cin();
    solve();
    return 0;
}