// domino's first k1 and k2 of fist row are filled with white color
// means min(k1,k2) are colored with both white
// also abs(k2-k1) can also have white color 
// black are n-k1 and n-k2 with similar conditions
// we know max black and white domino we can fill there
// all domino are of dimentino 2x1. 
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <complex>
#include <cmath>
#include <iomanip>
#include <fstream>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 

int main(){
    fast_cin();
    ll t;
    cin >> t;
    while(t--){
        int n,k1,k2; 
        cin>>n>>k1>>k2; 
        int w,b; 
        cin>>w>>b; 
        // find max white we can have 
        // find max black domino we can place
        int maxW = min(k1,k2) + abs(k1 - k2)/2; 
        k1 = n-k1; 
        k2 = n-k2; 
        int maxB = min(k1,k2) + abs(k1 - k2)/2; 
        if( maxW >= w and maxB >= b){
            cout<<"YES"<<endl; 
        }else{
            cout<<"NO"<<endl; 
        }
    }
    return 0;
}