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
vi path; 
set<int> toReach; 
vb visited;
ll ans = 0; 
int x,y,n,k,u,v; 
bool dfs(int node,int parent){
    if(node == y){
        path.push_back(node); 
        return true; 
    }
    for(auto &nbr: graph[node]){
        if(nbr != parent){
            if(dfs(nbr,node)){
                path.push_back(node); 
                return true; 
            }
        }
    }
    return false; 
}
bool find(int node,int distance = 0){
    bool ret = false; 
    bool needTake = (toReach.find(node) != toReach.end()); 
    for(auto &nbr: graph[node]){
        if(not visited[nbr]){
            visited[nbr]=true; 
            if(find(nbr,(ret == false)?distance + 1: 1)){
                ret =true; 
            }
        }
    }
    if((not ret) and needTake){ // if this path has not been used anywhere in feture then use it here and tell previous
        ans += 2*distance; 
        return true; 
    }
    return ret;  
}
void solve(){
    path.clear(); 
    cin>>n>>k>>x>>y;  
    graph = vvi(n+1); 
    visited = vb(n+1,false); 
    toReach.clear(); 
    for(int i=0;i<k;i+=1){
        int val; cin>>val; 
        toReach.insert(val);  
    }
    for(int i=0;i<n-1;i+=1){
        cin>>u>>v; 
        graph[u].push_back(v); 
        graph[v].push_back(u); 
    }
    dfs(x,-1); 
    ans = path.size()-1; 
    for(auto &node: path) visited[node] = true;
    for(auto &node: path){
        find(node); 
    }
    cout<<ans<<endl; 
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