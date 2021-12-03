// we can find each query by construction
// till q[i] , add all edges <= q[i] and then find all pairs possible for that graph 
// for better complexity sort all queries and use dsu to get size of each disjoint set
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
v32 par(N,-1); 
v32 rnk(N,1);
int find(int x){
    if(par[x] == -1){
        return x; 
    }
    return par[x] = find(par[x]); 
}
// ** edges are never going to join element in same component since it's a tree which has not cycles
int main()
{
    fast_cin();
    int n,q; 
    cin>>n>>q; 
    vv32 edges; 
    int x,y,w; 
    for(int i=0;i<n-1;i++){
        cin>>x>>y>>w; 
        edges.push_back({w,x,y}); 
    }
    sort(all(edges)); 
    vector<int> queries; 
    vector<int> id;
    for(int i=0;i<q;i++){
        cin>>w; 
        queries.push_back(w); 
        id.push_back(i); 
    }
    sort(all(id),[&](int &a,int &b){
        return queries[a] < queries[b]; 
    }); // this will help in getting other's back 
    vector<ll> res(q);
    int pairs = 0;  
    int ez = edges.size();
    int i=0;  
    int qi = 0; 
    ll ans = 0; 
    while(qi < q){
        // add till query has been resolved with smallest wt
        auto &wt = queries[id[qi]]; 
        // cout<<wt<<endl; 
        while(i<ez and edges[i][0] <= wt){
            int par1 = find(edges[i][2]); 
            int par2 = find(edges[i][1]);
            // cout<<edges[i][0]<<" "<<edges[i][1]<<" "<<edges[i][2]<<endl; 
            // cout<<"par "<<par1<<" "<<par2<<endl;  
            auto &r1 = rnk[par1]; 
            auto &r2 = rnk[par2]; 
            // cout<<"rank "<<r1<<" "<<r2<<endl; 
            ans -= r1*(r1-1ll)/2; 
            ans -= r2*(r2-1ll)/2; 
            int sum =r1 + r2; 
            if(r1 > r2){
                // add smaller on larger one 
                r1 += r2; 
                par[par2] = par1; 
            }
            else{
                r2 += r1; 
                par[par1] = par2; 
            }
            ans += sum*(sum-1ll)/2; 
            // edge has been successfully added 
            i++; 
        }
        res[id[qi]] = ans;
        qi++;  
    }
    for(auto i: res){
        cout<<i<<" "; 
    }
    cout<<endl; 
    return 0;
}