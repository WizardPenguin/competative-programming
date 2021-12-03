#include <bits/stdc++.h> 
#include <complex>
#include <cmath>
// there are going to be atmost n-1 restrictions means atlest 1 node which is not restricted to be in middel of any
// so we'll make that node as middle node and rest all attached with 1 edge with this node 
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
        int n,m; 
        cin>>n>>m; 
        vector<bool> taken(n+1,false); 
        int x,y,z; 
        for(int i=0;i<m;i++){
            cin>>x>>y>>z; 
            taken[y] = true;  
        }
        int center = -1; 
        for(int i=1;i<=n;i++){
            if(!taken[i]){
                // then we can take it as center
                center = i; 
                break; 
            }
        }
        for(int i=1;i<=n;i++){
            if(i!= center){
                cout<<i<<" "<<center<<endl; 
            }
        }
    }
    return 0;
}