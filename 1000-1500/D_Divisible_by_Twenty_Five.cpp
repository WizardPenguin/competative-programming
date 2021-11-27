// before going recursively generate all states of values of X and value of first number
// after then each remaining parts have 9 possibilities generate them 
// instead of generating them we can fix those 4 possibilities at starting 2 number and remaining 9^rem
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  
#include <cmath>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
v64 dp;
int n; 
ll recursive(string &s,int i,char ch = 'X'){
    if(i == n){
        // check last 2 characters
        auto sub = s.substr(n-2); 
        // cout<<sub<<" "; 
        if((sub == "00") or (sub == "25") or (sub == "50") or (sub == "75")){
            // cout<<sub<<" "; 
            return 1; 
        }
        return 0; 
    }
    // if(dp[i] != -1) return dp[i]; 
    if(s[i] == 'X'){
        s[i] = ch; 
        dp[i] = recursive(s,i+1,ch); 
        s[i] = 'X'; 
        return dp[i];
    }
    else if(s[i] == '_'){
        // dp[i] is not going to be called again before it's computed 
        dp[i] = 0; 
        for(int x='0';x<='9';x++){
            s[i] = x;  
            dp[i] += recursive(s,i+1,ch); 
        }
        s[i] = '_'; // back replacement 
        return dp[i];
    }
    else return dp[i] = recursive(s,i+1,ch); 
}
void solve(){
    string s; 
    cin>>s; 
    n = s.length();
    bool found = false; 
    for(auto &i: s){
        if(i == 'X'){
            found = true; 
            break; 
        }
    }
    ll ans = 0; 
    if(s[0] == '0' or s.length() == 1){
        if(s.length() == 1 and s[0] == '0') ans = 1; 
        else ans = 0; 
    }
    else if(found){
        // we have 2 states replace X and first number
        // if starting number is X then it boils down to single state
        if(s[0] == 'X'){
            for(int i='1';i<='9';i++){
                dp = v64(n,-1); 
                ans += recursive(s,1,i); 
            }
        } 
        else if(s[0] == '_'){ // 2 states
            for(int i='1';i<='9';i++){
                s[0] = i; 
                for(int j='0';j<='9';j++){
                    dp = v64(n,-1); 
                    ans += recursive(s,1,j); 
                }
            }
        }
        else{
            // single dimention since first char don't need any replacement in first number
            for(int j='0';j<='9';j++){
                dp = v64(n,-1); 
                ans += recursive(s,1,j);
                // dbg(dp[1]);
            }
        }
    }
    else{
        if(s[0] == '_'){ // 1 states 
            for(int i='1';i<='9';i++){
                s[0] = i; 
                dp = v64(n,-1); 
                ans += recursive(s,1);
            }
        }
        else{
            dp = v64(n,-1); 
            ans = recursive(s,1); 
        }
    }
    cout<<ans<<endl; 
    return; 
}
int main()
{
    fast_cin();
    ll test = 1;
    while(test--){
        solve();
    }
    return 0;
}