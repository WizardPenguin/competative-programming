// bruteforce
// for each character check how many removals are required for making it pallindorme
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
        int ans = INT_MAX; 
        for(int i='a';i<='z';i++){
            int x=0, y = n-1; 
            bool found = true; 
            int count = 0; 
            while(x < y){
                if(s[x] != s[y]){
                    if(s[x] == i){
                        x++; 
                    }
                    else if(s[y] == i){
                        y--; 
                    }
                    else{
                        found = false; 
                        break;
                    }
                    count++; 
                }
                else{
                    x++,y--; 
                }
            }
            if(found){
                ans = min(ans,count); 
            }
        }
        if(ans == INT_MAX){
            cout<<-1<<endl; 
        }
        else{
            cout<<ans<<endl; 
        }
    }
    return 0;
}