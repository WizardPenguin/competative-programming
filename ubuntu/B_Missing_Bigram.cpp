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
    vs v; 
    string s; 
    for(int i=0;i<n-2;i++){
        cin>>s; 
        v.push_back(s); 
    }
    bool found = false; 
    for(int i=1;i<n-2;i++){
        if(v[i-1][1] != v[i][0]){
            found = true; 
            string tp; 
            tp += v[i-1][1]; 
            tp += v[i][0];  
            v.insert(v.begin() + i,tp); 
            break; 
        }
    }
    if(!found){
        auto prev = v.back()[1]; 
        string tp; 
        tp += prev; 
        tp += prev; 
        v.push_back(tp); 
    }  
    string res; 
    res += v[0][0]; 
    for(int i=1;i<n-1;i++){
        res += v[i][0];
    }
    res += v.back()[1]; 
    cout<<res<<endl; 
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