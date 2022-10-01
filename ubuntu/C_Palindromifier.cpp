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
typedef vector<vector<bool> > vvb;
typedef vector<string> vs;
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 

void solve(){
    string s; 
    cin>>s; 
    int n = s.length(); 
    // apply and check 
    // string tp; 
    // tp = s.substr(2-1); 
    // tp.pop_back(); 
    // reverse(all(tp)); 
    // s += tp; 
    // cout<<s<<ln;
    // tp = s.substr(1,n-1); // from 1 of size n-1 
    // cout<<tp<<endl;  
    // reverse(all(tp)); 
    // s = tp + s; 
    // cout<<s<<endl;
    // tp = s.substr(1,n-2);  
    // reverse(all(tp)); 
    // s = tp + s; 
    // cout<<s<<endl;  
    cout<<3<<endl; 
    cout<<"R 2"<<ln; // come till 2nd index element 
    cout<<"L "<<n<<endl; // come till nth element so as to include R 
    cout<<"L "<<n-1<<endl; // come till n-1 th elment so as to exclude R 
    // also R n-1  ( take 2nd last character and append it at end )
    // L n (take till Rth character and append reverse )
    // L 2 works fine (now we have 2nd last character as 2nd character here take it in front)
    // L x b R 
    // L X b R b
    // R b X L X b R b
    // b R b X L X b R b // is final pallindrome 
}
int main(){
    fast_cin();
    solve();
    return 0;
}