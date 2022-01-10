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
#define N 4e5 + 5
void solve(){
    int n,x;
    cin>>n>>x; 
    // each input number can be tranformed by i+x or i-x any number of times so i + nx where n can be any real number
    vi v(N,0); 
    int req = 0; 
    int val; 
    for(int i=0;i<n;i++){
        cin>>val; 
        v[val%x]++; 
        while(v[req%x]){
            v[req%x]--; 
            req++; 
        }
        cout<<req<<ln; 
    }
}
int main(){
    fast_cin();
    solve();
    return 0;
}