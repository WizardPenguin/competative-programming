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
    vi v(n); 
    for(int i=0;i<n;i+=1){
        cin>>v[i]; 
    }
    v.insert(v.begin(), INT_MAX); 
    v.push_back(INT_MAX); 
    int ans = INT_MAX; 
    for(int i=1;i<=n;i+=1){
        // either kill all nbrs by hitting only middle node 
        // or kill middle node + smaller of left or right node 
        int mini = min(v[i-1],v[i+1]);
        int maxi = max(v[i-1],v[i+1]);  
        ans = min(ans,maxi); 
        ans = min(ans,(maxi - mini+1)/2 + mini);
        ans = min(ans, max( (v[i] + mini+2)/3,  max( (v[i] + 1)/2 , (mini + 1)/2 ) ) );
    }
    // or kill smallest 2 nodes in global space
    sort(all(v)); 
    ans = min(ans,(v[0] + 1)/2 + (v[1] + 1)/2); 
    cout<<ans<<endl; 
}
int main(){
    fast_cin();
    solve();
    return 0;
}