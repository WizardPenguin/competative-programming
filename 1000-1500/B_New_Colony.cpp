// using bruitforce throw a stone and then find where it reaches
// when you got first one which git's out of area then all next will do so 
// when array becomes strictly decreasing types then we are done and it takes N^2 complexity 
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
const int N = 1000006;
int main()
{
    fast_cin();
    ll test;
    cin >> test;
    while(test--){
        int n,k; 
        cin>>n>>k; 
        vector<int> v(n); 
        for(int i=0;i<n;i++){
            cin>>v[i]; 
        }
        bool fall = false;
        int i;  
        int x; 
        for(i=1;i<=min(N,k);i++){
            x = 1; 
            while(x < n and v[x] <= v[x-1]) x++; 
            // we have reached where this stone stops
            // cout<<x<<endl; 
            if(x == n){
                fall = true; break; 
            }
            v[x-1] ++; 
        }
        if(fall){
            cout<<-1<<endl; 
        }
        else{
            cout<<x<<endl; 
        }
    }
    return 0;
}