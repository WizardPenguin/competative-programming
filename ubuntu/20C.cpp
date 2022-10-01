// shortest path between vertex n and vertex 1
// simply use djkstras
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
 

void solve(){
    int n,m;
    cin>>n>>m; 
    vvpll graph(n+1);
    for(int i=0;i<m;i+=1){
        ll x,y,w; 
        cin>>x>>y>>w; 
        graph[x].push_back({y,w});
        graph[y].push_back({x,w});
    }
    // now use priority queue for implementing djsktras 
    priority_queue<pll,vpll,greater<pll> > pq; 
    pq.push({0,1}); // 1 at distance = 0; 
    vector<ll> dist(n+1,LLONG_MAX);
    vector<int> parent(n+1);
    parent[1] = -1; 
    dist[1] = 0; 
    while(not pq.empty()){
        auto [d,u] = pq.top(); pq.pop();
        if(dist[u] != d) continue; 
        for(auto &[v,w] : graph[u]){
            if(d + w < dist[v]){
                parent[v]= u; 
                dist[v] = d + w; // shorter distance stored 
                pq.push({dist[v],v});
            }
        }
    }
    if(dist[n] == LLONG_MAX){
        cout<<-1<<endl;
    }
    else{
        vector<int> res; 
        int node = n; 
        while(parent[node] != -1){
            res.push_back(node);
            node = parent[node]; 
        }
        res.push_back(1);
        reverse(all(res));
        for(auto &i: res) cout<<i<<" "; 
        cout<<endl; 
    }
}
int main(){
    fast_cin();
    solve();
    return 0;
}