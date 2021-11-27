// here dp[i][j] where i is ith time to work on and j is hour od day 
// here dp[i][j] us unique state since n <= h so at max we can have n-h deflection in time
// since we are taking mode then all values will lie <= h
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
int n,h,l,r; 
int recursive(vv32 &dp,v32 &v,int i,int time){
    if(i == n){
        return 0; 
    }
    if(dp[i][time] != -1) return dp[i][time]; 
    // take v[i] or v[i]-1
    int t1 = (time + v[i])%h; 
    int t2 = (time + v[i] - 1)%h; 
    return dp[i][time] = max((t1 >= l and t1 <= r) + recursive(dp,v,i+1,t1),
            (t2 >= l and t2 <= r) + recursive(dp,v,i+1,t2)); 
}
int main()
{
    fast_cin(); 
    cin>>n>>h>>l>>r; 
    vector<int> v(n); 
    for(int i=0;i<n;i++) cin>>v[i]; 
    vector<vector<int> > dp(n,vector<int>(h,-1)); 
    cout<<recursive(dp,v,0,0)<<endl; 
    return 0;
}