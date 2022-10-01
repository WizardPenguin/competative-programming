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
#define N 31

void solve(){
    int n,l;
    cin>>n>>l; 
    vi v(n); 
    for(int i=0;i<n;i++) cin>>v[i]; 
    vector<pair<int,int> > count(l,{0,0}); 
    for(auto &num: v){
        bitset<N> b = num; 
        for(int i=0;i<l;i++){
            if(b[i]){
                // if it's ON 
                count[i].first++; 
            }
            else{
                count[i].second++; 
            }
        }
    }
    ll ans = 0; 
    for(int i=0;i<l;i++){
        if(count[i].first > count[i].second){
            ans += (1<<i); 
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