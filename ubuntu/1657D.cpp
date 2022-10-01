// we can use only 1 types of team many times within cost
// CATCH: we want H/d > h/D means H*D > h*d where H,D are powers of team we are selecting 
// let H*D be power
// we need maximum power at each index 
// also we can repeat so find maximum at each index by repeating previous ones within cost
// finally we need to minimize number really used to getting some power by storing max power we can get at cost 
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
    ll n,c; 
    cin>>n>>c; 
    // vector<pair<int,int> > data; 
    vector<ll> power(c+1,0); // max power at each index using single element 
    for(int i=0;i<n;i+=1){
        ll c,d,h; 
        cin>>c>>d>>h; 
        power[c] = max(power[c],d*h); 
    }
    // now repeat elements within cost and maximize power again for each cost 
    for(ll i=1;i<=c;i+=1){
        for(ll j=1;j*i<=c;j+=1){
            // we are using j monsters of type i to fight 
            // that makes their power to add 
            power[j*i] = max(power[j*i],j*power[i]); 
        }
    }
    // for any index we need to store maximum power to get even if we use lower cost
    // this is done so array becomes increasing and we can use lower bound to find first element(least cost) elm
    for(int i=1;i<=c;i+=1){
        power[i] = max(power[i],power[i-1]); 
    }
    int monsters; 
    cin>>monsters; 
    while(monsters--){
        ll d,h; 
        cin>>d>>h; 
        int ub = upper_bound(power.begin(),power.end(),d*h) - power.begin();
        if(ub > c){
            cout<<-1<<" "; 
        } 
        else{
            cout<<ub<<" "; 
        }
    }
    cout<<endl; 
}
int main(){
    fast_cin();
    solve(); 
    return 0;
}