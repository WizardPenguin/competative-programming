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
#define mii map<int,int>
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
struct DSU{
    vi parent,rank;
    DSU(int n): parent(n,-1),rank(n,1){
        return; 
    }
    int find(int x){
        if(parent[x]==-1) return x; 
        return parent[x] = find(parent[x]); 
    }
    bool join(int x,int y){
        int px = find(x); 
        int py = find(y); 
        if(px == py){
            // means we can't join these components
            return false; 
        }
        if(rank[px] > rank[py]){
            parent[py] = px; 
            rank[px] += rank[py]; 
        }
        else{
            parent[px] = py; 
            rank[py] += rank[px]; 
        }
        return true; 
    }
};
vb visited; 
map<int,int> ma,mb;
void recursive(vi &a,vi &b,vi &c,int i){
    // for every node which has defined value of c is going to mark visited at value which is not taken out of a or b
    // means they are saying to mark visited w.r.t index i 
    // cerr<<"calling "<<i<<endl; 
    if(a[i] == c[i]){
        auto it = ma[b[i]]; 
        if(not visited[it]){
            visited[it] = true;
            c[it] = b[i]; // fix value at location to value we want and move recursively   
            recursive(a,b,c,it); 
        }
    }
    else{
        auto it = mb[a[i]]; 
        if(not visited[it]){
            c[it] = a[i]; 
            visited[it] = true; 
            recursive(a,b,c,it); 
        }
    }
}
void solve(){
    ma.clear(); 
    mb.clear(); 
    int n; 
    cin>>n; 
    vi a(n),b(n),c(n); 
    for(int i=0;i<n;i+=1) cin>>a[i]; 
    for(int i=0;i<n;i+=1) cin>>b[i]; 
    for(int i=0;i<n;i+=1) cin>>c[i]; 
    // now we have found all of these things
    visited = vb(n,false);  
    // for each value find their respective indices
    for(int i=0;i<n;i+=1){
        ma[a[i]] = i; 
    }
    for(int j=0;j<n;j+=1){
        mb[b[j]] = j; 
    }
    // now we have found respective indices 
    for(int i=0;i<n;i+=1){
        if(c[i]){
            visited[i] = true; 
            recursive(a,b,c,i); 
        }
    }
    // for(auto i: visited) cerr<<i<<" ";  cerr<<endl; 
    DSU dsu(n); 
    // now join edges formed by every component here 
    for(int i=0;i<n;i+=1){
        if(not visited[i]){
            dsu.join(i,mb[a[i]]); 
            dsu.join(i,ma[b[i]]); 
            // cerr<<dsu.join(i,mb[a[i]])<<" ";  // indices where a is present and index where b is present
            // cerr<<dsu.join(i,ma[b[i]])<<" "; 
        }
    }
    ll ans = 1; 
    const int mod = 1e9 + 7; 
    // for(auto &i: dsu.rank) cerr<<i<<" ";  cerr<<endl; 
    // for(auto &i: dsu.parent) cerr<<i<<" "; cerr<<endl; 
    for(int i=0;i<n;i+=1){
        if(dsu.rank[i] > 1 and dsu.parent[i] == -1){
            ans *= 2; 
            ans %= mod; 
        }
    }
    cout<<ans<<endl; 
}
int main(){
    fast_cin();
    ll test;
    cin >> test;
    while(test--){
        solve();
    }
    return 0;
}