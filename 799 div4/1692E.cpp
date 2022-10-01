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
    int n,s;
    cin>>n>>s; 
    vi v(n); for(auto &i: v) cin>>i; 
    vi pref = v; 
    for(int i=1;i<n;i+=1) pref[i] += pref[i-1];
    pref.insert(pref.begin(),0);
    // cerr<<pref.back()<<endl; 
    if(pref.back() < s){
        cout<<-1<<endl; 
        return; 
    }
    int ans = INT_MAX; 
    map<int,int> mp; 
    mp[0] = 0; 
    for(int i=1;i<=n;i+=1){
        if(mp.find(pref[i] - s) != mp.end()){
            ans = min(ans,mp[pref[i] - s] + n - i); 
        }
        if(mp.find(pref[i]) == mp.end())
        mp[pref[i]] = i; 
    }
    cout<<ans<<endl; 
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