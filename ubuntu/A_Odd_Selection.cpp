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
    int n,x;
    cin>>n>>x; 
    vi v(n); 
    for(int i=0;i<n;i++) cin>>v[i]; 
    int odd =0; 
    int even =0 ; 
    for(auto &i: v){
        if(i&1) odd++; 
        else even ++; 
    }
    if(x&1){
        if(odd)
        odd-=1;
        else{
            cout<<"No"<<endl; 
            return; 
        } 
        int rem = (odd/2)*2 + (even/2)*2; 
        if(rem >= x-1){
            cout<<"Yes"<<endl; 
        }
        else{
            cout<<"No"<<ln; 
        }
    }
    else{
        if(odd and even)
        odd -= 1,even -= 1; 
        else{
            cout<<"No"<<ln; 
            return; 
        }
        int rem = (odd/2)*2 + (even/2)*2; 
        if(rem >= x-2){
            cout<<"Yes"<<endl; 
        }
        else{
            cout<<"No"<<ln; 
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