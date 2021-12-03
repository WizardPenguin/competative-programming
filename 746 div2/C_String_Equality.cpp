// matching characters are OK in any order 
// remaining should be clubed in k characters of equal sizes
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
        int n,k; 
        cin>>n>>k; 
        string a,b; 
        cin>>a>>b; 
        vector<int> v(26,0),x(26,0); 
        // we can only increase values so for each value of b we need value in a which is less that it 
        for(int i=0;i<n;i++){
            v[a[i] - 'a']++; 
            x[b[i] - 'a']++; 
        }
        bool found = true;  
        for(int i=0;i<25;i++){
            if(v[i] < x[i]){
                found = false; 
                break; 
            }
            else{
                int remaining = v[i] - x[i]; 
                if(remaining % k != 0){
                    found = false; 
                    break; 
                }
                else{
                    // we need to convert these extra characters to other greater characters
                    v[i+1] += remaining; 
                }
            }
        }
        
        if(found){
            cout<<"Yes"<<endl; 
        }
        else{
            cout<<"No"<<endl; 
        }
    }
    return 0;
}