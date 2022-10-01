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
    unordered_map<int,int> mp; 
    for(auto &i: v) mp[i]+=1; 
    if(mp.size() <= 4 ){ 
        // at most 4 unique values are checked mannually 
        vector<int> tp; 
        for(auto &i: mp){
            int freq = min(3,i.second); 
            while(freq--) tp.push_back(i.first); 
        }
        n = tp.size(); 
        for(int i=0;i<n;i+=1){
            for(int j=i+1;j<n;j+=1){
                for(int k=j+1;k<n;k+=1){
                    if(mp.find(tp[i] + tp[j] + tp[k]) == mp.end()){
                        cout<<"NO"<<endl; 
                        return; 
                    }
                }
            }
        }
        cout<<"YES"<<endl; 
    }
    else{
        cout<<"NO"<<endl; 
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