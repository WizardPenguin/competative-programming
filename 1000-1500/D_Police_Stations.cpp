// find when we can remove any edge
// if it's not participating for making any node to be nearer to policestation then that edge can be removed
// so implement multisource bfs and find such nodes
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


int main()
{
    fast_cin();
    ll test = 1; 
    while(test--){
        int n,p,d; 
        cin>>n>>p>>d; 
        vector<vector<pair<int,int> > > graph(n+1); 
        // we are also going to store index of edge since those are required to find edges to be removed
        int x,y; 
        v32 visited(n+1,0);  // mark eveyone as not visited 
        queue<int> q; 
        for(int i=0;i<p;i++){
            cin>>x; 
            q.push(x);
            visited[x] = 1; 
        }
        for(int i=0;i<n-1;i++){
            cin>>x>>y; 
            graph[x].push_back({y,i}); 
            graph[y].push_back({x,i}); 
        }
        v32 answer(n,0); // mark all edges as not needed
        while(!q.empty()){
            int sz = q.size(); 
            for(int i=0;i<sz;i++){
                auto tp = q.front();
                q.pop();  
                for(auto &pr: graph[tp]){
                    auto &nd = pr.first; 
                    auto &ed = pr.second; 
                    if(!visited[nd]){
                        answer[ed] = 1; 
                        visited[nd] = true; 
                        q.push(nd);
                    }
                }
            }
        }
        vector<int> res; 
        for(int i=0;i<n-1;i++){
            if(answer[i] == 0)res.push_back(i+1); 
        }
        cout<<res.size()<<endl; 
        for(auto &i: res) cout<<i<<" "; cout<<endl; 
    }
    return 0;
}