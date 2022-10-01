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
vi visited,d; 
vvi res,graph; 
int dist(int node,int parent){ 
    d[node] = 1; // counting itself 
    for(auto nbr: graph[node]){
        if(nbr != parent){
            d[node] += dist(nbr,node); 
        }
    }
    return d[node]; 
}
void dfs(int node,int parent,int id){
    // goto lastest d[node]
    int maxi = -1; 
    int maxd = 0; 
    // cerr<<node<<" "<<id<<endl; 
    res[id].push_back(node); 
    visited[node] = true; 
    for(auto &nbr: graph[node]){
        if(nbr != parent and not visited[nbr]){
            if(maxd <= d[nbr]){
                maxi = nbr; 
                maxd = d[nbr]; 
            }
        }
    }
    // now triverse through this 
    if(maxi != -1){
        dfs(maxi,node,id); // pass same id  
    }
    for(auto &nbr: graph[node]){
        if(nbr != parent and not visited[nbr]){
            res.push_back({}); 
            dfs(nbr,-1,res.size()-1); 
        }
    }
}
void solve(){
    res.clear();
    int n; 
    cin>>n;  
    graph = vvi(n); 
    d = vi(n,0); 
    visited = vi(n,false); 
    // path is tp variable adn res stores everything to output 
    int val; 
    int parent = -1; 
    for(int i=0;i<n;i+=1){
        cin>>val; 
        if(val == i+1){
            parent = val-1; 
        }
        else{
            // we have found parent 
            graph[val-1].push_back(i); 
            graph[i].push_back(val-1); 
        }
    }
    dist(parent,parent); 
    // now find path that is feasible; 
    res.push_back({}); 
    dfs(parent,parent,0);
    cout<<res.size()<<endl; 
    for(auto &i: res){
        cout<<i.size()<<endl; 
        for(auto &j: i) cout<<j+1<<" "; 
        cout<<ln; 
    }
    cout<<ln; 
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