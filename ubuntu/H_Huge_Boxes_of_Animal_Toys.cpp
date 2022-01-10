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
    int a,b,c,d; 
    cin>>a>>b>>c>>d; 
    int sign = a + b; 
    if(sign&1){// odd number of -ve sign
        if(b + c > 0 and a + d > 0){
            // means we can have both larger and smaller values
            cout<<"Ya Ya Tidak Tidak"<<ln; 
        }
        else if(b + c > 0){
            cout<<"Tidak Ya Tidak Tidak"<<ln; 
        }
        else{
            cout<<"Ya Tidak Tidak Tidak"<<ln; 
        }
    }
    else{
        if(b + c > 0 and a + d > 0){
            cout<<"Tidak Tidak Ya Ya"<<ln; 
        }
        else if(b + c > 0){
            cout<<"Tidak Tidak Ya Tidak"<<ln; 
        }
        else{
            cout<<"Tidak Tidak Tidak Ya"<<ln; 
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