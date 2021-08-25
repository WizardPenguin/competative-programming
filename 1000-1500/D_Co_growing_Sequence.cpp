// *** we need to make yi i.e. xor taking sequence in lexiographically smaller sequency 
// smallest number that will satisfy condition of making ai&ai-1 = ai
// all other non required places has to be filled with 0 since that doesn't make any difference 
// also 0 helps in making sequence smaller
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
        int n; cin>>n; 
        vector<int> v(n);
        for(int i=0;i<n;i++) cin>>v[i];
        vector<int> res; 
        res.push_back(0);
        int prev = v[0];
        for(int i=1;i<n;i++){
            int num = 0;
            for(int j=0;j<30;j++){
                if(!(v[i] & (1<<j)) and (prev & (1<<j))){
                    num += (1<<j);
                }
            }
            res.push_back(num);
            prev = v[i] ^ num;
        }
        for(auto i: res) cout<<i<<" ";
        cout<<endl; 
    }
    return 0;
}