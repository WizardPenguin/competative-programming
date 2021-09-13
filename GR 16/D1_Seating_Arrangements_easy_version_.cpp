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
        int n,m; 
        cin>>n>>m; 
        vector<vector<int>> v; 
        int num; 
        for(int i=0;i<m*n;i++){
             cin>>num; 
             v.push_back({i,num}); 
        }
        sort(all(v),[&](vector<int> &a,vector<int> &b){
            if(a[1] == b[1]){
                // decreaseing id
                return a[0] > b[0]; 
            }
            return a[1] < b[1]; 
        }); 
        long long ans = 0; 
        for(int i=0;i<m;i++){
            for(int j=0;j<i;j++){
                if(v[i][0] > v[j][0]){
                    ans++; 
                }
                // cout<<i<<" "<<j<<endl; 
            }
        }
        cout<<ans<<endl; 
    }
    return 0;
}