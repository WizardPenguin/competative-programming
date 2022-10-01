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
map<char,pii> mv = {{'R', {0,1}}, {'L', {0,-1}},{'U', {1,0}},{'D' , {-1,0}}}; 

void solve(){
    string s; 
    cin>>s; 
    int n = s.length(); 
    map<int,pii> visited; 
    visited[0] = {0,0}; 
    int sx = 0,sy = 0; 
    for(int i=0;i<n;i+=1){
        auto &[dx,dy] = mv[s[i]]; 
        sx += dx; 
        sy += dy; 
        visited[i+1] = {sx,sy}; 
        cerr<<sx<<" "<<sy<<endl; 
    }
    int ans = 0; 
    for(int i=-1;i<n;i+=1){
        for(int j=i+1;j<n;j+=1){
            auto &[ox,oy] = visited[i]; 
            auto &[nx,ny] = visited[i+1]; 
            auto &[fx,fy] = visited[j+1]; 
            fx -= ox; 
            fy -= oy; 
            nx -= ox; 
            ny -= oy; 
            if(fx >=0 and nx >=0 and fy >=0 and ny >=0 and fx == nx and fy == ny){
                ans += 1; 
            }
        }
    }
    cout<<ans<<endl; 
}
int main(){
    fast_cin();
    ll test=1; 
    while(test--){
        solve();
    }
    return 0;
}