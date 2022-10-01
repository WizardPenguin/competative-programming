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
    int n; 
    cin>>n;
    vll v(n); 
    for(auto &i: v) cin>>i;
    int i=n-1; 
    while(v.size() and v.back() == 0) v.pop_back(); 
    if(v.size() == 0){
        cout<<"Yes"<<endl; 
        return; 
    }
    v[0] -= 1; 
    v.back() += 1; 
    n = v.size(); 
    ll val = 0; 
    for(int i=n-1;i>=0;i-=1){
        val += v[i]; 
        if(val > 0){
            cout<<"No"<<endl; 
            return; 
        }
    }
    if(val == 0){
        cout<<"Yes"<<endl; 
    }
    else{
        cout<<"No"<<endl; 
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