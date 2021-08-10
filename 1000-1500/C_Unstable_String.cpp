//
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
        int prev = 0; 
        int prevNeed = 0; 
        int prevQues = -1; 
        ll ans = 0; 
        int n = s.length();
        for(int i=0;i<n;i++){
            if(prevNeed == (s[i] - '0')){
                prevNeed = 1- prevNeed; 
                ans += i - prev+1;
                prevQues = -1;  
            }
            else if(s[i] == '?'){
                if(prevQues == -1){
                    prevQues = i;  
                }
                ans += i - prev + 1;
                prevNeed = 1-prevNeed;
            }
            else{
                // we have to start new string 
                prevNeed = s[i] - '0';
                if(prevQues != -1){
                    ans += i - prevQues+1;
                    prev = prevQues; 
                }
                else{
                    ans += 1; 
                    prev = i; 
                }
                prevNeed = 1 - prevNeed; 
                prevQues = -1; 
            }
            // dbg(prev); 
            // dbg(prevNeed); 
            // dbg(prevQues); 
            // dbg(ans); 
        }
        cout<<ans<<endl; 
    }
    return 0;
}