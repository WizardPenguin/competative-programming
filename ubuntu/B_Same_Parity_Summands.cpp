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
    int n,k; 
    cin>>n>>k; 
    // convert n to sum of k +ve numbers 
    vi res; 
    int tp = n; 
    if(n < k){
        cout<<"NO"<<endl; 
        return; 
    }
    for(int i=0;i<k-1;i++){
        n-=1; 
        res.push_back(1);
    }
    if(n&1){
        res.push_back(n); 
        cout<<"YES"<<endl; 
        for(auto &i: res) cout<<i<<" "; 
        cout<<endl; 
        return;
    }
    res.clear(); 
    n = tp; 
    if(n < 2*k){
        cout<<"NO"<<endl; 
        return; 
    }
    for(int i=0;i<k-1;i++){
        n -= 2; 
        res.push_back(2);
    }
    if(n&1){
        cout<<"NO"<<endl; 
    }
    else{
        cout<<"YES"<<endl; 
        res.push_back(n);
        for(auto &i: res) cout<<i<<" "; 
        cout<<endl; 
    }
    return;
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