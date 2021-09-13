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
        string a,b; 
        cin>>a>>b; 
        vector<int> v(n);
        for(int i=0;i<n;i++){
            if(a[i] != b[i]){
                v[i] = 2; 
            }
            else{
                v[i] = a[i] - '0'; 
            }
        }
        int i=0;
        int ans =0 ;  
        // for(auto i: v) cout<<i<<" "; 
        // cout<<endl; 
        while(i < n){
            if(v[i] == 2){
                ans +=2; 
            }
            else if(v[i] == 1){
                // then try find zero 
                int prev = v[i]; 
                while(i<n and v[i] == prev)i++; 
                if(i == n) break; 
                ans += 2; 
            }
            else{
                // v[i] == 0
                // mex = 1 but if we found 1 then well done
                if(i != n-1 and v[i+1] == 1){
                    ans += 2; 
                    i++; 
                }
                else{
                    ans += 1;
                }

            }
            i++; 
        }
        cout<<ans<<endl; 
    }
    return 0;
}