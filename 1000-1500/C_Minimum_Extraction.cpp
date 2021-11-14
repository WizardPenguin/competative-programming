// apply min extraction till there is some -ve element left
// then all elements are added with same value so next minimum will not change after this operation 
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
        vector<long long> v(n); 
        for(int i=0;i<n;i++){
            cin>>v[i]; 
        }
        sort(all(v));  // now -ve elements are at starting position 
        ll toadd = 0;
        int i=0; 
        ll ans = v[0];  
        while(i<n-1){
            ll val = v[i] + toadd; 
            ans = max(val,ans); 
            toadd -= val;
            i++;  
        }
        ans = max(ans,v[i] + toadd); 
        cout<<ans<<endl; 
    }
    return 0;
}