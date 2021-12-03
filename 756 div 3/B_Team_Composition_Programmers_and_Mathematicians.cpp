// create teams of 2 with 1 mathematicial and 1 programmer
// then add remaining to any team to make them team of size = 4 
// after then we can also merge 2 teams to 2 peoples together to get size = 4 team 
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
    ll a,b; 
    cin>>a>>b; 
    ll xa = min(a,b); 
    ll xb = max(a,b); 
    ll teams = xa; 
    ll rem = xb - xa; 
    rem/=2; 
    ll formed = min(rem,teams); 
    cout<<formed + (teams - formed)/2<<endl; 
    return;
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