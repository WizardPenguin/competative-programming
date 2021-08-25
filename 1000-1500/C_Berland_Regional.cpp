// for each university sort their participant on their skill then store cumsum 
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
        map<int,vector<long long> > pre;  
        vector<int> u(n); 
        for(int i=0;i<n;i++) cin>>u[i]; 
        int num; 
        for(int i=0;i<n;i++){
            cin>>num; 
            pre[u[i]].push_back(num); 
        }
        int maxSize = 0; 
        for(auto &v: pre) sort(all(v.second),greater<int>()); 
        for(auto &v: pre){
            for(int i=1;i<v.second.size();i++){
                v.second[i] += v.second[i-1]; 
            }
            maxSize = max(maxSize,int(v.second.size()));
        }
        // for(auto &v: pre){
        //     for(auto i: v) cout<<i<<" "; 
        //     cout<<endl; 
        // }
        long long ans; 
        for(int k=1;k<=n;k++){
            ans = 0; 
            set<int> ers; 
            if(k <= maxSize)
            for(auto &v: pre){
                int sz = v.second.size(); 
                if(sz < k){
                    ers.insert(v.first);
                    continue; 
                }
                int left = sz%k; 
                ans += v.second[sz-left-1]; 
            }
            for(auto i: ers) pre.erase(i);
            cout<<ans<<" "; 
        }
        cout<<endl; 
    }
    return 0;
}