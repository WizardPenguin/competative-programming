// if increase required then increase = ceil (100*ith - sum till i * precentage)/percentage
// also for making ith value in range we can increase any value behind it to desired amount
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
        ld n,p; 
        cin>>n>>p; 
        vector<long long> v(n); 
        for(int i=0;i<n;i++){ 
            cin>>v[i]; 
        }
        ld mini = 0; 
        long long sum = v[0]; 
        ll res =0; 
        for(int i=1;i<n;i++){
            ll increase = max(mini,ceil((100*v[i] - p*sum)/p));
            sum += v[i];
            sum += increase;
            res += increase;  
        }
        cout<<res<<endl; 
    }
    return 0;
}