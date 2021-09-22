// if there is no 0 in between we can never find such string ::: false we can have 2 same strings 
// if there if zero then we can either take same l = 1 or same r = len and then reach 0 and prev number
// such that conditions are satisfied 
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
        string s; 
        cin>>s; 
        int id = -1;
        for(int i=0;i<n;i++){
            if(s[i] == '0'){
                id = i; 
                break; 
            }
        }
        if(id == -1){ // if all are 1's then we can make 2 similar substrings easily 
            // from 1 to mid 
            // 1 to mid + 1
            cout<<1<<" "<<n/2<<" "<<2<<" "<<(n/2)+1<<endl; 
        }
        else if((id+1) > n/2){
            // then take l = 1 forms strings in form X and X0 which are having k = 2 
            cout<<1<<" "<<id + 1<<" "<<1<<" "<<id<<endl; 
        }
        else{
            // then take r = len forms string in form 0X X which are having k = 1
            cout<<id+1<<" "<<n<<" "<<id + 2<<" "<<n<<endl; 
        }
    }
    return 0;
}