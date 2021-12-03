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
        int ans =0; 
        if(n%3 == 0 or m%3 == 0){
             cout<<(n*m)/3<<endl ; 
        }
        else if(n%3 == 1){
            // single row with m columns left 
            ans += (n/3)*m; 
            if(m%3 == 1){
                // 1x1 matrix remaining 
                // lef's join previous 3 sized with this 1 that makes it 1x4 with 2 blue color required 
                ans += m/3 + 1;  
            }
            else if(m%3 == 2){
                ans += m/3 + 1; // 2x1 takes 1 blue cell
            }
            cout<<ans<<endl; 
        }
        else if(n%3 == 2){
            // 2 rows with m columns left
            ans += (n/3)*m;
            if(m%3 == 1){
                // 2x1 remaining 
                ans += (m/3)*2 + 1; 
            }
            else if(m%3 == 2){
                // now 2x2 remaining cell
                ans += (m/3)*2 + 2; 
            }
            cout<<ans<<endl; 
        }
    }
    return 0;
}