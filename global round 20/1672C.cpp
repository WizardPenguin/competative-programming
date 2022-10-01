#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<vector<ll> > vvll;
typedef vector<vector<pll> > vvpll;
typedef vector<pll> vpll;
typedef vector<pii> vpii;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<vector<bool> > vvb;
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 

void solve(){
    int n; 
    cin>>n; 
    vi v(n); 
    for(int i=0;i<n;i+=1) cin>>v[i]; 
    int i=0; 
    vector<pii> ids; 
    while(i<n){
        int val = v[i]; 
        int start = i; 
        int count = 0; 
        while(i<n and v[i] == val) i+=1,count+=1; 
        if(count > 1){
            ids.push_back({start,count-1}); 
        }
    }
    if(ids.size() == 0){
        cout<<0<<endl; 
    }
    else if(ids.size() > 1){
        // 1 case when we are doing them completely 
        // or taking from a partition index towards end nodes 
        int sz = ids.size(); 
        int ans = INT_MAX; 
        // for(int i=0;i<sz-1;i+=1){
        //     int left = ids[i].first + ids[i].second; 
        //     left = max(left-2,1); 
        //     int right = n - ids[i+1].first; 
        //     right = max(right-2,1); 
        //     ans = min(ans,left + right); 
        // }
        int start = ids[0].first; 
        int end = ids.back().first + ids.back().second; 
        ans = min(max(end - start - 2,1),ans);
        cout<<ans<<endl;  
    }
    else{ 
        if(ids.back().second == 1) cout<<0<<endl; 
        else
        cout<<max(ids.back().second -2,1)<<endl; 
    }
}
int main(){
    fast_cin();
    ll test;
    cin >> test;
    while(test--){
        // cerr<<"test case"<<endl; 
        solve();
    }
    return 0;
}