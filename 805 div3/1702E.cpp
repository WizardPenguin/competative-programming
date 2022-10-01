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
vvi graph; 
vi color; 
bool dfs(int node,int clr = 0){
    color[node] = clr; 
    for(auto &nbr: graph[node]){
        if(color[nbr] != -1){
            if(color[nbr] == color[node]){
                return false; // we don't found any solution 
            }
        }
        else if(not dfs(nbr,1-clr)) return false; 
    }
    return true; 
}
void solve(){
    int n; 
    cin>>n; 
    graph = vvi(n+1); 
    int x,y; 
    map<int,int> freq; 
    for(int i=0;i<n;i+=1){
        cin>>x>>y; 
        graph[x].push_back(y); 
        graph[y].push_back(x); 
        freq[x] +=1; 
        freq[y]+=1; 
    }
    for(auto &i: freq){
        if(i.second > 2){
            cout<<"NO"<<endl; 
            return; 
        }
    }
    //cerr<<"graph formed"<<endl; 
    color = vi(n+1,-1); 
    for(int i=1;i<=n;i+=1){
        if(color[i] == -1 and graph[i].size()){
            if(not dfs(i)){
                cout<<"NO"<<endl; 
                return; 
            } 
        }
    }
    cout<<"YES"<<endl; 
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