// we need prime facorisation and the one which is having largest power let say r
// r r r r ... pr is going to be sequence so that multiplication satisfies equation 
// we need to store prime factors till range 
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
#define N 100005
int main()
{
    fast_cin();
    ll test;
    cin >> test;
    vector<int> primes; 
    bitset<N> b(0); 
    for(ll i=2;i< N;i++){
        if(b[i] == 0){
            for(ll j=i*i;j < N;j+=i ){
                b[j] = 1; 
            }
            primes.push_back(i);
        }
    }
    while(test--){
        ll n; 
        cin>>n; 
        int c = 1; 
        long long p = n; 
        ll num = n; 
        for(long long i=0; primes[i]*(long long)primes[i] <= n; i++){
            auto prm = primes[i]; 
            int count =0 ; 
            while(n %prm == 0){
                n/=prm;
                count++; 
            }
            if(count > c){
                p = prm; 
                c = count; 
            }
        }
        vector<long long> res; 
        for(int i=0;i<c-1;i++){
            res.push_back(p); 
            num/=p; 
            // cout<<num<<" ";
        }
        res.push_back(num); 
        cout<<res.size()<<endl; 
        for(auto i: res){
            cout<<i<<" ";
        }
        cout<<endl; 
    }
    return 0;
}