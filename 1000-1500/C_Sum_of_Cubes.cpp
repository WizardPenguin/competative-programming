// precompute cubes
// then linear check for a and then using map check weather x - a^3 is in precomputed cubes
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
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define N 10004
int main()
{
    fast_cin();
    ll test;
    cin >> test;
    unordered_set<long long> st; 
    for(long long i=1;i<N;i++){
        st.insert(i*i*i);
    }
    while(test--){
        long long n; 
        cin>>n; 
        bool found = true; 
        for(long long i=1;i<N;i++){
            long long cube = i*i*i; 
            if(cube > n){
                found = false; 
                break; 
            }
            if(st.find(n - cube) != st.end()){
                found = true; 
                break; 
            }
        }
        if(found) cout<<"YES"<<endl; 
        else cout<<"NO"<<endl; 
    }
    return 0;
}