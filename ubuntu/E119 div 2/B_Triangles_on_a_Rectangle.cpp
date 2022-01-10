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
 

void solve(){
    ll h,w; 
    cin>>h>>w; 
    vll v; 
    for(int i=0;i<4;i++){
        int k; 
        cin>>k; 
        ll mini = INT_MAX; 
        ll maxi = 0; 
        ll val; 
        for(int j=0;j<k;j++){
            cin>>val; 
            mini = min(val,mini); 
            maxi = max(maxi,val); 
        }
        v.push_back(maxi - mini); 
    }
    ll ans1 = max(v[0]*w,v[1]*w); 
    ll ans2 = max(v[2]*h,v[3]*h);
    cout<<max(ans1,ans2)<<endl; 
}
int main(){
    fast_cin();
    ll test;
    cin >> test;
    while(test--){
        solve();
    }
    return 0;
}