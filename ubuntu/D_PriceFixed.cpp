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
typedef vector<vector<bool> > vvb;
typedef vector<string> vs;
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 

void solve(){
    int n; cin>>n; 
    vll a(n),b(n);  // a is amout to purchage, b is amount after which discount applies
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i]; 
    }
    vi id; 
    for(int i=0;i<n;i++) id.push_back(i); 
    sort(all(id),[&](const int &i,const int &j){
        return b[i] > b[j];  // if it's ith greater then return true so that greater could be on front
    }); 
    int i=0; 
    int j = n-1; 
    ll taken = 0; 
    ll cost = 0; 
    while(i<=j){
        auto as = a[id[i]]; 
        auto req = b[id[j]]; 
        auto toTake = min(as,req - taken); 
        toTake = max(toTake,0ll); 
        cost += toTake*2; 
        a[id[i]] -= toTake; 
        taken += toTake; 
        if(taken >= req){
            cost += a[id[j]]; 
            taken += a[id[j]]; 
            j--; 
        }
        if(a[id[i]] == 0){
            i++; 
        }
    }
    cout<<cost<<endl; 
}
int main(){
    fast_cin();
    solve();
    return 0;
}