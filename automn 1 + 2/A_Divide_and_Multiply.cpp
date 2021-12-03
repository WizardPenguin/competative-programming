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
void solve(){
    int n;
    cin>>n; 
    vector<ll>  v(n); 
    for(int i=0;i<n;i++) cin>>v[i]; 
    ll power = 0; 
    for(int i=0;i<n;i++){
        while((v[i]%2) == 0){
            v[i] >>=1; 
            power++; 
        }
    }
    ll powerUp = *max_element(all(v)); 
    ll ans = 0; 
    for(auto &i: v) ans += i; 
    ans -= powerUp; 
    cout<<ans + (powerUp<<power)<<endl; 
}
int main(){
    fast_cin();
    cout<<fixed; 
    ll test;
    cin >> test;
    while(test--){
        solve();
    }
    return 0;
}