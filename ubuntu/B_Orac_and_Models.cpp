// we are desired to have indexes sorted such that values at those indices are strictly increasing 
// for each index we can find all it's multiple index and update them if they have value > current 
// update only happens if this current index gives more elements compared to previous data
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
    n++; 
    vi v(n); 
    for(int i=1;i<n;i++) cin>>v[i]; 
    // now we are desired to have prime seive type movement for each index update all it's multiples 
    vi dp(n,1); // everyone can make valid set of single element 
    for(int i = 1;i<n;i++){
        for(int j=i+i; j< n; j+= i){
            if(v[j] > v[i] and (dp[j] < dp[i] + 1)){
                // then we can update dp 
                dp[j] = dp[i] + 1; 
            }
        }
    }
    // at end print largest dp value 
    int ans = 1; 
    for(auto &i: dp){
        ans = max(ans,i); 
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