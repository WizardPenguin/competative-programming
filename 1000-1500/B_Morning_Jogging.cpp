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
        int n,m; 
        cin>>n>>m; 
        vector<vector<int> > v(n,vector<int>(m)); 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>v[i][j]; 
            }
        }
        sort(all(v[0]));
        // store smallest value till now w.r.t each index 
        // keep this array sorted for further reference 
        // while considering next array sort it and chech whose min it can change 
        // check from start since we more number we can change more it's good for us
        // it doesn't matter which minima replaced by whom they should be maximum in count
        vector<int> temp; 
        vector<int> mini = v[0]; 
        for(int i=1;i<n;i++){
            sort(all(v[i]));
            temp = v[i]; 
            auto &ref = v[i];
            for(int i=0;i<m;i++) ref[i] = 0; 
            int start = m-1; 
            int end = m-1; 
            while(start >=0 and start >=0){
                if(temp[start] < mini[end]){
                    // replace it 
                    mini[end] = temp[start];  
                    ref[end] = temp[start];
                    temp[start] = 0; // mark this number as taken
                    start--; 
                    end--; 
                }
                else{
                    start--;
                }
            }
            // now place remaining elements where they need to be 
            start = 0; 
            int ptr = 0; 
            while(ptr < m and start < m){
                if(ref[ptr] == 0 and temp[start] != 0){
                    ref[ptr] = temp[start]; 
                    ptr++; 
                    start++; 
                }
                if(ptr < m and ref[ptr] != 0) ptr++; 
                if(start < m and temp[start] == 0) start++; 
            }
            sort(all(mini)); 
        }
        for(auto &i: v){
            for(auto j: i) cout<<j<<" ";
            cout<<endl; 
        }
    }
    return 0;
}