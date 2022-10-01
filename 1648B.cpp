// we want to check weather we have any possibility of making a*b = c 
// since we are using floor operations we need to check weather a*b = c c+1....c + b-1 possible 
// this can be checked in O(1) using prefix sum 
// calculations can be made in NlogN by using prime seive type apporach 
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
#define N 1000006
int dp[N];
void solve(){
    ll n,c; 
    cin>>n>>c; 
    vector<ll> v(n); 
    // find how many times ai/aj = c 
    for(int i=0;i<n;i+=1) cin>>v[i]; 
    sort(all(v));
    // we want to find for each x weather we have y such that x*c <= y < x*(c+1) and count those number
    ll ans = 0; 
    for(int i=0;i<n;i+=1){
        bool found = false; 
        for(int x=0;;x++){
            auto &div = v[x]; 
            int lb = lower_bound(v.begin()+i,v.end(),v[i]*div) - v.begin();
            if(lb == n) break; 
            int ub = lower_bound(v.begin()+ i,v.end(),(div+1)*(v[i])) - v.begin();
            if(ub != lb){
                found = true; 
                break; // check for ther one 
            }
        }
        if(not found){
            cout<<"No"<<endl;
            return;
        }
    }
    cout<<"Yes"<<endl; 
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