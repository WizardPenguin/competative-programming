// decide who'll get zero 
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
 

void solve(){
    int n; cin>>n; 
    vll v(n); for(int i=0;i<n;i+=1) cin>>v[i]; 
    ll ans = LLONG_MAX; 
    for(int i=0;i<n;i+=1){ // index getting zero 
        ll start = 1; 
        ll steps = 0;
        // cerr<<i<<endl; 
        // we are required to get value <= 1 
        // cerr<<"backwards"<<endl; 
        for(int j = i-1;j>=0;j-=1){
            ll needed = (start + v[j]-1)/v[j]; 
            // cerr<<needed<<" "; 
            steps += needed; 
            start = needed*v[j] + 1; 
            // cerr<<" s: "<<start<<"  "; 
        }
        start = 1; 
        // cerr<<endl; 
        // cerr<<"forwards"<<endl; 
        for(int j=i+1;j<n;j+=1){
            ll needed = (start + v[j] - 1)/v[j];
            // cerr<<needed<<" ";  
            steps += needed;
            start = needed*v[j] + 1;
            // cerr<<" s: "<<start<<"  "; 
        }
        // cerr<<endl; 
        ans = min(ans,steps);
    }
    cout<<ans<<endl; 
}
int main(){
    fast_cin();
    ll test = 1; 
    while(test--){
        solve();
    }
    return 0;
}