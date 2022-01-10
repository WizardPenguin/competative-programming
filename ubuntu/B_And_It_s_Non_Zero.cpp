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
#define N 200005
vvi dp(N,vector<int>(30,0)); 
void solve(){
    int l,r; 
    cin>>l>>r; 
    vi arr(30,0); 
    int maxi =log2(r); 
    for(int i=0;i<30;i++){
        arr[i] = dp[r][i] - dp[l-1][i]; 
    }
    // for(auto &i: arr) cout<<i<<" "; 
    int ans = r - l + 1; 
    for(int i=0;i<=maxi;i++){
        if(arr[i] != (r - l + 1))
        ans = min(ans,arr[i]); 
    }
    cout<<ans<<endl; 
}
int main(){
    fast_cin();
    ll test;
    for(int i=1;i<N;i++){
        dp[i] = dp[i-1]; // for making cumelative sum 
        for(int b=0;b<30;b++){
            if(  (i&(1<<b)) == 0){
                dp[i][b]++; 
            }
        }
    }
    cin >> test;
    while(test--){
        solve();
    }
    return 0;
}