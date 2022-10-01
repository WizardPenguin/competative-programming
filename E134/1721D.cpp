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
    vector<vpii> data,tdata;
    vi a(n),b(n); 
    for(int i=0;i<n;i+=1) cin>>a[i]; 
    for(int j=0;j<n;j+=1) cin>>b[j]; 
    vpii tp;
    for(int i=0;i<n;i+=1){
        tp.push_back({a[i],b[i]}); 
    }
    data.push_back(tp); 
    int ans = 0; 
    for(int i=30;i>=0;i-=1){
        bool found = true; 
        for(auto &elm: data){ 
            array<int,2> mp;
            mp[0] = mp[1] = 0; 
            for(auto &pr: elm){
                int f1 = ((pr.first)&(1<<i))?1:0; 
                int f2 = ((pr.second&(1<<i)))?0:1; 
                mp[f1] += 1; 
                mp[f2] -= 1; 
            }
            if(mp[0] != 0 or mp[1] != 0){
                found = false; 
            }
        }
        if(found){
            ans += (1<<i); 
            // create new data by dividing them accordingly 
            for(auto &elm: data){
                vector<vvi> v(2,vvi(2)); 
                for(auto &pr: elm){
                    int f1 = ((pr.first)&(1<<i))?1:0; 
                    int f2 = ((pr.second&(1<<i)))?1:0; 
                    v[0][f1].push_back(pr.first); 
                    v[1][f2].push_back(pr.second); 
                }
                // now create new element to be inserted in new data
                tp.clear(); 
                for(int it = 0; it<v[0][0].size();it+=1){
                    tp.push_back({v[0][0][it],v[1][1][it]});
                }
                if(tp.size())
                tdata.push_back(tp); 
                tp.clear(); 
                for(int it = 0; it<v[0][1].size();it+=1){
                    tp.push_back({v[0][1][it],v[1][0][it]});
                }
                if(tp.size())
                tdata.push_back(tp); 
            }
            swap(data,tdata); 
            // data = tdata; 
            tdata.clear();
        }
    }
    cout<<ans<<endl; 
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