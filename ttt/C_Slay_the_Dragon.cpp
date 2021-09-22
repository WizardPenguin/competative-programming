// try using binary serach 
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
    int n; 
    cin>>n; 
    vector<ll> v(n); 
    long long sum = 0; 
    for(int i=0;i<n;i++) cin>>v[i],sum += v[i]; 
    sort(all(v)); 
    int q; 
    cin>>q; 
    while(q--){
        ll p,d; 
        cin>>p>>d; 
        int id = lower_bound(all(v),p) - v.begin(); 
        if(id == n){
            // there is no one able to make fight 
            id--; 
            ll pd = v[id]; 
            // now we need to make use of coins to win this game 
            ll count = abs(pd - p); 
            ll def = sum - pd; 
            if(def < d){
                count += abs(def - d); 
            }
            cout<<count<<endl; 
        }
        else{
            // we have such element 
            ll pd = v[id]; 
            ll def = sum - pd; 
            if(def < d){
                // we need to check both id and id-1 as pd
                ll count = abs(def - d); 
                ll cnt = LLONG_MAX; 
                if(id != 0){
                    pd = v[id-1]; 
                    cnt = abs(pd - p); 
                    def = sum - pd; 
                    if(def < d){
                        cnt += abs(def - d); 
                    }
                }
                cout<<min(count,cnt)<<endl; 
            }
            else{
                // we are good to go with it 
                cout<<0<<endl; 
            }
        }
    }
    return 0;
}