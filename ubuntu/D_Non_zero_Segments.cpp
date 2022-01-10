// we are going to check which segment is causing zero 
// it can be checked using prefix sum where we are required to find weather prefix sum = 0
// of someone in previous part can make it zero 
// then we have to impute some number in between to make it nonzero
// after then we need to remove all numbers which were in previous prefix indices because they are not going to make zero 
// because of imputation of new number
// after then check again from that index onwards 
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
    vll v(n );
    for(int i=0;i<n;i++) cin>>v[i];
    set<ll> st; 
    st.insert(v[0]); 
    int ans = 0; 
    ll sm = v[0]; 
    st.insert(0); 
    for(int i=1;i<n;i++){
        sm += v[i]; 
        if(st.find(sm) != st.end()){
            ans++; 
            st.clear(); 
            // st.insert(v[i]); 
            st.insert(0); 
            // sm = v[i]; 
        }
        st.insert(sm); 
    }
    cout<<ans<<endl; 
}
int main(){
    fast_cin();
    solve() ;
}