// reversing substring then applying some operation on it is quickly done by moving from center to outwards
// for a center of reversing substring we can find product of reversed and original string easily 
// also we can have prefix and suffix multiplication of remianing string 
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
void solve(){
    int n; 
    cin>>n; 
    vll a(n),b(n); 
    for(auto &i: a) cin>>i; 
    for(auto &i: b) cin>>i; 
    vll prefix(n),suffix(n); 
    prefix[0] = a[0]*b[0]; 
    for(int i=1;i<n;i+=1){
        prefix[i] = prefix[i-1] + a[i]*b[i]; 
    }
    suffix.back() = a.back()*b.back(); 
    for(int i=n-2;i>=0;i-=1){
        suffix[i] = suffix[i+1] + a[i]*b[i]; 
    }
    // now find each substring 
    // debug(suffix,prefix); 
    ll maxSum = prefix.back(); 
    for(int i=0;i<n;i+=1){
        // odd length
        int l = i-1; 
        int r = i+1; 
        ll sum = a[i]*b[i]; 
        while(l>=0 and r < n){
            sum += a[l]*b[r]; 
            sum += a[r]*b[l]; 
            l--,r++; 
            maxSum = max(maxSum,sum + ((l>=0)? prefix[l]: 0) + ((r < n)? suffix[r] : 0)); 
        }
        // even length 
        l = i,r = i+1,sum = 0; 
        while(l>=0 and r < n){
            sum += a[l]*b[r]; 
            sum += a[r]*b[l]; 
            l--,r++; 
            maxSum = max(maxSum,sum + ((l>=0)? prefix[l]: 0) + ((r < n)? suffix[r] : 0)); 
        }
    }
    cout<<maxSum<<endl; 
}
int main(){
    fast_cin();
    ll test = 1; 
    while(test--){
        solve();
    }
    return 0;
}