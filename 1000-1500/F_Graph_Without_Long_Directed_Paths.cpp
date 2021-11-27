// to make graph having no path >= 2 then 
// for each node either all edges are towards it or all edges are away from it 
// i.e nodes have 2 properties either to take all or to give all 
// we can check weather we can give all nodes such property by using 2 coloring 
// based on colors assigned we can decide what type edge should have 
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
v32 color;  
bool dfs(vv32 &graph,int node,int clr){
    color[node] = clr;  
    for(auto &nbr: graph[node]){
        if(!color[nbr]){// node not visited
            if(dfs(graph,nbr,3-clr) == false) return false; 
        }
        else if(color[nbr] == color[node]) return false; 
    }
    return true; 
}
int main()
{
    fast_cin();
    ll test = 1; 
    while(test--){
        int n,m; 
        cin>>n>>m; 
        color = v32(n+1,0); 
        int x,y; 
        vp32 edges; 
        vv32 graph(n+1); 
        while(m--){
            cin>>x>>y; 
            edges.push_back({x,y}); 
            graph[x].push_back(y); 
            graph[y].push_back(x); 
        }
        // let colors are 1,2 then changing color is function 3 - color
        // we are having color = 0 as not visited node 
        // let color 1 means edges going far from it i.e u -> v
        if(dfs(graph,1,1)){
            cout<<"YES"<<endl; 
            for(auto &i: edges){
                if(color[i.first] == 1) cout<<1; 
                else cout<<0; 
            }
        }
        else{
            cout<<"NO"<<endl; 
        }
    }
    return 0;
}