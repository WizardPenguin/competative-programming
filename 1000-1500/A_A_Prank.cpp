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
#define N 10000
 // need to find largest consecutive sequence
void solve(){
    int n; 
    cin>>n; 
    v32 v(N,0); 
    int maxi = 0; 
    for(int i=0;i<n;i++){
        int val; 
        cin>>val; 
        v[val] = 1;
        maxi = max(maxi,val); 
    }
    int i=0; 
    int ans = 0; 
    while(i<N){
        int start = i;
        if(v[i]) 
        while(i<N-1 and v[i+1]) i++; 
        // till we are getting consecutive next element in array 
        int conseLen = i - start + 1; 
        // we need to save edge elements
        ans = max(ans,conseLen - 2);
        if(i == 1000  or start == 1){ // user knows starting and ending conditions
            ans = max(ans,conseLen - 1);
        }
        i++; 
    }
    cout<<ans<<endl; 
}
int main()
{
    fast_cin();
    ll test = 1; 
    while(test--){
        solve();
    }
    return 0;
}