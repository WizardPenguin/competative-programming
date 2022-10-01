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
    ll x,y; 
    cin>>x>>y; 
    if(x == 1 and y == 1){
        cout<<0<<endl; 
    }
    else if((x == 1 and y == 2) or (x == 2 and y == 1)){
        cout<<1<<endl; 
    }
    else if(x == 1 or y == 1){
        cout<<-1<<endl; 
    }
    else{
        ll ans = 0; 
        if(x < y) swap(x,y); 
        if(x > y){
            ans += 2*(y-1); 
            x -= y; 
            x += 1; 
            if(x&1){
                ans += x - 1  + x - 1; 
            }
            else{
                ans += x - 2 + x - 1;
            }
        }
        else{
            ans += 2*(x-1); 
        }
        cout<<ans<<endl; 
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