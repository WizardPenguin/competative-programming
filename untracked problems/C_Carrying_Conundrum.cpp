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

#define N 500005
int main()
{
    fast_cin();
    ll test;
    cin >> test;
    vector<int> x(N,0); 
    for(int i=1;i<N;i++){
        x[i] = x[i-1]^i; 
    }
    while(test--){
        int a,b; 
        cin>>a>>b; 
        vector<int> x,y; 
        while(a){
            x.push_back(a%10); 
            a/=10; 
        }
        while(b){
            y.push_back(b%10); 
            b/=10; 
        }
        reverse(all(x)); 
        reverse(all(y));
        for(auto i: x) cout<<i<<" "; 
        cout<<endl; 
        for(auto j: y) cout<<j<<" "; 
        cout<<endl;  
        // we have both numbers 
        vector<int> res(100,0); 
        int i=0; 
        while(i < x.size() and i < y.size()){
            int sum = x[i] + y[i] + res[i]; 
            // move carry 2 step forward 
            res[i+2] = sum/10; 
            res[i] = sum%10;  
            i++; 
        }
        while(i < x.size()){
            int sum = x[i] + res[i]; 
            res[i+2] = sum/10; 
            res[i] = sum%10; 
            i++; 
        }
        while(i< y.size()){
            int sum = y[i] + res[i]; 
            res[i+2] = sum/10; 
            res[i] = sum%10;  
            i++; 
        }
        i--; 
        while(res[i+2]){
            int sum = res[i]; 
            res[i+2] = sum/10; 
            res[i] = sum%10;
            i++;  
        }
        // it breaks if we don't have any undone carray 
        reverse(all(res)); 
        for(int x=0;x<i;x++){
            cout<<res[x]; 
        }
        cout<<endl; 
    }
    return 0;
}