// firstly minimize the absolute difference
// only consecutive elements give that min difference 
// to get max difficulty we need to arrange array in some sorted array 
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
        int minId; 
        int minDiff = INT_MAX; 
        sort(all(v));
        for(int i=1;i<n;i++){
            if(minDiff > (v[i] - v[i-1])){
                minDiff = v[i] - v[i-1];
                minId = i; 
            }
        }
        if(n == 2){
            cout<<v[0]<<" "<<v[1]<<endl; 
            continue; 
        }
        // if we go increasing from v[i] till we can then increasing from start to v[i-1] 
        for(int i=minId; i < n; i++){
            cout<<v[i]<<" ";
        }
        for(int i = 0;i<minId; i++){
            cout<<v[i]<<" ";
        }
        cout<<endl; 
    }
    return 0;
}