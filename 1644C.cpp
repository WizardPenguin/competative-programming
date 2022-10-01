#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
// find sum of subarray of all size 
// when we want to have query for k = i we need to increase each subarray size <= i to k*i
// and take maximum from largest sized subarray + k*i 
// because if we take whole maxima + k*i maximima might not support increase i times 

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
    int n,x; 
    cin>>n>>x; vi v(n); for(auto &elm: v) cin>>elm; 
    for(int i=1;i<n;i+=1) v[i] += v[i-1]; 
    vector<int> sum;
    for(int size=1;size<=n;size+=1){
        sum.push_back(v[size-1]); 
        for(int i=1;i + size -1<n;i+=1){
            sum.push_back(v[i+size-1] - v[i-1]); 
        }
    }
    vi maxiRight(sum.size()); maxiRight.back() = sum.back(); 
    for(int i=sum.size()-2;i>=0;i-=1){
        maxiRight[i] = max(maxiRight[i+1],sum[i]); 
    }
    maxiRight.push_back(INT_MIN);
    // now find values for each k 
    vector<int> res(n+1,0); 
    res[0] = max(res[0],maxiRight[0]); 
    int prevId = 0; 
    int maxiLeft = 0; 
    for(int k=1;k<=n;k+=1){
        for(int offset =0; offset < n-k + 1;offset+=1){
            maxiLeft = max(maxiLeft,sum[prevId + offset] + k*x); 
        }
        prevId += n-k+1;
        res[k] = max(maxiLeft,maxiRight[prevId] + k*x); 
    }
    for(auto &maxi: res) cout<<maxi<<" "; cout<<endl; 
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