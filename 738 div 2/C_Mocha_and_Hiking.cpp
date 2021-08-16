// if starting value if 1 then start from n+1 and reach 1 ..... n since we have paths
// else if we have i and i+1 with values 0 and 1 i.e from i to n+1 and fron n+1 to i+1 then possible else not
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
        vector<int> v(n); 
        for(int i=0;i<n;i++){
            cin>>v[i]; 
        }
        // for(auto i: v) cout<<i<<" "; cout<<endl; 
        if(v[0] == 1){
            cout<<n+1<<" "; 
            for(int i=0;i<n;i++){
                cout<<i+1<<" "; 
            }
            cout<<ln; 
            // cout<<" no need to search"<<endl; 
        }
        else if(v[n-1] == 0){
            // then move from 1...n and then n to n+1 
            for(int i=0;i<n;i++){
                cout<<i+1<<" "; 
            }
            cout<<n+1<<endl; 
        }
        else{
            // cout<<"search"<<endl; 
            // we need to find i and i+1; 
            int foundId  =-1; 
            for(int i=0;i<n-1;i++){
                if(v[i] == 0 and v[i+1] == 1){
                    foundId = i; 
                    break; 
                }
            }
            if(foundId == -1){
                cout<<-1<<endl; 
            }
            else{
                for(int i=0;i<=foundId; i++){
                    cout<<i+1<<" "; 
                }
                cout<<n+1<<" "; 
                for(int i=foundId+1;i<n;i++){
                    cout<<i+1<<" "; 
                }
                cout<<ln; 
            }
        }
    }
    return 0;
}