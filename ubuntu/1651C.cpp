// we need to make something like cycle 
// i.e. only connecting ending nodes with other Array makes any node in first array to stop 
// whole array is still connected with other part and with each other through other part 
// we have case when end <> end connection then we need 1 edge,
//   instead of 2 edges from each end 
// so connection of ends are either same end or opposite ends ( | | or X structure )
// also connection could go to middle nodes removing either 1 edge or both edge of || or X structure
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
int findMax(vll &a,int val){
    ll mini = LLONG_MAX; 
    for(auto &i: a){
        mini = min(mini,abs(val- i)); 
    }
    return mini; 
}

void solve(){
    int n; 
    cin>>n; 
    vll a(n),b(n); 
    for(int i=0;i<n;i+=1) cin>>a[i]; 
    for(int i=0;i<n;i+=1) cin>>b[i]; 
    ll maxAstart = findMax(b,a[0]); 
    ll maxBstart = findMax(a,b[0]); 
    ll maxAend = findMax(b,a[n-1]); 
    ll maxBend = findMax(a,b[n-1]);
    // cout<<(maxAend + maxBend + maxAstart + maxBstart)<<endl; 
    ll ans = min({
        maxAend + maxBend + maxAstart + maxBstart,
        abs(a[0] - b[n-1]) + abs(a[n-1] - b[0]),
        abs(a[0] - b[0]) + abs(a[n-1] - b[n-1]),
        abs(a[0] - b[n-1]) + maxAend + maxBstart,
        maxAstart + maxBend + abs(a[n-1] - b[0]),
        maxAstart + maxBstart + abs(a[n-1] - b[n-1]),
        abs(a[0] - b[0]) + maxAend + maxBend 
    }); 
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