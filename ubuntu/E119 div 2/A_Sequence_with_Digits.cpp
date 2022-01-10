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
// ai+1 = ai + min(ai)*max(ai)
// this will become zero after 1000 max queries
// because adding max*min at max is 2 digit number which makes carry at 3rd digit number
// after some time this becomes 9 and finally 0 in next few moves 
void solve(){
    ll n,k; 
    cin>>n>>k; 
    for(int i=0;i<min(k-1,1000ll);i++){
        int maxi = 0; 
        int mini = 10; 
        ll tp = n; 
        while(tp){
            int t = tp%10; 
            tp/=10; 
            mini = min(t,mini); 
            maxi = max(t,maxi); 
        } 
        n += maxi*mini; 
    }
    cout<<n<<endl;
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