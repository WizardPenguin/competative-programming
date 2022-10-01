// optimal for Rahul to sit at middle that gives maximum distance to each edge minimized
// so Tina has to remove those coordinates form rahul to pick 
// we can construct solution by sorting each node's max distance form each corner
// remove k nodes(smallest distance) , then find who is giving smallest distance which is solution for that k 
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
    int n,m; 
    cin>>n>>m; 
    vi dist; 
    // corners are having coordinates 0,0  0,n-1 n-1,0 n-1,n-1 
    // we need to find manhaten distance from those points
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dist.push_back(max({
            abs(0 - i) + abs(0 - j),
            abs(n-1 - i) + abs(m-1 - j),
            abs(0 - i) + abs(m-1 - j),
            abs(n-1 - i) + abs(0 - j)})); 
        }
    }
    // cout<<dist.size()<<endl; 
    sort(all(dist)); 
    for(int i=0;i<n*m;i++){
        cout<<dist[i]<<" "; 
    }
    cout<<ln; 
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