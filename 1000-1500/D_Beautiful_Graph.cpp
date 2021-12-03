//we need sum of elements assigned to each node should be odd means 1 even and 1 odd
// i.e. nodes at each edge should be of different color (adjacent node of different color) bipatite graph 
// now let it's possible to have such coloring then 
// assigning root as even(2) then it's childrent whould be of other color can have any of 1,3 i.e. 2 possibilities
// so total ways = 2^(nodes with other color)
// similarly if root is assigned odd(1,3) then some ways are possible 
// hance soln = 2^(x color) + 2^(y color nodes)
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
#define MOD 998244353
v32 color;
int colx,coly; 
bool dfs(vv32 &graph,int node = 1,int clr = 1){
    color[node] = clr; 
    for(auto &nbr: graph[node]){
        if(!color[nbr]){
            if(dfs(graph,nbr,3-clr) == false) return false; 
        }
        else if(color[nbr] == color[node]) return false; 
    }
    if(color[node] == 1) colx++; 
    else coly++; 
    return true; 
}
ll expo(ll p){ 
    ll res = 1; 
    ll val = 2; 
    while(p){
        if(p&1){
            res *= val; 
            res %= MOD; 
        }
        val *= val; 
        val %= MOD; 
        p>>=1; 
    }
    return res; 
}
int main()
{
    fast_cin();
    ll test;
    cin >> test;
    while(test--){
        int n,m; 
        cin>>n>>m; 
        vv32 graph(n+1); 
        int x,y; 
        while(m--){
            cin>>x>>y; 
            graph[x].push_back(y); 
            graph[y].push_back(x); 
        }
        color = v32(n+1,0);
        bool found = true; 
        ll ans = 1; 
        for(int i=1;i<=n;i++){
            if(color[i] == 0){
                colx = coly = 0; 
                if(dfs(graph,i)){
                    ans *= (expo(colx) + expo(coly))%MOD; 
                    ans %= MOD; 
                }
                else{
                    found = false; 
                    break; 
                }
            }
        }
        // cout<<expo(colx)<<" "<<expo(coly)<<endl; 
        // cout<<colx<<" "<<coly<<endl; 
        if(found){
            cout<<ans<<endl; 
        }
        else{
            cout<<0<<endl; 
        }
    }
    return 0;
}