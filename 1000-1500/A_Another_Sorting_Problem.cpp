// need to pass desired comparator 
// it's good not having strings of different sizes
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
    test = 1; 
    while(test--){
        int n,m; 
        cin>>n>>m; 
        vector<string> s(n); 
        for(int i=0;i<n;i++) cin>>s[i]; 
        vector<int> id; 
        for(int i=0;i<n;i++) id.push_back(i); 
        // lambda function needs to return when should x come before y 
        sort(all(id),[&](const int &x,const int &y){
            string &a = s[x]; 
            string &b = s[y]; 
            int i=0; 
            while(i<n and a[i] == b[i]) i++; 
            if(i!=n){
                if(i&1){
                    return a[i] > b[i]; 
                }
                else{
                    return a[i] < b[i]; 
                }
            }
            return false; 
        });
        for(auto &i: id) cout<<i + 1<<" "; 
    }
    return 0;
}