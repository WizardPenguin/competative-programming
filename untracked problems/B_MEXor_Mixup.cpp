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

#define N 500005
int main()
{
    fast_cin();
    ll test;
    cin >> test;
    vector<int> x(N,0); 
    for(int i=1;i<N;i++){
        x[i] = x[i-1]^i; 
    }
    while(test--){
        int a,b; 
        cin>>a>>b; 
        if(a == 0){
            // we want mex = 0 means all greater elements considered 
            cout<<2<<endl; 
            continue; 
        }
        int xo = x[a-1];
        int req = (b^xo); 
        // cout<<req<<"req"<<endl; 
        if(req == 0){
            cout<<a<<endl; 
        }
        else if(req == a){
            cout<<(a + 2)<<endl; 
        }
        else{
            cout<<(a + 1)<<endl; 
        }
    }
    return 0;
}