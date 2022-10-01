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
    map<int,vector<int> > v; 
    int val; 
    for(int i=0;i<n;i++){
        cin>>val; 
        if(v.find(val) != v.end())
            v[val].push_back(i); 
        else 
            v[val] = {i}; 
    }
    int maxi = 0; 
    for(auto &pr: v){
        auto &vec = pr.second; 
        for(int i=0;i<vec.size()-1;i++){
            maxi = max(maxi,vec[i] + 1 + n - vec[i+1] - 1); 
        }
    }
    // cout<<maxi<<endl; 
    if(maxi == 0){
        cout<<-1<<endl; 
        return;
    }
    cout<<maxi<<endl; 
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