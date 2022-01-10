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
typedef vector<vector<bool> > vvb;
typedef vector<string> vs;
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 

void solve(){
    // instead of triversing each segment l.r and finding product 
    // we can triverse from middle of segment and extend outwards so product can be found in O(n)
    int n; 
    cin>>n; 
    vll a(n),b(n); 
    for(int i=0;i<n;i++){
        cin>>a[i]; 
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    vll prod(n); 
    prod[0] = a[0]*b[0];
    for(int i=1;i<n;i++){
        prod[i] = prod[i-1] + a[i]*b[i]; // to find product of remaining segment quicky 
    }
    ll ans = prod[n-1]; // taking everything as it is 
    // segments can be of even and odd length 
    for(int i=0;i<n;i++){
        // centers of segment
        int j=1; 
        int l = i,r = i; 
        ll sp = a[l]*b[r]; 
        l--,r++; 
        while(l >=0 and r < n){ 
            sp += a[l]*b[r] + a[r]*b[l]; 
            ll tp = sp; 
            if(l != 0){
                tp += prod[l-1]; 
            }
            tp += prod[n-1] - prod[r]; 
            ans = max(ans,tp); 
            l--,r++; 
        }
    }
    for(int i=1;i<n;i++){
        // i and i-1 be centers of segment
        int l = i-1; 
        int r = i; 
        ll sp = 0;
        while(l >=0 and r < n){
            sp += a[l]*b[r] + a[r]*b[l]; 
            ll tp = sp; 
            if(l != 0){
                tp += prod[l-1]; 
            }
            tp += prod[n-1] - prod[r]; 
            ans = max(ans,tp); 
            l--,r++; 
        }
    }
    cout<<ans<<endl; 
}
int main(){
    fast_cin();
    solve();
    return 0;
}