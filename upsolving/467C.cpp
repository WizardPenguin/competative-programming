// for each index compute value of size m element 
// now problem reduces to taking 0 or 1 saying take or don't that ith element 
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
vvll dp; 
int n,m; 
ll recursive(vector<ll> &elm,int i,int k){
    // if k not 0 means its not valid solution but that is taken into account since this solution won't be max
    if(i >= elm.size() or k == 0) return 0; 
    if(dp[i][k] != -1) return dp[i][k];
    return dp[i][k] =  max(recursive(elm,i+1,k),recursive(elm,i+m,k-1) + elm[i]); 
}
void solve(){
    int k; 
    cin>>n>>m>>k; 
    vi v(n); 
    dp = vvll(n+1,vll(k+1,-1)); 
    for(int i=0;i<n;i+=1) cin>>v[i]; 
    vll elm; 
    ll sum = 0; 
    for(int i=0;i<m;i+=1){
        sum += v[i]; 
    }
    elm.push_back(sum); 
    for(int i=m;i<n;i+=1){
        sum -= v[i-m]; 
        sum += v[i]; 
        elm.push_back(sum); 
    }
    // for(auto &i: elm) cout<<i<<" "; cout<<endl; 
    cout<<recursive(elm,0,k)<<endl; 
}
int main(){
    fast_cin();
    ll test;
    test = 1; 
    while(test--){
        solve();
    }
    return 0;
}