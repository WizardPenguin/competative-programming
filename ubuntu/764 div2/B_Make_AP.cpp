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
    int a,b,c; 
    cin>>a>>b>>c; 
    int d,newv; 
    d = c - a; 
    if(abs(d)%2 == 0){
        d/=2; 
        newv = a + d; 
        if(newv > 0 and newv%b == 0){
            cout<<"YES"<<endl; 
            return; 
        }
    }
    d = b - a; 
    newv = a + 2*d; 
    if(newv > 0 and newv%c == 0){
        cout<<"YES"<<endl; 
        return; 
    }
    d = c - b; 
    newv = b - d; 
    if(newv > 0 and newv%a == 0){
        cout<<"YES"<<endl; 
        return; 
    }
    cout<<"NO"<<endl; 
    return; 
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