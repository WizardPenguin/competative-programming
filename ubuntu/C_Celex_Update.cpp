// generating for 3,3 we got 5 means 3-1*3-1 + 1
// generating for 2,2 we get 2 means 2-1 * 2-1 +1
// genearting for 2,3 we get 3 means 2-1*3-1 + 1
// in general for x,y we get (x-1)*(y-1) + 1
// each range can be tarnsformed back to 0,0 to some x,y moves
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
    ll x1,y1,x2,y2; 
    cin>>x1>>y1>>x2>>y2; 
    ll x = abs(x2-x1 +1); 
    ll y = abs(y2 - y1+1); 
    cout<<(x-1)*(y-1) + 1<<ln;  
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
