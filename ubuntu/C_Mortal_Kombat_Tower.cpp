// every time we are having 2 options either take 1 or 2 elements
// dp[i][turn] = min kills made by friend(0) if at index i , turn is going to make move 
// result is dp[i][0]
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
array<vi,2> dp;
int n;  
int recursive(vi &v,int i,int turn){
    if(i >= n){
        return 0; 
    }
    // we have 2 choices and take one which gives min kills by friend
    if(dp[turn][i] != -1) return dp[turn][i];
    if(turn == 0){
        dp[turn][i] = min(recursive(v,i+1,1-turn) + v[i],recursive(v,i+2,1-turn) + v[i] + v[i+1]); 
    }
    else{
        dp[turn][i] = min(recursive(v,i+1,1-turn),recursive(v,i+2,1-turn)); 
    }
    return dp[turn][i]; 
}
void solve(){
    cin>>n; 
    vi v(n); 
    for(int i=0;i<n;i++) cin>>v[i]; 
    v.push_back(0);
    v.push_back(0);
    dp[0] = dp[1] = vi(n,-1); 
    cout<<recursive(v,0,0)<<endl; 
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