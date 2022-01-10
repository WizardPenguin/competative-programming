// for a prime and a coprime 
// p and xp where x is remaining part left while dividing by p ,
// if x >= p
// then 3 numbers as side of triangle are 1,x,p 
// since x >= p , 1 + x > p satisfies triangnle inequality 
// so for each prime we need to find such number which might help to do something like this 
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
#define N 1000006
vll prime; 
void solve(){
    ll n; 
    cin>>n; 
    // int ans = 1; 
    // for(auto &i: prime){
    //     if(i<=n and i*i > n){
    //         ans++; 
    //     }
    // }
    // cout<<ans<<endl; 
    // we can apply binary search to find first one whose i*i > n 
    // after then find upper bound of n and hence we can calculate number of such primes
    int l = 0; 
    int r = prime.size()-1; 
    int ans = 0; 
    while(l<=r){
        int mid = (l + r)/2; 
        if(prime[mid]*prime[mid] > n){
            ans = mid; 
            r = mid-1; 
        }
        else{
            l = mid+1; 
        }
    }
    // now find upper bound 
    int id = upper_bound(all(prime),n) - prime.begin(); 
    cout<<(id - ans + 1)<<ln; 
}
int main(){
    fast_cin();
    ll test;
    cin >> test; 
    bitset<N> b(0); 
    for(ll i=2;i<N;i++){
        if(b[i] == 0){
            for(ll j = i*i;j<N;j+=i){
                b[j] = 1; 
            }
            prime.push_back(i); 
        }
    }
    while(test--){
        solve();
    }
    return 0;
}