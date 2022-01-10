// find prefix sum 
// we want pj - pi = j - i + 1
// also writeen as pj - j = pi - i + 1
// so insert prefix(i) - i + 1 into map 
// and when we encountered some pj where pj - j is in map we can join them and find solution 
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
    string s; 
    cin>>s; 
    int pref = 0; 
    map<int,int> mp; 
    mp[0]= 1; 
    ll ans = 0; 
    for(int i=0;i<n;i++){
        int x = s[i] - '0'; 
        // int sm = pref + x; 
        pref += x; 
        ans += mp[pref - i-1]; 
        // add this element to map in other form 
        mp[pref - i - 1] += 1; 
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