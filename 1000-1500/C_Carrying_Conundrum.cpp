// find number of ways to generate single digit number 
// after then using bitmasking generate all variants of carry number can have 
// first 2 and last 2 digits can't generaet carry 
// after then find number of way's to generate digits at those variants 
// last 2 digits can't enerate carry 
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
//// we are asked for +ve integers so remove case when any 1 of both the digits are 0
// there can be only 2 cases when x + y == z and either x or y = 0; 
// so we have given result as ans-2
int main()
{
    fast_cin();
    ll test;
    cin >> test;
    while(test--){
        string s; 
        cin>>s;  
        int n = s.length(); 
        reverse(all(s)); 
        vector<int> v(n); 
        // generating -1 or 9 with carry will automatically make their solution as 0
        for(int i=0;i<n;i++) v[i] = s[i] - '0'; 
        // for(auto &i: v) cout<<i<<" "; 
        // cout<<endl; 
        if(n <= 2){
            ll ans = 1; 
            for(auto &i: v){
                ans *= (i + 1); 
            }
            cout<<ans-2<<endl; 
            continue; 
        }
        int maskSize = n - 2;  
        // dbg(maskSize);
        ll res = 0; 
        for(ll i=0;i<(1<<maskSize);i++){
            ll ans = 1; 
            auto tp = v; 
            for(ll j=0;j<n;j++){
                if(i&(1<<j)){ // carry has been enerated by this bit  
                    ans *= (9 - tp[j]);
                    // then this carry reaches 2 steps after this tell his carry has reached him 
                    tp[j+2]--; 
                }
                else{
                    ans *= (tp[j] + 1); 
                }
            }
            res += ans; 
        }
        cout<<res-2<<endl; 
    }
    return 0;
}