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
// void solve(){
//     int n; 
//     cin>>n; 
//     vi v(n); 
//     for(int i=0;i<n;i++) cin>>v[i]; 
//     vector<array<ll,3> > dp(n+1,{0,0,0}); 
//     for(int i=0;i<n;i+=1){
//         if(i+1 <= n){
//             dp[i+1][0] = max(dp[i+1][0],dp[i][0] + ((i&1)?0: v[i]));
//             dp[i+1][2] = max(dp[i+1][2],max({dp[i][0],dp[i][1],dp[i][2]}) + ((i&1)?0:v[i])); 
//         }
//         // cerr<<dp[i+1][0]<<" "<<dp[i+1][2]<<"  & "<<dp[i][0]<<" "<<dp[i][2]<<endl; 
//         if(i+2 <= n){
//             // start from here , or start from some prevous started node
//             dp[i+2][1] = max(dp[i+2][1],max(dp[i][0],dp[i][1]) + ((i&1)? v[i]: v[i+1])); 
//         }
//     }
//     // for(auto &ar: dp){
//     //     for(auto &i: ar) cerr<<i<<" "; 
//     //     cerr<<endl; 
//     // }
//     // cerr<<endl; 
//     cout<<max({dp[n][0],dp[n][1],dp[n][2]})<<endl; 
// }
void solve(){
    int n; 
    cin>>n; 
    vi v(n); 
    ll sum = 0; 
    for(int i=0;i<n;i++) cin>>v[i],sum += (i&1)?0: v[i]; 
    vi odd,even; 
    for(int i=0;i<n-1;i++){
        if(i&1){ // off index
            odd.push_back(v[i] - v[i+1]);  // i+1(even) getting replaced by v[i](odd index )
        }
        else{ // even index 
            even.push_back(v[i+1] - v[i]); 
        }
    }
    // find largest sum of subarray using kdanes algorithm 
    ll largest = 0; 
    ll current = 0; 
    for(int i=0;i<even.size();i++){
        current += even[i]; 
        if(current < 0) current =0; 
        largest = max(largest,current); 
    }
    current = 0; 
    for(int i=0;i<odd.size();i+=1){
        current += odd[i]; 
        if(current < 0) current = 0; 
        largest = max(largest,current); 
    }
    cout<<largest + sum<<endl; 
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