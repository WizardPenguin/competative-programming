// number > 10d is alway's achievable 
// for smaller check bruteforcely substracting i*d and checking remaining number being lucky 
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
int n,d; 
bool isLucky(int a){
    while(a){
        if(a%10 == d) return true; 
        a/=10; 
    }
    return false; 
}
int main()
{
    fast_cin();
    ll test;
    cin >> test;
    while(test--){
        cin>>n>>d; 
        vector<int> v(n); 
        for(int i=0;i<n;i++) cin>>v[i]; 
        int maxi = 10*d; 
        for(int i=0;i<n;i++){
            if(v[i] >= maxi){
                cout<<"YES"<<endl; 
            }
            else{
                bool found = false; 
                for(int j=0;j<v[i];j+=d){
                    int check = v[i] - j;
                    if( isLucky(check) ){
                        found = true; 
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
        }
    }
    return 0;
}