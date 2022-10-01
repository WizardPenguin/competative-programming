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
 
vpii nodes = {{0,0},{1,0},{2,0},{2,1},{2,2},{1,2},{0,2},{0,1}}; 
void solve(){
    // now give every nodes offset of +100
    int n; 
    cin>>n; 
    // cout<<nodes.size()*n<<endl; 
    int offset = 3; 
    set<pii> res; 
    while(n--){
        for(auto &[x,y]: nodes){
            res.insert({x+offset,y+offset}); 
            // cout<<x+offset<<" "<<y+offset<<endl; 
        }
        offset+=2; 
    }
    cout<<res.size()<<endl; 
    for(auto &[x,y]: res) cout<<x<<" "<<y<<endl; 
    cout<<endl; 
}
int main(){
    fast_cin();
    ll test=1; 
    set<pii> st; 
    for(auto &[x,y]: nodes){
        st.insert({-x,-y}); 
        st.insert({x,y}); 
    }
    nodes = vpii(st.begin(),st.end()); 
    while(test--){
        solve();
    }
    return 0;
}