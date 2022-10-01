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
    int n; 
    cin>>n; 
    vi v(n); 
    for(int i=0;i<n;i++) cin>>v[i]; 
    vvi mapping(n+1); 
    for(int i=0;i<n;i++){
        mapping[v[i]].push_back(i); // indices are going to be laready sorted
    }
    /// mex = 0 then find first 0 in array 
    vi b; 
    int taken = -1; 
    while(true){
        int mex = 0; 
        int id = taken;  // start from here  
        while(true){
            // take first mex element 
            auto &mp = mapping[mex]; 
            if(mp.size() == 0) break; 
            int ub = upper_bound(all(mp),taken) - mp.begin(); 
            // before taken all elements have been removed we need to think differently 
            if(ub == mp.size()){
                break; // not found
            }
            else{
                // take this element for our use 
                id = max(id,mp[ub]); 
            }
            mex++; 
        }
        // cout<<"MEX"<<endl; 
        // cout<<mex<<" "<<id<<endl; 
        if(mex == 0){
            // no more increase can be there means we are going to get 0 for all remaining elements 
            break; 
        }
        b.push_back(mex); 
        taken = id; 
    }
    // now from id+1 .... n-1 we have mex = 0 that can be inserted 
    for(int i = taken+1;i<n;i++){
        b.push_back(0); 
    }
    // cout<<"RES"<<endl; 
    cout<<b.size()<<endl; 
    for(auto &i: b) cout<<i<<" "; 
    cout<<endl; 
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