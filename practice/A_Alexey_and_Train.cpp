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
// a,b are expected time of departure and arrival at station
// if current time if < b[i-1] then reach b[i-1];
#define wt(i) ceil((b[i] + 0.0 - a[i])/2)
int main(){
    fast_cin();
    ll t;
    cin >> t;
    while(t--){
        int n; 
        cin>>n;
        vector<int> a(n),b(n),tm(n); 
        forn(i,n){
            cin>>a[i];
            cin>>b[i];
        } 
        forn(i,n) cin>>tm[i];
        ll curTime = 0; 
        forn(i,n){
            ll requiredTime = a[i] -(i==0)?0:b[i-1] + tm[i]; 
            curTime += wt(i);
            cout<<curTime<<" ";
            if(curTime <= b[i] ){
                curTime = b[i];
            }
            curTime += requiredTime;
        }
        cout<<curTime<<ln; 
    }
    return 0;
}