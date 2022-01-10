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
vi dp; 
int n,m; 
#define tp tuple<int,int,int> 
map<string,tp> mp; 
bool recursive(string &s,int i){
    if(i >= m-1) return false; 
    if(i == (m-2)){
        // length 2 string remaining
        if(mp.find(s.substr(i)) != mp.end()){
            dp[i] = 2; 
            return true; 
        }
        return false; 
    }
    else if(i == (m-3)){
        // length 3 string remaining just find 
        if(mp.find(s.substr(i)) != mp.end()){
            dp[i] = 3; 
            return true; 
        }
        return false; 
    }
    if(dp[i] != 0) return true; 
    // now we have some larger string and need to consdier 2 cases  
    if(mp.find(s.substr(i,2)) != mp.end()){
        // check weather we can make all possible 
        if(recursive(s,i+2)){
            dp[i] = 2;
            return true;  
        }
    }
    if(mp.find(s.substr(i,3)) != mp.end()){
        if(recursive(s,i+3)){
            dp[i] = 3; 
            return true; 
        }
    }
    return false; 
}
void solve(){
    cin>>n>>m; 
    vs v(n); 
    for(int i=0;i<n;i++) cin>>v[i]; 
    // now we need to find substrings of these strings and map them with number(index on which number they are found)
    // we need only 2 and 3 length substrings since they can be used to form all larger ones 
    // since we don't need to minimize 
    dp = vi(m+1,0); 
    mp.clear(); 
    for(int i=0;i<n;i++){
        auto &str = v[i]; 
        for(int j=0;j+2<m;j++){
            mp[str.substr(j,2)] = {j+1,j + 2,i+1}; 
        }
        for(int j=0;j+3<m;j++){
            mp[str.substr(j,3)] = {j + 1,j + 3,i + 1}; 
        }
    }
    // now we need to break given string into substrings of previous number 
    // need to do recursively since we are having 2 possibilities either substring of size 2 or size 3
    // also we can store result dp[i] storing that we have correct division after index i 
    // also if dp[i] = true we need to store 2 or 3 sized string was taken so that we got result as true
    // simply use single dp that either store 2,3 showing we are done nicely 
    // or store 0 means we haven't found any good result 
    string fnd; 
    cin>>fnd; 
    // cout<<fnd<<endl; return; 
    if(recursive(fnd,0)){
        // generate subsequencies
        // cout<<"YES"<<endl; return;  
        vector<tp > res; 
        for(int i=0;i<m;i++){
            if(dp[i] == 2){
                // cout<<2;
                res.push_back(mp[fnd.substr(i,2)]); 
                i++; // 1 extra addition 
            }
            else{
                // cout<<3; 
                res.push_back(mp[fnd.substr(i,3)]); 
                i += 2; 
            }
        }
        // cout<<endl; 
        cout<<res.size()<<endl; 
        for(auto &i: res){
            cout<<get<0>(i)<<" "<<get<1>(i)<<" "<<get<2>(i)<<endl; 
        }
    }
    else{
        cout<<-1<<endl; 
    }
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