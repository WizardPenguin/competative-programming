// move in the direction where there is no wall, and mark nodes visited
// return number of nodes it visited
// using visited array separately worked 
// but using mat[i][j] = 0 after it's work has been done doesn't work gives wrong solution  
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
int moves[4][2] = {{0,-1},{1,0},{0,1},{-1,0}}; 
int cnt =0; 
void dfs(vector<vector<int> > &mat,vector<vector<bool> > &visited,int x,int y){
    // it's clear that we won't go out of range dfs will converge inself
    auto val = mat[x][y];
    cnt++; 
    visited[x][y] = false; 
    // cout<<val<<endl;   
    for(int i=0;i<4;i++){
        if((val&(1<<i)) == 0){
            // if this bit is off then we don't have all in this direction and need to move 
            int xx = x + moves[i][0]; 
            int yy = y + moves[i][1];  
            if(visited[xx][yy]){// if it's not visited only then visit it
                dfs(mat,visited,xx,yy); 
            }
        }
    }
    return; 
}
int main()
{
    fast_cin(); 
    ll test;
    test = 1; 
    while(test--){
        int n,m; 
        cin>>n>>m;  
        vector<vector<int> > v(n,vector<int>(m,0));  
        vector<vector<bool> > visited(n,vector<bool>(m,true)); 
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>v[i][j];
        vector<int> res; 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]){
                    cnt = 0; 
                    dfs(v,visited,i,j); 
                    res.push_back(cnt); 
                }
            }
        }
        // cout<<res.size()<<endl; 
        sort(all(res),greater<int>()); 
        for(auto &i: res) cout<<i<<" "; 
    }
    return 0;
}