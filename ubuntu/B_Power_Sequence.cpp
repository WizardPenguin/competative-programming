// if c = 1 then we get cost = sum(abs(a[i] - 1)) 
// after then we are required to check for other c's 
// we can stop if c*(n-1) - maxi > sum(a[i]) since for every c after that we have a better solution c= 1 
// also for most of cases we are not really required to increase c much using bruteforce 
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
    // 1e9 * 1e5 is max cost we can have 
    ll inf = 1e15; 
    int n ;
    cin>>n; 
    vi v(n); 
    for(int i=0;i<n;i++){
        cin>>v[i]; 
    }
    int c =1; 
    ll cost = inf; 
    while(true){
        ll pw = 1; 
        ll cst = abs(v[0] - pw); 
        for(int i=1;i<n;i++){
            pw *= c; 
            if(pw >= inf){
                goto end; 
            }
            cst += abs(v[0] - pw); 
        }
        
    }
    end:; 
}
int main(){
    fast_cin();
    solve();
    return 0;
} 