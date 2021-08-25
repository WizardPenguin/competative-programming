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
        ll n,u,v; 
        cin>>n>>u>>v; 
        vector<int> obj(n); 
        for(int i=0;i<n;i++) cin>>obj[i]; 
        bool isSame = true; 
        bool zero = false; 
        for(int i=1;i<n;i++){
            if(obj[i] != obj[0]){
                isSame = false; 
            }
            if(abs(obj[i] - obj[i-1]) > 1){
                zero = true; 
            }
        }
        if(zero){
            cout<<0<<endl; 
        }
        else if(isSame){
            cout<<min(2*v,u+v)<<endl; 
        }
        else{
            cout<<min(u,v)<<endl; 
        }
    }
    return 0;
}