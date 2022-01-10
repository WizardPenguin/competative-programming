// we can try it using bfs 
// also no need to recompute state which are already triversed for that we'll store largest id of states already computed 
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
 

void solve(){
    int n; 
    cin>>n;
    // for each index we are given max jump possible and slipping amount 
    vi maxJ(n); 
    vi slip(n); 
    for(int i=0;i<n;i++){
        cin>>maxJ[i]; 
    }
    for(int i=0;i<n;i++) cin>>slip[i]; 
    // start with ending index; 
    queue<int> q; // we are going to store index he is on after applying slipping 
    int mini =n-1; 
    q.push(n-1); 
    // for every node we can store which node has given it that minima 
    vi m(n,-1); 
    int step = 0; 
    vb visited(n,false); 
    visited[n-1] = true; 
    while(!q.empty()){
        step ++; 
        int sz = q.size(); 
        for(int i=0;i<sz;i++){
            auto tp = q.front();
            q.pop();  
            cout<<tp<<endl; 
            int mi = tp - maxJ[i]; 
            for(int i=mini-1; i>=mi;i--){
                cout<<i<<" "; 
                int r = i + slip[i]; 
                if(i == 0){
                    goto end; 
                }
                if(!visited[r]){
                    cout<<"v "; 
                    m[r] = tp; 
                    q.push(r); 
                }
            } 
            mini = min(mini,mi); 
        }
    }
    end:; 
    for(auto i: m) cout<<i<<" "; 
}
int main(){
    fast_cin();
    solve();
    return 0;
}