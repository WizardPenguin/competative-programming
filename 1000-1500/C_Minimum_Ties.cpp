// using editorial if i win again next n/2 elements then it's definately going to loose with previous n/2 elements
/// since n/2th is going to have loss from all previous n/2 element so only optoin is to win against next n/2
// in case of n begin even we can make 1 match draw n/2th element gives correct result using construction
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
        if(n&1){
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    if(j-i <= n/2){
                        cout<<1<<" ";
                        // win
                    }
                    else{
                        cout<<-1<<" "; 
                        // lose
                    }
                }
            }
        }
        else{
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    if(j-i < n/2){
                        cout<<1<<" "; 
                    }
                    else if(j-i == n/2){
                        cout<<0<<" "; 
                    }
                    else{
                        cout<<-1<<" "; 
                    }
                }
            }
        }
        cout<<endl;
    }
    return 0;
}