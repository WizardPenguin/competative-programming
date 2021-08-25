// if odd then n/2 n/2 1
// if it's even then n/2-1 and n/2-1 only if n/2-1 is even 
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
        int n,k; 
        cin>>n>>k;
        if(n%4 == 0){
            cout<<n/4<<" "<<n/4<<" "<<n/2<<endl; 
        }
        else if(n%2 == 0){
            int half = n/2; 
            cout<<half-1<<" "<<half-1<<" "<<2<<endl; 
        }
        else{
            cout<<n/2<<" "<<n/2<<" "<<1<<endl; 
        }
    }
    return 0;
}