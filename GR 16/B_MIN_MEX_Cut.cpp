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
        string s; 
        cin>>s; 
        int zeros = 0; 
        int ones = 0; 
        int i=0;
        int n = s.length();  
        while(i < n  and s[i] == '1') ones++,i++; 
        while(i < n and s[i] == '0')zeros++,i++; 
        while(i < n and s[i] == '1') ones++,i++; 
        if(n == ( zeros + ones)){
            if(zeros)
            cout<<1<<endl; 
            else cout<<0<<endl; 
        }
        else{
            cout<<2<<endl; 
        }
    }
    return 0;
}