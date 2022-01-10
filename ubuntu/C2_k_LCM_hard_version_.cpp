// k >= 3 means for every number we should be able to solve in 3 moves
// if n = odd then n/2 n/2 1
// if n is even n/2-1 n/2-1 (if n/2 is odd means n is not divisible by 4) and 2
// if n is divisible by 4 n/4 n/4 n/2
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
    int k; 
    cin>>n>>k; 
    for(int i=0;i<k-3;i++){
        cout<<1<<" "; 
        n--; 
    }
    if(n&1){
        cout<<n/2<<" "<<n/2<<" "<<1<<endl; 
    }
    else{
        if(n%4 == 0){
            cout<<n/4<<" "<<n/4<<" "<<n/2<<endl; 
        }
        else{
            cout<<n/2-1<<" "<<n/2-1<<" "<<2<<endl;
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