// store ones with count > 2 we can only use then twice not more than that 
// store which are single 
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
        string s; cin>>s; 
        map<char,int> ch; 
        for(auto i: s){
            ch[i] ++; 
        }
        int ones = 0; 
        int more =0 ; 
        for(auto i: ch){
            if(i.second == 1)ones++; 
            else more++; 
        }
        int ans = ones/2 + more; 
        cout<<ans<<endl; 
    }
    return 0;
}