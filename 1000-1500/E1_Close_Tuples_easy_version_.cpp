// we need to consider all cases 
// 1 1
// 2 2
// 1 1 2
// 1 2 2
// 1 2 3
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
        long long n; 
        cin>>n;
        // instead of map we can use count array that makes easy without any comparisons 
        vector<long long> v(n+4,0); 
        int val; 
        // also all numbers are in range  1...n
        for(int i=0;i<n;i++){
            cin>>val; 
            v[val]++; 
        }
        long long ans =0 ;
        ans += (v[1]*(v[1]-1)*(v[1]-2))/6; 
        ans += (v[1]*(v[1]-1)*v[2])/2;  
        for(int i=2;i<n;i++){
            long long count = v[i]; 
            ans += (count*(count- 1)*(count-2))/6; 
            ans += (count*(count-1)/2*(v[i+1])); 
            ans += (count*(count-1)/2*(v[i-1])); 
            // cout<<ans<<endl; 
            ans += v[i-1]*count*v[i+1]; 
            ans += ((v[i+1]-1)*(v[i+1])/2*v[i-1]);
            ans += (v[i-1]*(v[i-1]-1)/2*v[i+1]);
        }
        ans += v[n]*(v[n]-1)/2*v[n-1]; 
        ans += v[n]*(v[n]-1)*(v[n]-2)/6; 
        cout<<ans<<endl; 
    }
    return 0;
}