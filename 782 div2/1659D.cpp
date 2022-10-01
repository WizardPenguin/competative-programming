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
    int n; cin>>n; 
    vi v(n); 
    for(int i=0;i<n;i+=1) cin>>v[i]; 
    // find first v[i] > 0 means it has v[i] - i consecutive 1's after it 
    // then next element is shurely 0, substract previous 1's from it
    // if something remaining means next (remaining) elements are consecutively 1's 
    vector<int> res; 
    int i=0; 
    for(i=0;i<n and not v[i];i+=1) res.push_back(0);
    int count = v[i] - i,ones = 0; 
    while(count>0){
        res.push_back(1); 
        i+=1; 
        ones += 1; 
        count-=1; 
    }
    while(i<n){
        res.push_back(0); // this element is shurely 0 
        count = v[i] - min(ones,n - i - 1); 
        i+=1; 
        while(count--){
            i+=1; 
            res.push_back(1); 
            ones+=1; 
        }
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