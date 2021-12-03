// 2 numbers p and q 
// p not divisible by q then answer is q
// otherwise we need prime factorisatino of q find find max how many q needed to be removed from p let count times
// after then remove only that prime number which gives least decrease in p for removal 
#include <bits/stdc++.h> 
#include <complex>
#include <cmath>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define N 100000
int main()
{
    fast_cin();
    ll test;
    cin >> test;
    vector<int> primes; 
    bitset<N> b(0); 
    for(ll i=2;i<N;i++){
        if(b[i] == 0){
            primes.push_back(i); 
            for(ll j=i*i;j<N;j+=i){
                b[j] = 1; 
            }
        }
    } 
    while(test--){
        long long p,q; 
        cin>>p>>q; 
        ll tp = p; 
        ll tq = q; 
        // we have 1 case for q = 1 need to deal separately 
        if(p%q == 0){
            map<int,int> factors;
            for(int i=0;i<primes.size() and q > 1;i++){
                if(q%primes[i] == 0){
                    int count = 0; 
                    while(q%primes[i] == 0){
                        q/=primes[i]; 
                        count++; 
                    }
                    factors[primes[i]] = count; 
                }
            }
            if(q != 1){
                factors[q] = 1; 
            }
            q = tq;
            p = tp; 
            // we need to remove primes of q till it could not satisfy prime's count for atlest 1 division 
            // now find which is going to give largest p after removing that power of prime factor
            map<int,int> pfactors; 
            for(auto &i: factors){
                auto fct = i.first; 
                int count = 0; 
                while(p%fct == 0){
                    p/=fct; 
                    count++; 
                }
                pfactors[fct] = count; 
            }
            p = tp; 
            long long ans = LLONG_MAX; 
            for(auto &i: factors){ 
                ll fct = i.first; 
                int reqCount = i.second; 
                int present = pfactors[fct];  
                int toRemove = present - reqCount + 1; 
                long long formed = 1; 
                for(int i=0;i<toRemove;i++){
                    formed *= fct; 
                }
                ans = min(ans,formed); 
            } 
            cout<<p/ans<<endl; 
        }
        else{
            cout<<p<<endl; 
        }
    }
    return 0;
}