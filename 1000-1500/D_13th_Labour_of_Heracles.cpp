/// seems like we need to divide whole graph into k connected components(k)
// for getting max we need to divide graph from largest weithted node so it comes more than once in edge list
// we can do till it has that much edges connected to it = degree(vertex) after then consider 2nd max
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
        ll sum =0; 
        for(int i=0;i<n;i++){
            cin>>v[i]; 
            sum += v[i]; 
        }
        vector<int> deg(n,0); 
        for(int i=0;i<n-1;i++){
            int u,v; 
            cin>>u>>v; 
            deg[--u]++; 
            deg[--v]++; 
        }
        vector<int> ids; 
        for(int i=0;i<n;i++) ids.push_back(i); 
        int ptr = 0; 
        sort(all(ids),[&](const int &a,const int &b){
            return v[a] > v[b]; 
        });
        for(int k=1;k<n;k++){
            cout<<sum<<" "; 
            if(k == n-1) continue; 
            while(deg[ids[ptr]] <= 1){
                ptr++; 
            }
            sum += v[ids[ptr]]; 
            deg[ids[ptr]]--; 
        }
        cout<<endl; 
    }
    return 0;
}