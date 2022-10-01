
// we need up down movemenet and cyclic movement in row 
// for cyclic movemenet we are going to use mod
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
    int n,k; 
    cin>>n>>k; 
    vvi matrix(n,vector<int>(n,0)); 
    int x = 0; 
    int y = 0; 
    if((k%n) == 0){
        cout<<0<<endl; 
    }
    else{
        cout<<2<<endl; 
    }
    while(k--){
        matrix[x][y] = 1; 
        x += 1; 
        y = (y+1)%n; 
        if(x == n){
            x = 0; 
            y = (y + 1)%n; 
        }
    }
    for(auto &v: matrix){
        for(auto &i: v) cout<<i; 
        cout<<endl; 
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