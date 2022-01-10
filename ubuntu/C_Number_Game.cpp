// either ashish has 2 or odd number he wins 
// so this is winning state for him 
// on other case he should given fastfinger such number so fastfinger can only make move to make Ashish win 
// means either he given number without any odd number then fastfinger substracts to gve ashish win 
// or he gives 2*(prime) then fastfinger divide by prime and given ashish win state
// of some 2*coprime is there then ashish is not guarrentied to win 
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
bool prime(int n){ // for 100 test cases O(sqrt(n)) works
    if(n == 1) return false; 
    for(ll i=2;i*i<=n;i++){
        if(n%i == 0) return false; 
    }
    return true; 
}
void solve(){
    ll n; 
    cin>>n; 
    // or having 2*p or number without odd multiple are loosing states for ashish gup 
    // without odd multiple is number in power of 2
    if(n==1 or (n!=2 and (n&(n-1))==0) or (n%2 == 0 and prime(n/2))  ){
        cout<<"FastestFinger"<<endl;   
    }
    else{
        cout<<"Ashishgup"<<endl; 
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
