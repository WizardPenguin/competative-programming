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
string s;  
vs v; 
vvi mov; 
vpii dp; 
pii recursive(int i){
        int size = v[dp[i].second].length(); 
    // cout<<i<<" "; 
    if(i == s.length()){
        return {0,-1}; 
    }
    if(dp[i].first != -1) return dp[i]; 
    int ans = 1000000; 
    int foundAt = -1; 
    for(auto &nbr: mov[i]){
        // take nbr as current move 
        for(int x=1;x<=v[nbr].length();x+=1){
            auto ret = recursive(i+x); 
            if(ans > ret.first + 1){
                ans = ret.first + 1; 
                foundAt = nbr; 
            }
        }
    }
    return dp[i] =  {ans,foundAt}; 
}
void solve(){
    int n; 
    cin>>s; 
    cin>>n; 
    v = vs(n); for(auto &i: v) cin>>i;
    // debug(v);  
    mov = vvi(s.length());
    dp = vpii(s.length()+1,{-1,-1}); 
    for(int i=0;i<s.length();i+=1){
        // cerr<<i<<" "; 
        for(int j=0;j<n;j+=1){
            auto &str = v[j]; 
            if(i + str.length() > s.length()) continue; 
            bool found = true; 
            for(int offset = 0; offset < str.length();offset+=1){
                if(str[offset] != s[i+offset]){
                    found = false; 
                    break; 
                }
            }
            if(found){
                mov[i].push_back(j); 
                // cerr<<v[j]<<" "; 
            }
        }
        // cerr<<endl; 
    }
    auto ret = recursive(0); 
    if(ret.first > s.length()){
        cout<<-1<<endl; 
        return; 
    }
    cout<<ret.first<<endl; 
    int i=0; 
    // for(auto &i: dp){
    //     cout<<i.first<<" "<<i.second<<endl; 
    // }
    // return; 
    while(i<s.length()){
        int val = dp[i].first; 
        int vid = -1; 
        cout<<dp[i].second + 1<<" "<<i+1<<endl; 
        // cout<<i+1<<" "<<dp[i].second + 1<<endl; 
        for(int x = i+1; x < s.length(); x+=1){
            if(dp[x].first == val-1){
                vid = x; 
                break; 
            }
        }
        // dbg(vid);
        if(vid != -1){
            i = vid; 
        }
        else break; 
    }
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