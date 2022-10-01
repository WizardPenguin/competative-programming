#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
// we can adjust very element between min of array and max of array without changing score of array 
// after then if something remaining then we have to insert 1 and x in array any other remaining will adjust themselves
// 1 should be placed at minimum element (shurely it is going to have double occurence now) cost = mini-1 + mini-1
// or 1 can be placed at edges giving score = edge-1 from both side
// similarly x should be placed at max element placing it near other will definately give more score
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
    int n,x; 
    cin>>n>>x; 
    vi v(n); for(int i=0;i<n;i+=1) cin>>v[i]; 
    int maxi = v[0]; 
    int mini = v[0]; 
    ll ans = 0; 
    for(int i=1;i<n;i+=1){
        ans += abs(v[i] - v[i-1]); 
        maxi = max(maxi,v[i]); 
        mini = min(mini,v[i]); 
    }
    // now find cost 
    if(maxi < x){
        ans += min({2*(x - maxi),abs(x - v[0]), abs(x - v.back())});
    }
    if(mini > 1){
        ans += min({2*(mini - 1),abs(v[0] - 1), abs(v.back() - 1)}); 
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