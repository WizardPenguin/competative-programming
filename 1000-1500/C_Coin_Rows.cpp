// alice wants to minimize bob's score and bob want to maximize his score 
// alice play's first then he give's bob two options wither take bottom left or upper right part left by alice 
// we simply want's to minimize bob's score
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
        int n; cin>>n; 
        vector<vector<int> > v(n,vector<int>(2,0)); 
        for(int i=0;i<n;i++) cin>>v[i][0]; 
        for(int i=0;i<n;i++) cin>>v[i][1]; 
        if(n == 1){
            cout<<0<<endl; 
            continue; 
        }
        for(int i=1;i<n;i++){
            v[i][1] += v[i-1][1]; 
        }
        for(int i=n-2;i>=0;i--){
            v[i][0] += v[i+1][0]; 
        }
        // for(int i=0;i<n;i++){
        //     cout<<v[i][0]<<" "<<v[i][1]<<endl; 
        // }
        // i denotes point where alice make down move 
        // after then bob takes max of two parts left for him 
        int bob = INT_MAX; 
        for(int i=0;i<n;i++){
            if(i ==0){
                bob = min(bob,v[i+1][0]);
            }
            else if(i == n-1){
                bob = min(bob,v[i-1][1]);
            }
            else{
                int left = v[i-1][1]; 
                int right = v[i+1][0]; 
                // bob playing optimally 
                bob = min(bob,max(left,right)); 
            }
        }
        cout<<bob<<endl; 
    }
    return 0;
}