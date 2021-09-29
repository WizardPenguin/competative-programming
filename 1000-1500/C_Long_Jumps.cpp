// if we calculate scores from right side then each element will have to move only 1 step in order to get their goal 
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
        for(int i=0;i<n;i++){
            cin>>v[i]; 
        }
        vector<long long> ans(n,-1);
        long long maxi = -1; 
        for(int i=n-1;i>=0;i--){
            ans[i] = v[i]; 
            if((i + v[i]) < n){
                ans[i] += ans[i+v[i]]; 
            }
            maxi = max(maxi,ans[i]);
        }
        cout<<maxi<<endl; 
    }   
    return 0;
}