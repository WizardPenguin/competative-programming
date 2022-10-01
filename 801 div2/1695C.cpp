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
#define N 5000
#define BIT bitset<N>
void solve(){
    int n,m; 
    cin>>n>>m; 
    vvi v(n,vi(m)); 
    for(auto &i: v){
        for(auto &j: i) cin>>j; 
    }
    queue<pii> q; 
    q.push({0,0}); 
    map<pii,BIT> mp;
    BIT tp(0); 
    if(v[0][0] == 1){
        tp[N/2] = 1; 
    }
    else{
        tp[N/2-2] = 1; 
    }
    mp[{0,0}] =tp;  
    while(true){
        auto [x,y] = q.front(); q.pop(); 
        // erase this value if needed 
        auto &val = mp[{x,y}]; 
        if(x == n-1 and y == m-1) break; 
        if(x < n-1){
            pii p = {x+1,y}; 
            if(mp.find(p) == mp.end()){
                mp[p] = {}; 
                q.push(p); 
            }
            if(v[x+1][y] == -1){
                mp[p] |= (val<<1); 
            }
            else{
                mp[p] |= (val>>1); 
            }
        }
        if(y < m-1){
            pii p = {x,y+1}; 
            if(mp.find(p) == mp.end()){
                mp[p] = {}; 
                q.push(p); 
            }
            if(v[x][y+1] == -1){
                mp[p] |= (val<<1); 
            }
            else{
                mp[p] |= (val>>1); 
            }
        }
        mp.erase({x,y}); 
    }
    auto st = mp[{n-1,m-1}]; 
    // cout<<st<<endl; 
    if(st[N/2 - 1]){
        cout<<"YES"<<endl; 
    }
    else{
        cout<<"NO"<<endl; 
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