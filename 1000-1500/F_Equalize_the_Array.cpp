// we need to check every c and find how many removals are going to be there for that c 
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
        // we are supposed to consider how to deal with O(N^2) complexity 
        // we can linearly move over all possible c's in sorted array 
        long long n; 
        cin>>n; 
        map<int,int> mp;
        long long sum = n;
        int val;   
        for(int i=0;i<n;i++){
            cin>>val; 
            mp[val]++; 
        }
        vector<int> v; 
        for(auto i: mp){
            v.push_back(i.second);
        } 
        sort(all(v));
        // for(auto i: v) cout<<i<<" "; 
        // cout<<endl; 
        n = v.size();   	
        // we need to have left sum to be considered 
        int prev = 0; 
        int i=0; 
        long long prevSum =0;
        long long ans = LLONG_MAX; 
        while(i < n){
            int cur = v[i];
            // cout<<"cur "<<cur<<" "; 
            long long len = (upper_bound(all(v),cur) - v.begin()) - i;
            // cout<<len<<" "; 
            sum -= (cur - prev)*(n- i); 
            // cout<<sum<<" "; 
            ans = min(ans,prevSum + sum);        
            prevSum += len*(cur);
            // cout<<prevSum<<endl; 
            i += len;  
            prev = cur; 
        }
        cout<<ans<<endl; 
    }
    return 0;
}