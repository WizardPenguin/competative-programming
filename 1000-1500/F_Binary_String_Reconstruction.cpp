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
    int a,b,c; 
    cin>>c>>b>>a; 
    string res; 
    // let a being all 1
    // b being consecutive 
    // c being all 0
    if(a){
        // atlest 2 1's are added like this 
        for(int i=0;i<=a;i++) res += "1"; 
        if(b == 0) goto end;  // since if there is no b there can't be c anymore so conclude here 
        if(b&1){
            for(int i=0;i<(b-1)/2;i++){
                res += "01"; 
            }
        }
        else{
            for(int i=0;i<(b-2)/2;i++){
                res += "01"; 
            }
            res = "0" + res; 
        }
        for(int i=0;i<=c;i++){
            res += "0"; 
        }
    }
    else if(c){
        // then add 0's and then desired 01
        for(int i=0;i<=c;i++){
            res += "0"; 
        }
        for(int i=0;i<b;i++){
            if(i&1){
                res += "0"; 
            }
            else{
                res += "1"; 
            }
        }
    }
    else{
        res = "0"; 
        for(int i=0;i<b;i++){
            if(i&1){
                res += "0"; 
            }
            else{
                res += "1"; 
            }
        }
    }
    end:;
    cout<<res<<endl; 
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