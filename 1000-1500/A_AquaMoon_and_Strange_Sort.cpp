// only adjacent swaps are allowed
// we need to find how many moves does it takes to reach it's position
// each element has it's target position and to reach there it takes difference_of_positions + even swaps
// even swaps are if we require it to overshoot from position for taking other to desired position
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
#define N 500005
int main()
{
    fast_cin();
    ll test;
    cin >> test;
    // creating this large array each time costs a lot 
    vector<vector<int> > data(N,vector<int>(2,0));
    while(test--){
        int n; cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin>>v[i]; 
        vector<int> temp(n);
        // we only care weather element's even or odd position
        // if there is repeation then they may be at odd or even position so we need to take care of both of them 
        // vector<vector<int> > data(N,vector<int>(2,0));
        for(int i=0;i<n;i++){
            data[v[i]][i&1]++; 
        }
        sort(all(v)); 
        for(int i=0;i<n;i++){
            data[v[i]][i&1]--;
        }
        bool found = true; 
        // for(auto pr: data){
        //     if(pr[0] or pr[1]){
        //         // any ones of then is non zero then it's not possible to have same color 
        //         found = false; 
        //         break; 
        //     }
        // }
        for(int i=0;i<n;i++){
            if(data[v[i]][0] != 0 or data[v[i]][1] != 0){
                found = false; 
                break; 
            }
        }
        if(found) cout<<"YES"<<ln; 
        else cout<<"NO"<<ln; 
        // remove previous data
        for(int i=0;i<n;i++){
            data[v[i]][0] = data[v[i]][1] = 0; 
        }
    }
    return 0;
}