// we know every number's contribution try to replace it with it's neighbour
// find one which gives highest decrease in cost using those operations 
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
        for(int i=0;i<n;i++){
            cin>>v[i]; 
        }
        // we can change any number with it's neighbour to get decrease which is optimal 
        // also first and last element has only 1 neighbour
        // find which id should be changed 
        // such that they gives max decrease
        int maxi = INT_MIN; 
        for(int i=1;i<n-1;i++){
            int left = abs(v[i] - v[i-1]); 
            int right = abs(v[i] - v[i+1]); 
            int finalVal = abs(v[i-1] - v[i+1]); 
            if(maxi < (left + right - finalVal)){
                maxi = left + right - finalVal; 
            }
        }
        if(abs(v[0] - v[1]) > maxi){
            maxi = abs(v[0] - v[1]); 
        }
        if(abs(v[n-2] - v[n-1]) > maxi){
            maxi = abs(v[n-1] - v[n-2]); 
        }
        long long sum = 0; 
        for(int i=1;i<n;i++){
            sum += abs(v[i] - v[i-1]); 
        }
        sum -= maxi; 
        cout<<sum<<endl; 
    }
    return 0;
}