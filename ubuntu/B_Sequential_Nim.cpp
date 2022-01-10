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
 
// winner is the one who gets last move
// so we are desired to have last move at us to win 
// if we got number > 1 at any move then we can either given next move to other or take it by ourselves by making v[i] = 1 or not
// so one getting such number will be winner 

void solve(){
    int n; 
    cin>>n; vi v(n); 
    for(int i=0;i<n;i++) cin>>v[i];
    int w = 1; 
    for(int i=0;i<n;i++){
        if(v[i] == 1 and i!= n-1){
            w = 1-w; 
        }
        else{
            break; 
        }
    }
    if(w){
        cout<<"First"<<endl; 
    }
    else{
        cout<<"Second"<<endl; 
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