// prime + prime = even except if it's = 2
// so we can only chose 2 and other edge for it 
// prime , 2 , prime such cycle needs to be there 
// if any node has more than 2 edges not possible 
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
 
vi res; 
vb visited; 
map<pair<int,int> ,int > mp; 
void dfs(vvi &graph,int x,bool even){
    // we have at max 1 nbr of this node 
    // dbg(x); 
    visited[x] = true; 
    for(auto &nbr: graph[x]){
        if(!visited[nbr]){
            // visited[nbr] = true; 
            res[mp[{x,nbr}]] = (even)?2:3; 
            dfs(graph,nbr,!even);
        }
    }
    return; 
}
void solve(){
    int n,x,y;  
    cin>>n; 
    vvi graph(n); 
    vi indeg(n,0); 
    res = vi(n,-1); 
    visited = vb(n,false); 
    mp.clear(); 
    for(int i=0;i<n-1;i++){
        cin>>x>>y; 
        x--,y--; 
        graph[x].push_back(y); 
        graph[y].push_back(x); 
        // cout<<x<<" "<<y<<endl; 
        indeg[x]++; 
        indeg[y]++; 
        mp[{x,y}] = i; 
        mp[{y,x}] = i; 
    }
    int indeg1 = -1; 
    for(int i=0;i<n;i++){
        if(indeg[i] > 2){
            cout<<-1<<endl; 
            return; 
        }
        else if(indeg[i] == 1){
            indeg1 = i; 
        }
    }
    // we know starting point 
    // cout<<indeg1<<endl; 
    dfs(graph,indeg1,false); 
    for(int i=0;i<n-1;i++){
        cout<<res[i]<<" "; 
    }
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