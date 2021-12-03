// n <= 10^3 means N^2 solution will work 
// so for each condition if they require to join 2 different component then join them and take largest component as answer
// otherwise we have ability to form an extra edge since condition is already satisfied
// for that we'll store components into heap and take top k + 1(extra edges we can make)
// then join those largest k+1 components using those edges to get single one having largest no of aquintances
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  
#include <cmath>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define N 1003
v32 par(N,-1); 
v32 rnk(N,1); // after connecting 2 components we are going to make one of them having rank = -1 
int find(int x){
    if(par[x] == -1) return x; 
    return par[x] = find(par[x]); 
}
void join(int x,int y){
    int px = find(x); 
    int py = find(y); 
    // we are shure that call only made when both parents are differet
    if(rnk[px] > rnk[py]){
        par[py] = px; 
        rnk[px] += rnk[py]; 
        rnk[py] = -1; 
    }
    else{
        par[px] = py; 
        rnk[py] += rnk[px]; 
        rnk[px] = -1; 
    }
}
int main()
{
    fast_cin();
    int n,m; 
    cin>>n>>m; 
    int x,y; 
    int k=0; 
    while(m--){
        cin>>x>>y; 
        if(find(x) == find(y)){
            k++; 
        }
        else{
            join(x,y); 
        }
        // dbg(k); 
        priority_queue<int,vector<int>,greater<int>> pq; 
        for(int i=1;i<=n;i++){
            if(rnk[i] != -1) pq.push(rnk[i]); 
            if(pq.size() > k+1){
                pq.pop(); // smallest element removal 
            }
        }
        // now taking top k elements sum 
        int ans = k; // it has k edges which are not added between any component 
        while(!pq.empty()){
            ans += pq.top(); 
            pq.pop(); 
            ans --; // removing 1 edge since we have added 2 components with each other 
        }
        cout<<ans<<endl; 
    }
    return 0;
}
