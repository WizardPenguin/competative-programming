// courses are having their pre requisites 
// we'll triverse them in level and i be iteration for which book read to complete any chapter 
// time[node] = max(pre requisites time ) + 1 if pre requisit taking largest time is > him 
// otherwise it can be read in same iteration of book reading 
// using this we can find iteration of book for which all are read 
// also if at a point bfs ends but we haven't triversed all nodes means there are unresolved dependencies inf time taken in that case
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
    ll test;
    cin >> test;
    while(test--){
        int n;
        cin>>n; 
        // if x is pre requisite then edge x -> node directed edge need to be formed 
        vv32 pre(n + 1); 
        vv32 graph(n + 1); 
        v32 deg(n + 1,0); 
        int size;
        int node;  
        for(int i=1;i<=n;i++){
            cin>>size; 
            for(int j=0;j<size;j++){
                cin>>node; 
                graph[node].push_back(i); 
                pre[i].push_back(node); 
            }
            deg[i] = size; 
        }
        v32 time(n + 1,0); 
        queue<int> q; 
        for(int i=1;i<=n;i++){
            if(deg[i] == 0){
                q.push(i); 
                time[i] =1; 
            }
        }
        while(!q.empty()){
            auto tp = q.front();
            q.pop(); 
            for(auto &nd: graph[tp]){
                deg[nd] --; 
                if(deg[nd] == 0){
                    // find the one who took the largest iterations 
                    int maxi = 0; 
                    int val = 0; 
                    for(auto &p: pre[nd]){
                        // ** need to consider eg like all pre have same time then we need to take largest value out of them
                        if((time[p] > maxi) or time[p] == maxi and p > val){ 
                            val = p; 
                            maxi = time[p]; 
                        }
                    }
                    if(val < nd){
                        time[nd] = maxi; 
                    }
                    else{
                        time[nd] = maxi+1; // we need to have new iteration for this node 
                    }
                    // now insert it to queue
                    q.push(nd); 
                }
            }
        }
        int ans = 0;
        bool found = false; 
        for(int i=1;i<=n;i++){
            if(time[i]){
                ans = max(ans,time[i]); 
            }
            else{
                found = true; 
                break; 
            }
        }
        if(found){
            cout<<-1<<endl; 
        }
        else{
            cout<<ans<<endl; 
        }
    }
    return 0;
}