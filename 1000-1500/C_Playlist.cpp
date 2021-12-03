/// sort in increasing order 
// for having max pleasure we need largest length with some good min buty 
// so for each min beauty we'll take largest length and multiply them to find max pleasure 
// after we have found atlest k elements we need to pop element with min length so k values with larger length are in playlist 

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
    int n,k;
    cin>>n>>k; 
    vp32 v(n); 
    for(auto &i: v){
        cin>>i.first>>i.second; 
    }
    sort(all(v),[](auto &a,auto &b){
        return a.second > b.second; // sort with decreasing beauty 
    });
    // for(auto &i: v) cout<<i.first<<" "<<i.second<<endl; 
    priority_queue<int,vector<int>,greater<int> > q; 
    ll sum =0; 
    ll ans = 0; 
    for(int i=0;i<n;i++){
        sum += v[i].first; 
        q.push(v[i].first); 
        ans = max(ans,sum*v[i].second); 
        if(q.size() == k){
            // cout<<q.top()<<endl; 
            sum -= q.top(); 
            q.pop(); 
        }
    }
    cout<<ans<<endl; 
}
int main()
{
    fast_cin();
    ll test=1; 
    while(test--){
        solve();
    }
    return 0;
}