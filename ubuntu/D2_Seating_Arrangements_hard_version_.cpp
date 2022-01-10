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
    vi v(n*m); 
    for(int i=0;i<n*m;i++) cin>>v[i]; 
    vi id(n*m); 
    for(int i=0;i<n*m;i++) id[i] = i; 
    sort(all(id),[&](auto &a,auto &b){
        if(v[a] == v[b]){
            return a < b; 
        }
        return v[a] < v[b]; // lower sight get's earlier seat 
    });
    // for(auto &i: id) cout<<i<<" "; 
    ll ans = 0; 
    for(int i=0;i<n*m;i+=m){
        sort(id.begin()+i,id.begin() + i+m,[&](const int &a,const int &b){
            if(v[a] == v[b]){
                return a > b; 
            }
            else{
                return v[a] < v[b]; 
            }
        });
        for(int j=0;j<m;j++){
            // find how many are already inserted which are having lower index that this one 
            for(int k=0;k<j;k++){
                if(id[i+k] < id[i+j]) ans++; 
            }
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