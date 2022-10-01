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
 
vector<string> dix; 
void solve(){
    string s; 
    cin>>s; 
    int lb = lower_bound(all(dix),s) - dix.begin(); 
    cout<<lb + 1<<endl;
}
int main(){
    fast_cin();
    ll test;
    cin >> test;
    for(auto i = 'a' ;i<='z';i+=1){
        for(auto j='a'; j<='z';j+=1){
            if(i == j) continue; 
            string res; 
            res += i; 
            res += j; 
            dix.push_back(res); 
        }
    }
    sort(all(dix)); 
    while(test--){
        solve();
    }
    return 0;
}