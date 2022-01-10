// find multiples of n till n*n-1
// for each i find weather (prod + 1) is multiple of i 
// multiples can be found in summesion(n/i) which is O(log(n))
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
    ll n; 
    cin>>n; 
    vll guess; 
    for(int i=0;i<n-1;i++){
        guess.push_back(n*i + 1); 
    }
    for(auto &i: guess) cout<<i<<" "; 
    cout<<endl; 
    vi res = {1}; 
    for(int i=2;i<n;i++){
        for(ll j=i+1;j < n;j++){
            if(binary_search(all(guess),i*j)){
                if(i != j){
                    res.push_back(i); 
                    res.push_back(j); 
                }
            }
        }
    }
    sort(all(res)); 
    for(auto &i: res) cout<<i<<" "; 
    cout<<endl; 
}
int main(){
    fast_cin();
    solve(); 
    return 0;
}