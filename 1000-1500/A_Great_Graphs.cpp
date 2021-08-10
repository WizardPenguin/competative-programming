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
        int n; cin>>n; 
        vector<int> v(n); for(int i=0;i<n;i++) cin>>v[i]; 
        sort(all(v),greater<int>()); 
        ll sum = 0;
        // a1 a2 a3 a4 ......
        // a1 being largest so to make min distance = a2 when reach there add a2-a1 edge
        // similarly from each node to each ending node except last node = 0 
        // a2-a1, a3 - a1,a3 - a2
        // so each node is (i) times +ve 
        // but from each node -ve edge to 0th node so (i-1) time +ve
        // for(int i=1;i<n-1;i++) sum += (i)*v[i]; 
        // for(int i=0;i<n-1;i++) sum -= (n-i - 1ll)*v[i];
        for(int i=1;i<n;i++) sum += v[i]*(2*i + 1ll - n); 
        sum -= (n-2ll)*v[0];
        cout<<sum<<endl; 
    }
    return 0;
}