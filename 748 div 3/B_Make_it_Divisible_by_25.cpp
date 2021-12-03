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
#define N 25
int main()
{
    fast_cin();
    ll test;
    cin >> test;
    while(test--){
        string s; 
        cin>>s; 
        reverse(all(s)); 
        int ans = INT_MAX; 
        int n = s.length(); 
        for(int i=0;i<n;i++){
            if(s[i] == '0'){
                bool found = false; 
                int j=0; 
                for(j=i+1;j<n;j++){
                    if(s[j] == '5' or s[j] == '0'){
                        found = true; 
                        break; 
                    }
                }
                if(found){
                    int toRemove = i + (j - i - 1);
                    ans = min(ans,toRemove); 
                } 
            }
            else if(s[i] == '5'){
                bool found = false; 
                int j = 0; 
                for(j=i+1;j<n;j++){
                    if(s[j] == '2' or s[j] == '7'){
                        found = true; 
                        break; 
                    }
                }
                if(found){
                    int toRemove = i + (j - i -1); 
                    ans = min(ans,toRemove); 
                }
            }
        }
        cout<<ans<<endl; 
    }
    return 0;
}