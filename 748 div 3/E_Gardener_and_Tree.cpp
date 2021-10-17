
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
#define N 400005
int main()
{
    fast_cin();
    ll test;
    cin >> test;
    while(test--){
        int n; 
        cin>>n;  
        int k; 
        cin>>k;
        // let's try bfs from leaves to insider of array 
        // also try find distance till node is having only 2 edges 
        // we can have visited array so we don't have to remove edges from nodes
        vector<vector<int> > graph(n); 
        vector<int> siz(n,0); 
        for(int i=0;i<n-1;i++){
            int u,v; cin>>u>>v; 
            u--,v--; 
            // cout<<u<<" "<<v<<endl; 
            graph[u].push_back(v); 
            graph[v].push_back(u); 
            siz[u]++; 
            siz[v]++; 
        }
        queue<int> q; 
        vector<int> dist(n,0); 
        for(int i=0;i<n;i++){
            if(siz[i] <= 1){
                q.push(i); 
                dist[i] = 1; 
            }
        } 
        int d = 2; 
        while(!q.empty()){
            int t = q.size(); 
            // cout<<t<<" "; 
            for(int i=0;i<t;i++){
                auto f = q.front();  
                q.pop(); 
                // if distance have been updated means we have triversed that node
                for(auto &x: graph[f]){
                    if(dist[x] != 0) continue; 
                    siz[x]--; 
                    if(siz[x] == 1){
                        dist[x] = d; 
                        q.push(x); 
                    }
                }
            }
            d++; 
        }
        // cout<<endl; 
        int ans = n; 
        for(int i=0;i<n;i++){
            if(dist[i] <= k){
                ans--; 
            }
        }
        cout<<ans<<endl; 
    }
    return 0;
}