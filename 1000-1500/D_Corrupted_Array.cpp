// sum can be either last number or second last number  in sorted array 
// if it's last then need to check all elements for x
// else k is last element wholesum == 2nd last element 
// otherwise solution not possible 
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
        int n; cin>>n; 
        n+=2; 
        vector<int> v(n); 
        for(int i=0;i<n;i++) cin>>v[i] ;
        long long sum = 0; 
        sort(all(v)); 
        for(int i=0;i<n-2;i++) sum += v[i]; 
        if(sum == v[n-2]){
            for(int i=0;i<n-2;i++) cout<<v[i]<<" ";
            cout<<endl; 
        }
        else{
            sum += v[n-2];  
            int id = -1; 
            for(int i=0;i<=n-2;i++){
                sum -= v[i];
                if(sum == v[n-1]){
                    id = i; 
                    break; 
                }
                sum += v[i]; 
            } 
            if(id != -1){
                for(int i=0;i<n-1;i++) if(i != id) cout<<v[i]<<" "; 
                cout<<endl; 
            }
            else{
                cout<<id<<endl; 
            }
        }
    }
    return 0;
}