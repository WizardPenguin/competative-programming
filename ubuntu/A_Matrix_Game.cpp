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
    // we can only color numbers which have no 1 in their row or column 
    // so changing any color will eliminate 1 row and 1 column at a time 
    // count no of row r and column c available for chang e
    // if min(r,c) is odd then Ashish wins others Vivek wins
    int n,m; 
    cin>>n>>m; 
    vvi v(n,vi(m)); 
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin>>v[i][j]; 
    }
    // now check how many rows and column are avaiable 
    vb r(n,false); 
    vb c(m,false); 
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j] == 1){
                r[i] = c[j] = true; 
            }
        }
    }
    int rc=0,cc = 0; 
    for(int i=0;i<n;i++){
        if(!r[i]) rc++; 
    }
    for(int i=0;i<m;i++){
        if(!c[i]) cc++; 
    }
    if(min(rc,cc)%2){
        cout<<"Ashish"<<endl; 
    }
    else{
        cout<<"Vivek"<<endl; 
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