// at each step take largest element to it's position which is not at it's position takes max n steps 
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
    while(test--){
        int n; 
        cin>>n; 
        vector<int> v(n); 
        for(int i=0;i<n;i++) cin>>v[i]; 
        vector<int> s = v; 
        sort(all(s)); 
        vector<vector<int> > res; 
        for(int i=n-1;i>=0;i--){
            if(v[i] == s[i]){
                continue; 
            }
            else{
                // find largest element and take it here 
                int j; 
                for(j=0;j<i;j++){
                    if(v[j] == s[i]){
                        break; 
                    }
                }
                // perform left rotation by 1
                res.push_back({j+1,i+1,1}); 
                // cout<<j + 1<<" "<<i + 1<<" "<<1<<endl; 
                // perform actual rotation 
                for(int x = j;x<i;x++){
                    swap(v[x],v[x+1]);
                    // v[j] = v[j+1];
                }
                // v[i] = s[i];
                // for(auto &x: v) cout<<x<<" "; 
                // cout<<endl; 
            }
        }
        cout<<res.size()<<endl; 
        for(auto &i: res){
            for(auto j: i){
                cout<<j<<" "; 
            }
            cout<<endl; 
        }
    }
    return 0;
}