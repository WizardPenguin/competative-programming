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
    sort(all(v)); 
    if(n&1){
        cout<<"NO"<<endl; 
    }
    else{
        if(n == 2 and v[0] != v[1]){
            if(v[0] != v[1]){
                cout<<v[0]<<" "<<v[1]<<endl; 
            }
            else{
                cout<<"NO"<<endl; 
                return; 
            }
        }
        if(v[0] == v[n/2] or v[n/2-1] == v.back()){
            cout<<"NO"<<endl; 
        }
        else{
            cout<<"YES"<<endl; 
            for(int i=0;i<n/2;i+=1){
                cout<<v[n-1-i]<<" "; 
                cout<<v[n/2 - i - 1]<<" "; 
            }
            cout<<endl; 
        }
    }
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