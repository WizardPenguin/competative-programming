// from editorial 
// given which cells are exitable we want must be able to determine exactly which grid could give such result 
// for that we want to find which kind of structure is causing us not able to find grid exactly 
/*
  d
 dd    where d is non deterministic cells in this condition rightmost d can either be filled or not 
 so if some column has such structure then that subgrid can't be deterministic except subgrid with single column 
*/
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
    ll test = 1; 
    while(test--){
        int n,m; 
        cin>>n>>m;
        vector<string> v(n); 
        for(int i=0;i<n;i++){
            cin>>v[i]; 
        }
        vector<int> dp(m,0); 
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(v[i-1][j] == 'X' and v[i][j-1] == 'X'){
                    // then this node is nondeterministic mark this column as bad one 
                    dp[j] = 1; 
                }
            }
        }
        for(int i=1;i<m;i++){
            dp[i] += dp[i-1]; 
        }
        int q; cin>>q; 
        while(q--){
            int x,y; 
            cin>>x>>y; 
            x--,y--; 
            if(dp[y] - dp[x]){
                cout<<"NO"<<endl; 
            }
            else{
                cout<<"YES"<<endl; 
            }
        }
    }
    return 0;
}