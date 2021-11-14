// if we have number of computers available that can copy data >= k then we can find it 
// till then we can have double computer with files copied in every hour
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
        ll n,k; 
        cin>>n>>k; 
        long long done = 1; 
        long long hours = 0; 
        while(done <=k and done < n){
            done *= 2; 
            hours ++; 
        }
        if(done < n){
            // then we can only make k number of files in each step after this 
            hours += ceil((n - done)/(k*1.0));
        }
        cout<<hours<<endl; 
    }
    return 0;
}