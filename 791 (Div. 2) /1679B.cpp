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
    int n,q; 
    cin>>n>>q; 
    vi v(n); 
    ll ans = 0; 
    for(int i=0;i<n;i+=1) cin>>v[i],ans += v[i]; 
    set<int> st; for(int i=0;i<n;i+=1) st.insert(i);
    ll type,x,y;  
    int prev = -1; 
    while(q--){
        cin>>type; 
        if(type == 1){
            cin>>x>>y; 
            x--; 
            if(st.find(x) != st.end()){
                ans -= v[x]; 
            }
            else{
                ans -= prev; 
                st.insert(x); 
            }
            v[x] = y; 
            ans += v[x]; 
        }
        else{
            st.clear(); 
            // cerr<<st.size()<<endl; 
            cin>>x; 
            ans = x*n; 
            prev = x; 
        }
        cout<<ans<<ln; 
    }
}
int main(){
    fast_cin();
    solve();
    return 0;
}