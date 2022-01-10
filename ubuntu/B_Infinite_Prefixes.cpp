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
    int n,x; 
    cin>>n>>x; 
    vector<int> pre; 
    string s; 
    cin>>s;
    int val = 0; 
    pre.push_back(val);  
    for(int i=0;i<n;i++){
        if(s[i] == '0'){
            val++;
        }
        else{
            val--; 
        }
        pre.push_back(val); 
    }
    // now val is value for whole string 
    int ans = 0;
    if(x == 0){
        if(val == 0){
            cout<<-1<<endl; // infinite possibilities are there 
            return; 
        }
        for(int i=0;i<pre.size()-1;i++){
            if(abs(pre[i])%abs(val) == 0 and (-pre[i])/val >= 0){
                ans++; 
            }
        }
    }
    else{
        if(val == 0){
            for(auto &i: pre){
                if(i == x){
                    cout<<-1<<endl; 
                    return; 
                }
            }
            cout<<0<<endl; 
            return;
        }
        // x*val + pre = X if such prefix is there then we can form our solution 
        for(int i=0;i<pre.size()-1;i++){
            // cout<<pre[i]<<" "; ]
            if(abs(x - pre[i])%abs(val) == 0 and (x - pre[i])/val >= 0){
                ans++; 
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