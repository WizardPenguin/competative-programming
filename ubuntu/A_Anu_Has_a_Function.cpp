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
    int n; 
    cin>>n; 
    vi v(n); 
    for(int i=0;i<n;i++) cin>>v[i];
    // operation can be written as a&(-b) sinc a|b add's both common bits and -b removes all bits of b
    // means we are removing all bits of b from a
    // similarly applying for more times we are removing bits of other numbers also 
    // so except one number (taken as a) find | or all remaining and remove it from this number 
    // this or can be found by using suffix and prefix OR
    vector<int> left(n); 
    vector<int> right(n); 
    left[0] = v[0]; 
    for(int i=1;i<n;i++){
        left[i] |= left[i-1]|v[i]; 
    }
    right[n-1] = v[n-1]; 
    for(int i=n-2;i>=0;i--){
        right[i] |= right[i+1]|v[i];
    }
    int id = 0; 
    int maxi = v[0]&(~right[1]); 
    for(int i=1;i<n-1;i++){
        int val = v[i]; 
        int ori = left[i-1]|right[i+1]; 
        val = val&(~ori); 
        if(val > maxi){
            maxi = val; 
            id = i; 
        }
    }
    if(v.size() > 1){
        int val = v[0]; 
        int ori = right[1];
        val = val&(~ori); 
        if(val > maxi){
            maxi = val; 
            id = 0; 
        }
        val = v[n-1]; 
        ori = left[n-2]; 
        val = val &(~ori); 
        if(val > maxi){
            maxi = val; 
            id = n-1; 
        }
    }
    cout<<v[id]<<" "; 
    for(int i=0;i<n;i++){
        if(id == i) continue; 
        cout<<v[i]<<" ";  
    }
    cout<<endl;
}
int main(){
    fast_cin();
    solve();
    return 0;
}