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
        int n,h; 
        cin>>n>>h;
        vector<int> v(n); 
        int max1,max2; 
        max1 = max2 = INT_MIN; 
        for(int i=0;i<n;i++){
            cin>>v[i]; 
            if(v[i] >= max1){
                max2  = max1; 
                max1 = v[i]; 
            }
            else if(v[i] >= max2){
                max2 = v[i]; 
            }
        }
        int a = max1;
        int b = max2;
        int moves = a+b; 
        int count = h/moves; 
        count*=2; 
        h%= moves;
        if(h > 0){
            count++;
            h-=a;  
        }
        if(h > 0){
            count++; 
            h-=b; 
        }
        cout<<count<<endl; 
    }
    return 0;
}