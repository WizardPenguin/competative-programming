// if period of sequence is 1 no need to change 
// otherwise we can shurely make this period = 2
// by taking 01 n times makes length <= 2*n
// and either 0 or 1 of each pair matches if given seqnence
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
    bool found = true; 
    for(int i=1;i<n;i++){
        if(s[i] != s[i-1]){
            found = false; 
            break; 
        }
    }
    if(found){
        cout<<s<<endl; 
    }
    else{
        string res; 
        for(int i=0;i<n;i++){
            res += "01"; 
        }
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