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
    ll time = LLONG_MAX;
    while(test--){
        ll n; cin>>n; 
        if((n%10) ==0){
            time = (n/10)*25; 
        }
        else if((n%8) == 0){
            time = (n/8)*20; 
        }
        else if((n%6) == 0){
            time = (n/6)*15; 
        }
        else{
            ll ans1 = LLONG_MAX,ans2 = LLONG_MAX; 
            // now need to do it greedily 
            ll temp = n;
            if(n >= 10){
                ll div = n/10; 
                n = n - div * 10; 
                ans1 = div*25;  
                if(n >= 8){
                    ans2 = ans1;
                    ans2 += ceil(n/8.0)*20;
                }
                ans1 += ceil(n/6.0)*15; 
                ans1 = min(ans1,ans2);
            }
            n = temp; 
            if(n >= 8){
                ll div = n/8; 
                n = n- div*8; 
                ans2 = div*20; 
                ans2 = ceil(n/6.0)*15;  
            }
            time = min(ans2,ans1);
        }
        cout<<time<<endl; 
    }
    return 0;
}