// we need ways such that sum of 3 parts is same 
// total sum = s
// we want each part to be able to have sum = s/3
// find from starting where sum = s/3 , then find from right side weather we can get desired sum 
// middle part will automatically adjust itself 
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
    int n; 
    cin>>n; 
    vector<int> v(n);
    ll sum = 0; 
    for(int i=0;i<n;i+=1) cin>>v[i],sum += v[i];
    if(sum%3){
        cout<<0<<endl; 
        return;
    } 
    ll pref = 0;
    vi count(n+1,0);
    for(int i=n-1;i>=0;i-=1){
        pref += v[i];
        count[i] = (count[i+1] + (pref == (sum/3)));
    }
    pref = v[0]; 
    long long ans = 0; 
    for(int i=1;i<n-1;i+=1){
        if(pref == sum/3){
            // means we can find j's for it using prefix counts
            ans += count[i+1]; 
        }
        pref += v[i]; 
    }
    cout<<ans<<endl; 
    return; 
}
int main(){
    fast_cin();
    ll test = 1;
    while(test--){
        solve();
    }
    return 0;
}