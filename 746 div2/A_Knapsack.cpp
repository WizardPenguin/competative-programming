// check if there is something > c/2
// if not then add some elements to get something like that 
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
        long long n,w; 
        cin>>n>>w; 
        vector<int> v(n); 
        long long need = ceil(1.0*w/2.0);
        int ans = -1; 
        for(int i=0;i<n;i++){
            cin>>v[i];
            if(v[i] >= need and v[i] <= w){
                ans = i+1;
            }
        }
        if(ans != -1){
            cout<<1<<endl; 
            cout<<ans<<endl;
            continue; 
        }
        long long sum = 0;
        int id = -1;  
        int count =0; 
        for(int i=0;i<n;i++){
            if(v[i] > w) continue; 
            sum += v[i];
            count++;  
            if(sum >= need){ 
                id = i; 
                break; 
            }
        }
        if(id != -1){
            cout<<count<<endl; 
            for(int i=0;i<=id;i++){
                if(v[i] > w) continue; 
                cout<<i+1<<" "; 
            }
            cout<<endl; 
        }
        else{
            cout<<id<<endl; 
        }
    }
    return 0;
}