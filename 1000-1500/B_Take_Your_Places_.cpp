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
        vector<int> st(n); 
        for(int i=0;i<n;i++) cin>>st[i]; 
        for(auto i: st) cout<<i<<" "; 
        cout<<endl; 
        int odd_0 = 0, even_0 = 0;
        int odd_1 = 0, even_1 = 0;
        for (int i = 0; i < n; i++){
            if ((i % 2) == 0){
                if (st[i]&1)
                    even_1++;
                else
                    even_0++;
            }
            else{
                if (st[i]&1)
                    odd_1++;
                else
                    odd_0++;
            }
        }
        cout<<even_1<<even_0<<odd_1<<odd_0<<endl; 
        cout<<min(min(even_0,odd_1),min(even_1,odd_0))<<endl; 
    }
    return 0;
}