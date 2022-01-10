// higher order digits are deciders
// create prefix sum of digits if it's higher then required sum 
// then decrease current number to 0 
// for that it requires to increase next bit 
// after then find steps required to get resulting number 
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
    ll n,s; 
    cin>>n>>s; 
    auto tp = n; 
    int d = log10(n); 
    vi digits(d+2,0),newn(d +2,0); 
    // since we might have increase of 1 digit in solution
    int i=0; 
    while(n){
        digits[i] = n%10 ;
        n/=10;
        i++; 
    }
    newn = digits; 
    // now generate prefix sum of digits 
    --i; 
    // return; 
    while(i >= 0){
        digits[i] += digits[i+1];
        i--; 
    }
    for(int i=0;i<d+1;i++){
        if(digits[i] > s){
            // means make it - and increase next digit with 1 
            newn[i+1] += 1; 
            digits[i+1] += 1; // sum is also increased 
            newn[i] = 0; // make this particular digit = 0 
        }
    }
    // now create new number 
    ll res = 0; 
    for(int i=d+1;i>=0;i--){
        res = res*10 + newn[i]; 
    }
    cout<<(res - tp)<<endl; 
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