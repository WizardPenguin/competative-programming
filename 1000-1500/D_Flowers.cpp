// we found recurrence for all i < k dp[i] = 1; // only 1 way 
// otherwise we have dp[i] = dp[i-1] + dp[i+1]; 
// at end we can take sum of all from i,j for efficient we can precompute prefix sum for 1..1e5 then O(1) for each test case
#include <bits/stdc++.h> 
#include <complex>
#include <cmath>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define N 1e5 + 5
const int MOD = 1e9 + 7;
int main()
{
    fast_cin();
    ll test;
    cin >> test;
    int k; 
    cin>>k; 
    v64 dp(N,1); 
    // this can be further optimized by taking all queries and finding what is max n they are asking 
    for(int i=k;i<N;i++){
        dp[i] = (dp[i-1] + dp[i-k])%MOD; 
    }
    // now compute prefix sum 
    for(int i=1;i<N;i++){
        dp[i] += dp[i-1]; 
        dp[i]%=MOD;
    }
    while(test--){
        int a,b; 
        cin>>a>>b;
        cout<<(dp[b] - dp[a-1] + MOD)%MOD<<endl; 
    }
    return 0;
}