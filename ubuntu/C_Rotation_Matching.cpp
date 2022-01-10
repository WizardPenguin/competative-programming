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
    int n; 
    cin>>n; 
    vi a(n),b(n); 
    vi ma(n+ 1),mb(n + 1); 
    for(int i=0;i<n;i++){
        cin>>a[i]; 
        ma[a[i]] = i; 
    }
    for(int i=0;i<n;i++){
        cin>>b[i]; 
        mb[b[i]] = i; 
    }
    // now mapping how many numbers are matching for particular rotation 
    map<int,int> mp; 
    for(int i=1;i<=n;i++){
        int rot = (ma[i] - mb[i]+n)%n; 
        if(mp[rot]){
            mp[rot]++; 
        }
        else{
            mp[rot] = 1; 
        }
    }
    int maxi =0 ; 
    for(int i=0;i<n;i++){
        maxi = max(maxi,mp[i]); 
    }
    cout<<maxi<<endl;  
}
int main(){
    fast_cin();
    solve();
    return 0;
}