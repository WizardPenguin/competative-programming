// chooose last element make array equal to them
// since assignment is done from last half to first half
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
    vi v(n); 
    for(int i=0;i<n;i++){
        cin>>v[i]; 
    }
    reverse(all(v)); 
    int ans = 0; 
    // log(N) times done 
    for(int size=2;size <=n/2; size*=2){
        bool swap = false; 
        for(int i=0,j=(size/2);j<size;i++,j++){
            if(v[i] != v[j]){
                swap = true; 
                break; 
            }
        }
        if(swap)
        for(int i=1;i<size;i++){
            v[i] = v[i-1]; // make all equal 
        }
        ans += swap; 
    }
    // check for final swap if required 
    for(int i=1;i<n;i++){
        if(v[i] != v[i-1]){
            ans++; 
            break; 
        }
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