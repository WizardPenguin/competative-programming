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
typedef vector<vector<bool> > vvb;
typedef vector<string> vs;
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 
vvi graph; 
set<int> st; 
bool broken = false; 
bool found = true; 
bool check(int node,int parent){
    int count = 0; 
    for(auto &nbr: graph[node]){
        if(nbr == parent) continue; 
        count += check(nbr,node);  
    }
    if(count > 2 or (broken and(count or (st.find(node) != st.end())))){
        found = false; 
        return 0; 
    }
    if(count == 2){
        broken = true; 
        return 0; 
    }
    return (st.find(node) != st.end()) or count; 
}
void solve(){
    int n; 
    cin>>n; 
    graph = vvi(n+1); 
    int x,y;
    for(int i=0;i<n-1;i+=1){
        cin>>x>>y; 
        graph[x].push_back(y); 
        graph[y].push_back(x); 
    }
    int q,val; 
    cin>>q; 
    while(q--){
        int sz; 
        cin>>sz; 
        st.clear();  
        for(int i=0;i<sz;i+=1){
            cin>>val; 
            st.insert(val); 
        }
        found = true; 
        broken = false; 
        check(1,-1); 
        if(found){
            cout<<"YES"<<endl; 
        }
        else{
            cout<<"NO"<<endl ;
        }
    }
}
int main(){
    fast_cin();
    solve();
    return 0;
}