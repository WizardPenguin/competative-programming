// try finding * from current + x distance backward for each replacment
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
        int n; cin>>n; 
        int d; cin>>d; 
        string s; cin>>s;
        int i=0;
        // search for first *
        while(i < n and s[i] != '*') i++ ;
        int replacement = 1; 
        for(i;i<n;){  
            int j = min(i + d,n-1); 
            while(j > i and s[j] != '*') j--; 
            if(j == i) break; // there might not be any other replacement further
            i = j;
            // cout<<j<<endl; 
            replacement++; 
        }
        cout<<replacement<<endl; 
    }
    return 0;
}
