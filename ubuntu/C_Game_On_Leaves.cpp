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
 

void solve(){
    int n,x; 
    cin>>n>>x; 
    vvi graph(n+1); 
    int u,v; 
    for(int i=0;i<n-1;i++){
        cin>>u>>v; 
        graph[u].push_back(v); 
        graph[v].push_back(u); 
    }
    if(graph[x].size() <= 1){
        cout<<"Ayush"<<ln; 
    }
    else{
        // remove all nodes till x has atlest 2 child otherwise this node becomes leaf and someone will win 
        // no-one want's other to win 
        n-=3; 
        if(n&1){
            cout<<"Ayush"<<ln; 
        }
        else{
            cout<<"Ashish"<<ln; 
        }
    }
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