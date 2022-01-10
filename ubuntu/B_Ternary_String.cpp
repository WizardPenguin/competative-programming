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
    // shortest substring with all 3 characters 
    string s; 
    cin>>s; 
    int n = s.length(); 
    array<int,3> ar = {0,0,0}; 
    int i=0; 
    int j=0; 
    int len = n+1; 
    while(j<n){
        ar[s[j]-'1']++; 
        j++; 
        if(ar[0] and ar[1] and ar[2]){
            // try to decrease length of substring 
            while(i<j and ar[0] and ar[1] and ar[2]){
                ar[s[i] - '1']--; 
                i++; 
            }
            // i is 1 step forward lets take it back
            // find length and store shortest one
            len = min(len,j - i+1); 
        }
    }
    if(len == n+1){
        cout<<0<<endl; 
    }
    else{
        cout<<len<<endl;
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