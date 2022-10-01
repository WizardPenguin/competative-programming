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
    int n,k; 
    cin>>n>>k; 
    vi v(n); 
    for(int i=0;i<n;i+=1){
        cin>>v[i]; 
    }
    priority_queue<ll> components; 
    int i=0; 
    while(i<n){
        int val = v[i]; 
        int c = 0; 
        while(i<n and v[i] == val) i++,c++; 
        components.push(c); 
    }
    while(components.top() > 1 and k--){
        auto tp = components.top(); 
        components.pop(); 
        if(tp == 2){
            components.push(1); 
            components.push(1); 
            continue; 
        }
        // we are going to insert 1 new elememnt going to divide it into 2 components 
        components.push(tp/2); 
        components.push(1); 
        if(tp&1){
            components.push(tp/2);
        }
        else{
            components.push((tp/2)-1); 
        }
    }
    ll ans = 0; 
    while(not components.empty()){
        auto tp = components.top(); 
        // cerr<<tp<<" "; 
        components.pop(); 
        ans += (tp*(tp+1))/2; 
    }
    // cerr<<endl; 
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