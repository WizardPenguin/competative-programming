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
ll sumession(ll n){
    return n*(n+1)/2; 
}

void solve(){
    ll n,k; 
    cin>>n>>k; 
    vi v(n); 
    for(int i=0;i<n;i+=1){
        cin>>v[i]; 
    } 
    // find extra cost if we have > n steps otherwise we need to take only largest substring in proper order 
    // giving largest substring sum + k*(k-1)/2 as value 
    if(k == 0){
        cout<<0<<endl; 
        return; 
    }
    else if(k <= n){
        // find largest sum substring 
        ll sum = 0; 
        for(int i=0;i<k;i+=1){
            sum += v[i]; 
        }
        ll maxSum = sum; 
        for(int i=k;i<n;i+=1){
            // now add and remove elements 
            sum += v[i]; 
            sum -= v[i-k]; 
            maxSum = max(maxSum,sum); 
        }
        cout<<maxSum + sumession(k-1)<<endl; 
    }
    else{
        // now we are required to make some serious calculation 
        ll totalSum = 0; 
        for(auto &i: v) totalSum += i; 
        ll res = (k - n)*2 + 1 + (n-2)*k - sumession(n-2) + totalSum; 
        cout<<res<<endl; 
    }
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