// try to generate gcd = p1^x1 * p2^x2 ......
// find power of primes present in resulting gcd 
// find largest power of pi preset in a1....an
// let it be k1.....kn
// then each are going to be pairted atlest once (sort(all(k))) 
// min we can get = min(k) + 2nd min(k) *********WRONG
// since taking lcm of a[i] , a[j] it makes power(prime) = max(power in a[i], power in a[j]); 
// so smallest power possible is = 2nd minimum of all k present there 
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
 #define N 2000006
void solve(){
    int n;
    cin>>n; 
    vi v(n); 
    for(int i=0;i<n;i++){
        cin>>v[i]; 
    }
    // generate all primes 
    bitset<N> b(0);
    ll ans = 1; 
    for(ll i=2;i<N;i++){
        if(b[i] == 0){
            // mark it's factor as non Prime 
            for(ll j=i*i;j<N;j+=i){
                b[j] = 1; 
            }
            // now find maximum power we can get 
            int m1,m2; 
            m1 = m2 = INT_MAX; 
            for(int x=0;x<n;x++){
                // check largest power 
                auto tp = v[x]; 
                int p = 0; 
                while(tp%i == 0){
                    tp/=i; 
                    p++; 
                }
                if(p <= m1){
                    m2 = m1; 
                    m1 = p; 
                }
                else if(p < m2){
                    m2 = p; 
                }
                if(m1 == m2 and m1 == 0) break; 
            }
            // dbg(m1),dbg(m2); 
            for(int x=0;x<(m2);x++){
                ans *= i; 
            }
        }
    } 
    cout<<ans<<endl; 
}
int main(){
    fast_cin();
    solve();
    return 0;
}