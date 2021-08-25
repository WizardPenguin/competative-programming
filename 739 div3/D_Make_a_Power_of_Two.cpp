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
    ll test;
    cin >> test;
    vector<string> v; 
    // for(long long i=1;i<=LLONG_MAX;i*=2){ 
    //     v.push_back(to_string(i)); 
    //     if(i == LLONG_MAX) break;
    // }
    for(long long i=0;i<63;i++){
        v.push_back(to_string(1ll << i)); 
    }
    while(test--){
        string s; 
        cin>>s; 
        int ans = INT_MAX; 
        for(auto &str: v){
            // try making i using s
            int start = 0; 
            for(int i=0;i<s.length();i++ ){
                if(str[start] == s[i])start++; 
            }
            // now remaining characters have to be removed 
            int remove = s.length() - (start ); 
            int add = str.length() - (start); 
            ans = min(ans,add + remove); 
        }
        cout<<ans<<endl; 
    }
    return 0;
}