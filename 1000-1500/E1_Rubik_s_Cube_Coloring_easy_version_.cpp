#include <bits/stdc++.h> 
#include <complex>
#include <cmath>

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
#define MOD 1000000007
ll fastexp(ll num, ll p,ll mod){
    ll res = 1; 
    ll mult = num; 
    for(int i=0;i<=60;i++){
        if(p&(1ll<<i)){
            res *= mult; 
            res %= mod; 
        }
        mult*= mult; 
        mult%= mod; 
    }
    return res; 
}
int main()
{
    fast_cin();
    int k; 
        cin>>k; 
        // it has 2^k - 1 non root nodes 
        // so solution is 6*(4^(2^k-1)) 
        // since we are taking res%prime number then 
        ll power = (1ll<<k) - 2; 
        // cout<<power<<endl; 
        ll res = fastexp(4,power,MOD); 
        res *= 6; 
        res %= MOD; 
        cout<<res<<endl; 
    return 0;
}