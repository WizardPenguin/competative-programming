// members are maxNumber,maxNumber - 1
// for permutation to be not nice we need to make only non-members to the right side of maxNumber 
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
#define MOD 998244353
#define N 200005
int main()
{
    fast_cin();
    ll test;
    cin >> test;
    // for faster computations we need to store factorials in advance 
    vector<ll> fact(N); 
    fact[0] = 1; 
    for(int i=1;i<N;i++){
        fact[i] = fact[i-1]*i; 
        fact[i] = fact[i]%MOD; 
    }
    cout<<endl; 
    while(test--){
        int n; 
        cin>>n; 
        vector<ll> v(n); 
        int maxi = -1;
        for(int i=0;i<n;i++){
            cin>>v[i]; 
            if(v[i] > maxi){
                maxi = v[i]; 
            }
        }
        // find members 
        int eq = 0; 
        int eq1 = 0;
        for(auto &i: v){
            if(i == maxi){
                eq++;  
            }
            else if(i == maxi-1){
                eq1++; 
            }
        }
        int members = eq1;
        if(eq > 1){
            cout<<fact[n]<<endl; 
            continue; 
        }
        else if(members == 0){
            cout<<0<<endl; 
            continue; 
        }
        // now need to take all non-members to the left side 
        ll factor = 1; 
        ll ans = fact[n]; 
        ll prod = n - members - 1; 
        // we are selecting i items on left side which are non members then place them on i places 
        for(int i=0;i<=n - members - 1;i++){
            ll num = n - i - 1; 
            ll subs = fact[num]*factor; 
            subs%= MOD; 
            // no need to place n selected elements on n seats since they are selected for particular seat itself
            // if(i != 0){
            //     subs *= fact[i-1]; 
            //     subs %= MOD; 
            // }
            ans -= subs;
            factor*=prod; 
            prod--; 
            ans %= MOD; 
            factor %= MOD;  
        }
        cout<<(ans + MOD)%MOD<<endl; 
    }
    return 0;
}