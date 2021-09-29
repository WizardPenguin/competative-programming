// take first number as pointer 
// sort all friends on basis of their k values 
// then for friend with particular k if k is < pointer then give him money otherwise give him pointers gift
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
        int n,m;
        cin>>n>>m;
        vector<int> friends(n,0); 
        vector<int> costs(m,0); 
        for(int i=0;i<n;i++){
            cin>>friends[i]; 
        }
        for(int i=0;i<m;i++){
            cin>>costs[i]; 
        }
        int id=0; 
        long long ans = 0; 
        // sort(all(friends));
        // wrong
        // for(int i=0;i<n;i++){
        //     if(id < friends[i]){
        //         ans += costs[id];
        //         id++;  
        //     }
        //     else{
        //         ans += costs[friends[i]-1];
        //     }
        //     cout<<ans<<" "; 
        // }
        // it's better to have lower costs available for larger id's since smaller one can take gift itself 
        // so start giving from friend having k largest 
        sort(all(friends),greater<int>()); 
        for(int i=0;i<n;i++){
            if(id < friends[i]){
                ans += costs[id]; 
                id++; 
            }
            else{
                ans += costs[friends[i] - 1]; 
            }
            // cout<<ans<<" "; 
        }
        // cout<<endl; 
        cout<<ans<<endl; 
    }
    return 0;
}