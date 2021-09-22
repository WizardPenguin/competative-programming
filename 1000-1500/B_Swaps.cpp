// for each element in a array we need to find first element which is larger than this 
// for each element in b array we need to find first smallar element in a array 
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
        vector<int> o(n),e(n); 
        for(int i=0;i<n;i++) cin>>o[i]; 
        for(int j=0;j<n;j++) cin>>e[j]; 
        vector<int> fSmall(2*n + 1,-1); 
        vector<int> fLarge(2*n + 1,-1);  
        // first small required for even numbers 
        int id = 2*n; 
        for(int i=0;i<n;i++){
            int elm = o[i];  
            for(int j=elm;j<=id;j++){
                fSmall[j] = i;
            }
            id = min(id,elm);
        }
        // for odd we need first larger element 
        id = 0; 
        for(int i=0;i<n;i++){
            int elm = e[i]; 
            for(int j=id;j<=elm;j++){
                fLarge[j] = i; 
            }
            id = max(id,elm);
        }
        // cout<<"for even"<<endl; 
        // for(auto i: fSmall){
        //     cout<<i<<" "; 
        // }
        // cout<<endl;
        // cout<<"for odd"<<endl;  
        // for(auto i: fLarge){
        //     cout<<i<<" "; 
        // }
        int ans = INT_MAX; 
        // for odd we are finding first element larger
        for(int i=0;i<n;i++){
            ans = min(ans,i +fLarge[o[i]] ); 
        }
        for(int i=0;i<n;i++){
            ans = min(ans,i + fSmall[e[i]]); 
        }
        cout<<ans<<endl; 
    }
    return 0;
}