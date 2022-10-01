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
    int n,m; 
    cin>>n>>m; 
    // cerr<<m<<endl; 
    vi v(n); 
    for(int i=0;i<n;i+=1) cin>>v[i]; 
    int k; 
    cin>>k; 
    vi res(k); 
    for(int i=0;i<k;i+=1) cin>>res[i]; 
    if(m == 1){
        if(res == v){
            cout<<"Yes"<<endl; 
        }
        else{
            cout<<"No"<<endl; 
        }
    }
    else{
        vector<pll> tv; 
        for(auto &i: v){
            ll count = 1; 
            while(i%m == 0){
                count *= m; 
                i/=m; 
            }
            if(not tv.empty() and tv.back().first == i){
                tv.back().second += count;
            }
            else{
                tv.push_back({i,count}); 
            }
        }
        // for(auto &pr: tv){
        //     cerr<<pr.first<<" "<<pr.second<<endl;
        // }
        vector<pll> tr; 
        for(auto &i: res){
            ll count = 1; 
            while(i%m == 0){
                count *= m; 
                i/=m; 
            }
            if(not tr.empty() and tr.back().first == i){
                tr.back().second += count; 
            }
            else{
                tr.push_back({i,count}); 
            }
        }
        // for(auto &pr: tr){
        //     cerr<<pr.first<<" "<<pr.second<<endl;
        // }
        if(tr == tv){
            cout<<"Yes"<<endl; 
        }
        else{
            cout<<"No"<<endl; 
        }
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