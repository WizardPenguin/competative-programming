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
    string s; 
    cin>>s; 
    int n = s.length(); 
    // we want to make winning possibility maximum if we start from any index 
    // so if we use maxi frequency term to get beaten for 1st chance
    // now to maximise chances in each start index we can make all ci as same 
    // so every time that maximum values are given that maximizes average
    map<char,int> mp = {{'R',0},{'P',1},{'S',2}};
    array<int,3> freq = {0,0,0}; 
    for(auto &i: s){
        freq[mp[i]]++; 
    }
    int maxi = *max_element(all(freq)); 
    if(maxi == freq[0]){
        // rock beaten by P
        for(int i=0;i<n;i++) cout<<"P"; 
    }
    else if(maxi == freq[1]){
        // paper beaten by S
        for(int i=0;i<n;i++) cout<<"S"; 
    }
    else if(maxi == freq[2]){
        // seassor beaten by R
        for(int i=0;i<n;i++) cout<<"R"; 
    }
    cout<<endl; 
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