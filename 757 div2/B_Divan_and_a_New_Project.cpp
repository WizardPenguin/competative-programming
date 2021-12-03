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
    vector<ll> v(n+1); 
    for(int i=1;i<=n;i++) cin>>v[i]; 
    vector<int> res(n+1); 
    vector<int> id(n); 
    for(int i=0;i<n;i++) id[i] = i+1; 
    sort(all(id),[&](const int &a,const int &b){
        return v[a] > v[b]; 
    }); 
    // for(auto &i: id) cout<<i<<" ";
    // cout<<endl; 
    int pos = 1; 
    int neg = -1; 
    res[0] = 0; 
    ll val = 0; 
    for(auto &i: id){
        if(pos < -neg){
            res[i] = pos; 
            pos++; 
        }
        else{
            res[i] = neg; 
            neg --; 
        }
        val += 2ll*abs(res[i])*v[i]; 
    }
    cout<<val<<endl; 
    for(auto &i: res) cout<<i<<" ";
    cout<<endl;  
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