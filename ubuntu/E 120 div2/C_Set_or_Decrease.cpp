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
    ll n,k; 
    cin>>n>>k; 
    vll v(n);
    for(int i=0;i<n;i++) cin>>v[i]; 
    sort(all(v));
    // we are going to apply some reduction on first element then preform replication 
    vll suff(n); 
    suff[n-1] = v[n-1]; 
    for(int i=n-2;i>=0;i--){
        suff[i] = suff[i+1] + v[i]; 
    }
    if(suff[0] <= k){
        cout<<0<<endl; 
        return; 
    }
    ll a = suff[0]; 
    ll ans = LLONG_MAX; 
    // try to have some part and then which needs replication of first number
    // so find such number that helps taking values <= k 
    for(int i=n-1;i>0;i--){
        double sz = n - i; 
        ll steps = n-i; 
        // change first and >= i indexed elements into other elememnt x
        ll newf = ((k - a + v[0] + suff[i])/(sz + 1.0));
        newf = min(v[0],newf); // we can't make increase operations
        bool fnd = (a - v[0] - suff[i] + (sz + 1)*newf) <= k; 
        if(!fnd) newf--; 
        ans =min(ans,v[0] - newf + steps); 
    }
    // case when all values are changed 
    ll newf = (k/(n*1.0)); 
    newf = min(v[0],newf); 
    ans = min(ans,v[0] -newf + n-1 ); 
    // case when only 1st value changed
    newf = k - a + v[0]; 
    ans = min(ans,v[0] - newf);
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