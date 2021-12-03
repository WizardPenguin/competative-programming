#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  
#include <cmath>
// count number of ones and zeros 
// then replace them with max number of substrings of 2nd string 
// put remaining in any form into solution string 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 

void solve(){
    string a,b; 
    cin>>a>>b; 
    if(b.length() > a.length()){
        cout<<a<<endl;
        return;  
    }
    int ones =0,zeros=0,o=0,z=0; 
    for(auto &i: a){
        if(i=='1') ones++; 
        else zeros++; 
    }
    for(auto &i: b){
        if(i == '1') o++; 
        else z ++; 
    }
    // we need to find largest ending string of b that is same as starting part of b
    // for this we are going to use hashing 
    int n = b.length(); 
    ll p = 17; 
    ll mod = 1000000007; 
    ll start = 0; 
    ll end = 0; 
    int id = n; 
    ll prod = 1; 
    v64 prefix(n); 
    for(int i=0;i<n-1;i++){
        // generating suffix and prefix hashes
        start += prod*b[i]; 
        start %= mod; 
        end *= p; 
        end %= mod; 
        end += b[n-i-1]; 
        end %= mod; 
        prod *= p; 
        prod%=mod; 
        // cout<<start<<" "<<end<<endl; 
        if(start == end){
            // then check them weather they are really same 
            // cout<<"checking"<<endl; 
            bool found = true; 
            for(int c=0;c<=i;c++){
                if(b[c] != b[n-i-1 + c]){
                    found = false; 
                    break; 
                }
            }
            if(found) id = n - i - 1; 
        }
    }
    // cout<<id<<endl; 
    // doing this gives first index from which substring looks same as strting string of b
    // this remove largest use of o's and 1' s to form b
    // create first occurence if possible 
    string res; 
    string sub = b.substr(n-id); 
    // cout<<sub<<endl; 
    if(ones >= o and zeros >= z){
        res += b; 
        ones -= o; 
        zeros -= z; 
        // now only add desired smaller substring 
        z = o = 0; 
        for(int i=n-id; i<n;i++){
            if(b[i] == '0') z++; 
            else o++; 
        }
        while(ones >=o and zeros >= z){
            res += sub; 
            ones -= o; 
            zeros -= z; 
        }
        while(ones--) res += "1"; 
        while(zeros--) res += "0"; 
        cout<<res<<endl; 
    }
    else{
        cout<<a<<endl; 
    }
}
int main()
{
    fast_cin();
    ll test = 1;
    while(test--){
        solve();
    }
    return 0;
}