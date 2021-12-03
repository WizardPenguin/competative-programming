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
ll n,h; 
bool check(vector<ll> &v,ll mid){
    ll damage = 0; 
    for(int i=0;i<n-1;i++){
        damage += min(mid,v[i+1] - v[i]); 
        if(damage >= h) return true; 
    }
    damage += mid;  // final daggar 
    if(damage >= h) return true; 
    return false; 
}
void solve(){
    cin>>n>>h; 
    vector<ll> v(n); 
    for(int i=0;i<n;i++) cin>>v[i]; 
    ll l = 1; 
    ll r = h; 
    // int count =0; 
    while(l <= r){
        // count++; 
        // if(count > 100) break; 
        ll mid = (l + r)/2; 
        if(check(v,mid)){
            r = mid-1; 
        }
        else{
            l = mid+1; 
        }
    }
    // dbg(count); 
    cout<<(r+1)<<endl; 
}
int main()
{
    fast_cin();
    ll test;
    cin >> test;
    while(test--){
        solve();
    }
    return 0;
}