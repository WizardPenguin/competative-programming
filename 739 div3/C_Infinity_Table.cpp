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
    vector<long long> v; 
    v.push_back(0); 
    for(long long i=1;(i*i)<=10000000000;i++ ){
        v.push_back(i*i); 
    }
    while(test--){
        int n; 
        cin>>n; 
        auto it = lower_bound(all(v),n) - v.begin();
        // cout<<it<<endl; 
        // it can have +- of (it-1)
        if(v[it] == n){
            cout<<it<<" "<<1<<endl; 
            continue; 
        }
        // now find where it should have to be 
        long long diff = it -1; 
        // cout<<diff<<endl; 
        if(abs(v[it] - n) <= diff){
            cout<<it<<" "<<((v[it]- n) + 1)<<endl; 
        }
        else{ 
            // cout<<"else"<<endl; 
            cout<<(it - (v[it] - n - diff) )<<" "<<it<<endl;
        }
    }
    return 0;
}