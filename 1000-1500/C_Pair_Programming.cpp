// only need to take care before editing a[i]th page we need to have that page 
// so stop there and allow other person to work there 
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
#define pii pair<int,int> 
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
        int k,m,n; 
        cin>>k>>n>>m; 
        vector<int> a(n); 
        vector<int> b(m); 
        for(int i=0;i<n;i++) cin>>a[i]; 
        for(int j=0;j<m;j++) cin>>b[j];
        // now need to iterate over both array's 
        // if value at position is smaller than k then we can take this 
        int i=0;
        int j=0;
        bool found = false; 
        vector<int> res;  
        while(true){
            if(i < n and a[i] <= k){
                res.push_back(a[i]);
                k += (a[i] == 0);
                i++;
            }
            else if(j < m and b[j] <= k){
                res.push_back(b[j]);
                k += (b[j] == 0);
                j++;
            }
            else if(i == n and j == m){
                found = true; 
                break; 
            }
            else{
                break; 
            }
        }
        if(found){
            for(auto i: res) cout<<i<<" ";
        }
        else{
            cout<<-1;
        }
        cout<<ln;

    }
    return 0;
}