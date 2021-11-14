// nums[i] must not be divisible by numbers between 2 or i+1 then we can always remove that number
// also if number is divisible by all consecutive 1...i then it must have product(i) as factor 
// this factors can only be <= N i.e i can be max 25 whcih needs to be checked 
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
        vector<int> v(n); 
        bool print = true; 
        for(int i=0;i<n;i++) cin>>v[i]; 
        for(int i=0;i<n;i++){
            bool found = false; 
            for(int j=2;j<=min(25,i+2);j++){
                if(v[i]%j != 0){
                    found = true; 
                }
            }
            if(!found){
                print = false; 
            }
        }
        if(print){
            cout<<"YES"<<endl; 
        }
        else{
            cout<<"NO"<<endl; 
        }
    }
    return 0;
}