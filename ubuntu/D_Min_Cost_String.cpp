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
string inrep; 
vvb dp; 
int k; 
void dfs(int n){
    inrep += char(n + 'a'); 
    for(int i=0;i<k;i++){
        if(dp[n][i] == false){
            // make this move 
            dp[n][i] = true; 
            dp[i][n] = true; 
            dfs(i); 
        }
    }
    return; 
}

void solve(){
    int n; 
    cin>>n>>k; 
    dp = vvb(k,vb(k,false));
    dfs(0); 
    cout<<inrep<<endl; 
}
int main(){
    fast_cin();
    solve(); 
    return 0;
}