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
    int n,k; 
    cin>>n>>k; 
    if(k >= n){
        cout<<1<<endl; 
        cout<<1<<endl; 
        return 0; 
    }
    else if((2*k + 1) >= n){
        cout<<1<<endl; 
        cout<<k+1<<endl; 
        return 0; 
    }
    int rem = n%(2*k + 1); 
    int count = n/(2*k+1); 
    if(rem == 0 or rem > k){ // then last centre in inside range 
        if(rem == 0) cout<<count<<endl; 
        else cout<<count+1<<endl; 
        for(int i=k+1;i<=n;i+=2*k+1){
            cout<<i<<" "; 
        }
        cout<<endl; 
    }
    else{
        // here instead of checking requirnments just start it from 1 then we'll have k elements extra to cover
        // but since rem <=k means it can cover 2*k+1-k elements <= k it will be correnct
        count++;
        cout<<count<<endl;
        int i =1;  
        while(count--){
            cout<<i<<" "; 
            i += 2*k+1; 
        }
        cout<<endl; 
    }
    return 0;
}