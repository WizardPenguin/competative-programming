// we can make only even pizza and all even numbers > 6 can be made by these set of pizzas
// for any n we can take pizza of size 6 many times this can give use reminder 0 2 4 
// 0 means we have found exact number of pizza 
// 2 means if we go one step back 6 + 2= 8 
// 4 means 10 heance all even numbers can be made 
// way to construct this doesn't matter since they give constant time 5/2 to make 1 slice of pizza 
// i.e 5 for 2 pizza
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
        ll n; cin>>n; 
        n += n&1; 
        if(n < 6) cout<<15<<endl; 
        else{
            n/=2; 
            cout<<(n*5)<<endl; 
        }
    }
    return 0;
}