// we have 100 test case and 100x100 grid
// we can move only right and down by increasing either x or y 
// it's very good question draw one test case then you'll get to solution
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
        int n,m,k; 
        cin>>n>>m>>k; 
        vector<vector<int> > dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            dp[i][0] = i; 
        }
        for(int j=0;j<m;j++){
            dp[0][j] = j; 
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                dp[i][j] = dp[i-1][j] + j + 1;
            }
        }
        // cout<<dp[n-1][m-1]<<endl;
        if(dp[n-1][m-1] == k){
            cout<<"YES"<<endl; 
        }
        else{
            cout<<"NO"<<endl; 
        }

    }
    return 0;
}