#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
// if all are same then 0 steps 
// if sum of requirnments to make everyone = x is 0 then 1 step
// otherwise 2 steps, 1st make someone = x and adjust others accordingly 
// after then make everyone 0 and adjust 1st element accordintly 
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
    int n,x; 
    cin>>n>>x; 
    vi v(n); 
    int sum = 0; 
    bool found = true; 
    bool onefound = false; 
    for(int i=0;i<n;i++){
        cin>>v[i]; 
        if(v[i] != x) found = false;
        else onefound = true;  
        sum += (x - v[i]); 
    }
    if(found){
        cout<<0<<endl; 
    }
    else if(sum == 0 or onefound){
        cout<<1<<endl; 
    }
    else{
        cout<<2<<endl; 
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