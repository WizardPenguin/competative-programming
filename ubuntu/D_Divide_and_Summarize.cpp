// we are required to find mid = (max + min)/2 and take elements in left or right array 
// after then condition is checked on sum of elements means order of elements doesn't matter 
// sort all elements
// find mid
// break array over mid and find sum of middle part using prefix sum in O(1)
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
set<ll> st; 
vll prefix,v; 
int n,q; 
void recursive(int l,int r){
    if(l > r){
        return; 
    }
    // add this range sum to set
    st.insert(prefix[r+1] - prefix[l]); 
    ll mid = (v[l] + v[r])/2; 
    auto u = upper_bound(v.begin() + l,v.begin() + r+1,mid); 
    int ub; 
    ub = u - v.begin(); 
    // now break array into parts 
    if(ub < l or ub > r){
        return; 
    }
    recursive(l,ub - 1); 
    recursive(ub,r); 
    return; 
}

void solve(){
    cin>>n>>q; 
    v = vll(n); 
    prefix = vll(n + 1); 
    st.clear(); 
    prefix[0] = 0; 
    for(int i=0;i<n;i++) cin>>v[i]; 
    sort(all(v)); 
    for(int i=1;i<=n;i++){
        prefix[i] = v[i-1]; 
        prefix[i] += prefix[i-1]; 
    }
    recursive(0,n-1); 
    while(q--){
        ll s; 
        cin>>s; 
        if(st.find(s) != st.end()){
            cout<<"Yes"<<endl; 
        }
        else{
            cout<<"No"<<endl; 
        }
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