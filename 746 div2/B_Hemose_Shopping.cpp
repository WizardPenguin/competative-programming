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
        int n,x; 
        cin>>n>>x; 
        vector<int> v(n); 
        for(int i=0;i<n;i++){
            cin>>v[i]; 
        }
        if(x <= n/2){
            cout<<"YES"<<endl; 
        }
        else{
            // cout<<"we are here"<<endl; 
            auto tp = v; 
            sort(all(tp)); 
            // for(auto i: tp) cout<<i<<" "; 
            // cout<<endl; 
            // thing that already needed to be sorted 
            int start = n-x; 
            bool found = true; 
            // cout<<"working"<<endl; 
            for(int i=start;i+start<=n;i++){
                // cout<<i<<endl; 
                if(v[i] != tp[i]){
                    found = false; 
                    cout<<"NO"<<endl; 
                    break; 
                }
            }
            if(found){
                cout<<"YES"<<endl;
            }
        }
    }
    return 0;
}