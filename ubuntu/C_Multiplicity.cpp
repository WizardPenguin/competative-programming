// different dp state is defined by count of possibilities till index i for some k 
// dp[i][k] is count of subsequencies possible of size = k 
// but due to constraint k we can't use 2d dp instead reusing previous array for next dp for each k 
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
const int mod = 1e9+7; 
// dp[i] defines for some k how many possibilities are there ending at index i 
// dp[i][k] = dp[i-1][k-1]; if v[i]%k == 0 
// means using previous value in previous dp which needs to be presurved before use
void solve(){
    int n; 
    cin>>n; 
    vi v(n); 
    for(int i=0;i<n;i++) cin>>v[i]; 
    vll dp(n+1,0);  // k can be from 1 .. n 
    dp[0] = 1; // i=0 and k = 0 1 possibility 
    dp[1] = 1; // for i = 0 which is previus dp array 
    ll res = 0; 
    for(int i=1;i<n;i++){
        // for v[i] we'll update only for k which are desiring update
        // find all indices(k's) that divides it , might be more than n 
        vi id; 
        auto val = v[i]; 
        for(ll x=1;x*x <= val; x++){
            if(val %x == 0){
                id.push_back(x); 
                if(val/x != x){
                    id.push_back(val/x); 
                }
            }
        }
        sort(all(id));
        // for(auto &x : id) cout<<x<<" "; 
        int j=id.size()-1; 
        while(id[j] > n) j--; 
        // dp[0] = 1 meakes update for k=1 for each i = 1 easier so it needs to be there 
        while(j >=0){
            dp[id[j]] += dp[id[j]-1]; 
            dp[id[j]] %= mod; 
            j--; 
        }
    }
    for(int i=1;i<=n;i++) res = (res + dp[i])%mod; 
    cout<<res<<endl; 
}
int main(){
    fast_cin();
    solve(); 
    return 0;
}