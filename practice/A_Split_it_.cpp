// check if it's odd pallindrome or k == 0
// this will also work if we have atlest k elements in both directions
// so not necessarily need to be pallindrome 
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
        int n,k; 
        cin>>n>>k; 
        string s; 
        cin>>s;
        if(k == 0) cout<<"YES"<<ln;  
        else{
            int i=0;
            while(i < n/2 and s[i] == s[n - 1 - i]) i++; 
            // if we have found atleast k elements that can be reversed
            if(i >= k){
                if(n&1) cout<<"YES"<<ln; 
                // even length
                else if(k < n/2) cout<<"YES"<<ln; 
                else cout<<"NO"<<ln; 
            }
            else{
                cout<<"NO"<<ln; 
            }
        }
    }
    return 0;
}