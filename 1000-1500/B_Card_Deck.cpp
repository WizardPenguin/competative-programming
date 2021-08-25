// take increasing part as whole 
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
        vector<int> v(n); 
        for(int i=0;i<n;i++){
            cin>>v[i]; 
        }
        // if it's increasing break it
        // if decreasing then take largest decreasing part till it's smaller then first number of this part
        int i=0;
        deque<int> res; 
        while(i < n){
            if(i < n-1 and v[i] < v[i+1]){
                res.push_front(v[i]); 
            }
            else{
                int prev = i; 
                while(i < n-1 and v[prev] > v[i+1]){
                    i++; 
                }
                for(int j = i;j >= prev;j--){
                    res.push_front(v[j]); 
                } 
            }
            i++; 
        }
        for(auto j: res){
            cout<<j<<" "; 
        }
        cout<<endl; 
    }
    return 0;
}