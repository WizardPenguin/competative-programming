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
#define N 5003
int main()
{
    fast_cin();
    ll test;
    cin >> test;
    while(test--){
        int n; 
        cin>>n; 
        v32 v(n);  
        for(int i=0;i<n;i++){
            cin>>v[i]; 
        }
        // assign first node as centre and add all nodes different from it directly to it 
        // after then add remaining after any different node 
        // only case to check when all are having same value 
        bool found  =true; 
        for(int i=1;i<n;i++){
            if(v[i] != v[i-1]){
                found =false; 
                break; 
            }
        }
        if(found){
            cout<<"NO"<<endl; 
        }
        else{
            cout<<"YES"<<endl; 
            int first = v[0]; 
            int other; 
            for(int i=1;i<n;i++){
                if(v[i] != first){
                    cout<<1<<" "<<i+1<<endl; 
                    other = i; 
                }
            }
            for(int i=1;i<n;i++){
                if(v[i] == first){
                    cout<<other+1<<" "<<i+1<<endl; 
                }
            }
        }
    }
    return 0;
}