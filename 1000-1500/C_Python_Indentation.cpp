// let's divide whole thing into blocks ffffs and remaining s
// ffffffs is required since each for should have atleast 1 statement 
// after then find how many way's we can move those blocks 
// starting fro bottom for can have n options moving till any ith statement inside it's block
// similarly any for contributes some ways that are going to be multiplied with whole solution 
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
#define MOD 1000000007
void solve(){
    int n; 
    cin>>n; 
    vector<char> v(n); 
    for(int i=0;i<n;i++) cin>>v[i]; 
    v32 blocks; // blocks are of 2 types either for or single statement 
    int i=0; 
    while(i<n){
        if(v[i] == 's') blocks.push_back(0); 
        else{
            int count=0; 
            while(v[i] != 's') i++,count++; 
            blocks.push_back(count); 
        }
        i++; 
    }
    // for(auto i: blocks) cout<<i<<" "; 
    // cout<<endl; 
    ll ans = 1; // making answer = 1 and skipping last block
    int prev =1; 
    for(i=blocks.size()-2;i>=0;i--){
        if(blocks[i] == 0){
            prev++;
        }
        else{
            ans *= (prev + 1ll)*(blocks[i]);
            prev = 1; 
            ans %= MOD; 
        }
    } 
    cout<<ans<<endl; 
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