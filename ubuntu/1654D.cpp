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
#define Graph vector< vector< tuple<int,int,int> > >
#define N 200005
#define MOD 998244353
ll pwr(ll x,ll p){
    if(p == 1) return x;  
    if(p&1){
        return (x*pwr(x,p-1))%MOD; 
    }
    ll half = pwr(x,p/2); 
    return (half*half)%MOD; 
}
ll modInv(ll x){
    if(x == 1) return 1; 
    return pwr(x,MOD-2); 
}
vi tp,maxi;
vvi primeFactors(N+1); 
Graph graph;
ll res = 0; 
void lcm(int node,int par){ 
    // here we want to find max power of prime in denominator 
    // reality number*q/p but here we are adding power of p since comulating denominator powers
    // we have factor as p/q and need to multipy q/p to our area
    for(auto &[nbr,p,q] : graph[node]){
        if(nbr == par) continue; 
        for(auto &factor: primeFactors[q]){
            tp[factor] -= 1; 
        }
        for(auto &factor: primeFactors[p]){
            tp[factor] += 1; 
            maxi[factor] = max(maxi[factor],tp[factor]); 
        }
        lcm(nbr,node);
        for(auto &factor: primeFactors[q]){
            tp[factor] += 1; 
        } 
        for(auto &factor: primeFactors[p]){
            tp[factor] -= 1; 
        } 
    }
}
void multiplication(ll l,int node,int par){ // before this lcm would have been calculated 1
    res += l; 
    // cout<<res<<endl; 
    if(res > MOD){
        res -= MOD; 
    }
    for(auto &[nbr,p,q] : graph[node]){
        if(nbr == par) continue; 
        ll tp = l; 
        for(auto &factor: primeFactors[q]){
            tp *= factor; 
            tp %= MOD; 
        }
        for(auto &factor: primeFactors[p]){
            tp *= modInv(factor); 
            tp %= MOD; 
        } 
        multiplication(tp,nbr,node); 
    }
}
void solve(){
    int n; 
    cin>>n;
    res = 0; 
    maxi = vector<int>(n+1,0);
    tp = vector<int>(n+1,0);  
    graph = Graph(n);  
    int x,y,p,q;  
    for(int i=0;i<n-1;i+=1){
        cin>>x>>y>>p>>q; 
        x--,y--; 
        graph[x].push_back({y,p,q}); 
        graph[y].push_back({x,q,p}); 
    }
    lcm(0,-1); 
    ll val = 1; 
    for(int i=2;i<=n;i+=1){
        while(maxi[i]--){
            val *= i; 
            val %= MOD; 
        }
    }
    multiplication(val,0,-1); 
    cout<<(res)%MOD<<endl; 
}
int main(){
    fast_cin();
    ll test;
    vector<int> primeFactor(N+1,0); 
    // find prime factors of each number takes NlongN space and time complexity 
    // we are going to store smallest prime factor of a given number and by dividing it by that number we can find other factors 
    for(ll i=N-1;i>1;i-=1){
        for(ll j=i;j<N;j+=i){
            primeFactor[j] = i;  
        }
    }
    primeFactors[1].push_back(1); 
    for(int i=2;i<N;i+=1){
        auto tp = i; 
        while(tp > 1){
            primeFactors[i].push_back(primeFactor[tp]); 
            tp /= primeFactor[tp];
        }
    }
    cin >> test;
    while(test--){
        solve();
    }
    return 0;
}