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
vi id,pw; 
void solve(){
    int n; 
    cin>>n;
    id = vi(n); 
    pw = vi(n); 
    for(int i=0;i<n;i++){
        cin>>id[i]; 
    }
    for(int i=0;i<n;i++){
        cin>>pw[i]; 
    }
    stack<pair<ll,ll>> stk; 
    stk.push({id[0],id[0] - pw[0] + 1}); 
    int i=1; 
    while(i<n){
        // insert new element 
        ll start = id[i] - pw[i] +1; 
        auto tp = stk.top(); 
        if(start > tp.first){
            // start new sequence 
            stk.push({id[i],start}); 
        }
        else{
            while(!stk.empty()){
                tp = stk.top(); 
                if(tp.first < start){
                    // means we have to start new sequence form next elements instead
                    stk.push({id[i],start}); 
                    break; 
                }
                else if(tp.second <= start){
                    // check if extending this sequence is enough 
                    stk.pop(); 
                    stk.push({id[i],tp.second}); 
                    break; 
                }
                else{
                    stk.pop(); // remove this sequence 
                }
            }
            if(stk.empty()){
                stk.push({id[i],start}); 
            }
        }
        i++; 
    }
    ll ans = 0; 
    while(!stk.empty()){
        auto tp = stk.top(); 
        // cout<<tp.first<<" "<<tp.second<<endl; 
        stk.pop(); 
        ll len = tp.first - tp.second + 1; 
        // cout<<len<<" "; 
        ans += len*(len+1)/2; 
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