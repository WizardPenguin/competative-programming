// use bitset store numbers possible considering consecutive numbers till ith term 
// then for i+1th term we'll get number prevBitset<<a[i+1] and a[i+1] store this in global bitset using | operation 
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
#define N 8003
void solve(){
    int n; 
    cin>>n; 
    // ith bit ON means we can form number i 
    // always we can form 0 so we have oth bit ON
    bitset<N> res(0),tp(0); 
    bitset<N> que; 
    vector<int> v(n); 
    int val; 
    cin>>val; 
    tp[val] = 1; 
    que[val]=1;
    v[0] = val; 
    for(int i=1;i<n;i++){
        cin>>val; 
        v[i] = val; 
        tp <<= val;  
        res |= tp;
        // cout<<tp<<" "<<res<<endl; 
        tp[val] = 1; // mark 0th bit ON again 
        que[val] = 1; 
    }
    int ans = 0; 
    res &= que; 
    for(int i=0;i<n;i++){
        ans += res[v[i]]; 
    }
    cout<<ans<<endl; 
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