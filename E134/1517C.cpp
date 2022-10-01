// always move left, if left not available then move down 
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
void dfs(vector<vector<int> > &matrix,int i,int j,int val,int count){
    // cerr<<i<<" "<<j<<endl; 
    // cerr<<count<<" dddd "<<val<<endl; 
    if(not count) return; 
    count-=1; 
    matrix[i][j] = val; 
    if(j>0 and not matrix[i][j-1]){
        dfs(matrix,i,j-1,val,count); 
    }
    else{
        dfs(matrix,i+1,j,val,count);
    }
}
void solve(){
    int n; 
    cin>>n; 
    vi p(n);
    for(auto &i: p) cin>>i; 
    vector<vector<int> > res(n,vector<int>(n,0)); 
    for(int i=0;i<n;i+=1){
        dfs(res,i,i,p[i],p[i]); 
    }
    for(int i=0;i<n;i+=1){
        for(int j=0;j<=i;j+=1){
            cout<<res[i][j]<<" "; 
        }
        cout<<endl; 
    }
}
int main(){
    fast_cin();
    ll test = 1; 
    while(test--){
        solve();
    }
    return 0;
}