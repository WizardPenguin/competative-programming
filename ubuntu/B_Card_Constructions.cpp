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
#define N 300005
vll dp(N);
void solve(){
    ll n; 
    cin>>n; 
    // find lower bound till we are having a valid lower bound then we can work with it
    int id = upper_bound(all(dp),n) - dp.begin();
    int count = 0; 
    while(id > 1){
        n -= dp[id-1];
        count++; 
        id = upper_bound(all(dp),n) - dp.begin();
    }
    cout<<count<<endl; 
}
int main(){
    fast_cin();
    ll test;
    cin >> test;
    dp[0] = 0; 
    dp[1] = 2; 
    for(int i=2;i<N;i++){
        dp[i] = dp[i-1] + i*2 + i-1; 
    }
    while(test--){
        solve();
    }
    return 0;
}