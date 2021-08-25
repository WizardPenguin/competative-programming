// good sequence have same and wrt all index prefix and suffix 
// that means if number is already good then it's all permutation except last element = & of whole array 
// also since we need to permutate index it's n! permutation for middle indices(except first ,last)
#include <bits/stdc++.h> 
#include <complex>
#include <cmath>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define MOD 1000000007

int main()
{
    fast_cin();
    ll test;
    cin >> test;
    while(test--){
        int n; cin>>n; 
        vector<int> v(n); for(int i=0;i<n;i++) cin>>v[i]; 
        // ********** sequence need not to be already good so no need for such check   
        // vector<int> preAnd(n); 
        // preAnd[0] = v[0]; 
        // for(int i=1;i<n;i++) preAnd[i] = preAnd[i-1]&v[i]; 
        // vector<int> postAnd(n); 
        // postAnd[n-1] = v[n-1]; 
        // for(int i=n-2;i>=0;i--) postAnd[i] = postAnd[i+1]&v[i]; 
        // bool found = true; 
        // for(int i=0;i<n-1;i++){
        //     if(postAnd[i+1] != preAnd[i]){
        //         found = false; break; 
        //     }
        // }
        int wholeAnd = v[0]; 
        for(int i=1;i<n;i++) wholeAnd &= v[i]; 
        int freq = 0; 
        for(int i=0;i<n;i++) freq += (wholeAnd == v[i]);
        if(freq >= 2){
            long long ans = 1; 
            for(int i=1;i<=n-2;i++) ans *= i,ans %= MOD; 
            ans *= freq; 
            ans %= MOD ; 
            ans *= (freq -1); 
            ans %= MOD; 
            cout<<ans<<endl; 
        }
        else{
            cout<<0<<endl; 
        }
    }
    return 0;
}