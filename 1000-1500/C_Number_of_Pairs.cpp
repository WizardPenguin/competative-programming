// lower bound and upper bound might work good in this case 
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
        int n,l,r; cin>>n>>l>>r; 
        vector<int> v(n); for(int i=0;i<n;i++) cin>>v[i];
        sort(all(v)); 
        ll ans = 0; 
        for(int i=1;i<n;i++){
            // we need element >= l - v[i] and <= r - v[i]; 
            int lower = l - v[i]; 
            int higher = r - v[i]; 
            int it1 = lower_bound(v.begin(),v.begin() + i,lower) - v.begin();
            if(it1 == i) continue; // all are < l 
            int it2 = upper_bound(v.begin(),v.begin() + i,higher) - v.begin();
            it2--; // we have found greater element we need <= so decrease by 1
            // even if all element satisfies condition we still need iterator to last element so decreased by 1
            // upper bound is greater element we need strictly lower elements 
            // cout<<v[i]<<" "<<it1<<" "<<it2<<endl; 
            if(it2 >= it1)
            ans += it2 - it1+1; 
        }
        cout<<ans<<endl; 
    }
    return 0;
}