// using tutorial binary search is good option
// if x is solution then we can have to find elements with x elements to right 
// then next elements should have x-1 to right and 1 to left (atlest conditions)
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
bool check(v32 &a,v32 &b,int x){
    int l = 0; 
    int r = x-1; 
    int found = 0; 
    for(int i=0;i<a.size();i++){
        if(b[i] >= l and a[i] >= r){
            found++; 
            l++; 
            r--; 
        }
    }
    return found >= x; 
}
void solve(){
    int n; 
    cin>>n; 
    v32 a(n),b(n); 
    for(int i=0;i<n;i++) cin>>a[i],cin>>b[i]; 
    int l = 0; 
    int r = n; 
    while(l <= r){
        int mid = (l + r)/2; 
        if(check(a,b,mid)){
            l = mid+1; 
        }
        else{
            r = mid-1; 
        }
    }
    cout<<l-1<<endl; 
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