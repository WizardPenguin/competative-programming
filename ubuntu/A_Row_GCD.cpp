// from tutorial
// gcd(a,b) = gcd(a,b-a)  where a is smaller than b
// so gcd(x1,x2,....xn) = gcd(x1,x2-x1,.....xn-x1); 
// so gcd(x1 + b , ....) = gcd(x1 + b,gcd(x2-x1,x3 - x1,x4-x1 ...))
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
    int n; 
    cin>>n; 
    int q; 
    cin>>q; 
    vll v(n); 
    for(int i=0;i<n;i++){
        cin>>v[i]; 
    }
    // here we can have difference = 0
    // means elements are same in that case gcd(x,0) = x 
    // if single element is there then gcd = a + b ; 
    if(n == 1){
        while(q--){
            ll b; 
            cin>>b; 
            cout<<(v[0] + b)<<" "; 
        }
        cout<<endl; 
        return; 
    }
    sort(all(v)); 
    ll gcd = v[1] - v[0]; 
    for(int i=2;i<n;i++){
        if(v[i] - v[0]) gcd = __gcd(gcd,v[i] - v[0]); 
    }
    // now find result for each query 
    while(q--){
        ll b; 
        cin>>b; 
        ll res = __gcd(v[0] + b,gcd); 
        cout<<res<<" "; 
    }
    cout<<endl ;
}
int main(){
    fast_cin();
    solve();
    return 0;
}