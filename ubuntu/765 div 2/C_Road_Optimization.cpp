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
#define N 505
int n,l; 
map<int,ll> dp; 
vll speed; 
vll dist; 
// previous speed directly decides prevDist so only p taken in state transition works 
ll recursive(int i,int p,ll prevDist,int k){ 
    if(k < 0){
        return LLONG_MAX; // illigal move 
    }
    if(i == n) return 0; 
    // 2 cases either skip this or take this
    ll prevSpeed = speed[p];
    // ll state = (((i+1)*n*n + (k+1))*n + (p+1))*n; 
    ll state = (i + 1)*n + (k + 1); 
    if(dp.find(state) != dp.end()){
        return dp[state]; 
    }
    // if skip prev speed not changes we just reach here using prevSpeed and k changes 
    ll ans1 = recursive(i+1,p,dist[i + 1],k-1);
    if(ans1 != LLONG_MAX){
        ans1 += prevSpeed*(dist[i+1] - prevDist);
    }
    // if don't skip then reach next point using new speed 
    ll ans2 = recursive(i+1,i,dist[i + 1],k);
    if(ans2 != LLONG_MAX){
        ans2 += (dist[i+1] - prevDist)*speed[i];
    }
    return dp[state] = min(ans1,ans2); 
}
void solve(){
    int k; 
    cin>>n>>l>>k; 
    dist = vll(n,0); 
    speed = vll(n,0); 
    for(int i=0;i<n;i++) cin>>dist[i]; 
    dist.push_back(l); // final end pont
    for(int i=0;i<n;i++) cin>>speed[i]; 
    // always start from next index 
    ll ans = recursive(1,0,dist[1],k) + dist[1]*speed[0];
    cout<<ans<<endl; 
}
int main(){
    fast_cin();
    solve(); 
    return 0;
}