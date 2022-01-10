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
vs stamps = {"abc","acb","cab","cba","bca","bac"}; 
void solve(){
    int n,q; 
    cin>>n>>q; 
    string s; 
    cin>>s; 
    vvi v(6,vi(n,0)); 
    for(int i=0;i<6;i++){
        auto &st = stamps[i]; 
        if(s[0] != st[0]){
            v[i][0]= 1; 
        }
        for(int j=1;j<n;j++){
            if((s[j] != st[j%3])){
                v[i][j] = v[i][j-1] + 1; 
            }
            else{
                v[i][j] = v[i][j-1]; 
            }
        }
    }
    while(q--){
        int x,y; 
        cin>>x>>y; 
        x--,y--; 
        int ans = INT_MAX; 
        if(x == 0){
            for(int i=0;i<6;i++){
                ans = min(ans,v[i][y]); 
            }
        }
        else{
            for(int i=0;i<6;i++){
                ans = min(ans,v[i][y] - v[i][x-1]); 
            }
        }
        cout<<ans<<endl; 
    }
}
int main(){
    fast_cin();
    solve();
    return 0;
}