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
    int m,n; // n friends and m shops
    cin>>m>>n; 
    // we want to sort each shops joys and then check if it's top 2 are taken for 2 friends and remaining takes their respective maxima what will be the result 
    // so we are making matrix with row dimention as shops
    vvi mat(m,vi(n,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j]; 
        }
    }
    // first steps is to find maxima for each friends which they can take 
    // if they are having it from n different shops then we are required to make 2 friends covered in single shop
    set<int> id; 
    vi v(n,0); 
    for(int j=0;j<n;j++){
        int maxi = 0; 
        int maxid; 
        for(int i=0;i<m;i++){
            if(mat[i][j] > maxi){
                maxi = mat[i][j]; 
                maxid = i; 
            } 
        }
        id.insert(maxid); 
        v[j] = maxi;
    }
    if(id.size() < n){
        sort(all(v)); 
        cout<<v[0]<<endl; 
    }
    else{
        vi ids(n); 
        int ans = 0; 
        for(int i=0;i<n;i++) ids[i] = i; 
        for(int i=0;i<m;i++){
            auto &x = mat[i]; 
            sort(all(ids),[&](const int &a,const int &b){
                return x[a] > x[b];  // we want a on front if a is greater 
            });
            sort(all(x),greater<int>()); 
            pii tp = {v[ids[0]],v[ids[1]]}; 
            v[ids[0]] = x[0]; 
            v[ids[1]] = x[1]; 
            int mini = *min_element(all(v)); 
            ans = max(mini,ans); 
            v[ids[0]] = tp.first; 
            v[ids[1]] = tp.second; 
        }
        cout<<ans<<endl; 
    }
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