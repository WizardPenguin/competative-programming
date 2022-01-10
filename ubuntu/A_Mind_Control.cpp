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
    int n,m,k; 
    cin>>n>>m>>k; 
    vi v(n); 
    for(int i=0;i<n;i++) cin>>v[i]; 
    // remove k elements of our choice i.e which gives maximum value in any condition when mth person take value 
    // so take window of size n-k denotes that k elements have been removed 
    int ans =0; 
    int w1 = n - k; 
    int w2 = n - m + 1; 
    if(w1 >= w2)
    for(int i=0;i+w1<=n;i++){
        // now we need window if size n-m+1 so mth can remove best answer 
        // cout<<i<<"        "<<i+w1-1<<endl; 
        int ans2 = INT_MAX; 
        for(int j=i;j+w2<=i+w1;j++){
            // cout<<j<<" "<<j+w2-1<<endl; 
            ans2 = min(max(v[j],v[j+w2-1]),ans2); 
        }
        ans = max(ans,ans2); 
        // dbg(ans); 
    }
    else{
        // we can maxi for each lower window
        for(int i=0;i+w2<=n;i++){
            ans = max(ans,max(v[i],v[i+w2-1])); 
        }
    }
    cout<<ans<<endl; 
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