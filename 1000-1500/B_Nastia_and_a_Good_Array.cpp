// swap min element out 
// then replace all n-1 element by consecutive elements
// this will take n steps in total 
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

// max value 10^9 increased to 10^5 in bound
int main()
{
    fast_cin();
    ll test;
    cin >> test;
    while(test--){
        int n; cin>>n; 
        vector<int> v(n); 
        for(int i=0;i<n;i++) cin>>v[i]; 
        int ptr = min_element(all(v)) - v.begin(); 
        // if(ptr != 0) swap(v[ptr],v[0]); 
        // for(int i=0;i<n;i++){
        //     for(int i=0;i<n;i++) cout<<v[i]<<" "; 
        //     cout<<endl; 
        //     if(i == n-1) break; 
        //     v[i+1] = v[i] + 1; 
        // }
        // we need to give i,j x,y as output
        if(ptr != 0){
            cout<<n<<ln; 
            cout<<1<<" "<<ptr + 1<<" "<<v[ptr]<<" "<<v[0]<<ln; 
            swap(v[0],v[ptr]);
        }
        else{
            cout<<n-1<<ln; 
        }
        for(int i=1;i<n;i++){
            cout<<(1)<<" "<<(i+1)<<" "; 
            cout<<v[0]<<" "<<v[i-1] + 1<<" "; 
            v[i] = v[i-1]  +1;
            cout<<ln; 
        }
    }
    return 0;
}