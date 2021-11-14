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


int main()
{
    fast_cin();
    ll test;
    cin >> test;
    while(test--){
        ll h,p; 
        cin>>h>>p; 
        ll count = 0;
        auto tp = p; 
        cout<<fixed;
        while(tp){
            tp>>=1; 
            count++; 
        }
        if(h <= count){
            cout<<h<<endl; 
            continue; 
        }
        long double n = 0;
        for(int i=count;i<h;i++){
            n += (1ll<<i); 
        }
        // cout<<n<<endl; 
        cout<<(ll)(count + ceil(n/p) )<<endl; 
    }
    return 0;
}