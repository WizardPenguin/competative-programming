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
        vector<vector<int> > v(n,vector<int>(5)); 
        for(int i=0;i<n;i++){
            for(int j=0;j<5;j++){
                cin>>v[i][j]; 
            }
        }
        for(int i=0;i<5;i++){
            for(int j=i+1;j<5;j++){
                // let's try to divide whole dataset into group's of i and j 
                int left,right; 
                left = right = 0; 
                // also we need to take care of number which are present in both 
                int both = 0; 
                for(int x=0;x<n;x++){
                    if(v[x][i] and v[x][j]){
                        both++; 
                    }
                    else if(v[x][i]){
                        left++; 
                    }
                    else if(v[x][j]){
                        right++; 
                    }
                }
                if(left <= n/2 and right <= n/2 and left + right + both == n){
                    cout<<"YES"<<endl; 
                    goto end; 
                }
            }
        }
        cout<<"NO"<<endl; 
        end:; 
    }
    return 0;
}