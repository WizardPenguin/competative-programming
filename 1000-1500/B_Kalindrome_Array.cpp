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
    int n; 
    cin>>n;
    vector<int> v(n); 
    for(int i=0;i<n;i++) cin>>v[i]; 
    int i=0; 
    int j=n-1; 
    while(i< n/2 and v[i] == v[j])i++,j--; 
    // now eighter we are done or we have character which we are going to remove  
    if(i != n/2){
        int rem1 = v[i]; 
        int rem2 = v[j]; 
        vector<int> tp; 
        for(auto x: v){
            if(x == rem2) continue; 
            tp.push_back(x); 
        }
        i=0; 
        int sz = tp.size(); 
        j=sz-1; 
        while(i<sz/2 and tp[i] == tp[j]) i++,j--;
        // dbg(i);  
        if(i == sz/2){
            cout<<"YES"<<endl; 
            return; 
        }
        tp.clear(); 
        for(auto x: v){
            if(x == rem1) continue; 
            tp.push_back(x); 
        }
        i=0; 
        sz = tp.size(); 
        j = sz-1; 
        while(i<sz/2 and tp[i] == tp[j]) i++,j--; 
        // dbg(i); 
        if(i == sz/2){
            cout<<"YES"<<endl; 
        }
        else{
            cout<<"NO"<<endl; 
        }
    }
    else{
        cout<<"YES"<<endl; 
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