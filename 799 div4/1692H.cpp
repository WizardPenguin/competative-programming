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
    vi v(n); for(int i=0;i<n;i+=1) cin>>v[i]; 
    map<int,vector<int> > mp;  
    for(int i=0;i<n;i+=1){
        mp[v[i]].push_back(i); 
    }
    // for(auto &pr: mp){
    //     cerr<<pr.first<<endl; 
    //     for(auto &i: pr.second) cerr<<i<<" "; 
    //     cerr<<endl; 
    // }
    // cerr<<endl; 
    int ans = 1; 
    int val = v[0]; 
    int startId = 0; 
    int sz = 1; 
    for(auto &pr: mp){
        auto &ar = pr.second;
        int count =1; 
        int i=1; 
        int start = 0; 
        int size = 1; 
        while(i<ar.size()){
            count += 1;
            count -= (ar[i] - ar[i-1] -1);  
            if(count <= 0){
                count =1; 
                start = i; 
                size = 0; 
            }
            size += 1; 
            if(ans < count){
                ans = count; 
                val = pr.first; 
                startId = start; 
                sz = size; 
            }
            i+=1; 
        }
    }
    // cerr<<sz<<endl; 
    cout<<val<<" "<<mp[val][startId] + 1<<" "<<mp[val][startId + sz-1] + 1<<endl; 
}
int main(){
    fast_cin();
    ll test;
    cin >> test;
    while(test--){
        solve();
    }
    return 0;
}