// we need to pass previous edge to create greater cycle if this current chain's edge are joinding different parts
// also we are required to pass middle part already taken so don't take it again 
// but if middle part is 0 then we can't join this cycle with previous one 
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
    int n; 
    cin>>n; 
    // a specifies where is first edge going to join 
    // b specifies where is second edge going to join 
    // c specifies length of chain
    // at each step we have 2 options either continue with previous array appended
    // or create new cycle fron this chain itself
    // we are going to produce new chain if we are having edge length greater then previous 
    vi c,a,b; 
    int val; 
    for(int i=0;i<n;i++) cin>>val,c.push_back(val); 
    for(int i=0;i<n;i++) cin>>val,a.push_back(val); 
    for(int i=0;i<n;i++) cin>>val,b.push_back(val); 
    ll maxLen = 0; 
    ll middle = 0; 
    ll previous = 0; 
    for(int i=n-1;i>0;i--){
        // previous is considered as complete strip + 2 joining edges + middle part of next chain 
        // joining both cycles removes middle part so we are required to remove middle part
        // if previous cycle is being getting added 
        previous = c[i]- 1 + previous + 2;  
        // maxLen = max(maxLen,previous); 
        middle = abs(b[i] - a[i]); 
        maxLen = max(maxLen,previous + middle); 
        if(previous < middle){
            // means previous is giving less edge length as compared to adding next chain as main 
            // so we are going to start new cycle from that node itself
            previous = 0; 
        }
        else{
            previous -= middle; // so when next edge added with previous it would auto remove middle part
            // we are using previous cycle 
        }
        if(middle==0){
            previous = 0; 
        }
        // cout<<previous<<" "<<middle<<" "<<maxLen<<endl; 
    }
    cout<<maxLen<<endl; 
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