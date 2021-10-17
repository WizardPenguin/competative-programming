// we want when ith element removed then it should be distributed amont n-1 elements to make them equal 
// means sum must be divisible by n-1 
// also we want each element to be < sum/n-1 since we can't decrease element 
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
        long long val,sum=0,maxi = INT_MIN; 
        for(int i=0;i<n;i++){
            cin>>val; 
            sum += val; 
            maxi = max(maxi,val); 
        }
        long long finalVal = ceil((sum*1.0)/(n-1)); 
        if(finalVal < maxi){
            cout<<(maxi)*(n-1) - sum<<endl; 
        }
        else{
            cout<<(finalVal*(n-1)) - sum<<endl; 
        }
    }
    return 0;
}