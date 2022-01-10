// find 1.(2..n) using 2 consecutive values we can find 1 value in array 
// calls are made 1..(2,n) and substracting consecutive elements we are going to get number of flamingos at a index
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
 

void solve(){
    int n; 
    cin>>n; 
    vi v; 
    int val; 
    for(int i=2;i<=n;i++){
        cout<<"? 1 "<<i<<endl; 
        fflush(stdout); 
        cin>>val; 
        v.push_back(val); 
    }
    vi res(n); 
    for(int i=1;i<v.size();i++){
        res[i+1] = (v[i] - v[i-1]);
    }
    cout<<"? 2 3"<<endl; 
    fflush(stdout); 
    cin>>val; 
    res[0] = v[1] - val; 
    res[1] = v[0] - res[0]; 
    res[2] = val - res[1];
    cout<<"! " ;
    for(auto &i: res) cout<<i<<" "; cout<<endl; 
    fflush(stdout); 
}
int main(){
    solve();
    return 0;
}