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
        // we are given some ac their positions and tempratures
        int n,ac; 
        cin>>n>>ac; 
        v32 temprature(ac),positions(ac);
        for(int i=0;i<ac;i++) cin>>positions[i];
        for(int i=0;i<ac;i++) cin>>temprature[i];
        v32 v(n,INT_MAX-1);
        for(int i=0;i<ac;i++) v[positions[i]-1] = temprature[i]; 
        // we need to make updates in array in -> and <- directions and place min value of temprature there
        for(int i=1;i<n;i++){
            v[i] = min(v[i],v[i-1] + 1);
        }
        for(int i=n-2;i>=0;i--){
            v[i] = min(v[i],v[i + 1] + 1);
        }
        for(auto i: v) cout<<i<<" ";
        cout<<endl; 
    }
    return 0;
}