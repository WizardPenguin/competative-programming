// 2 adjacent figures of different type should be colored with different color 
// means if we want to represent this problem by graph then there should be edge between nodes
// if they have different type of figure in them 
// we need to color those components with min colors possible 
// if all are same then single color 
// if all adjacent elements are of different type and last element is different from first then 3 colors 
// otherwise 2 colors 
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
#define N 2e5 + 5

v32 color(N); 
// let color == 0 being visited marker 
void dfs(vv32 &graph,int node,int col){
    color[node] = col; 
    for(auto &nbr: graph[node]){
        if(color[nbr] == 0){ // this is unvisited node
            dfs(graph,nbr,3-col); 
        }
        else if(color[nbr] == color[node]){
            color[nbr] = 3; // color it with 3rd color since it's causing problem 
        }
    }
    return; 
}
int main()
{
    fast_cin();
    ll test;
    cin >> test;
    while(test--){
        int n; 
        cin>>n; 
        vector<int> nodes(n); 
        vv32 graph(n); 
        for(int i=0;i<n;i++) cin>>nodes[i]; 
        for(int i=1;i<n;i++){
            if(nodes[i] != nodes[i-1]){
                graph[i].push_back(i-1); 
                graph[i-1].push_back(i); 
            }
        }
        if(nodes[0] != nodes[n-1]){
            graph[0].push_back(n-1); 
            graph[n-1].push_back(0); 
        }
        for(int i=0;i<n;i++){
            color[i] = 0; 
        }
        for(int i=0;i<n;i++){
            if(color[i] == 0){
                dfs(graph,i,1); 
            }
        }
        auto maxi = *max_element(color.begin(),color.begin() + n);
        cout<<maxi<<endl; 
        for(int i=0;i<n;i++) cout<<color[i]<<" "; 
        cout<<endl; 
    }
    return 0;
}