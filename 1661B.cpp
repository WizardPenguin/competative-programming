// we can iterate over all possibilities 
// we have at max 15 moves for any number, so we can itereate over all possibilities of add, mult in 15 moves
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
#define M 32768
// void solve(){
//     int n; 
//     cin>>n; 
//     int minOp = 15; 
//     for(int i=0;i<=15;i+=1){
//         for(int j=0;j<=15;j+=1){
//             if(( ((n+i)<<j)%MOD ) == 0){
//                 minOp = min(minOp,i+j); 
//             }
//         }
//     }
//     cout<<minOp<<" "; 
// }
// this is shortest path type problem each node has 2 moves available and find shortest path from 0 
int main(){
    fast_cin();
    int n; cin>>n; 
    vector<int> v(n); 
    for(int i=0;i<n;i+=1) cin>>v[i];  
    vvi graph(M+1);
    /// we need reverse graph since frm node i we can go to i*2 and i+1 
    // so i*2 and i+1 has nbr i since we are starting from destination to other sources
    // for(int i=0;i<=M;i+=1){ 
    //     graph[i].push_back((i+1)%M); 
    //     graph[i].push_back((2*i)%M); 
    // }  
    for(int i=0;i<=M;i+=1){
        graph[(i+1)%M].push_back(i); 
        graph[(2*i)%M].push_back(i); 
    }
    vector<int> dist(M+1,INT_MAX);
    dist[0] = 0;
    queue<int> q; 
    q.push(0);
    while(not q.empty()){
        auto ft = q.front(); q.pop(); 
        for(auto &nbr: graph[ft]){
            if(dist[nbr] == INT_MAX){
                dist[nbr] = dist[ft] +1; 
                q.push(nbr);
            }
        }
    }
    for(int i=0;i<n;i++) cout<<dist[v[i]]<<" "; 
    cout<<endl; 
    return 0;
}