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
#define MOD 1000000007
#define N 200005
vi dp; 
void solve(){
    int n; 
    cin>>n; 
    int moves; 
    cin>>moves; 
    int ans = 0; 
    while(n){
        int num = n%10; 
        n/=10; 
        int lmoves = moves - (10 - num); 
        if(lmoves >= 0){
            ans += dp[lmoves]; 
            ans %= MOD; 
        }
        else{
            ans += 1; 
        }
    }
    cout<<ans<<endl; 
}
int main(){
    fast_cin();
    ll test;
    cin >> test;
    dp = vi(N,2);
    // we are considering dp as number of digits obtained by applying operation on 01 string
    // when steps are < 9 then we can't explode any digit so digit remains 2
    // otherwise we can explode digits
    // also when we have 9 moves we can only explode 1 and no more explosion left
    dp[9] = 3; 
    for(int i=10;i<N;i++){
        dp[i] = dp[i-9] + dp[i-10]; 
        dp[i] %= MOD; 
    }
    while(test--){
        solve();
    }
    return 0;
}