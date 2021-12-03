// check for all k from 1..n and find if we can divide array into such partition so each = sum/partitions
// check can be done using binary search 
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
        for(int i=0;i<n;i++){
            cin>>v[i]; 
        }
        for(int i=1;i<n;i++){
            v[i] += v[i-1]; 
        }
        // let's say after k steps array has became such that each element is equal 
        // then we can check weather it's possible 
        int sum = v[n-1];
        int ans = 0;  
        for(int k=0;k<n;k++){
            int parts = n-k;
            if(sum%parts != 0 ) continue; 
            int req = sum/parts; 
            int temp = req; 
            // check if k parts are there or not if yes we have found solution 
            bool found = true; 
            for(int i=0;i<parts;i++){
                if(binary_search(all(v),req)){
                    req += temp; 
                }
                else{
                    found = false; 
                    break; 
                }
            }
            if(found){
                ans = k; 
                break; 
            }
        }
        cout<<ans<<endl; 
    }
    return 0;
}