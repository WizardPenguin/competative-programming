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
typedef vector<vector<bool> > vvb;
typedef vector<string> vs;
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define N 500005
vvi v(N); 
void solve(){
    int q; 
    cin>>q; 
    int x,y,z; 
    vector<int> res; 
    while(q--){
        cin>>x; 
        if(x == 1){
            cin>>y; 
            res.push_back(y); 
            v[y].push_back(res.size()-1); 
        }
        else{
            cin>>y>>z; 
            // replace all x's with y's 
            if(y == z) continue; 
            auto &ys = v[y]; 
            auto &zs = v[z]; 
            // after this operation x becomes empty and z has all it's values with y's values 
            // instead of blind triversal we can make the larger array as z so only samller part needs movement
            // initially we are moving all u's to z's but if x has more elements then it's not beneficial 
            if(ys.size() > zs.size()){
                swap(ys,zs); 
            }
            // now ys will be smaller ones 
            for(auto i: ys) zs.push_back(i);
            ys.clear();  
        }
    }
    for(int i=0;i<N;i++){
        for(auto &val: v[i]){
            res[val] = i; 
        }
    }
    for(auto &i: res) cout<<i<<" "; 
}
int main(){
    fast_cin();
    solve();
    return 0;
}