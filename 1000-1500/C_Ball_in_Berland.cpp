// if we take ith pair(x,y) out of k pairs then we can take only pairs not having x,y as girl/boy
// do this for all k pairs and find how many 2 pairs can we form 
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
        int a,b,k; 
        cin>>a>>b>>k; 
        vector<int> boy(a + 1,0);
        vector<int> girl(b + 1,0);
        vector<vector<int> > v(2,vector<int>(k));
        ll x,y,ans =0;
        for(int i=0;i<k;i++){
            cin>>x; 
            v[0][i] = x; 
        }
        for(int i=0;i<k;i++){
            cin>>y; 
            v[1][i] = y;  
        }
        for(int i=0;i<k;i++){
            x = v[0][i]; 
            y = v[1][i]; 
            boy[x]++; 
            girl[y]++; 
        }
        for(int i=0;i<k;i++){
            x = v[0][i];  
            y = v[1][i];  
            ans += max(0,k - boy[x] - girl[y] + 1);  
        }
        // here each 2 pair are formed twice so need to remove them 
        cout<<ans/2<<endl; 
    }
    return 0;
}