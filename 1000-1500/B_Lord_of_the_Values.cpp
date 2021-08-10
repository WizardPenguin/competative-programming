// for every consecutive a,b
// a+b b
// a+b -a
// b -a
// b-a -a
// b-a -b
// -a -b 
// took 6 steps i.e at max 3*10^3 steps
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
#define XY cout<<" "<<i<<" "<<i+1<<ln;
int main()
{
    fast_cin();
    ll test;
    cin >> test;
    while(test--){
        int n; 
        cin>>n; 
        int temp; 
        for(int i=0;i<n;i++) cin>>temp; 
        cout<<(3*n)<<endl; 
        for(int i=1;i<=n;i+=2){
            cout<<1; XY; 
            cout<<2; XY; 
            cout<<1; XY; 
            cout<<1; XY; 
            cout<<2; XY; 
            cout<<1; XY; 
        }
    }
    return 0;
}