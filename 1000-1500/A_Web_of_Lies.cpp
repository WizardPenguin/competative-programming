// store for reach nodes who are going to be killed by whom 
// if those friendship removed then remove this node from killer list
// if node is not with direct contact with killer then it can't be killed 
// no of rounds doesn't matter
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
    // we are only storing count of killers 
    int n,m;
    cin>>n>>m; 
    vector<int> killers(n+1,0); 
    int survivors = n; 
    for(int i=0;i<m;i++){
        int a,b; 
        cin>>a>>b; 
        int k = min(a,b); 
        if(killers[k] == 0) survivors--; 
        killers[k] ++; 
    }
    int q; cin>>q; 
    while(q--){
        int a,b,c; 
        cin>>a; 
        if(a == 3){
            cout<<survivors<<endl; 
        }
        else{
            cin>>b>>c; 
            int k = min(b,c); 
            if(a == 2){
                // remove friendship
                killers[k]--; 
                if(killers[k] == 0) survivors++; 
            }
            else{
                if(killers[k] == 0) survivors--; 
                killers[k] ++; 
            }
        }
    }
    return 0;
}