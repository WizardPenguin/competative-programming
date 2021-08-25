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
        vector<pair<long long,int>> pre; 
        for(int i=0;i<n;i++){
            int sz; 
            cin>>sz; 
            vector<int> v(sz); 
            for(int j=0;j<sz;j++) cin>>v[j]; 
            // we need to find max element it requires here 
            long long start = v[0] + 1; 
            for(int j=1;j<sz;j++){
                if(v[j] >= start + j) start += (v[j] - start - j) + 1;
            }
            pre.push_back({start,-sz});
        }
        sort(all(pre)); 
        // for(auto i: pre){
        //     cout<<i.first<<" "<<i.second<<endl; 
        // }
        long long init = pre[0].first;
        init -=  pre[0].second; // it wins this cage completely 
        long long increase = 0; 
        for(int i=1;i<n;i++){
            if(init > pre[i].first ){
                // then mark it as win
                init -= pre[i].second; 
            }
            else{
                // we need to increase it's power
                increase += (pre[i].first - init); 
                init += (pre[i].first - init);  // win the game 
                init -= pre[i].second; // increase remaining power
            }
            // cout<<init<<" "<<increase<<endl; 
        }
        cout<<pre[0].first + increase<<endl; 
    }
    return 0;
}