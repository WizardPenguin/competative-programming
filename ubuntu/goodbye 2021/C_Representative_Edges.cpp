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
 
double e = 1e-9; 
void solve(){
    int n;
    cin>>n; 
    vi v(n); 
    for(int i=0;i<n;i++) cin>>v[i]; 
    int ans = n-1; 
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            // dbg(i); 
            // dbg(j); 
            double len = j - i; 
            // dbg(len);
            double d = 0; 
            if(i != j)
            d = (v[j] - v[i] + 0.0)/len; 
            // dbg(v[j] - v[i]); 
            // dbg(len); 
            double tp = v[i]; 
            int steps = 0; 
            // cout<<d<<endl; 
            for(int k = i-1;k>=0;k--){
                tp -= d; 
                if(abs(tp - v[k]) <= e) continue; 
                else{
                    steps++; 
                }
            }
            tp = v[i]; 
            for(int k=i+1;k<n;k++){
                tp += d; 
                if(abs(tp - v[k]) <= e){
                    continue; 
                }
                else{
                    steps++; 
                }
            }
            ans = min(ans,steps); 
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