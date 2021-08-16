// atmost 50 querires are going to be of order N
// once they has been processed all queries will be processed in atmost 50 steps 
// since each color would have been taken on top and lowest index will be that color each time 
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
    // colors are 1 indexed
    fast_cin();
    int n,q; 
    cin>>n>>q; 
    vector<int> v(n); 
    for(int i=0;i<n;i++) cin>>v[i]; 
    for(int i=0;i<q;i++){
        int col; 
        cin>>col; 
        int index ;
        for(int i=0;i<n;i++){
            if(col == v[i]){
                index = i; 
                break; 
            }
        }
        cout<<index + 1<<" "; 
        for(int i=index;i>0;i--){
            v[i] = v[i-1]; 
        }
        v[0] = col; 
    }
    return 0;
}