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
 

void solve(){
    int n,k; 
    cin>>n>>k; 
    vi v(n); for(auto &i: v) cin>>i; 
    int i=0; 
    int ans = 0; 
    while(i<n){
        int start = i; 
        int val = v[i]; 
        while(i<n-1){
            if((val&1 and v[i+1] >= (v[i]+1)/2 )or((val&1) == 0 and v[i+1] > v[i]/2) ){
                val = v[i+1]; 
                i+=1; 
            }
            else break; 
        }
        // i was final index which was supporting everything 
        // cerr<<i-start + 1<<" "; 
        ans += max(0,i - start + 1 - k);
        i+=1; 
    }
    // cerr<<endl; 
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