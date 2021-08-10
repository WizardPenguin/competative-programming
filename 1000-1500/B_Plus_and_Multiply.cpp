// number formed by this operation is necessarily going to be in format of a^x + y*b
// we can remove b's any number of time and check weather remaining number is in form a^x
// instead removing a^x first gives better time complexity 
// if a>=2 then we can find answer in at most 32 operations
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
        int n,a,b; 
        cin>>n>>a>>b; 
        ll temp = a; 
        bool found = false; 
        // remove powers of a from it
        if((n-1)%b == 0) found = true;
        else{
            for(int i=0;i<32 and temp <= n;i++){
                if((n - temp)%b == 0){
                    found = true; 
                    break; 
                }
                temp*=a; 
            }
        }
        if(found) cout<<"Yes"<<ln; 
        else cout<<"No"<<ln;
    }
    return 0;
}