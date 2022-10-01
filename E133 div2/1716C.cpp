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
vector<ll>  find(vector<ll> &v){
    int n = v.size();
    vll res(n,0); 
    res[0] = max(1ll,v[0] + 1ll); 
    ll ans = res[0]; 
    for(int i=1;i<n;i+=1){
        res[i] =  ans = max(ans + 1ll, v[i] + 1ll); 
    }
    return res; 
}
ll findCost(vector<ll> &v,int id){
    return v[id]; 
}
void solve(){
    int n; 
    cin>>n; 
    vvll v(2,vll(n)); 
    for(int i=0;i<2;i++){
        for(int j=0;j<n;j+=1) cin>>v[i][j]; 
    }
    vvll upper(2,vll(n)),lower(2,vll(n)); 
    upper[0] = find(v[0]); 
    for(auto &i: upper[0]) i = upper[0].back(); 
    reverse(all(v[0])); 
    upper[1] = find(v[0]); 
    reverse(all(v[0]));
    // lower side prefix sum  
    lower[0] = find(v[1]);
    for(auto &i: lower[0]) i = lower[0].back();  
    reverse(all(v[1])); 
    lower[1] = find(v[1]); 
    reverse(all(v[1])); 
    ll ans = 0; 
    debug(upper); debug(lower);  
    for(int i=1;i<n;i+=1){
        ans = max(ans+1,v[0][i] + 1); 
    }
    for(int i=n-1;i>=0;i-=1){
        ans = max(ans+1,v[1][i] + 1);
    }
    ll res = ans; 
    debug(res);
    bool turn = true; 
    ans = max(1ll,v[1][0]+1); 
    for(int i=1;i<n;i+=1){
        auto tp = ans; 
        ll costLower = findCost(lower[0],i); 
        ans = max(ans + n - i,costLower); 
        ll costUpper = findCost(upper[1],n-1-i); 
        ans = max(ans + n - i, costUpper); 
        debug(i,ans); 
        res = min(res,ans); 
        ans = tp; 
        ans = max(ans + 1,v[turn][i]+1); 
        ans = max(ans + 1, v[not turn][i]+1); 
        swap(lower,upper); 
        turn = not turn; 
        debug(ans); 
    }
    res = min(res,ans); 
    cout<<res<<endl; 
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