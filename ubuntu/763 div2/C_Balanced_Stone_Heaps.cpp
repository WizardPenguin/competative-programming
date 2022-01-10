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
int n; 
bool check(vll &v,ll mid){
    vll tp = v; 
    for(int i=n-1;i>1;i--){
        if(tp[i] >= mid){
            // we can give at max v[i] to previous array in multiple of 3 
            ll g = min(v[i],tp[i]-mid)/3; 
            tp[i-1] += g; 
            tp[i-2] += 2*g; 
        }
        else{
            return false; 
        }
    }
    if(tp[0] >= mid and tp[1] >= mid) return true; 
    return false; 
}
void solve(){
    cin>>n; 
    vll v(n); 
    for(int i=0;i<n;i++) cin>>v[i]; 
    ll l = 0; 
    ll r = 1e9+ 7; 
    ll ans = *min_element(all(v)); 
    while(l<=r){
        ll mid = (l + r)/2; 
        if(check(v,mid)){
            ans = mid; 
            // try to find larger answer 
            l = mid+1; 
        }
        else{
            r = mid-1; 
        }
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