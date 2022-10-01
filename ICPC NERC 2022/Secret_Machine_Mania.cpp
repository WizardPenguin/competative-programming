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
    ll x,c; 
    cin>>x>>c; 
    map<int,int> factors; 
    for(ll i=2;i*i <= x;i+=1){
        while(x%i == 0){
            x/=i; 
            factors[i] += 1; 
        }
    }
    if(x != 1){
        factors[x] += 1; 
    }
    // cerr<<x<<endl; 
    for(auto &i: factors){
        // cerr<<i.first<<" "<<i.second<<endl; 
        i.second = min(i.second%c, (c - (i.second%c))); 
    }
    ll minimized = 1; 
    for(auto &i: factors){
        for(int x=0;x<i.second;x+=1){
            minimized*=i.first; 
        }
    }
    cout<<minimized<<endl; 
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