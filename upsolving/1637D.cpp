// sum(ai + aj)*2 + sum(bi + aj)*2
// ai*2 + aj*2 + bi*2 + bj*2 + 2*ai*aj + 2*bi*bj
// minimize 2*ai*aj + 2*bi*bj
// so for any index value depend on previous sum of elements with whom current value multiplied
// dp states are swap/not + prefixSum, index
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
int dp[10004][102][2];
vi a,b; 
int n; 
int recursive(int suma,int sumb,int i,int swap){
    if(i == n) return 0; 
    if(dp[suma][i][swap] != -1) return dp[suma][i][swap];
    return dp[suma][i][swap]  = min(a[i]*suma + b[i]*sumb + recursive(suma + a[i],sumb + b[i],i+1,false),
    recursive(suma + b[i],sumb + a[i],i + 1,true) + a[i]*sumb + b[i]*suma);
}
void solve(){
    cin>>n; 
    a = b = vi(n); 
    int sumSquares = 0; 
    for(int i=0;i<n;i+=1)cin>>a[i],sumSquares += a[i]*a[i];
    for(int j=0;j<n;j+=1) cin>>b[j],sumSquares += b[j]*b[j]; 
    for(int i=0;i<10001;i+=1){
        for(int j=0;j<n;j+=1){
            dp[i][j][0] = dp[i][j][1] = -1;
        }
    }
    if(n == 1){
        cout<<0<<endl; 
        return; 
    }
    cout<<2*recursive(0,0,0,true) + (n-1)*sumSquares<<endl; 
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