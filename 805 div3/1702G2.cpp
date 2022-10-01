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
int n,x,y; 
vvi graph; 
vvi parents; 
vi in,out,height; 
int timer = 0; 
void dfs(int node,int parent,int ht = 0){
    parents[node][0] = parent; 
    height[node] = ht;
    in[node] = timer++; 
    for(auto &nbr: graph[node]){
        if(nbr == parent) continue; 
        dfs(nbr,node,ht+1); 
    }
    out[node] = timer++; 
}
void parentsData(){
    // fill all parents data 2^ith parent of each node
    for(int i=1;i<=n;i+=1){
        for(int p=1;p<32;p+=1){
            auto x = parents[i][p-1]; 
            parents[i][p] = parents[x][p-1];
        }
    }
    cerr<<"parents generated"<<endl; 
}
int findKthParent(int node,int k){
    int p = node; 
    for(int i=0;k;i+=1){
        if(k&1){
            p = parents[p][i]; 
        }
        k>>=1; 
    }
    return p; 
}
int findLCA(int x,int y){
    cerr<<"finding LCA of "<<x<<" "<<y<<endl; 
    for(int i=31;i>=0;i-=1){
        if(parents[x][i] != parents[y][i]){ // then start over again from i-1 and go more near to breaking point
            x = parents[x][i]; 
            y = parents[y][i]; 
        }
    }
    return parents[x][0]; 
}
int LCA(int x,int y){
    // first take them to same height then find LCA using binary search 
    if(height[x] < height[y]){
        y = findKthParent(y,height[y] - height[x]);
    }
    else x = findKthParent(y,height[x] - height[y]); 
    // now both are at same height find who those are 
    if(x == y) return x; 
    return findLCA(x,y);
}
void solve(){
    cin>>n; 
    graph = vvi(n+1); 
    parents = vvi(n+1,vi(32,-1)); // -1 be parent of all  
    height = in = out = vi(n+1); 
    for(int i=0;i<n-1;i+=1){
        cin>>x>>y; 
        graph[x].push_back(y); 
        graph[y].push_back(x); 
    }
    // graph formed now find in and out time of nodes and parents
    parentsData(); 

}
int main(){
    fast_cin();
    solve();
    return 0;
}
