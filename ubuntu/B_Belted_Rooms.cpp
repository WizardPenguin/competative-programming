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

const int N = 3e6 + 6; 

void solve(){
    int n; 
    cin>>n; 
    string s; 
    cin>>s; 
    // check for clockwise circle > or -
    bool found = true; 
    for(int i=0;i<n;i++){
        if(s[i] == '<'){
            found = false; 
            break; 
        }
    }
    if(found){
        cout<<n<<endl; 
        return; 
    }
    found = true; 
    for(int i=0;i<n;i++){
        if(s[i] == '>'){
            found = false; 
            break; 
        }
    }
    if(found){
        cout<<n<<endl; 
        return; 
    }
    bitset<N> b(0); 
    for(int i=0;i<n;i++){
        if(s[i] == '-'){
            b[i] = 1; 
            b[(i+1)%n] = 1; 
        }
    }
    cout<<b.count()<<endl; 
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