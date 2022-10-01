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
vpll range; 
vvi graph; 
vvi rgraph; 
void solve(){
    int n; 
    cin>>n; 
    // we got parent of each node 
    int p; 
    graph = rgraph = vvi(n+1); 
    range = vpll(n+1); 
    queue<int> q; 
    for(int i=2;i<=n;i+=1){
        cin>>p;
        graph[p].push_back(i);  // directed graph formed 
        rgraph[i].push_back(p); // reverse graph for feture use 
    }
    for(int i=1;i<=n;i+=1){
        if(graph[i].size() == 0){
            q.push(i); 
        }
    }
    for(int i=0;i<n;i+=1){
        int x,y; 
        cin>>x>>y; 
        range[i+1].first = x; 
        range[i+1].second = y; 
    }
    // we have ranges, graph; 
    // let's start from leaves , having no children  
    vll formed(n+1,0); 
    int ans = 0; 
    while(not q.empty()){
        auto tp = q.front(); q.pop(); 
        if(formed[tp] < range[tp].first){
            // increase it to second 
            formed[tp] = range[tp].second; 
            ans += 1; 
        }
        else{
            formed[tp] = min(formed[tp],range[tp].second); 
        }
        // now for each parent update it's value 
        for(auto &p: rgraph[tp]){
            formed[p] += formed[tp]; 
            graph[p].pop_back(); 
            if(graph[p].size() == 0){
                q.push(p); 
            }
        }
    }
    cout<<ans<<endl; 
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