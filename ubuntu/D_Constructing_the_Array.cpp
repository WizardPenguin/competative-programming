/// make division and store size of their array and middle element that is going to be stored 
// first part is to make all divisions 
// after then sort those divisions based on their sizes 
// then put elements in order
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
vpii res; 
void part(int l,int r){
    if(l>r) return; 
    int sz = r - l + 1; 
    if(sz == 1){
        res.push_back({sz,l}); 
        return; 
    }
    if(sz&1){
        int mid = (l + r)/2; 
        res.push_back({sz,mid}); 
        part(l,mid-1); 
        part(mid+1,r); 
    }
    else{
        int mid = (l + r - 1)/2; 
        res.push_back({sz,mid});
        part(l,mid-1); 
        part(mid+1,r); 
    }
}
void solve(){
    int n;
    cin>>n; 
    res.clear(); 
    part(0,n-1); 
    sort(all(res),[](auto &a,auto &b){
        // when is a going to be earlier 
        // if it's size is greater 
        // is same size then it's index should be lower
        if(a.first == b.first){
            return a.second < b.second; 
        }
        return a.first > b.first; 
    }); 
    int i=1;
    vi tp(n); 
    for(auto &pr: res){
        tp[pr.second] = i++; 
    }
    for(auto &i: tp) cout<<i<<" "; 
    cout<<ln; 
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