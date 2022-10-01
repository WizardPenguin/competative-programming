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
    int n; 
    cin>>n; 
    vector<int> v(n); 
    for(int i=0;i<n;i+=1) cin>>v[i]; 
    vector<pair<int,int> > count(n+1,{0,0}); 
    /// defining parity 
    int parity = v[0]&1; 
    for(int i=n-1;i>=0;i-=1){
        // finding count for given parity 
        count[i].first = count[i+1].first; 
        count[i].second = count[i+1].second; 
        if(v[i]&1){
            count[i].first+=1; 
        }
        else{
            count[i].second +=1; 
        }
        // cerr<<count[i].first<<" "<<count[i].second<<endl; 
        // count of odd and even till given index 
    }
    if(parity == (v.back()&1)){
        // cerr<<"same parity "<<parity<<endl; 
        // first and last have same parity 
        // means we can go without changing parity 
        // othwerise we are necessarity required to change parity 
        // cerr<<count[0].first<<" "<<count[0].second<<endl; 
        if(parity){
            // odd 
            cout<<count[0].first-1<<endl; 
        }
        else{
            // even
            cout<<count[0].second-1<<endl; 
        }
        return; 
    }
    int c = 0; 
    int ans = INT_MAX; 
    for(int i=0;i<n;i+=1){
        if((v[i]&1) == parity){ // we have found element with same parity , 
            c += 1; 
            if(parity){ // add remaining with other parity 
                ans = min(ans,c + count[i+1].second); 
            }
            else{
                ans = min(ans, c + count[i+1].first); 
            }
        }
    }
    cout<<ans-1<<endl; 
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