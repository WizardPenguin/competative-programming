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
    vi v(n+2,0); 
    int val;   
    for(int i=0;i<n;i++){
        cin>>val; 
        v[val] ++; 
    }
    stack<pair<int,int> > stk; 
    ll ans = 0; 
    if(v[0]){
        int i; 
        cout<<v[0]<<" "; 
        if(v[0] > 1)
        stk.push({0,v[0] -1}); 
        for(i=1;i<=n;i++){
            if(v[i-1]){ // for mex = i we need i-1 
                ll tans = v[i];  // need i's to be converted into something else 
                cout<<tans + ans<<" "; 
                if(v[i] > 1){
                    stk.push({i,v[i]-1}); 
                }
            }
            else{
                if(!stk.empty()){
                    auto tp = stk.top(); stk.pop(); 
                    tp.second--; 
                    if(tp.second){
                        stk.push(tp); 
                    }
                    // we have made value 
                    ans += i-1 - tp.first; 
                    ll tans = v[i]; 
                    if(v[i] > 1){
                        stk.push({i,v[i]-1});
                    }
                    cout<<tans+ans<<" "; 
                }
                else{
                    break; 
                }
            }
        }
        for(i;i<=n;i++){
            cout<<-1<<" "; 
        }
    }
    else{
        // there is no zero means we can make mex = 0 in 0 steps 
        cout<<0<<" "; 
        for(int i=1;i<=n;i++){
            cout<<-1<<" "; 
        }
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