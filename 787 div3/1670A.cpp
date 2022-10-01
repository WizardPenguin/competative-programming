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
    if(n == 1){
        cout<<"YES"<<endl; 
        return; 
    }
    int count = 0; 
    for(auto &i: v){
        if(i<0) count += 1; 
    }
    // so first count values should be sorted and remaining should be sorted
    int val = v[0]; 
    bool found = false; 
    for(int i=1;i<count;i+=1){
        if(abs(v[i] ) > abs(v[i-1])){
            found = true; 
            break; 
        }
    }
    for(int i=count+1;i<n;i+=1){
        if(abs(v[i]) < abs(v[i-1])){
            found = true; 
            break; 
        }
    }
    if(found){
        cout<<"NO"<<endl; 
    }
    else{
        cout<<"YES"<<endl; 
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