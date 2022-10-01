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
    vi a(n),b(n); 
    for(int i=0;i<n;i+=1) cin>>a[i]; 
    for(int i=0;i<n;i+=1) cin>>b[i]; 
    bool allZero = true; 
    for(auto &elm: b){
        if(elm){
            allZero = false;
            break;
        }
    }
    if(allZero){
        cout<<"YES"<<endl; 
        return; 
    }
    int mini = 0; 
    int minelm = INT_MAX; 
    for(int i=0;i<n;i+=1){
        if(b[i] and minelm > b[i]){
            minelm = b[i]; 
            mini = i; 
        }
    }
    int steps = (a[mini] - b[mini]); 
    if(steps < 0){
        cout<<"NO"<<endl; 
        return; 
    }
    // cerr<<steps<<endl; 
    for(int i=0;i<n;i+=1){
        a[i] = max(0,a[i] - steps); 
        if(a[i] != b[i]){
            cout<<"NO"<<endl; 
            return; 
        }
    }
    cout<<"YES"<<endl; 
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