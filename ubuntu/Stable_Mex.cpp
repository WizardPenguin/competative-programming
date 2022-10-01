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
    vector<int> x(n); 
    bool allZero = true; 
    for(int i=0;i<n;i+=1) cin>>x[i], allZero &= (x[i] == 0); 
    set<int> st(x.begin(),x.end()); 
    vector<int> v(st.begin(),st.end()); 
    if(allZero){
        cout<<-1<<endl; 
        return; 
    }
    if(v[0] != 0){
        cout<<v[0] - 1<<endl; 
        return; 
    }
    int component = 0; 
    int start=-1;
    int i=0;  
    while(i<n and v[i+1] == start+1) start = v[i],i+=1,component += 1; 
    int ans = 0; 
    // cerr<<component<<endl; 
    while(i<n){
        int start = v[i]-1; 
        int c =0; 
        while(i<n and v[i]  == start+1) start = v[i],i+=1,c+=1; 
        if(c >= component-1) ans += 1; 
        // cerr<<i<<" "<<c<<endl; 
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