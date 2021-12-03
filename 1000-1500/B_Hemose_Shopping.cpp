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
        int n,x; 
        cin>>n>>x; 
        vector<int> v(n); 
        for(int i=0;i<n;i++) cin>>v[i]; 
        if(n >= 2*x){
            cout<<"YES"<<endl; 
            // since element y is <x distance from it's oritinal position then it can be taken far
            // after then y can be taken in it's true position so always possible
        }
        else{
            // for each element i we can swap it with element < i-x and > i+x 
            // after then it gives this ith element more position to get swaped with from new pos
            // so if some element which can never we swaped needs to be at their original position 
            // there must be such element now since x > n/2 so there are from n-x-1 index to xth index 
            vector<int> s = v; 
            sort(all(s)); // increasing order
            bool found = false; 
            for(int i=n-x;i<x;i++){
                if(s[i] != v[i]){
                    found = true; 
                    break; 
                }
            }
            if(found){
                cout<<"NO"<<endl; 
            }
            else{
                cout<<"YES"<<endl; 
            }
        }
    }
    return 0;
}