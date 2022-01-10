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
    string s; cin>>s; 
    int i=0; 
    int n = s.length(); 
    map<int,int> mp; 
    while(i<n){
        stack<char> stk; 
        int start = i; 
        int len = 0; 
        while(i<n){
            if(s[i] == '('){
                stk.push(s[i]); 
            }
            else{
                if(stk.empty()){
                    break; 
                }
                else{
                    stk.pop(); 
                }
            }
            i++; 
        }
        if(stk.empty())
        len = i - start; 
        if(len == 0) i++; // otherwise last character might form other balanced bracket
        // cout<<start<<" "<<len<<" "<<i<<endl; 
        if(mp[len]) mp[len]++; 
        else mp[len] = 1; 
    }
    pair<int,int> res; 
    for(auto &i: mp){
        res = i; 
    }
    if(res.first == 0) cout<<"0 1"<<endl; 
    else cout<<res.first<<" "<<res.second<<endl; 
}
int main(){
    fast_cin();
    solve();
    return 0;
}