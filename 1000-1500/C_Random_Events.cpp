// we need to find probability of sorting whole array 
// first element from right not in sorted position should be in sorted position only then task is achieved
// for probability of failure* p of sorting gives probability of sucess
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
    cout<<fixed<<setprecision(6)<<endl; 
    while(test--){
        int n,k;
        cin>>n>>k ; 
        vector<int> v(n); 
        for(int i=0;i<n;i++){
            cin>>v[i]; 
        }
        auto tp = v; 
        sort(all(tp));  
        int id = 0; 
        for(id = n-1;id >=0; id--){
            if(tp[id] != v[id]) break; 
        }
        int a; 
        double x;
        double ans = 0.0;
        for(int i=0;i<k;i++){
            cin>>a>>x; 
            if(a > id){
                ans += (1.0 - ans)*x; 
            }
        }
        if(id < 0){
            cout<<1.0<<endl; 
            continue; 
        }
        cout<<ans<<endl; 
    }
    return 0;
}