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
ll gcd(ll a,ll b){
    return __gcd(a,b); 
}
void solve(){
    ll n; 
    cin>>n; 
    vll v(n); 
    for(int i=0;i<n;i++) cin>>v[i]; 
    if(n == 2){
        if((v[0] == v[1]))
            cout<<0<<ln; 
        else cout<<max(v[0],v[1])<<ln; 
        return; 
    }
    ll g = v[0];
    for(int i=0;i<n;i+=2){
        g = gcd(g,v[i]); 
    }
    bool found = true; 
    if(g!=1){
        // check weather it works 
        vb b(n,false); 
        for(int i=0;i<n;i++){
            if(v[i]%g == 0){
                b[i] = true; 
            }
        }
        for(int i=1;i<n-1;i++){
            if(b[i] == b[i-1] or b[i] == b[i+1]){
                found = false; 
            }
        }
        if(found){
            cout<<g<<endl; 
            return; 
        }
    }
    found = true; 
    g = v[1]; 
    for(int i=1;i<n;i+=2){
        g = gcd(g,v[i]); 
    }
    if(g != 1){
        vb b(n,false); 
        for(int i=0;i<n;i++){
            if(v[i]%g == 0){
                b[i] = true; 
            }
        }
        for(int i=1;i<n-1;i++){
            if(b[i] == b[i-1] or b[i] == b[i+1]){
                found = false; 
            }
        }
        if(found){
            cout<<g<<endl; 
            return; 
        }
    }
    cout<<0<<endl; 
    return; 
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