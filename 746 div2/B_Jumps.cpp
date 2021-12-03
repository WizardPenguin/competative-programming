// try using 1,2,3 ..... till sum <= x
// if == x then we have found
// otherwise next number is going to crease some difference/overshoot so to remove them we can remove previous
// preivous removal can give us 2....n-1
// if need 1 then we need to take next element as well with removal 
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
        int n; 
        cin>>n; 
        int i=1; 
        long long sum = 0; 
        while(sum + i <= n){
            sum += i; 
            i++;  
        }
        if(sum == n){
            cout<<i-1<<endl; 
            continue; 
        }
        // overshoot condition 
        int diff = sum + i - n; 
        if(diff == 1){
            // cout<<" diff == 1"<<endl ;
            cout<<i+1<<endl; 
        }
        else{
            // we can replace any previous number with -1 
            cout<<i<<endl; 
        }
    }
    return 0;
}