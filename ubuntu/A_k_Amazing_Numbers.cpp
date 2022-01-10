// instead of finding value for each k 
// we can find which value is valid for which k 
// find each occurence of element 
// then find maximum distance between then and from first and last index 
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
    vi v(n); 
    for(int i=0;i<n;i++) cin>>v[i]; 
    // now check which k is valid for which value 
    vvi oc(n+1); 
    for(int i=0;i<n;i++){
        oc[v[i]].push_back(i); 
    }
    vi res(n+1,INT_MAX); 
    for(int i=1;i<=n;i++){
        // now check for which value it's valid 
        auto &c = oc[i]; 
        if(c.size() == 0) continue; 
        int start = c[0]; 
        int dist = start+1; // distance from starting node 
        for(int i=1;i<c.size();i++){
            int d = c[i] - start; 
            dist = max(dist,d); 
            start = c[i]; 
        }
        // distance from final node 
        dist = max(dist,n - start); 
        res[dist] = min(res[dist],i); 
    }
    for(int i=1;i<=n;i++){
        res[i] = min(res[i],res[i-1]); 
        if(res[i] == INT_MAX){
            cout<<-1<<" ";
        }
        else cout<<res[i]<<" ";     
    }
    cout<<endl; 
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