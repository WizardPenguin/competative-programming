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
#define N 55
void solve(){
    int n; 
    cin>>n; 
    vi v(n); 
    for(int i=0;i<n;i++){
        cin>>v[i]; 
    }
    string s; 
    for(int i=0;i<N;i++){
        s += "a"; 
    }
    vs res; 
    res.push_back(s); 
    for(int i=0;i<n;i++){
        string tp = res.back().substr(0,v[i]);
        char end; 
        if(res.back()[v[i]] == 'a'){
            end = 'b'; 
        }
        else{
            end = 'a'; 
        }
        for(int x=tp.length()-1;x<N;x++){
            tp += end; 
        }
        res.push_back(tp); 
    }
    for(auto &str: res) cout<<str<<endl; 

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