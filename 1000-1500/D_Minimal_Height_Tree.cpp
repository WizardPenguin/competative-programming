// in increasing part found then take 2 nodes as children of 1 node 
// otherwise for a node take single node as it's children for that level 
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
        int level = 0; 
        int i=1; 
        int sz = 1; 
        v.push_back(0); // to get rid of out of bound error
        // tree don't necessarily needs to be binary tree
        while(i<n){
            int newsz = 0; 
            level++; 
            while(i<n and sz--){
                if(v[i] > v[i+1]){
                    // only 1 child for this node 
                    newsz++; 
                    i++; 
                }
                else{
                    int start = i; 
                    while(start < n and v[start] < v[start+1]){
                        start++; 
                    }
                    newsz += (start - i + 1); 
                    i = start + 1; 
                } 
            }
            sz = newsz;  
        }
        // dbg(sz)<<endl; 
        // if(sz) level++; 
        cout<<level<<endl; 
    }
    return 0;
}