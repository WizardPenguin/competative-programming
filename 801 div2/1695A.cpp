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
    int n,m; 
    cin>>n>>m; 
    vvi v(n,vi(m)); 
    pii maxi = {0,0}; 
    int maxElm = INT_MIN; 
    for(int i=0;i<n;i+=1){
        for(int j=0;j<m;j+=1){
            cin>>v[i][j];
            if(maxElm < v[i][j]){
                maxElm = v[i][j]; 
                maxi = {i,j}; 
            } 
        }
    }
    // find steps required to cover this maxi in every condition 
    int cmax = max(maxi.second + 1,m-maxi.second); 
    int rmax = max(maxi.first + 1,n - maxi.first); 
    cout<<cmax*rmax<<endl; 
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