#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  
#include <cmath>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 

void solve(){
    ll n,m; 
    cin>>n>>m;
    // case when m == 0
    if(m == 0){
        cout<<n<<" "<<n<<endl; 
        return; 
    }
    int mini; 
    for(ll i=2;i<=n;i++){
        // try to form complete graph with each node having edge to each other node
        if(i*(i-1)/2 >= m){
            mini = i; 
            break; 
        }
    } 
    ll maxi = min(2*m,n);
    cout<<n - maxi<<" "<<n - mini<<endl;  
}
int main()
{
    fast_cin();
    ll test = 1; 
    while(test--){
        solve();
    }
    return 0;
}