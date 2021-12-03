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
        map<int,int> a; 
        int val; 
        for(int i=0;i<n;i++){
            cin>>val; 
            if(a[val]){
                a[val]++;
            }
            else{
                a[val] = 1; 
            }
        }
        bool found = true; 
        vector<int> b(n); 
        for(int i=0;i<n;i++) cin>>b[i]; 
        sort(all(b),greater<int>()); 
        // firstly resolve condition of equal ony then see previous element
        for(int i=0;i<n;i++){
            val = b[i]; 
            // if a array has val then good
            // else we can increase val-1 to val using operation so check for val-1 
            // else not possible 
            if(a[val]){
                a[val]--; 
            }
            else if(a[val-1]){
                a[val-1]--; 
            }
            else{
                found = false; 
                break; 
            }
        }
        if(found){
            cout<<"YES"<<endl; 
        }
        else{
            cout<<"NO"<<endl; 
        }
    }
    return 0;
}