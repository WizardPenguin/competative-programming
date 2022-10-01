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
    cin>>n; vi v(n); 
    for(int i=0;i<n;i+=1) cin>>v[i]; 
    sort(all(v)); 
    int i=0; 
    int left = true; 
    vector<int> l,r; 
    bool singleFound = false; 
    while(i<n){
        int val = v[i]; 
        int count =0 ; 
        while(i<n and v[i] == val) i+=1,count+=1; 
        if(count > 1){
            l.push_back(val); 
            r.push_back(val); 
        }
        else if(left){
            l.push_back(val);
            left = false;  
        }
        else{
            r.push_back(val); 
            left = true; 
        }
        if(count == 1) singleFound = true; 
    }
    if(l.size() == r.size()){
        cout<<l.size()<<endl; 
    }
    else{
        cout<<min(l.size(),r.size()) + singleFound<<endl; 
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