// we need to find cyclic movements so that no number repeats in any row
// if both coln has same values then we can't make any swap 
// otherwise we have a solution by swapping nodes
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
        const int mod = 1000000007; 
        ll ans = 1; 
        cin>>n; 
        vector<vector<int> > v(2,vector<int>(n)); 
        vector<map<int,int> > mp(2); 
        for(int j=0;j<2;j++){
            for(int i=0;i<n;i++){
                cin>>v[j][i]; 
                mp[j][v[j][i]] = i; 
            }
        }
        vector<bool> visited(n,false); 
        for(int i=0;i<n;i++){
            int toFind = v[0][i]; 
            int fromFind = v[1][i]; 
            if(visited[i]) continue; 
            visited[i] = true; 
            ll count = 1; 
            while(toFind != fromFind){
                // move to from element of 0th node 
                visited[mp[0][fromFind]] = true; 
                fromFind = v[1][mp[0][fromFind]];
                count++; 
            }
            // cout<<count<<endl; 
            ans *= min(count,2ll); 
            ans %= mod; 
        }
        cout<<ans<<endl; 
    }
    return 0;
}