#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  
#include <cmath>
// for every node store min time it takes to each depth = 0 
// if that path is adventagious that consider to compute it's node values otherwise not 
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
v32 ans; 
int sz; 
bool dfs(v32 &a,v32 &b,v32 &vis,v32 &res,int depth,int time =0 ){
    if(depth == 0){
        if(res.size() < sz){
            ans = res;
            sz = ans.size();  
        } 
        return true; 
    }
    if(vis[depth] <= time){
        return false; 
    }
    vis[depth]= time; 
    bool fnd = false;  
    for(int i=0;i<=a[depth];i++){ // take jump and then slip from that position call dfs from this new position
        res.push_back(depth - i); 
        fnd |= dfs(a,b,vis,res,depth - i + b[depth - i],time+1); 
        res.pop_back(); 
    }
    if(!fnd){
        vis[depth] = 0; // never go through this path again 
    }
    return fnd;
}
void solve(){
    int n; 
    cin>>n; 
    v32 a(n + 1),b(n + 1); 
    // we have total of n positions where we can fall and 0th position is resulting position that we wants
    v32 vis(n+1,INT_MAX); 
    v32 res; 
    sz = INT_MAX; 
    for(int i=1;i<=n;i++) cin>>a[i]; 
    for(int i=1;i<=n;i++) cin>>b[i]; 
    b[0] = a[0] = 0; // no more slipping from top 
    ans = v32(); 
    dfs(a,b,vis,res,n); 
    if(ans.size()){
        cout<<ans.size()<<endl; 
        for(auto &i: ans) cout<<i<<" "; 
    }
    else{
        cout<<-1<<endl; 
    }
}
int main()
{
    fast_cin();
    ll test = 1; 
    while(test--){
        solve();
    }
    return 0;
}