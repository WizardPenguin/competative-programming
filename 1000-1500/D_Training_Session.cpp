#include <bits/stdc++.h> 
#include <complex>
#include <cmath>
// either all same course or all same dificulties 
// so negation would be 2 courses same , all courses different with either 2 difficulties same or all diffuculties same 
// case with all course and all difficulties same can't be possible since all (x,y) pairs are different 
// so only case when 2 courses same and 2 difficulties same 
// a,c  a,b d,b such case
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
        ll n; 
        cin>>n; 
        vector<ll> xcount(n+1,0),ycount(n+1,0);
        vector<pair<int,int> > v; 
        ll ans = n*(n-1)*(n-2)/6; 
        while(n--){
            int x,y; 
            cin>>x>>y; 
            v.push_back({x,y}); 
            xcount[x]++; 
            ycount[y]++; 
        } 
        for(auto &i: v){
            auto &x = i.first; 
            auto &y = i.second; 
            ans -= (xcount[x] - 1)*(ycount[y]-1); 
        }
        cout<<ans<<endl; 
    }
    return 0;
}