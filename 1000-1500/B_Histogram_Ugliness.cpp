// if number is larger than both nbrs then we can decrease it till max(both nbrs) this decrease ugliness
// no other option decreases ugliness
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
        vector<int> v(n+2,0); 
        for(int i=1;i<=n;i++) cin>>v[i];
        ll steps = 0; 
        for(int i=1;i<=n;i++){
            int maxi = max(v[i-1],v[i+1]); 
            if(v[i] > maxi){
                // then we can decrease ugliness
                steps += v[i] - maxi;
                v[i] = maxi;   
            }
        } 
        // now find resulting ugliness if value increase then add ugliness if decreases then also add ugliness
        for(int i=1;i<=n+1;i++){
            steps += abs(v[i]  - v[i-1]); 
        }
        cout<<steps<<endl; 
    }
    return 0;
}