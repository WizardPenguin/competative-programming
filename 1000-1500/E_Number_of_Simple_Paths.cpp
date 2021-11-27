// n vetices with n edges in connected graph tells only 1 cycle is going to be there 
// cycle causes many nodes to have 2 different paths to reach other nodes 
// except the nodes in subtree attached to cycle they have single path between each other to reach them 
#include <bits/stdc++.h> 
#include <complex>
#include <cmath>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
vector<int> nodes; 
int start,nd; 
vector<int> parent; 
void findCycle(vv32 &graph,v32 &visited,int node,int par = -1){
    visited[node] = true; 
    parent[node] = par;  // this is made to triverse back the cycle 
    for(auto nbr: graph[node]){
        if(nbr == par) continue; 
        if(visited[nbr]){
            // marking start and end of cycle
            nd = nbr; 
            start = node; 
        }
        else{
            findCycle(graph,visited,nbr,node);
        }
    }
    return;
}
int dfs(vv32 &graph,int node,int par = -1){
    // since we are having tree triversal no visited array required 
    int ans = 1; 
    for(auto &nbr: graph[node]){
        if(nbr == par) continue; 
        if(!binary_search(all(nodes),nbr)){
            ans += dfs(graph,nbr,node); 
        }
    }
    return ans; 
}
int main()
{
    fast_cin();
    ll test;
    cin >> test;
    while(test--){
        ll n; 
        cin>>n; 
        vv32 graph(n+1); 
        nodes.clear(); 
        vector<int> visited(n+1,false); 
        int x,y; 
        parent = vector<int>(n+1,-1);
        for(int i=0;i<n;i++){
            cin>>x>>y; 
            graph[x].push_back(y); 
            graph[y].push_back(x); 
        }
        findCycle(graph,visited,1,-1); 
        // get cycle nodes and start dfs from each node
        nodes.push_back(start); 
        while(nd != start){
            nodes.push_back(nd); 
            nd = parent[nd]; 
        }
        // for(auto i: nodes) cout<<i<<" "; cout<<endl; 
        sort(all(nodes));  
        ll solution = n*(n-1); // let all have 2 path to every other nodes 
        // is singe path was there solution is n*(n-1)/2 since path fron a->b and b->a are same 
        // now we multiplied it with 2 to get solution when there are 2 paths
        // so tree nodes needs to be removed once 
        for(int i=0;i<nodes.size();i++){
            ll count = dfs(graph,nodes[i],-1); 
            solution -= count * (count-1)/2; 
        } 
        cout<<solution<<endl; 
    }
    return 0;
}