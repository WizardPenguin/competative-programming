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
    vi v(n),f(k); 
    for(int i=0;i<n;i++) cin>>v[i]; 
    // now we need to take friends values
    for(int i=0;i<k;i++) cin>>f[i]; 
    // smallest number is going to be smallest in atlest 1 array 
    // so we can take it with largest number and removing smaller element in between as max as possible 
    // so we are going to take largest and all smallest from other part with it  
    sort(all(v),greater<int>()); 
    sort(all(f)); 
    // first give to those which needs only 1 since they are going to take largest number
    // after then entertain largest requires for friends first so that they takes end pointer nearer to larger numbers
    int start =0 ; 
    int end = n-1; 
    ll res = 0; 
    int s = 0; 
    while(s < k and f[s] == 1){
        s++; 
        res += 2*v[start]; 
        start++; 
    }
    // now deal with remaining in decreasing order 
    // cout<<start<<endl; 
    for(int i=k-1;i>=s;i--){
        auto friends = f[i]; 
        res += v[start]; 
        start++; 
        res += v[end]; 
        end -= (friends - 1); 
        // cout<<start<<" "<<end<<endl; 
    }
    cout<<res<<endl; 
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