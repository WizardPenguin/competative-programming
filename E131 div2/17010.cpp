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
    int n = 2,m = 2; 
    vvi v(n,vi(m)); 
    for(auto &i: v){
        for(auto &j: i) cin>>j;
    }
    if(v == vvi{{0,0},{0,0}}){
        cout<<0<<endl; 
        return; 
    }
    for(int i=0;i<n;i+=1){
        for(int j=0;j<n;j+=1){
            // chooose this row and column
            bool found = true;  
            for(int x=0;x<n;x+=1){
                for(int y=0;y<n;y+=1){
                    if(v[x][y] and x != i and y != j){
                        found = false; 
                        break; 
                    }
                }
            }
            if(found){
                cout<<1<<endl; 
                return; 
            }
        }
    }
    cout<<2<<endl; 
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