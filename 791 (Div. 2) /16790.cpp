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
    ll n; 
    cin>>n; 
    vector<ll> v; 
    if(n%6 == 0){
        v.push_back(n/6); 
    }
    if(n%4 == 0){
        v.push_back(n/4); 
    }
    if(n>=6 and ((n-6)%4) == 0){
        v.push_back((n-6)/4 + 1); 
    }
    if(n>=4 and ((n-4)%6) == 0){
        v.push_back((n-4)/6 + 1); 
    }
    if(n>=8 and ((n-8)%6) == 0){
        v.push_back((n-8)/6 + 2); 
    }
    if(v.size())
    cout<<*min_element(all(v))<<" "<<*max_element(all(v))<<endl; 
    else cout<<-1<<endl; 
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