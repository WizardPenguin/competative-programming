#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  
#include <cmath>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define N 1000006
bitset<N> prime(0); 
void solve(){
    int n,e; 
    cin>>n>>e; 
    vector<int> v(n); 
    for(int i=0;i<n;i++){
        cin>>v[i]; 
    }
    vector<int> left(n,0); 
    vector<int> right(n,0); 
    for(int i=e;i<n;i++){
        if(v[i-e] == 1 and v[i] == 1){
            left[i] = left[i-e] + 1; 
        }
    } 
    for(int j=n-e-1; j>=0;j--){
        if(v[j+e] == 1 and v[j] == 1){
            right[j] = right[j+e] + 1; 
        }
    }
    ll ans =0; 
    for(int i=e;i<n-e;i++){
        if(prime[v[i]] == 0){
            ll l,r; 
            l = r = 0;  
            if(v[i-e] == 1){
                l = 1 + left[i-e]; 
                if(v[i+e] == 1){
                    r = 1 + right[i+e]; 
                    ans += l + r + l*r;  
                }
                else{
                    ans += l; 
                }
            }
            else if(v[i+e] == 1){
                r = 1 + right[i+e]; 
                ans += r; 
            }
        }
    }
    for(int i=0;i<e;i++){
        if(prime[v[i]] == 0){
            if(i+e < n )
            if(v[i+e] == 1){
                ans += 1 + right[i+e]; 
            }
        }
    }

    for(int i=n-e;i<n;i++){
        if(prime[v[i]] == 0){
            if(i-e >=0)
            if(v[i-e] == 1){ 
                ans += 1 + left[i-e]; 
            }
        }
    }
    cout<<ans<<endl; 
}
int main()
{
    fast_cin();
    prime[0] = prime[1] = 1; 
    for(ll i=2;i<N;i++){
        if(prime[i] == 0){
            for(ll j=i*i; j<N;j+=i){
                prime[j] = 1; // mark it as non prime
            }
        }
    }
    // we have found marker to each prime 
    ll test;
    cin >> test;
    while(test--){
        solve();
    }
    return 0;
}