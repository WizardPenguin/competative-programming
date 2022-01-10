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
    string s; 
    cin>>s; 
    int i=n-1; 
    while(i>=0 and k and s[i] == 'L'){
        i--; 
        k--; // making last looses as win since they always add's 2 to score instead of 1 
    }
    int start = 0; 
    int j=0;
    while(j<n and  s[j] == 'L')j++,start++; 
    // we are avoiding 1st looses since they will give 1 for atlest 2 loose
    vector<int> blocks; 
    while(j<i){
        if(s[j] == 'W')j++; 
        else{
            int st = j; 
            while(j<i and s[j] == 'L')j++; 
            blocks.push_back(j - st); 
        }
    }
    sort(all(blocks)); 
    for(auto &i: blocks) cout<<i<<" "; 
    cout<<endl; 
    i=0; 
    while(i<blocks.size() and blocks[i] >= k){
        k-=blocks[i]; 
        i++; 
    }
    if(i == blocks.size()){
        // we have k remaining and all blocks has been covered then it's time to cover fist elements 
        start -= min(k,start); 
        cout<<2*(n - start) - 1<<endl; 
    }
    else{
        // some blocks are still remaining
        if(k){
            blocks[i] -= k; 
        }
        int sub = blocks.size() - i;  // blocks which are going to cost 1
        int nw = 0;  // blocks which are not having wins 
        while(i<blocks.size()){
            nw += blocks[i]; 
            i++; 
        }
        cout<<(n-nw)*2 - sub<<endl; 
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