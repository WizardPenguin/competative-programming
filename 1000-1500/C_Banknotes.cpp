// we will try to take largest number of notes of smallest number such that it can't be 
// represented by any larger note
// then try to make number of notes > given 
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
ll pwr(int n){
    ll res = 1; 
    while(n--){
        res *= 10; 
    }
    return res; 
}
int main()
{
    fast_cin();
    ll test;
    cin >> test;
    while(test--){
        ll n,k; 
        cin>>n>>k; 
        vector<int> v(n); 
        for(int i=0;i<n;i++){
            cin>>v[i]; 
        }
        k++;
        ll taken = 0; 
        ll formed = 0; 
        for(int i=0;i<n-1;i++){
            ll canTake = pwr(v[i+1] - v[i])-1;
            ll tkn;  
            if(taken + canTake > k){
                tkn = (k - taken); 
            }
            else{
                tkn = canTake; 
            }
            taken += tkn;
            formed += pwr(v[i])*tkn;
            // cout<<tkn<<" ";  
        }
        // cout<<endl; 
        if(taken < k){
            ll toTake = (k - taken); 
            formed += pwr(v[n-1])*toTake; 
        }
        cout<<formed<<endl; 
    }
    return 0;
}