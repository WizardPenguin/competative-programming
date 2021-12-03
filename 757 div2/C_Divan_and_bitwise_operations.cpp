#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  
#include <cmath>
 
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
#define MOD 1000000007
ll power(ll n){
    ll v = 2; 
    ll ans = 1; 
    while(n){
        if(n&1){
            ans *= v; 
            ans %= MOD; 
        }
        v *= v; 
        v %= MOD; 
        n >>= 1; 
    }
    return ans; 
}
ll xm(vector<int> &arr){
    // we have 1 extra usused element 
    ll n = arr.size(); 
    ll b = 0;
    for (ll i=1; i<n; ++i) b |= arr[i];
    ll ans = b*power(n-2); 
    return ans%MOD;
}
void solve(){
    int n; 
    cin>>n; 
    vector<int> arr(n+1,0); 
    // cout<<(arr[0] == INT_MAX)<<endl; 
    int m; 
    cin>>m; 
    for(int i=0;i<m;i++){
        ll l,r,o; 
        cin>>l>>r>>o; 
        arr[l] |= o; 
        if(l != n) // it's last element of array or it's last element of segment 
        arr[l+1] |= o; 
        arr[r] |= o; 
    }
    for(int i=1;i<=n;i++){
        if(arr[i] == INT_MAX){ // nothing told about this number
            arr[i] = 0; 
        }
    }
    cout<<xm(arr)<<endl; 
}
int main()
{
    fast_cin();
    ll test;
    cout<<fixed; 
    cin >> test;
    while(test--){
        solve();
    }
    return 0;
}