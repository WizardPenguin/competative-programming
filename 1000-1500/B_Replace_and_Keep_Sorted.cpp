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
    int n,q,k; 
    cin>>n>>q>>k; 
    vector<int> v(n+1); 
    for(int i=1;i<=n;i++) cin>>v[i]; 
    // for(auto i: v) cout<<i<<" "; 
    // cout<<endl; 
    vector<long long> pre(n+1); 
    pre[1] = v[2] - 2ll; 
    pre[n] = v[n-1] - 1ll; 
    for(int i=2;i<n;i++){
        pre[i] += v[i+1] - v[i-1] - 2ll + pre[i-1]; 
    }
    pre[n] += pre[n-1]; 
    // for(auto i: pre) cout<<i<<" "; 
    // cout<<endl; 
    // storing cumulative sum of apporximate query results
    while(q--){
        int l,r; 
        cin>>l>>r;
        long long ans = 0; 
        if(l == r){
            ans = k-1;  
        }
        else{
            // solution for end points
            ans = v[l+1]-2ll;
            ans += k - v[r-1] - 1ll;
            // solution for interior points
            ans += pre[r-1] - pre[l]; 
        }
        cout<<ans<<endl; 
    }
    return 0;
}