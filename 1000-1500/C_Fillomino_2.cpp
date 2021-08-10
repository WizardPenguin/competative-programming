// it seems solution is alway's possible we decide priority of moves as left,down,then right 
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

vector<vector<int> > moves(3,vector<int>(2));
int val; 
int k; 
void dfs(vector<vector<int> > &v,int i,int j){
    if(k <= 0) return ; 
    for(auto &m: moves ){
        int x = i + m[0]; 
        int y = j + m[1];
        // if it's valid and is not already filled
        if(x >=0 and y >=0 and x < v.size() and y < v.size() and v[x][y] == 0 and k > 0){
            v[x][y] = val; 
            k--; 
            dfs(v,x,y); 
        }
    }
    return; 
}

int main()
{
    fast_cin();
    moves = {{0,-1},{1,0},{0,1}};
    int n;
    cin>>n; 
    vector<vector<int> > v(n,vector<int>(n,0)); 
    for(int i=0;i<n;i++) cin>>v[i][i]; 
    for(int i=0;i<n;i++){
        val = v[i][i]; 
        k = v[i][i] -1; 
        dfs(v,i,i);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<=i; j++) cout<<v[i][j]<<" "; 
        cout<<endl; 
    }
    return 0;
}