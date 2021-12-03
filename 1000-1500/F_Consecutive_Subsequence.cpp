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


int main()
{
    fast_cin();
    int n; 
    cin>>n; 
    vector<int> v(n); 
    for(int i=0;i<n;i++) cin>>v[i]; 
    // here dp[i] represents largest consecutive subsequence formed starting with number i by considering element after it in array 
    map<int,int> dp; 
    int ans = 0; 
    int ele = -1; 
    for(int i=n-1;i>=0;i--){
        auto val = v[i]; 
        if(dp.find(val+1) != dp.end()){
            dp[val] = dp[val+1] + 1; 
        }
        else{
            dp[val] = 1; 
        }
        if(ans < dp[val]){
            ele = val; 
            ans = dp[val]; 
        } 
    } 
    cout<<ans<<endl; 
    // we know solution starts with ele 
    // after then greedily using linear serach to find nearest ele+1 and print it's index
    map<int,int> index; 
    int j=0; 
    for(int i=0;i<ans;i++){
        int elm = ele + i; 
        while(j<n and v[j] != elm) j++; 
        cout<<j+1<<" "; 
    }
    cout<<endl; 
    return 0; 
}