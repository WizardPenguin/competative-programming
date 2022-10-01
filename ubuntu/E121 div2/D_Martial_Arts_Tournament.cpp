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
// guess size of middle part 
// then using 2 pointer find some valid subarray for that part 
/// and divide remaining parts in 1st and last one as optimized as possible 
// means find largest set bit and increase from there if that is already not in power of 2
void solve(){
    int n; 
    cin>>n; 
    vi v(n+1,0); 
    int val; 
    for(int i=0;i<n;i++){
        cin>>val; 
        v[val]++; 
    }
    int largePower = log2(n); 
    if(n&(n-1)){
        // means it's not in power of 2
        largePower ++; 
    } 
    int cost = INT_MAX; 
    for(int p=0;p<=largePower;p++){
        int i=1; 
        int j = 1; 
        int sum = 0; 
        int toFind = 1<<p; 
        int left = 0; // left part has no element 
        int right = n; // right part has ll elements
        while(j<=n){
            // add jth element 
            sum += v[j]; 
            right -= v[j]; 
            if(sum > toFind){
                // we need to remove elements 
                while(sum > toFind){
                    sum -= v[i]; 
                    left += v[i]; 
                    i++; 
                }
                // i has overshooted but worth it 
            }
            // if sum has not overshooted then no need to remove elements 
            // find clogest powers and cost to make them  
            int lp = log2(left); 
            int rp = log2(right); 
            if(left&(left-1)){
                lp++;
            }
            if(right&(right-1)){
                rp++; 
            }
            cost = min(cost,toFind - sum + (1<<lp) - left + (1<<rp) - right); 
            j++; // add next element
        }
    }
    cout<<cost<<endl; 
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