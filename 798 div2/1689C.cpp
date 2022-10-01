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
typedef vector<vector<bool> > vvb;
typedef vector<string> vs;
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
vpii childs; 
// 2 cases node destructed or not 
int recursive(vvi &graph,int node,int parent){
    childs[node].first = 1; 
    vi ch; 
    for(auto &nbr: graph[node]){
        if(nbr == parent) continue; 
        childs[node].first += recursive(graph,nbr,node); 
        ch.push_back(nbr); 
    }
    // now consider case when this node is destructed
    if(ch.size() == 0){
        childs[node].second = 0; 
    }
    else if(ch.size() == 1){
        childs[node].second = childs[ch[0]].first-1; 
    }
    else{
        // take optimal one, kill 1 and infect 1 
        auto x = ch[0]; 
        auto y = ch[1]; 
        childs[node].second = max(childs[x].first + childs[y].second,childs[x].second + childs[y].first)-1; 
    }
    return childs[node].first ; 
}
void solve(){
    int n; 
    cin>>n; 
    vvi graph(n+1);
    childs = vpii(n+1,{0,0});
    int x,y;  
    // binary tree rooted at 1
    for(int i=0;i<n-1;i+=1){
        cin>>x>>y; 
        graph[x].push_back(y); 
        graph[y].push_back(x); 
    }
    // graph formation done find number of nodes in bustree and greedily save one with largest nodes
    recursive(graph,1,0); 
    cout<<childs[1].second<<endl; 
}
int main(){
    fast_cin();
    int test; 
    cin>>test; 
    while(test--){
        solve();
    }
    return 0;
}