// we can give desired triversal only if parent has been triversed earlier than all it's child
// after then we need to assign weights to edge 
// first node should get wt = 0
// after then we'll try to have prevNode + 1 wt in next node taking in account what it's parent have passed on to it
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  
#include <cmath>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
bool dfs(vv32 &graph,v32 &rank,v32 &par,int node){
    int minRank = graph.size(); 
    for(auto &nbr: graph[node]){
        if(nbr != par[node]){
            minRank = min(minRank,rank[nbr]); 
            if(!dfs(graph,rank,par,nbr)) return false; 
        }
    }
    return minRank >= rank[node]; 
}
void solve(){
    int n; 
    cin>>n;
    v32 par(n + 1); 
    vv32 graph(n+1); 
    int root; 
    for(int i=1;i<=n;i++){
        cin>>par[i]; 
        if(par[i]==i) root = i; 
        else{
            graph[par[i]].push_back(i); 
            graph[i].push_back(par[i]); 
        }
    }
    v32 rank(n+1);  // we'll store rank of each node to check using dfs weather this triversal is possible or not
    v32 pern(n);
    for(int i=0;i<n;i++){
        cin>>pern[i];
        rank[pern[i]] = i; 
    }
    if(dfs(graph,rank,par,root)){
        // it's time for weight assignment 
        // wt stores distance of node from root to this node 
        v32 wt(n+1,0); 
        for(int i=1;i<n;i++){
            auto &nd = pern[i]; 
            auto &prev = pern[i-1]; 
            int wtp = wt[par[nd]]; 
            wt[nd] = max(wtp,wt[prev] + 1);  // including parents wt and  max wt in sorted order till now
        }
        for(int i=1;i<=n;i++) cout<<wt[i] - wt[par[i]]<<" "; 
        cout<<endl;  
    }
    else{
        cout<<-1<<endl; 
    }
}
int main()
{
    fast_cin();
    ll test;
    cin >> test;
    while(test--){
        solve();
    }
    return 0;
}