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
    vi v(n); 
    for(int i=0;i<n;i++) cin>>v[i]; 
    string s; 
    cin>>s; 
    vpii ones,zeros; 
    for(int i=0;i<n;i++){
        if(s[i] == '1'){
            ones.push_back({v[i],i}); 
        }
        else{
            zeros.push_back({v[i],i}); 
        }
    }
    vi res(n,0); 
    sort(all(ones)); // auto sorted according to pi values
    for(int i=n,j=ones.size()-1;j>=0;i--,j--){
        res[ones[j].second] = i; 
    }
    // now each remaining should get in sorted order
    sort(all(zeros)); 
    for(int i=0,j=1;i<zeros.size();i++,j++){
        res[zeros[i].second] = j; 
    }
    for(auto &i: res) cout<<i<<" "; 
    cout<<endl; 
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