// envelop has n stemps and no stemp repeat 
// means this generates a linear path from a starting node to ending node (having only 1 edge)
// we need to generate that path from start->end from given stemps
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
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
void dfs(map<int,vector<int> > &graph,int node,int par){
    cout<<node<<" "; 
    for(auto &i: graph[node]){
        if(i == par) continue; 
        dfs(graph,i,node);
    }
}
int main()
{
    fast_cin();
    int n; 
    cin>>n; 
    map<int,vector<int> > mp; 
    int a,b; 
    for(int i=0;i<n;i++){
        int a,b; 
        cin>>a>>b; 
        mp[a].push_back(b); 
        mp[b].push_back(a); 
    }
    int node = -1; 
    for(auto &i: mp){
        if(i.second.size() == 1){
            node = i.first; 
            break;  
        }
    }
    dfs(mp,node,-1); 
    cout<<endl; 
    return 0;
}