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
    sort(all(s));
    string t; 
    cin>>t; 
    int n = s.length(); 
    vi v(26,0);
    for(auto &i: s){
        v[i-'a']++; 
    }
    if(t == "abc" and v[0]){
        for(int i=0;i<v[0];i++){
            cout<<"a"; 
        }
        for(int i=0;i<v[2];i++) cout<<"c"; 
        for(int i=0;i<v[1];i++) cout<<"b"; 
        for(int i=3;i<26;i++){
            while(v[i]--) cout<<char(i+'a'); 
        }
    }
    else{
        for(int i=0;i<26;i++){
            while(v[i]--) cout<<char(i+'a'); 
        }
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