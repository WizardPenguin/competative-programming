// store count of a[i]%m 
// then we can pair elements that will sum = m in any permutation saparated in new sets
// remaining each element need new set for them 
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
        int n,m; 
        cin>>n>>m; 
        vector<int> v(m,0); 
        int val;  
        for(int i=0;i<n;i++){
            cin>>val; 
            v[val%m]++; 
        }
        int sets = 0; 
        if(v[0] != 0) sets++; 
        for(int i=1;i<m;i++){
            // skip if no pairing possible
            if(v[i] == 0 or v[m-i] == 0) continue; 
            if(abs(v[i] - v[m-i]) <= 1){
                v[i] = 0;
                v[m-i] = 0; 
            }
            else if(v[i] > v[m-i]){
                v[i] -= v[m-i]+1;
                v[m-i]= 0;
            }
            else{
                v[m-i] -= v[i]+1; 
                v[i] = 0; 
            }
            sets++; 
        }
        for(int i=1;i<m;i++){
            sets += v[i]; 
        }
        cout<<sets<<endl; 
    }
    return 0;
}