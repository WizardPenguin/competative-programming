// we can have offset of +- (l-r) at max 
// we need to check for every a what offset gives us valid value of n 
// if a < m then we can only give offset of a-r that adds to m to give integral m 
// othwereise we have 2 cases either offset or -r or a-r 
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
 
ll l,r,m;
void solve(){ 
    cin>>l>>r>>m; 
    for(int a=l;a<=r;a+=1){
        // cerr<<a<<" "<<m%a<<endl; 
        if(a>m){
            // cerr<<" o "<<endl; 
            int offset = a - m%a; 
            if((l+offset) <= r){
                cout<<a<<" "<<l <<" "<<l + offset<<endl; 
                return; 
            } 
        }
        else{
            // cerr<<" t "<<endl; 
            int offset = m%a; 
            if((offset+l)<= r){
                cout<<a<<" "<<l + offset<<" "<<l<<endl; 
                return; 
            }
            offset = a - offset; 
            if((offset+l) <= r){
                cout<<a<<" "<<l<<" "<<l + offset<<endl; 
                return; 
            }
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