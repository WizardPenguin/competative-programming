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
    // if we have atlest 1 of both color then we can do it 
    // since if we want swap between elements of 2 different color we'll swap it with other color and that other color swap with other element 
    int n; 
    cin>>n; 
    // or if all are already sorted then any color combo works 
    vi v(n); 
    for(int i=0;i<n;i++){
        cin>>v[i]; 
    }  
    bool inc,dec; 
    inc = dec = true;  
    for(int i=1;i<n;i++){
        if(v[i] < v[i-1]){
            inc = false; 
        }
        else if(v[i] > v[i-1]){
            dec = false; 
        }
    }
    bool z,o; 
    z = o = false; 
    char ch; 
    for(int i=0;i<n;i++){
        cin>>ch; 
        if(ch == '1') z = true; 
        else o = true; 
    }
    if(inc or dec){
        cout<<"Yes"<<endl; 
    }
    else if(z and o){
        cout<<"Yes"<<endl; 
    }
    else{
        cout<<"No"<<endl; 
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