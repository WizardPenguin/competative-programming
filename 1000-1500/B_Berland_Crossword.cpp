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
int n; 
// bool check(int &x,int &y,int &z){
//     // if we fix those elements then we store how many we can fix more 
//     if(x == n){
//         if(y > 0 and z > 0 and x >=2){
//             y--,z--; 
//             x-=2;
//             return true; 
//         }
//     }
//     else if(x == n-1){
//         if(y > 0 and x >=1){
//             // we have fixed 1 element 
//             x--;
//             y--; 
//             return true; 
//         }
//         else if(z > 0 and x >= 1){
//             x--;
//             z--; 
//             return true; 
//         }
//     }
//     else return true; 
//     return false; 
// }
int main()
{
    fast_cin();
    ll test;
    cin >> test;
    while(test--){
        cin>>n; 
        int a,b,c,e; 
        cin>>a>>b>>c>>e;  
        int u,r,d,l;  
        u = a,r = b,d = c,l = e; 
        // if(check(u,l,r) and check(d,l,r) and check(r,d,u) and check(l,d,u)){
        //     cout<<"YES"<<endl; 
        // }
        // else{
        //     cout<<"NO"<<endl; 
        // }
        // try all possible configuration of fixing elements at corners
        // then check remaining could be fitted in n-2 area then we have solution
        // u r d l u 
        bool found = false; 
        for(int i=0;i<16;i++){
            u = a; 
            r = b; 
            d = c; 
            l = e; 
            if(i&1){
                u--,r--; 
            }
            if(i&2){
                r--,d--; 
            }
            if(i&4){
                d--,l--; 
            }
            if(i&8){
                l--,u--; 
            }
            if(min(min(u,r),min(d,l)) >=0 and max(max(u,r),max(d,l)) < n-1){
                found = true; break; 
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