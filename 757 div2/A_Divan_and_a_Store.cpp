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
    int n,l,r,k; 
    cin>>n>>l>>r>>k; 
    v32 v(n); 
    for(int i=0;i<n;i++) cin>>v[i]; 
    sort(all(v)); 
    int lb = lower_bound(all(v),l) - v.begin();
    if(lb == n){
        cout<<0<<endl; 
        return;
    } 
    int count =0 ; 
    while(lb < n and (k-(v[lb]) )>=0 and v[lb] <= r){
        k -= v[lb]; 
        lb++; 
        count++; 
    }
    cout<<count<<endl; 
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