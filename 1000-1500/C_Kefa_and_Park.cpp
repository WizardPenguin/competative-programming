#include <bits/stdc++.h> 
#include <complex>
#include <cmath>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
vector<int> cats; 
int n,m; 
int dfs(vector<vector<int> > &graph,int par = -1,int cur = 1,int prev = 0){
    // cout<<cur<<endl; 
    if(prev > m) return 0;
    if(graph[cur].size() == 1 and par != -1){
        return 1; 
    }
    int ans = 0; 
    for(auto &i: graph[cur]){
        if(i == par) continue; 
        if(cats[i]){
            ans += dfs(graph,cur,i,prev + 1); 
        }
        else ans += dfs(graph,cur,i,0); 
    }
    return ans; 
}
int main()
{
    fast_cin();
    ll test = 1; 
    while(test--){
        // tree is necesaarily a binary tree
        cin>>n>>m; 
        vector<vector<int> > graph(n + 1);
        cats = vector<int>(n+1,0); 
        for(int i=0;i<n;i++) cin>>cats[i + 1]; 
        int x,y; 
        for(int i=0;i<n-1;i++){
            cin>>x>>y; 
            graph[x].push_back(y); 
            graph[y].push_back(x); 
        } 
        // we know tree is rooted at 1
        if(cats[1]) cout<<dfs(graph,-1,1,1); 
        else{
            cout<<dfs(graph)<<endl;
        } 
    }
    return 0;
}