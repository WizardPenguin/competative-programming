// find how many parts of sorted array are there 
// parts <= k
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
#define N 10000007

int main()
{
    fast_cin();
    ll test;
    cin >> test;
    while(test--){
        int n; 
        cin>>n; 
        int k; cin>>k; 
        vector<int> v(n); 
        for(int i=0;i<n;i++) cin>>v[i];
        vector<int> temp;
        temp = v;
        sort(all(temp)); 
        unordered_map<int,int> mp; 
        for(int i=0;i<temp.size();i++){
            mp[temp[i]] = i; 
        }
        for(int i=0;i<n;i++){
            v[i] = mp[v[i]]; 
        }
        v.push_back(n); 
        int parts = 0; 
        int i=0;
        while( i < n ){
            while(i < n and (v[i+1] ==(v[i] + 1)) ) i++; 
            // cout<<v[i]<<endl; 
            parts ++; 
            i++; 
        }
        // cout<<parts<<endl; 
        if(parts <= k) cout<<"Yes"<<endl; 
        else cout<<"No"<<endl; 
    }
    return 0;
}