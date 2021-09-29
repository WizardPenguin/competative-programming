// since distance is only depending on difference on x and difference on y 
// so we minimize difference w.r.t x independently and w.r.t y independently
// if x in even then n/2 + n/2 element lies in middle are going to give same distance w.r.t all points 
// if x is odd then middle element is going to give smallest distance 
// similar case for y 
// so we can take any combination of such x and y 
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


int main()
{
    fast_cin();
    ll test;
    cin >> test;
    while(test--){
        int n; 
        cin>>n; 
        vector<long long> x,y; 
        int a,b; 
        for(int i=0;i<n;i++){
            cin>>a>>b; 
            x.push_back(a); 
            y.push_back(b); 
        }
        if(n & 1){
            cout<<1<<endl; 
        }
        else{
            sort(all(x)); 
            sort(all(y)); 
            int l = (n -1)/2; 
            int r = (n )/2; 
            cout<<(x[r] - x[l] + 1)*(y[r] - y[l] + 1)<<endl; 
        }
        sort(all(x)); 
        sort(all(y));
    }
    return 0;
}