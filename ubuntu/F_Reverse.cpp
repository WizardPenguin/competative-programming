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
string itos(ll x){
    string s; 
    while(x){
        if(x&1) s += '1';
        else s += '0';
        x >>= 1;  
    }
    reverse(all(s)); 
    return s; 
}
int bal = 0; 
bool check(string &sx,string &sy,int n,int m){
    if(n >= m)
    for(int i=0;i<n-m+1-bal;i++){
        bool found = true; 
        for(int j=0;j<m;j++){
            if(sy[i+j] != sx[j]){
                found = false; 
                break; 
            }
        }
        if(found){
            for(int j=0;j<i;j++){
                if(sy[j] != '1'){
                    found = false; 
                    break; 
                }
            }
            if(!found) continue; 
            for(int j=i+m;j<n + bal;j++){
                if(sy[j] != '1'){
                    found = false; 
                    break; 
                }
            }
            if(found){
                return true; 
            }
        }
    }
    return false; 
}
void solve(){
    ll x,y; 
    cin>>x>>y; 
    // convert x to y 
    // cout<<bitset<4>(x)<<" "<<bitset<4>(y)<<endl; 
    string sx = itos(x); 
    string sy = itos(y); 
    int n = sy.length(); 
    int m = sx.length(); 
    if(check(sx,sy,n,m)){
        cout<<"YES"<<endl; 
        return; 
    }
    // cout<<"1"<<endl; 
    while(sx.back() == '0'){
        sx.pop_back(); 
    }
    m = sx.size(); 
    if(check(sx,sy,n,m)){
        cout<<"YES"<<endl; 
        return; 
    }
    // cout<<"2"<<endl; 
    reverse(all(sx)); 
    if(check(sx,sy,n,m)){
        cout<<"YES"<<endl; 
        return; 
    }
    cout<<"NO"<<endl; 
}
int main(){
    fast_cin();
    solve();
    return 0;
}