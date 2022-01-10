// find common givers and takers
// (x,y.....) given them (y....x) everyone get's next number 
// for non common givers takers we can easily make them pairs 
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
#define N 200005
void solve(){
    int n; 
    cin>>n; 
    vi v(n+1); 
    for(int i=1;i<=n;i++) cin>>v[i]; 
    bitset<N> give; 
    bitset<N> take; 
    for(int i=1;i<=n;i++){
        if(v[i]){
            give[i] = 1; 
            take[v[i]] = 1; 
        }
    }
    auto ngive = ~give; 
    auto ntake = ~take; 
    auto common = ngive & ntake; 
    vector<int> cmn; 
    for(int i=1;i<=n;i++){
        if(common[i]) cmn.push_back(i); 
    }
    // now add remaining takers 
    int sz = cmn.size(); 
    // for(auto &i: cmn) cout<<i<<" "; cout<<endl; 
    for(int i=1;i<=n;i++){
        if(!common[i] and ntake[i]){
            cmn.push_back(i); 
        }
    }
    for(int i=0;i<sz;i++){
        if(i+1 == cmn.size()) continue; 
        v[cmn[i]] = cmn[i+1];
        ngive[cmn[i]] = 0; // it has given now 
        ntake[cmn[i+1]] = 0; // it has taken now 
    }
    // now time for remaining numbers which have not given and not taken yet 
    vi g,t; 
    for(int i=1;i<=n;i++){
        if(ngive[i]){
            g.push_back(i); 
        }
        if(ntake[i]){
            t.push_back(i); 
        }
    }
    // for(auto &i: g) cout<<i<<" "; cout<<endl; 
    // for(auto &i: t) cout<<i<<" "; cout<<endl; 
    for(int i=0;i<g.size();i++){
        v[g[i]] = t[i]; 
    }
    for(int i=1;i<=n;i++) cout<<v[i]<<" "; cout<<ln; 
}
int main(){
    fast_cin();
    solve();
    return 0;
}