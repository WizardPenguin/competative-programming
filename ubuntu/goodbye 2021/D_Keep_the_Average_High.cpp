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
    vll v(n);
    for(int i=0;i<n;i++) cin>>v[i]; 
    ll x; 
    cin>>x; 
    ll taken = 0; 
    ll sum = 0; 
    ll len = 0; 
    for(int i=0;i<n;i++){
        // we can take first element 
        if(len == 0){
            sum += v[i]; 
            taken++; 
            len = 1; 
        }
        else{
            if((sum + v[i]) >= (x*(len+1)) and (v[i-1] + v[i]) >= 2*x){
                len++; 
                sum += v[i]; 
                taken++; 
            }
            else{
                cout<<i<<" "; // not taken numbers
                len = 0; 
                sum = 0; 
            }
        }
    }
    dbg(taken); 
    // cout<<taken<<endl; 
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