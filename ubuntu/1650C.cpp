// just take smallest 2*n points and add their powers to minimize our cost
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
    vector<array<int,3>> v; 
    int n,m; 
    cin>>n>>m; 
    int x,y; 
    for(int i=0;i<m;i+=1){
        cin>>x>>y; 
        v.push_back({x,y,i+1});
        // we are inserting coord,weight,index 
    }
    sort(all(v),[](auto &a,auto &b){
        // sort such that if a has lower weight it comes first 
        return a[1] < b[1]; 
    }); 
    ll cumulated = 0;
    for(int i=0;i<2*n;i+=1){
        cumulated += v[i][1]; 
    }
    // now sort first 2*n numbers based on their coordinates 
    sort(v.begin(),v.begin() + 2*n,[](auto &a,auto &b){
        // lower coordinate comes first
        return a[0] < b[0];
    });
    // now cumulate weight and output result
    cout<<cumulated<<endl;  
    for(int i=0;i<n;i+=1){
        auto a = v[i][2]; 
        auto b = v[2*n - i - 1][2];
        cout<<min(a,b)<<" "<<max(a,b)<<endl;  
    }
    cout<<endl; 
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