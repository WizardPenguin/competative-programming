// let gcd is in powers of 2 of length c 
// after then multiply it by 3,5 respectively to get a,b of respective lengths
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
int len(long long n){
    int count =0 ; 
    while(n){
        n/=10; 
        count++; 
    }
    return count; 
}

int main()
{
    fast_cin();
    ll test;
    cin >> test;
    while(test--){
        int a,b,c; 
        cin>>a>>b>>c; 
        long long gcd = 1;
        while(len(gcd) < c){
            gcd *= 2; 
        }
        // now we have found desired gcd in long2(10^c) steps
        int x = gcd; 
        int y = gcd; 
        while(len(x) < a) x*=3; 
        while(len(y) < b) y*=5; 
        cout<<x<<" "<<y<<endl; 
    }
    return 0;
}