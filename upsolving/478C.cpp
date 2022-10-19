// we can't make pairs having all same 
// first make triplets having all different = min(a,b,c)
// now remaining are of a , b where a is larger 
// adjust double a's with single b's 
// we can make min((a + b + c)/3,(two smallest since worst case they are used once and largest used twice))
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
    ll a,b,c; 
    cin>>a>>b>>c; 
    cout<<min((a+b+c)/3,a+b+c  - max({a,b,c}))<<endl; 
}
int main(){
    fast_cin();
    ll test;
    test = 1; 
    while(test--){
        solve();
    }
    return 0;
}