// we can define state using ith statement under condiration and is present at lth level 
// dp[i][j] if ith statement if for then next statement cound only be at next level = dp[i][j+1]
// dp[i][j] = sum (dp[i][k]) for k <= j next statemen can be at any level < j since ith statement is a normal statement
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
typedef vector<vector<bool> > vvb;
typedef vector<string> vs;
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
const int MOD = 1e9 + 7; 
// level are form 0 ... 
string s; 
vvll dp; 
// for(int j=0;j<=level;j++){
//     val += recursive(i+1,j); // it is sum of all previous values at level i+1 
//     // so try it without recursive calls storing prefix sum and using it where it requires
//     val %= MOD; 
// }
void solve(){
    int n; 
    cin>>n;
    dp = vvll(n,vll(n+1,0));// at max there can be n-1 levels but n can be called in else case so size = n+1 
    for(int i=0;i<n;i++){
        char c; 
        cin>>c; 
        s += c; 
    }
    // base case when last element is under consideration then we can place it in only 1 way 
    for(int i=0;i<=n;i++) dp[n-1][i] = 1; 
    for(int i=n-2;i>=0;i--){
        ll sum =0; // to store prefix sum of dp[i+1][x] that can be used for dp[i][x]
        if(s[i] == 's')
        for(int j=0;j<n;j++){ 
            sum += dp[i+1][j]; 
            sum %= MOD; 
            if(s[i] == 's'){
                dp[i][j] = sum; 
            }
        }
        else{
            for(int j=0;j<n;j++)
            dp[i][j] = dp[i+1][j+1]; 
        }
    }
    cout<<dp[0][0]<<endl; 
}
int main(){
    fast_cin();
    solve();
    return 0;
} 