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
    int n; 
    cin>>n; 
    int t; 
    cin>>t; 
    v64 v(n); 
    int prev = 0; 
    for(int i=0;i<n;i++){
        cin>>v[i]; 
        v[i] += prev;
        prev = v[i];  
    }
    prev = 0;  
    ll ans = 0; 
    for(int i=0;i<n;i++){
        // let i be index from where we are starting 
        ll lb = upper_bound(v.begin() + i,v.end(),t+prev) - v.begin() - i; 
        // cout<<lb<<" "; 
        prev = v[i]; 
        if(lb > (n - i)) continue; 
        ans = max(ans,lb);
    }
    cout<<endl; 
    cout<<ans<<endl; 
    return 0;
}