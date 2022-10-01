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
#define N 1000006
void solve(){
    int n; 
    cin>>n; 
    int val; 
    bitset<N> b(0); 
    for(int i=0;i<n;i++){
        cin>>val; 
        b[val] = 1; 
    }
    int res = 0;   
    for(ll i=N-1;i>0;i--){ // check weather i can be gcd of numbers
        int count = 0; 
        for(ll j=1;j*i<N;j++){
            if(b[i*j]){
                count++; 
            }
            if(count >= 2){
                break; 
            }
        }     
        if(count >= 2 and b[i] == 0){
            // cout<<i<<" ";
            b[i] = 1; // we have inserted this number 
            res++;
            // for(ll j =1;i*j<N;j++){
            //     b[i*j] = 0; // mark them false since they have made a gcd and can't particupate any more 
            // }  
        }
    }
    cout<<res<<endl; 
}
int main(){
    fast_cin();
    solve();
    return 0;
}