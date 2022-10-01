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
    int x,y; 
    cin>>x>>y; 
    cout<<x<<" "<<y<<ln; 
    bool left = true; 
    // first conver this row 
    for(int j = y-1;j>0;j--){
        cout<<x<<" "<<j<<ln; 
    }
    // move in other direction if possible 
    if(y != m){
        // we can move right 
        for(int j=y+1;j<=m;j++){
            cout<<x<<" "<<j<<ln; 
        }
        left = false; 
    }
    // now move up 
    for(int i=1;i<=n;i++){
        if(i == x) continue; 
        if(left){
            for(int j=1;j<=m;j++){
                cout<<i<<" "<<j<<ln; 
            }
            left = false; // we have gone to right direction
        }
        else{
            for(int j=m;j>0;j--){
                cout<<i<<" "<<j<<ln; 
            }
            left = true; 
        }
    }
}
int main(){
    fast_cin();
    solve(); 
    return 0;
}