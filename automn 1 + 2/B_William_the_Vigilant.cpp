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
 

int main()
{
    fast_cin();
    int n,q; 
    cin>>n>>q; 
    string s;
    cin>>s; 
    int ans =0; 
    for(int i=0;i<n-2;i++){
        if(s[i] == 'a' and s[i+1] == 'b' and s[i+2] == 'c'){
            ans++; 
        }
    }
    // cout<<ans<<endl; 
    while(q--){
        int id; 
        char ch; 
        cin>>id>>ch; 
        id--; 
        // cout<<id<<" "<<ch<<endl; 
        auto prev = s[id]; 
        // removing previous character
        // cout<<ans<<" "; 
        if(prev == 'a'){
            ans -= (id<n-2 and s[id+1] == 'b' and s[id+2] == 'c'); 
        }
        else if(prev == 'b'){
            ans -= (id > 0 and id < n-1 and s[id-1] == 'a' and s[id+1] == 'c');
        }
        else if(prev == 'c'){
            ans -= (id > 1 and s[id-1] == 'b' and s[id-2] == 'a'); 
        }
        // effect of replacement 
        // cout<<ans<<endl; 
        s[id] = ch; 
        if(ch == 'a' ){
            ans += (id < n-2 and s[id+1] == 'b' and s[id+2] == 'c'); 
        }
        else if(ch == 'b' ){
            ans += (id > 0 and id < n-1 and s[id-1] == 'a' and s[id+1] == 'c'); 
        }
        else if(ch == 'c'){
            ans += (id > 1 and s[id-1] == 'b' and s[id-2] == 'a'); 
        }
        cout<<ans<<endl; 
    }
    return 0;
}