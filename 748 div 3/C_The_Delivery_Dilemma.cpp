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
        vector<array<long long,2> > ar(n); 
        for(int i=0;i<n;i++){
            int a; cin>>a; 
            ar[i][0] = a; 
        }
        for(int i=0;i<n;i++){
            int a; cin>>a; 
            ar[i][1] = a; 
        }
        sort(all(ar),[](auto &a,auto &b){
            return a[0] > b[0]; 
        });
        // now we have largest element on first index we can go for it ourselves instead of delivery boy 
        long long sum = 0; 
        int i=0; 
        for(;i<n;i++){
            sum += ar[i][1]; 
            if(sum >= ar[i][0]){
                // dont' go for it ask for it by delivery 
                sum -= ar[i][1]; 
                break; 
            }
        }
        if(i == n) cout<<sum<<endl; 
        else cout<<max(ar[i][0],sum)<<endl; 
    }
    return 0;
}