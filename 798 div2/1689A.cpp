// **************** we dont' need to end both strings at same time 
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
    int n,m,k; 
    cin>>n>>m>>k; 
    string a,b; 
    cin>>a>>b; 
    sort(all(a)); sort(all(b)); 
    int i=0,j=0; 
    auto swapping = [&](){
        swap(a,b); swap(n,m); swap(i,j);
    }; 
    if(b[j] < a[i]){
        swapping(); 
    }
    string res; 
    while(i<n or j <m){
        auto tp = k; 
        while(i<n and tp-- and a[i] < b[j]){
            res += a[i++]; 
        }
        if(i == n)break; 
        if(a[i] < b[j]){
            res += b[j++];
        }
        else{
            swapping();
        }
    }
    cout<<res<<endl; 
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