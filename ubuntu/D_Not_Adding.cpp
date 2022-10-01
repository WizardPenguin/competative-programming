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
    bitset<N> b(0); 
    int val; 
    for(int i=0;i<n;i++){
        cin>>val; 
        b[val] = 1; 
    }
    int res = 0; 
    for(ll i=N-1;i>=1;i--){
        int count = 0; 
        ll gcd = N; 
        for(ll j = i;j<N;j+=i){
            if(b[j]){
                if(count == 0){
                    gcd = j; 
                    count++; 
                }
                else{
                    gcd = __gcd(gcd,j); 
                }
            }
        }
        if(gcd == i ) res++; 
    }
    cout<<res - n<<endl; 
}
int main(){
    fast_cin();
    solve();
    return 0;
}