#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<vector<ll> > vvll;
typedef vector<vector<pll> > vvpll;
typedef vector<pll> vpll;
typedef vector<pii> vpii;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<vector<bool> > vvb;
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 

void solve(){
    int n,k,z; 
    cin>>n>>k>>z; 
    vll v(n); 
    for(int i=0;i<n;i+=1) cin>>v[i]; 
    ll maxSum = 0;
    for(int i=0;i<k+1;i+=1){
        maxSum += v[i]; 
    }
    for(int i=1;i<=z;i+=1){
        int take = k - 2*i + 1;
        if(take < 0) break; 
        ll maxPair = 0; 
        ll curSum = 0; 
        for(int j=0;j<take;j+=1){
            if(j!= n-1)
            maxPair = max(v[j] + v[j+1],maxPair); 
            curSum += v[j]; 
        }
        maxSum = max(maxSum,curSum + maxPair*i); 
    }
    cout<<maxSum<<endl; 
}
int main(){
    fast_cin();
    ll test;
    cin >> test;
    while(test--){
        solve();
    }
    return 0;
}