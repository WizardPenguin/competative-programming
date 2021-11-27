// participants may or maynot move 
// means only need to find min time of participant to reach any node 
// after then taking any time > min he can reach that node to catch vlad
// vlad needs to find such path for which nodes having min time should be > min time vlad reaches here 
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
 

void solve(){
    int n,k; 
    cin>>n>>k; 
    v32 f(k); 
    for(int i=0;i<k;i++){
        cin>>f[i]; 
    }
    vv32 graph(n+1); 
    int x,y; 
    for(int i=0;i<n-1;i++){
        cin>>x>>y; 
        graph[x].push_back(y); 
        graph[y].push_back(x); 
    }
    // find shortest path of f nodes to reach any node, means node going to triversed only once 
    v32 vis(n+1,false); 
    v32 dist(n+1,0); 
    queue<int> q; 
    for(int i=0;i<k;i++) q.push(f[i]),vis[f[i]]  =true; 
    int d= 0; 
    while(!q.empty()){
        int sz = q.size(); 
        d++; 
        for(int i=0;i<sz;i++){
            auto tp = q.front(); q.pop(); 
            for(auto &nbr: graph[tp]){
                if(!vis[nbr]){
                    q.push(nbr); 
                    dist[nbr] = d; 
                    vis[nbr] = true; 
                }
            }
        }
    }
    // for(int i=1;i<=n;i++) cout<<dist[i]<<" "; 
    // cout<<endl; 
    // now make bfs from root node or room no. 1
    q.push(1); 
    vis = v32(n+1,false); 
    vis[1] = true; 
    if(dist[1] == 0){ // some friend is already here
        cout<<"NO"<<endl; 
        return; 
    }
    d = 0; 
    while(!q.empty()){
        int sz = q.size(); 
        d++; 
        for(int i=0;i<sz;i++){
            auto tp = q.front(); q.pop(); 
            if(graph[tp].size() == 1 and tp != 1){ // room into which only 1 corridore leads and it's not 1 
                cout<<"YES"<<endl; 
                return; 
            }
            for(auto &nbr: graph[tp]){
                if(!vis[nbr] and dist[nbr] > d){
                    q.push(nbr);
                    vis[nbr] = true; 
                }   
            }
        }
    }
    cout<<"NO"<<endl; 
    return;  
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