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
        int n ; cin>>n; 
        if(n == 1){
            cout<<1<<" "<<0<<endl; 
        }
        else if(n == 2){
            cout<<0<<" "<<1<<endl; 
        }
        else if(n%3 == 0){
            int a = n/3; 
            cout<<a<<" "<<a<<endl; 
        }
        else if(((n-1)%3 )== 0){
            int a = (n-1)/3 + 1;
            int b = a - 1; 
            cout<<a<<" "<<b<<endl; 
        }
        else{
            int a = (n-2)/3;
            int b = a + 1; 
            cout<<a<<" "<<b<<endl;
        }

    }
    return 0;
}