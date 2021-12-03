// we need (hor - ver) <= 1 since they needs to be consecutive
// also we can have +ve and -ve horizontal and vertical moves
// n even n/2 n/2, also we have +ve -ve pairs n/2+1 so total n/2+1 **2
// n odd n/2,n/2+1 we have n/2+1 * n/2 + 2
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
    long long n; 
    cin>>n; 
    if(n%2 == 0){
        cout<<(n/2 + 1)*(n/2 + 1); 
    }
    else{
        // since we can have eg for n = 5 2,3 and 3,2 
        cout<<2*(n/2 + 1)*(n/2 + 2); 
    }
    return 0;
}