// we need to replace character if required such that it don't match with 2left and 2right nodes
// main thing is we don't have to make actual replacement 
// every pallindrome of size 2 and 3 are needing replacement 
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
        vector<int> toReplace(s.length(),true); 
        int ans =0 ; 
        if(s[0] == s[1]){
            toReplace[1] = false; 
            ans ++; 
        }
        // we'll check current character is making pallindrom with previous unreplaced character if it does then replace
        for(int i=2;i<s.length();i++){
            if(s[i] == s[i-1] and toReplace[i-1]){
                toReplace[i] = false ;
                ans++; 
            }
            else if(s[i] == s[i-2] and toReplace[i-2]){
                toReplace[i] = false; 
                ans ++; 
            }
        }
        cout<<ans<<endl; 
    }
    return 0;
}