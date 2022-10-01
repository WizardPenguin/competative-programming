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
set<int> res; 
void add(vector<int> sides){
    int gcd = sides[0]; 
    for(int i=0;i<sides.size();i+=1){
        gcd = __gcd(gcd,sides[i]); 
    }
    // find factors of gcd and add them to solution 
    for(int i=1;i*i<=gcd;i+=1){
        if((gcd%i) == 0){
            res.insert(gcd/i); 
            res.insert(i); 
        }
    }
    return; 
}
void solve(){
    int l,r; 
    cin>>l>>r; 
    res.clear(); 
    add({l-1,r-1}); add({r-2,l}); add({l-2,r}); add({l,l-2,r-1}); add({r,r-2,l-1}); add({l,l-1,r-1,r-2});
    add({r,r-1,l-1,l-2}); 
    cout<<res.size()<<" "; 
    for(auto &i: res) cout<<i<<" "; 
    cout<<endl;  
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