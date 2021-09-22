// if there is a composit number there then take it 
// if someone repeats then take it's 2 occurances
// if all are primes then make all numbers and check if someone is non-prime formed there 
// if 0 is there then take it with any number before it 
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
    vector<int> cp = {1,4,6,8,9};
    bitset<100000> b(0); 
    b[0] = 0; 
    b[1] = 1; 
    for(ll i = 2;i<N;i++){
        if(b[i] == 0)
        for(ll j = i*i; j<N;j+=i){
            b[j] = 1; 
        }
    }
    while(test--){
        int n; cin>>n;
        // there are going to be n digits
        string s; cin>>s; 
        bitset<16> count(0); 
        bool found = false; 
        int repeat = -1; 
        int zero = -1; 
        for(int i=0;i<n;i++){
            if(s[i] == '0'){ // if there is zero we can take any number before it 
                zero = i; 
            }
            if(b[s[i] - '0' ]){ // composite occured 
                cout<<1<<endl; 
                cout<<s[i]<<endl; 
                found = true; 
                break; 
            }
            if(count[s[i] - '0'] and s[i] != '0' ){ // someone repeats except 0 
                repeat = s[i] - '0';
            }
            count[s[i] - '0'] = 1; 
        }
        if(!found){
            if(repeat != -1){
                cout<<2<<endl; 
                cout<<repeat<<repeat<<endl; 
                continue; 
            }
            if(zero != -1){
                cout<<2<<endl; 
                cout<<s[zero]<<s[zero -1 ]<<endl;
            }
        }
        else continue; 
        // we have all prime numbers check all possibilities of them weather they are nonprime or not 
        // now count may only be
        int d = 100; 
        int nm = INT_MAX; 
        for(int i=0;i<(1<<n);i++){
            int num = 0; 
            int digits = 0; 
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    num = num*10 + (s[j] - '0'); 
                    digits++; 
                }
            }
            if(b[num]){
                if(digits < d){
                    d = digits; 
                    nm = num;
                }
            }
        }
        cout<<d<<endl; 
        cout<<nm<<endl;  
    }
    return 0;
}