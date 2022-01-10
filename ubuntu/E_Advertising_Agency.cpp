// we are desired to take largest elements first 
// if some element's all occurences are not taken then we are required to take some combination of those elements
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
#define MOD 1000000007
// we need to find factorial with modulo and their respective modulo inverses 
ll inverse(ll fact,ll mod){
    mod-=2; // we need to find fact^(mod-2);
    ll res = 1; 
    while(mod){
        if(mod&1){
            res *= fact; 
            res %= MOD; 
        }
        fact *= fact; 
        fact %= MOD; 
        mod>>=1; 
    }
    return res; 
}
ll factorial(int n){
    ll res = 1; 
    while(n){
        res *= n; 
        res%=MOD; 
        n--; 
    }
    return res; 
}
vll f(1001,1),finv(1001,1); 
void solve(){
    int n; 
    cin>>n; 
    int k; cin>>k; 
    vi v(n); 
    for(int i=0;i<n;i++) cin>>v[i]; 
    map<int,int> mp; 
    for(auto &i: v){
        mp[i] = mp[i] + 1;
    }
    for(auto it = mp.rbegin(); it != mp.rend() and k;it++){
        // now we are desired to take some elements 
        if(it->second > k){
            // means we are desired to take some combination of it 
            // take k elements from it->second elements
            ll fn = f[it->second]; 
            ll fnk = finv[it->second - k]; 
            ll fk = finv[k]; 
            ll res = fn*fnk%MOD; 
            res *= fk; 
            res %= MOD; 
            cout<<res<<endl; 
            return; 
        }
        else{
            k-= it->second; 
        }
    }  
    cout<<1<<endl; // means we had exact change for given number having maximum followers
}
int main(){
    fast_cin();
    ll test;
    cin >> test;
    for(int i=1;i<=1000;i++){
        f[i] = factorial(i);
        finv[i] = inverse(f[i],MOD);  
    }
    while(test--){
        solve();
    }
    return 0;
}