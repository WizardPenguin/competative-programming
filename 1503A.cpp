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
    // count of 1's should be even eventually 0 should be even 
    // balance 1's and 0's separately they should give us balanced sequence 
    // after then invert positions of 0's that also should give balanced sequence 
    // base cases when not possible , if 0's or 1's are odd or totoal length odd, or first or last = 0
    int n; 
    cin>>n; 
    string s; 
    cin>>s; 
    vector<int> ids[2]; 
    for(int i=0;i<n;i+=1){
        ids[s[i] - '0'].push_back(i); 
    }
    string res = s; 
    if(ids[0].size()&1 or s[0] != '1' or s.back() != '1'){
        cout<<"NO"<<endl; 
        return; 
    }
    int sz1 = ids[1].size(),sz0 = ids[0].size();
    for(int i=0;i<sz1/2;i+=1){
        res[ids[1][i]] = '('; 
        res[ids[1][sz1-1-i]] = ')';
    }
    for(int i=0;i<sz0;i+=2){
        res[ids[0][i]] = '('; 
        res[ids[0][i+1]] = ')'; 
    }
    string other = res; 
    for(int i=0;i<ids[0].size();i+=2){
        other[ids[0][i]] = ')'; 
        other[ids[0][i+1]] = '('; 
    }
    cout<<"YES"<<endl; 
    cout<<other<<endl; 
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