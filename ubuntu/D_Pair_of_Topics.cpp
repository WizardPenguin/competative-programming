#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
// ai + aj > bi + bj 
// ai - bi > bj - bi; 
// for each j find how many i are having ai - bi smaller
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
 

void solve(){
    int n; 
    cin>>n; 
    vi a(n),b(n),d(n); 
    for(int i=0;i<n;i++) cin>>a[i]; 
    for(int i=0;i<n;i++) cin>>b[i]; 
    for(int i=0;i<n;i++) d[i] = a[i] - b[i]; 
    sort(all(d)); 
    int ans = 0; 
    for(int i=0;i<n;i++){
        int chk = b[i] - a[i]; 
        auto lb = lower_bound(all(d),chk); 
        if(lb == d.end()){
            continue; // nothing found 
        }
        ans += ( lb - d.begin()) ; 
    }
    cout<<ans/2<<endl; 
}
int main(){
    fast_cin();
    solve(); 
    return 0;
}