// check if it's odd pallindrome or k == 0
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
        if(k == 0) cout<<"YES"<<endl;  
        else{
            // check for pallindrome 
            // sorry this can even be possible for even pallindrome 
            // we can take even part ad mid node that need not to be pepeated of length >=2
            // for that k < n/2 
            int i=0;
            while(i < ceil(n/2) and s[i] == s[s.length() - 1 - i]) i++; 
            if(i == ceil(n/2)){
                if(n & 1 == 0 and k < n/2){
                    cout<<"YES"<<endl;
                }
                else if(n & 1){
                    cout<<"YES"<<endl; 
                }
                else{
                    cout<<"NO"<<endl; 
                }
            }
            else cout<<"NO"<<endl; 
        }
    }
    return 0;
}