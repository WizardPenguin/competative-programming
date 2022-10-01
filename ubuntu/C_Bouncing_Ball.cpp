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
    int n,start,k; 
    cin>>n>>start>>k; 
    // start++;
    // we are going to jump directly on pth cell means cells till now are not going to be used 
    // after then we are going to move with step of k 
    // find how many are not filled while moving in step of k from pth cell 
    // at each step we are going to move 1 step forward removing some cell and finding solution again 
    // so we have to take min of all solutions such found 
    string s; 
    cin>>s; 
    map<int,int> mp; 
    start--; 
    for(int i=start;i<n;i++){
        if(s[i] == '0'){
            mp[(i-start)%k] += 1; 
        }
    }
    // now it's time for removing some or 0 elements form front
    ll p,q; 
    cin>>p>>q;  
    ll costFront = 0; 
    ll costAdd = mp[0]*p;
    ll ans = costFront + costAdd;  
    for(int i=0;i + start + 1<n;i++){
        // remove ith element giving p unit of time 
        costFront += q; 
        // also we need to remove i+pth element from map 
        if(s[i+start] == '0'){
            // remove this element from map 
            mp[(i)%k]--; 
        }
        costAdd = mp[(i+1)%k]*p; 
        // dbg(costFront + costAdd); 
        ans = min(ans,costFront + costAdd);
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