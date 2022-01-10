// place first element at it's position 
// after then find what is max and min height we can achieve given that all conditions are satisfied
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
    ll n,k; 
    cin>>n>>k; 
    vll v(n); 
    for(int i=0;i<n;i++) cin>>v[i];
    ll mini = v[0]+k; 
    ll maxi = mini; 
    int i=1; 
    while(i<n){
        maxi = min(maxi + k-1,v[i] + k-1+k); 
        mini = max(mini -(k-1),v[i]+k);                                                           
        if(maxi < mini){
            break; 
        }
        i++;  
    }
    // at end we are required to attach it to base 
    v[n-1] += k; 
    if(i == n and v[n-1]>= mini and v[n-1]<= maxi){
        cout<<"YES"<<endl; 
    }
    else{
        cout<<"NO"<<endl; 
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