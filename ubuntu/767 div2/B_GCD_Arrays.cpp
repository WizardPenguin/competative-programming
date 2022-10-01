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
// if l == r no options 
// if l == r+1 then only 1 can be in gcd so necessary remove 1 
// if(l is even) then better make gcd = 2 remove half elements 
// otherwise try and check for 3 also weather it can be or not 
void solve(){
    int l,r,k; 
    cin>>l>>r>>k; 
    if(l == r){
        if(l == 1) cout<<"NO"<<endl; 
        else cout<<"YES"<<endl; 
    }
    else if(l == r -1){
        if(k >= 1){
            cout<<"YES"<<ln; 
        }
        else{
            cout<<"NO"<<ln; 
        }
    }
    else{
        int multiples = r/2 - (l-1)/2;
        int multiples2 =  r/3 - (l-1)/3; 
        // dbg(multiples2); 
        // dbg(multiples); 
        int rem = (r - l + 1) - max(multiples,multiples2); 
        // dbg(rem); 
        if(rem <= k){
            cout<<"YES"<<endl; 
        } 
        else{
            cout<<"NO"<<endl; 
        }
    }
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