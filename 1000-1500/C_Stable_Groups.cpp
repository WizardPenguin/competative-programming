// we find difference and store how many insertion it requires
// then resolve those who are taking less insertions till we have power to do that 
// then count of insertion values + 1 is min number of group formed 
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
    ll n,k,x; cin>>n>>k>>x;
    // x is max difference 
    vector<ll> v(n); for(int i=0;i<n;i++) cin>>v[i]; 
    sort(all(v));
    ll prev = v[0];
    vector<ll> group; 
    for(int i=1;i<n;i++){
        ll diff = v[i] - prev; 
        if((diff%x) == 0) diff--; 
        diff = (diff/x); // how many insertion required 
        if(diff > 0) group.push_back(diff);
        prev = v[i];
    }
    sort(all(group));
    int i=0;
    while(i < group.size() and group[i] <= k) k-= group[i],i++;
    int ans = group.size() - i + 1; 
    cout<<ans<<endl; 
    return 0;
}