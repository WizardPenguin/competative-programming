// if we can't have first character of each k substring as smallest one 
// then we have largest substring as the largest of k substring where each have only 1 character 
// since we can insert remaining characters after smallest one still that kth string is largest 
// otherwise if we have all same characters when we can evenly distribute characters 
// othwerise optimal to increase length of 1 string instead spreading characters over all strings 
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
    string s; 
    cin>>s; 
    sort(s.begin(),s.end()); 
    if(s[0] != s[k-1] or k == n){
        cout<<s[k-1]<<endl; 
    }
    else if(s[k] == s[n-1]){
        // we can evenly distribute
        cout<<s[0];
        int len= (n-k + k-1)/k; 
        while(len--) cout<<s[k]; 
        cout<<endl; 
    }
    else{
        cout<<s[0] + s.substr(k)<<endl; 
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