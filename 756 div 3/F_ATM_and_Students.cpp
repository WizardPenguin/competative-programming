// initial value = given 
// then add elements till we get -ve value 
// after that -ve value start new sequence with initial value = given 
// find largest sequence such found 
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  
#include <cmath>
 
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
    ll n,s; 
    cin>>n>>s; 
    v32 v(n); 
    for(int i=0;i<n;i++) cin>>v[i]; 
    ll maxlen = 0; 
    p32 ret = {-1,-1}; 
    int i=0; 
    int j =0; 
    ll val = s; 
    while(j<n){
        val += v[j]; 
        j++; 
        if(val < 0){
            while(i<j and val  < 0){
                val -= v[i]; 
                i++; 
            }
        }
        else{
            // this can be possible answer 
            if(j - i + 1 > maxlen){
                ret.first = i+1; 
                ret.second = j; 
                maxlen = j - i + 1; 
            }
        }
    }
    if(maxlen){
        cout<<ret.first<<" "<<ret.second<<endl; 
    }
    else{
        cout<<-1<<endl; 
    }
}
int main()
{
    fast_cin();
    ll test;
    cin >> test;
    while(test--){
        solve();
    }
    return 0;
}