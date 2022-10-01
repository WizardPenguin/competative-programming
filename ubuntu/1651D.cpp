// nearest excluded points 
// let all are clustered at single center even then there would be some points who have nearest point at dist = 1
// after then check their nbrs, if these nbrs are in dataset then they also have same excluded points
// repeat this till we have no point left to check 
// if points don't have their nbrs at distance == 1 then they are shurely going to have it at larger distance 
// and that distance shurely passes through points which are having required point at distance = 1, because they are blockers 
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
int moves[4][2] = {{0,-1},{0,1},{-1,0},{1,0}}; 
void solve(){
    int n;
    cin>>n; 
    vvi graph(n); 
    int x,y; 
    vpii points; 
    set<pii> st; 
    for(int i=0;i<n;i+=1){
        cin>>x>>y; 
        points.push_back({x,y}); 
        st.insert({x,y}); 
    }
    map<pii,pii> res; 
    queue<pii> q; 
    for(auto &[x,y]: points){
        for(auto &[dx,dy]: moves){
            int X = x + dx; 
            int Y = y + dy; 
            if(st.find({X,Y}) == st.end()){
                q.push({x,y}); 
                res[{x,y}] = {X,Y}; 
                break;
            }
        }
    }
    while(not q.empty()){
        auto &[x,y] = q.front(); q.pop(); 
        for(auto &[dx,dy] : moves){
            int X = x + dx; 
            int Y = y + dy; 
            if(st.find({X,Y}) != st.end() and res.find({X,Y}) == res.end()){
                q.push({X,Y}); 
                res[{X,Y}] = res[{x,y}]; 
            }
        }
    }
    for(auto &pr: points){
        cout<<res[pr].first <<" "<<res[pr].second<<endl;
    }
    cout<<endl; 
}
int main(){
    fast_cin();
    solve();
    return 0;
}