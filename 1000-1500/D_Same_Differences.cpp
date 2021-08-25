// from tutorial
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
        vector<int> v(n+1); for(int i=1;i<=n;i++) cin>>v[i]; 
        // a[j] - j = a[i] - i; 
        // i.e find elements == a[j] - j
        // store elements as a[i] - i
        long long count = 0; 
        map<int,int> mp; 
        for(int i=1;i<=n;i++){
            count += mp[v[i] - i];
            mp[v[i] - i] ++; 
        }
        cout<<count<<endl; 
    }
    return 0;
}