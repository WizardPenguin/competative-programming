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
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
#define MOD 1000000007
void solve(){
    int x,k; 
    cin>>x>>k; 
    vector<ll> dp(x+1,0); 
    dp[0] = 1;
    queue<int> q; q.push(0);  
    unordered_map<int,int> mp,tmp;
    tmp[0] = 1;
    for(int i=k;not q.empty();i+=1){
        int sz = q.size(); 
        for(int j=0;j<sz;j+=1){
            auto tp = q.front(); q.pop(); 
            for(int steps = i; steps + tp <= x; steps += i){
                dp[tp + steps] += tmp[tp]; 
                dp[tp + steps] %= MOD; 
                if(mp[tp+steps]){
                    mp[tp+steps] += 1; 
                }
                else{
                    mp[tp+steps] = 1; 
                    q.push(tp + steps);
                }
            }
        }
        swap(mp,tmp); 
        mp.clear(); 
    }
    for(int i=1;i<=x;i+=1) cout<<dp[i]<<" "; cout<<endl; 
}
// int dp[100][100]; 
// int x,k; 
// int recursive(int n,int increase){
//     if(n == x){
//         dp[n][increase] += 1; 
//         return 0; 
//     }
//     if(n > x) return 0; 
//     dp[n][increase] +=1;
//     int step = k + increase; 
//     for(int i=step;i + n <= x;i+=step){
//         recursive(n+i,increase+1); 
//     }
//     return dp[n][increase]; 
// }
// void solve(){
//     cin>>x>>k; 
//     dp[0][0] = 1; 
//     for(int i=0;i<=x;i+=1){
//         for(int j=0;j<=x;j+=1){
//             dp[i][j] = 0; 
//         }
//     }
//     recursive(0,0); 
//     for(int i=0;i<=x;i+=1){
//         for(int j=0;j<=x;j+=1){
//             cerr<<dp[i][j]<<" ";
//         }
//         cerr<<endl; 
//     }
// }
int main(){
    fast_cin();
    ll test = 1;
    while(test--){
        solve();
    }
    return 0;
}