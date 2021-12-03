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
        long long n,m,k; 
        cin>>n>>m>>k; 
        long long mini = n-1; 
        long long maxi = (mini * n)/2; 
        if(m >= mini and m <= maxi ){
            if(n == 1 and k > 1){
                // ******* n == 1 is valid for all valid diameters of tree
                cout<<"YES"<<endl;
            }
            else if(k >= 4){
                cout<<"YES"<<endl; 
            }
            else if(k == 3){
                // means < 2 i.e 1
                if(m == maxi){
                    cout<<"YES"<<endl; 
                } 
                else{
                    cout<<"NO"<<endl; 
                }
            }
            else if(k == 2){
                cout<<"NO"<<endl; 
            }
            else{
                cout<<"NO"<<endl; 
            }
        }
        else{
            // either not connected or multiple edges
            cout<<"NO"<<endl; 
        }
    }
    return 0;
}