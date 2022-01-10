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
    set<pair<int,int> > st; 
    map<pair<int,int> ,int> mp; 
    vpii pr; 
    int x,y; 
    int n; 
    cin>>n; 
    for(int i=0;i<n;i++){
        cin>>x>>y; 
        st.insert({x,y});
        mp[{x,y}] = i;  
        pr.push_back({x,y}); 
    }
    vi res(n,0); 
    stack<pair<int,int> > stk;
    stk.push({1,n});  
    while(stk.size()){
        auto tp = stk.top();
        stk.pop(); 
        auto l = tp.first; 
        auto r = tp.second; 
        auto id = mp[tp]; 
        if(l == r){
            res[id] = l; 
            continue; 
        }
        for(int i=l;i<=r;i++){
            if(i == tp.first){
                if(st.find({l+1,r}) != st.end()){
                    res[id] = i; 
                    stk.push({l+1,r}); 
                    break; 
                }
            }
            else if(i == r){
                if(st.find({l,r-1}) != st.end()){
                    res[id] = i; 
                    stk.push({l,r-1}); 
                    break; 
                }
            }
            else{
                if((st.find({l,i-1}) != st.end()) and st.find({i+1,r}) != st.end()){
                    res[id] = i;
                    stk.push({l,i-1});  
                    stk.push({i+1,r}); 
                    break; 
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<pr[i].first<<" "<<pr[i].second<<" "<<res[i]<<endl; 
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