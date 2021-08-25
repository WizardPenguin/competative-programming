// find all edges and try adding that edge in both graph such that no cycle detected using dsu 
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
struct DSU{
    vector<int> par;
    vector<int> rank; 
    public: 
    DSU(int n){
        par = vector<int>(n,-1); 
        rank = vector<int>(n,1); 
    } 
    int find(int i){
        if(par[i] == -1){
            return i; 
        }
        return par[i] = find(par[i]); 
    }
    bool unite(int x,int y){
        // only called if unite is possible
        int s1 = find(x); 
        int s2 = find(y); 
        if(s1 != s2){
            if(rank[s1] < rank[s2]){
                par[s1] = s2; 
                rank[s2] += rank[s1]; 
            }
            else{
                par[s2] = s1;
                rank[s1] += rank[s2]; 
            }
            return true; 
        }
        return false; 
    }
    bool check(int x,int y){
        int s1 = find(x); 
        int s2 = find(y); 
        return s1 != s2; 
        // returns true if we can't work with them 
    }
};
int main()
{
    fast_cin();
    ll test;
    test = 1; 
    while(test--){
        int n; 
        cin>>n; 
        int m1,m2; 
        cin>>m1>>m2; 
        n++; 
        // two forests
        DSU f1(n),f2(n); 
        map<pair<int,int> ,bool> edges; 
        for(int i=1;i<n;i++){
            for(int j=i+1;j<n;j++){
                edges[{i,j}] = false;  // not taken
            }
        }
        int u,v; 
        for(int i=0;i<m1;i++){
            cin>>u>>v; 
            f1.unite(u,v); 
            edges[{u,v}] = true;  // mark them as taken 
        }
        for(int i=0;i<m2;i++){
            cin>>u>>v; 
            f2.unite(u,v); 
            edges[{u,v}] = true; 
        }
        // now we need to add remaining edges
        vector<pair<int,int> > res; 
        for(auto &i: edges){
            if(i.second == false){
                // try taking this edge
                auto edge = i.first; 
                if(f1.check(edge.first,edge.second) and f2.check(edge.first,edge.second)){
                    // if we have this possibility then add this edge
                    f1.unite(edge.first,edge.second); 
                    f2.unite(edge.first,edge.second);
                    res.push_back(edge);  
                }
            }
        }
        cout<<res.size()<<endl; 
        for(auto i: res){
            cout<<i.first<<" "<<i.second<<endl;
        }
    }
    return 0;
}