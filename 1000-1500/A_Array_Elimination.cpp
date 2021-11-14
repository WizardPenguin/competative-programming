// for removing i'th bit each numbmer with ith bit ON are considered as different set
// after then we can only choose k such that we can remove that bit from each element of set
// this needs to be done w.r.t each bit to remove them from array 
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
        int n; 
        cin>>n; 
        vector<int> v(n); 
        for(int i=0;i<n;i++) cin>>v[i];
        vector<int> dp(32,0); 
        for(int i=0;i<n;i++){
            for(int j=0;j<=31;j++){
                if(v[i] & (1<<j)){
                    dp[j]++; 
            }
        }
        }
        vector<int> s(n+1,0); 
        int ON = 0; 
        for(int i=0;i<32;i++){
            if(dp[i]) ON++; 
            for(int j=1;j<=dp[i];j++){
                if(dp[i]%j == 0){
                    s[j]++; 
                }
            }
        }
        // cout<<"ON"<<endl; 
        for(int i=1;i<=n;i++){
            if(s[i] == ON){
                cout<<i<<" ";
            }
        }
        cout<<endl; 
    }
    return 0;
}