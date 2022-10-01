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
    vi v(n+1); 
    int zor = 0; 
    for(int i=0;i<n+1;i+=1){
        cin>>v[i]; 
        zor ^= v[i]; 
    }
    if(n%2 == 0){
        int finalZor = 0; 
        int leftXor = 0; 
        for(int i=0;i<n;i+=1){
            zor ^= v[i]; // remove from right part
            if((leftXor^zor) == zor){
                finalZor = v[i]; 
                break;  
            }
            leftXor ^= v[i]; //add this to left part
        }
        zor = finalZor; 
    }
    cerr<<zor<<endl; 
    vector<int> res; 
    for(int i=0;i<n+1;i+=1){
        if(v[i] == zor) continue; 
        res.push_back(v[i]^zor); 
    }
    // input remaing numbers
    while(res.size() < n){
        res.push_back(0); 
    }
    for(auto &elm: res) cout<<elm<<" "; cout<<endl;
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