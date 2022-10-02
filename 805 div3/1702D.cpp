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
 map<char,int> values; 
void solve(){
    string s; 
    cin>>s; 
    int p; cin>>p; 
    int n = s.length(); 
    int sval = 0;
    vector<pair<int,int> > v; 
    int i=0; 
    for(auto &ch: s){
        sval += values[ch]; 
        v.push_back({values[ch],i}); 
        i+=1; 
    }
    sort(all(v),greater<pii>()); 
    // for(auto &[x,y]: v) cerr<<x<<" "; cerr<<endl; 
    vector<bool> removed(n,false); 
    i=0; 
    while(sval > p){
        removed[v[i].second] = true; 
        sval -= v[i].first; 
        i+=1; 
    }
    string res; 
    for(int i=0;i<n;i+=1){
        if(not removed[i]) res += s[i]; 
    }
    cout<<res<<endl; 
}
int main(){
    fast_cin();
    ll test;
    cin >> test;
    for(int i='a';i<='z';i+=1) values[i] = i-'a'+1; 
    while(test--){
        solve();
    }
    return 0;
}