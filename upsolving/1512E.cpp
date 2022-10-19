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
    int n,l,r,s; 
    cin>>n>>l>>r>>s; 
    int size = r-l+1;
    int minSum = size*(size+1)/2; 
    int maxSum = minSum + (n-size)*size; 
    debug(maxSum,minSum); 
    if(s < minSum or s > maxSum){
        cout<<-1<<endl; return; 
    } 
    vi perm; 
    int curSum = 0; 
    for(int i=0;i<size;i+=1){
        perm.push_back(n-size + i+1); 
        curSum += n-i; 
    }
    int i=0; 
    while(curSum > s){
        int required = curSum - s;
        int reduce = min(required,n-size); 
        curSum-=reduce; 
        perm[i] -= reduce; 
        i++; 
        debug(s,reduce); 
    }
    debug(perm); 
    // now we have found required numers 
    set<int> used; for(auto &i: perm) used.insert(i); 
    int num =1;
    while(--l){
        if(not used.count(num)){
            cout<<num<<" "; 
        }else l++; 
        num+=1; 
    }
    for(auto &elm: perm) cout<<elm<<" "; 
    while(num<=n){
        if(not used.count(num)){
            cout<<num<<" "; 
        }
        num+=1; 
    }
    cout<<endl; 
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