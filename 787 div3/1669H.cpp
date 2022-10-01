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
    int n,k; 
    cin>>n>>k; 
    vi v(n); 
    for(int i=0;i<n;i+=1) cin>>v[i]; 
    vector<int> count(31,0); 
    for(int i=0;i<n;i+=1){
        for(int j=0;v[i]; j+=1){
            count[j] += (v[i]&1); 
            v[i] >>= 1; 
        }
    }
    // we need to find which bits are set using count 
    for(int i=30;i>=0;i-=1){
        int needed = n - count[i]; 
        if(k >= needed){
            count[i] += needed; 
            k -= needed; 
        }
    }
    // now check which bit is ON
    ll ans = 0;  
    for(int i=0;i<31;i+=1){
        if(count[i] == n){
            ans += (1<<i); 
        }
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