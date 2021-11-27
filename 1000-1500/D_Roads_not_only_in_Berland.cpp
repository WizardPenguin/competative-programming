// we need to remove roads which are cyclic in nature so that we can construct new road instead of that to connect city
// so using construction when we found a edge adding nodes of same connected component then we need to remove that
// at end find components which are not joined with each other and make edges btw them 
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
#define N 1e3 + 3
v32 par(N,-1); 
v32 rnk(N,1); // for applying rnk optimisation 
int find(int x){
    if(par[x] == -1) return x; 
    return par[x] = find(par[x]); 
}
bool join(int x,int y){
    x = find(x); 
    y = find(y); 
    if(x == y){
        return false; 
    }
    else{
        if(rnk[x] > rnk[y]){
            // attach smaller to larger one 
            par[y] = x; 
            rnk[x] += rnk[y]; 
        }
        else{
            par[x] = y; 
            rnk[y] += rnk[x]; 
        }
    }
    // now we have joined edge successfully 
    return true; 
}
int main()
{
    fast_cin();
    int n; 
    cin>>n; 
    int x,y; 
    vp32 edges;  
    for(int i=0;i<n-1;i++){
        cin>>x>>y; 
        // now this edge is added to graph 
        // if we are not able to join
        if(!join(x,y)){
            // if we are not able to join nodes by this edge then this edge needs to be removed 
            edges.push_back({x,y}); 
        }
    }
    vector<int> needJoin; 
    for(int i=1;i<=n;i++){
        if(par[i] == -1){
            needJoin.push_back(i); 
        }
    }
    cout<<edges.size()<<endl; 
    for(int i=1;i<needJoin.size();i++){
        auto &edg = edges[i-1]; 
        cout<<edg.first<<" "<<edg.second<<" "<<needJoin[i-1]<<" "<<needJoin[i]<<endl; 
    }
    return 0;
}