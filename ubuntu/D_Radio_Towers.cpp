#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
// we are having dp[i] = dp[i-1] + dp[i-3] ..... taking a tower of some power x gives overage over even number of elements
// so we are required to have sum of these dp states for each i 
// since each point is having either ON or OFF state with same probability so all cases are divided with 2^n
// and number of valid cases possible are dp[i] ;
// base case dp[0] = 0; 
// dp[1] = 1; 
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
#define MOD 998244353
ll pwr(ll n,ll p){
    ll res = 1; 
    while(p){
        if(p&1){
            res = res*n; 
            res %= MOD; 
        }
        n = n*n; 
        n%= MOD;
        p>>=1;  
    }
    return res; 
}
void solve(){
    // we have to create two prefix sum since there are not directly depended on previous dp state 
    // it depends on states which are at odd position for particular node 
    int n ;
    cin>>n; 
    ll pre0 = 0; 
    ll pre1 = 1;
    // even numbers are going to use pre0
    // odd numbers are going to use pre1 
    for(int i=1;i<=n;i++){
        if(i&1){
            ll ans = pre1; 
            pre0 += ans; 
            pre0 %= MOD; 
        }
        else{
            ll ans = pre0;
            pre1 += ans; 
            pre1 %= MOD;  
        }
    }
    // now find 2^n and it's modulo inverse 
    ll p = pwr(2,n);
    ll pinv = pwr(p,MOD-2); 
    ll res = 1; 
    if(n&1){
        // cout<<pre1<<" "; 
        res = pre1*pinv; 
        res %= MOD; 
    }
    else{
        // cout<<pre0<<endl; 
        res = pre0*pinv; 
        res %= MOD; 
    }
    cout<<res<<endl; 
}
int main(){
    fast_cin();
    solve(); 
    return 0;
}