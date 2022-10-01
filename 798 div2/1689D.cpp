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
    vs v(n); for(auto &i: v) cin>>i; 
    // now time ot find largest and smallest y 
    vpii dp(n,{-1,-1}); 
    vpii blacks; 
    // now finding distance 
    for(int i=0;i<n;i+=1){
        for(int j=0;j<m;j+=1){
            if(v[i][j] == 'B'){
                // x being i, place it's max and mini
                auto &[x,y] = dp[i]; 
                if(x == -1){
                   x = y = j; 
                }
                else{
                    x = min(x,j); y = max(y,j); 
                }
            }
        }
    }
    int maxDist = INT_MAX; 
    pii res = {0,0}; 
    for(int i=0;i<m;i+=1){
        vi tp(n); /// we have fixed 1 ye form us we need to find distances for all x's w.r.t this y 
        for(int j=0;j<n;j+=1){
            auto &[x,y] = dp[j]; 
            if(x == -1){
                tp[j] = -1; 
                continue; 
            }
            tp[j] = max(abs(x - i),abs(y-i)); 
        }
        // now find left and right maxima's of distances if we take i as our x 
        vi left(n),right(n);
        left[0] = (tp[0] == -1)?0: tp[0]; 
        for(int j=1;j<n;j+=1){
            int newValue =  (v[j-1][i] == 'B' or left[j-1])?left[j-1] + 1: 0; 
            left[j] = max(newValue,tp[j]);
        }
        right.back() = (tp.back() == -1)?0: tp.back(); 
        for(int j=n-2;j>=0;j-=1){
            int newValue = (v[j+1][i] == 'B' or right[j+1])? right[j+1] + 1: 0; 
            right[j] = max(newValue,tp[j]); 
        }
        int distance = INT_MAX; 
        int miniX = -1; 
        for(int j=0;j<n;j+=1){
            if(distance > max(left[j],right[j])){
                distance = max(left[j],right[j]); 
                miniX = j; 
            }
        }
        if(distance < maxDist){
            maxDist = distance; 
            res = {miniX,i};
        }
    }
    cout<<res.first + 1<<" "<<res.second + 1<<ln;
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