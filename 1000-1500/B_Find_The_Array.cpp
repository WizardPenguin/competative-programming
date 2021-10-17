// we can take 1 then a[i] which are multiple hence we are good to go with it 
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
        int n; 
        cin>>n; 
        vector<int> v(n); 
        ll s = 0; 
        for(int i=0;i<n;i++){
            cin>>v[i]; 
            s+= v[i]; 
        }
        vector<int> res1(n),res2(n); 
        for(int i=0;i<n;i++){
            if(i&1){
                res1[i] = 1; 
                res2[i] = v[i]; 
            }
            else{
                res1[i] = v[i]; 
                res2[i] = 1; 
            }
        }
        // now check both options 
        ll s1 = 0,s2 = 0;
        for(int i=0;i<n;i++){
            s1 += abs(v[i] - res1[i]); 
            s2 += abs(v[i] - res2[i]);
        }
        if(s1 < s2){
            for(int i=0;i<n;i++){
                cout<<res1[i]<<" "; 
            }
            cout<<endl; 
        }
        else{
            for(int i=0;i<n;i++){
                cout<<res2[i]<<" "; 
            }
            cout<<endl; 
        }
    }
    return 0;
}